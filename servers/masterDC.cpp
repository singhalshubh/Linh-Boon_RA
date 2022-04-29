/* Master Data center acts as the following: 

1. In case of decentralised platform, it acts like any other data center (given by the flag data center = true) but in case of centralised, it acts as the master which will be denoted by the following address only "127.0.0.1:8000/8001/8002" as the set of replicas working together(replica number = 2).

2. Like other DCs, it knows the network toplogy adjacent to the data center assuming the topology denoted by mesh, ring, or shape given by the optional request flag denoting the adj matrix/adj list of the other DC's omn user's choice on paper, given by the flag = NetworkTypeTopology; 
var NetworkTopology: mesh, ring, adj_matrix, adj_list where the partition of which DC gets what is done at the bash script level. 

3. DC's individual struct computeThatCanBeExecutedUser, totalVolumeThatCanBeStored User by mentioning it in either way by providing "-all<struct>", or "--pair <struct>", where we read the data from the user file provided: DC_info.protobufp, json, apache-thrift,xml-rpc, php, which will be provided by the client support given in clients/ directory. 

4.	  From server_config.json<server-id = 1(for master in case of centralised)>: 
		queueLength; //Scheduler Characteristics
		policyOfScheduler given by functionName=policyFileName (in case of centralised, have a separate flag which contains our communication protocol.)
		type=centralised, (should be same for all servers (pjm only) -> Record and send the tasks using estimation module!!) otherwise,
		Decentralised-type(scheduler is "same" for (1,2) or "functionName=policyFileName" for 2.  
			1. client request job subtask received, 
			2. allocated by other pjms of other DC's) -> (pjm + sjm)
*/



#include "setupServers.cpp"
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <arpa/inet.h>
#include <vector>
#include <strings.h>
#include <sys/socket.h>
#include <string>
#include <unordered_map>

#include <semaphore.h>
#include <fstream>
#include "./common/kvcomm.pb.h"


#define NUMBER_OF_CONNECTIONS_ALLOWED 1000

struct r {

	// Facility to return the answer would definitely be considered but application specific!
	double arrival_time;
	double waiting_time;
	double rtt_time_total;
	int number_of_tasks;
	string sender;
	string cor_job_id;
	double exec_time;
};

unordered_map<string, struct r*> job_map;
unordered_map<string, struct r*> task_map;

int server_port;
string server_ip;
string server_address;

struct thread_info {
	pthread_t threadID;
	int connection_fd;
	string type = "";
};


/*Scheduler code is here. Shift it to scheduler after completion*/

struct task {

	vector<string> command;
	int datacenter;
	int compute;
	int input_vol;
	string task_id;

};

struct job {

	int connection_fd; //For communicating with the client
	kv::command job_desc;
	int estimatedTime;
	vector<struct task*> tasks;
};

vector<struct job*> job_queue;
vector<struct task*>task_queue;
pthread_mutex_t isSchedulerJobRun;
pthread_mutex_t isSchedulerTaskRun;
pthread_mutex_t jobQueue;
pthread_mutex_t taskQueue;
bool flag_scheduler_run_job = false;
bool flag_scheduler_run_task = false;

sockaddr_in getSockAddr(const std::string &ip_port) {
    size_t position = ip_port.find(':');
    std::string ip = ip_port.substr(0, position);
    int port = std::stoi(ip_port.substr(position + 1, std::string::npos));
    struct sockaddr_in addr{};
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &(addr.sin_addr));
    return addr;
}

void doRead(int fd, char *buffer, size_t bytes_to_read) {
    size_t bytes_read;
    size_t last_index = 0;
    while ((bytes_read = read(fd, &buffer[last_index], bytes_to_read)) < bytes_to_read) {
        if (bytes_read < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        last_index += bytes_to_read;
        bytes_to_read -= bytes_read;
    }
}

void writeCommand(int sock_fd, kv::command &command){
    size_t comm_len = command.ByteSizeLong();
    write(sock_fd, &comm_len, sizeof(comm_len));
    char serialization[command.ByteSizeLong()];
    command.SerializeToArray(serialization, (int) command.ByteSizeLong());
    write(sock_fd, serialization, command.ByteSizeLong());

}


int taskRun(string command) {

	int childpid = fork();
	if(childpid == 0) {

		// Maintianed for (only) python scripts without any flags
		char *argv[3];
		argv[0] = (char *) "/usr/bin/python3";
        argv[1] = (char *) command.c_str();
        argv[2] = NULL;
           //execvp("/usr/bin/python",argv);
        execvp(argv[0], argv);

	}
	else {

		wait(NULL);

	}

}

// Taks execution begins from here wrt to scheduler
void schedulerRunTask(string type) {

	if(type.compare("scf") == 0) {

		while(!task_queue.empty()) {
			pthread_mutex_lock(&taskQueue);

			int min_compute = task_queue[0]->compute;
			int pos = 0;
			// Perform the iteration!
			for(int i = 0; i < task_queue.size(); i++) {

				if(min_compute > task_queue[i]->compute) {
					pos = i;
					min_compute = task_queue[i]->compute;
				}
			}

			task_queue.erase(task_queue.begin()+pos);
			// Update the waiting times
			unordered_map<string, struct r*>:: iterator t;
			if( (t = task_map.find(task_queue[pos]->task_id)) != task_map.end()) {
				t->second->waiting_time = time(NULL) - t->second->arrival_time; // Waiting time is in seconds and is the difference for the time-arrival!
			}
			else {
				fprintf(stderr, "[Task Map at fault, please check code!]\n");
			}
			// fprintf(stderr, "%d\n", min_exec_time);
			pthread_mutex_unlock(&taskQueue);
			// Execute the job by undangling the task stored in vector<tasks>
				
			clock_t t1;
    		t1 = clock();

			for(auto command: task_queue[pos]->command) {

				taskRun(command);

			}

			t1 = clock() - t1;
			t->second->exec_time = (double) t1/CLOCKS_PER_SEC;
			fprintf(stderr, "Time taken: %f\n", t->second->exec_time);
			// time noted for the task and then returned from the sender suing task-map!
			// Return the struct r to the sender!
			kv::command task_response;
			task_response.set_comm_type("Task-Response");
			task_response.set_unique_task_id(t->first);
			task_response.set_waiting_time(t->second->waiting_time);
			task_response.set_exec_time(t->second->exec_time);
			//fprintf(stderr, "Sending the task_response\n");
			fprintf(stderr, "%s\n", t->second->sender.c_str());
			int sock_fd = socket(PF_INET, SOCK_STREAM, 0);
		    struct sockaddr_in servaddr = getSockAddr(t->second->sender);
		    if (connect(sock_fd, (struct sockaddr *) &servaddr, sizeof(servaddr)) != -1) {
				fprintf(stderr, "[Writing to the server]: %s\n", t->second->sender.c_str());
				writeCommand(sock_fd, task_response);
			}
			close(sock_fd);

		}
	}

}

int schedulerRun(string type) {

	if(type.compare("stf") == 0) {

		pthread_mutex_lock(&jobQueue);
		fprintf(stderr, "Running\n");
		while(!job_queue.empty()) {

			int min_exec_time = job_queue[0]->estimatedTime;
			int pos = 0;
			// Perform the iteration!
			for(int i = 0; i < job_queue.size(); i++) {

				if(min_exec_time > job_queue[i]->estimatedTime) {
					pos = i;
					min_exec_time = job_queue[i]->estimatedTime;
				}
			}

			job_queue.erase(job_queue.begin()+pos);

			fprintf(stderr, "[Size left]%ld\n",job_queue.size());

			// fprintf(stderr, "%d\n", min_exec_time);
			// Execute the job by undangling the task stored in vector<tasks>
			unordered_map<string, struct r*>::iterator j;
			if( (j = job_map.find(job_queue[pos]->job_desc.unique_job_id())) != job_map.end()) {
				j->second->number_of_tasks = job_queue[pos]->tasks.size();
			}
			else {
				fprintf(stderr, "[Error in job_map, please check the code]\n");
			}
			
			for(int i = 0; i < job_queue[pos] -> tasks.size(); i++) {

				struct r* mapping = new r;
				mapping->sender = server_address;
				mapping->cor_job_id = job_queue[pos]-> job_desc.unique_job_id();
				task_map.insert(make_pair(job_queue[pos] -> job_desc.unique_job_id() + to_string(i), mapping));

				kv::command task;
				task.set_comm_type("Task-Reply");
				task.set_sender_address(server_address);
				task.set_compute_task(job_queue[pos]->tasks[i]->compute);
				// Only one task per task, not consideriung parallel tasks
				string task_list = "";
				for(auto t : job_queue[pos]->tasks[i]->command) {
					task_list += t + ",";
				}
				task_list += "END";
				task.set_task_info(task_list);
				task.set_unique_task_id(job_queue[pos] -> job_desc.unique_job_id() + to_string(i));

				string to_send = serverInfo[job_queue[pos]->tasks[i]->datacenter - 1] -> address;
				int sock_fd = socket(PF_INET, SOCK_STREAM, 0);
			    struct sockaddr_in servaddr = getSockAddr(to_send);
			    if (connect(sock_fd, (struct sockaddr *) &servaddr, sizeof(servaddr)) != -1) {
					fprintf(stderr, "[Writing to the server]\n");
					writeCommand(sock_fd, task);
				}


			}
		}
		pthread_mutex_unlock(&jobQueue);


	}

}


void indicateSchedulerTaskToRun() {
	pthread_mutex_lock(&isSchedulerTaskRun);
	flag_scheduler_run_task = true;
	pthread_mutex_unlock(&isSchedulerTaskRun);
	schedulerRunTask("scf");
}

void indicateSchedulerJobToRun() {
	pthread_mutex_lock(&isSchedulerJobRun);
	flag_scheduler_run_job = true;
	pthread_mutex_unlock(&isSchedulerJobRun);
	schedulerRun("stf");
	
	// round robin scheduler!

	// Indicate the scheduler to start the procedure of scheduling in job_queue
}





/*--------------------------------------------------------------*/

void readFromJobsJson(string jobs_fileName, struct job *nn, int index) {

	// Check if the fileName is json type or not.
	ifstream j(jobs_fileName, ifstream::binary);
	Json::Value job_file_info;
	j >> job_file_info;
	
	string job_index = to_string(index);
	nn->estimatedTime = job_file_info[job_index]["time"]["seconds"].asInt();

	// Iterate for the tasks inside the job
	string tracker = "1";
	// time is parameter so tracker < size! adjust accprdingly
	while(stoi(tracker) < job_file_info[job_index].size()) {

		struct task *tt = new task;
		// fprintf(stderr, "Reading%d\n", job_file_info[job_index].size());

		for(int i = 0; i < job_file_info[job_index][tracker]["command"].size(); i++) {
			tt->command.push_back(job_file_info[job_index][tracker]["command"][i].asString());
		}

		tt->datacenter = job_file_info[job_index][tracker]["datacenter"].asInt();
		tt->compute = job_file_info[job_index][tracker]["compute"].asInt();
		tt->input_vol = job_file_info[job_index][tracker]["input"].asInt();

		nn->tasks.push_back(tt);
		// fprintf(stderr, "%s\n", tracker.c_str());
		tracker = to_string(stoi(tracker)+1);
		// fprintf(stderr, "%s\n", tracker.c_str());
	}

}


// Requires server-number, file name as argument

void processCommand(struct thread_info* node, kv::command &command) {

	if(command.comm_type().compare("Client:Job") == 0) {

		// see the DC that the job has to be allocated and then allocate it and move on.
		// Server is sending the request to the correct server and executing the request.

		// which data center does the job belong to?
		// extract the server number anbd port which the data center is corresponding to?
		int datacenterIndex = command.data_center()-1;
		fprintf(stderr, "[Client-Job is for: ]%s\n", serverInfo[datacenterIndex]->address.c_str());
		string server_port = to_string(serverInfo[datacenterIndex] -> port);
		string server_ip = serverInfo[datacenterIndex] -> ip;

		time_t sec = time(NULL);
		struct r* mapping = new r;
		mapping->sender = command.sender_address();
		job_map.insert(make_pair(to_string(sec+command.job_id()), mapping));

		command.set_sender_address(server_ip + ":" + server_port);
		command.set_sender_type("server"); 
		command.set_comm_type("Server:Job");
		command.set_unique_job_id(to_string(sec+command.job_id()));

		fprintf(stderr, "[Sending the request at]%s\n",command.sender_address().c_str());
		// send this to ther server!
		int sock_fd = socket(PF_INET, SOCK_STREAM, 0);
	    struct sockaddr_in servaddr = getSockAddr(command.sender_address());
	    if (connect(sock_fd, (struct sockaddr *) &servaddr, sizeof(servaddr)) != -1) {
			fprintf(stderr, "[Writing to the server]\n");
			writeCommand(sock_fd, command);
		}
		
		close(sock_fd);

	}

	else if(command.comm_type().compare("Server:Job") == 0) {

		struct job *nn = new job;
		nn->job_desc.CopyFrom(command);
		// Unthread the jobs as series of tasks
		readFromJobsJson("jobs.json", nn, command.job_id());
		
		if(job_map.find(command.unique_job_id()) != job_map.end()) {
			fprintf(stderr, "[Same datacenter was the job alocated for]\n");
		}
		else {
			struct r* mapping = new r;
			mapping->sender = command.sender_address();
			job_map.insert(make_pair(command.unique_job_id(), mapping));
		}

		// Update the mapping for unique_job_id -> number of tasks to the task_size(done in readFromJobs)!


		pthread_mutex_lock(&jobQueue);
		job_queue.push_back(nn);
		pthread_mutex_unlock(&jobQueue);
		// for(auto x : nn->tasks) {
		// 	for(auto y: x->command[0]) {
		// 		fprintf(stderr, "%s\n", y.c_str());
		// 	}
		// }

		if(flag_scheduler_run_job == false) {
			indicateSchedulerJobToRun();
		}


		// Execute the job like DAG and record the times at individual DC using logs
		// Return the request to the server who send it.

	}
	else if(command.comm_type().compare("Task-Reply") == 0) {
		// SM execution which is just executing the next thing in task queue.
		fprintf(stderr, "%s\n",command.comm_type().c_str());
		if(task_map.find(command.unique_task_id()) == task_map.end()) {
			struct r* mapping = new r;
			mapping->sender = command.sender_address();
			mapping->arrival_time = time(NULL);
			task_map.insert(make_pair(command.unique_task_id(), mapping));
		}
		else {
			fprintf(stderr, "Belgins to the same DC\n");
		}
		struct task *nn = new task;
		nn->compute = command.compute_task();
		nn->task_id = command.unique_task_id();
		string s = "";
		for(auto c : command.task_info()) {
			if(c == 'E') {
				break;
			}
			else if(c != ',') {
				s += c; 
			}

			else if(c == ',') {
				nn->command.push_back(s);
				fprintf(stderr, "[String]%s\n", s.c_str());
				s = "";
			}

		}
		
		pthread_mutex_lock(&taskQueue);
		task_queue.push_back(nn);
		pthread_mutex_unlock(&taskQueue);

		if(flag_scheduler_run_task == false) {
			indicateSchedulerTaskToRun();
		}
	}
	else if(command.comm_type().compare("Task-Response") == 0) {
		// After receiving the task response you need to send it to the corresponding client at the end.
		// So if the sender type is server, then keep on passing, otherwise, received_time - issue_time,
		// Sending the task to the server who is issuing the job is important first and then the iteration can happen for rtt, so rtt should be in job!

		// Get theb unique_job_id;
		unordered_map<string, struct r*>::iterator j;
		unordered_map<string, struct r*>::iterator t;
		string cor_job_id;
		if( (t = task_map.find(command.unique_task_id())) != task_map.end()) {
			cor_job_id = t->second->cor_job_id;
			if( (j = job_map.find(cor_job_id)) != job_map.end()) {
				j->second->number_of_tasks--;
				if(j->second->number_of_tasks == 0) {
					// send to the srevrs and client respectively iterastively!
					//Unfold all times from the tasks stored in jobs<vector tasks> and then return the corresponding total and print on the screen all the wait times!

				}
			}
			else {
				fprintf(stderr, "[Error in code, please check job_map, in task-response!]\n");
			}
		}
		else {
			fprintf(stderr, "[Error in code, please check task_map, in task-response!]\n");
		}


	}

}

void *processRequest(void *nn) {

	struct thread_info *node = (struct thread_info *) nn;
	size_t bytes_to_read;
    while (true) {
        
        if (read(node -> connection_fd, &bytes_to_read, sizeof(size_t)) < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }
       
        char buffer[bytes_to_read];
        doRead(node -> connection_fd, buffer, bytes_to_read);
        kv::command command;
		command.ParseFromArray(buffer, (int) bytes_to_read);
		time_t sec = time(NULL);
		fprintf(stderr, "[Request received][%ld]%s\n", sec, command.comm_type().c_str());
		
		processCommand(node, command);
    }
}


int main(int argc, char *argv[]) {

	GOOGLE_PROTOBUF_VERIFY_VERSION;

	int server_number = stoi(argv[1]) - 1;
	
	generate_server_info();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
	
	server_port = serverInfo[server_number] -> port;
	server_ip = serverInfo[server_number] -> ip;

	server_address = server_ip + ":" + to_string(server_port);

	fprintf(stderr, "Server is running at: %s:%d\n",serverInfo[server_number]->ip.c_str(), serverInfo[server_number]->port);

	// Accept the connections from the client

	int fd = socket(PF_INET, SOCK_STREAM, 0);

	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;

	servaddr.sin_port = htons(server_port);
	inet_pton(AF_INET, server_ip.c_str(), &(servaddr.sin_addr));
	bind(fd, (struct sockaddr*)&servaddr, sizeof(servaddr));

	listen(fd, NUMBER_OF_CONNECTIONS_ALLOWED);

	while(true) {

		struct sockaddr_in clientaddr;
		socklen_t clientaddrlen = sizeof(clientaddr);

		int connection_fd = accept(fd, (struct sockaddr*)&clientaddr, &clientaddrlen);

		if(connection_fd == -1) {
			fprintf(stderr, "[Threads are over!]: Server EXPLODS\n");
			continue;
		}

		static pthread_t threadID;

		struct thread_info *node = new thread_info;
		
		node->threadID = threadID;
		node->connection_fd = connection_fd;
		
		if(pthread_create(&threadID, NULL, &processRequest, node) != 0) {
			fprintf(stderr, "[Error] pthread_create could not create a new thread\n");
		}
	}


}

