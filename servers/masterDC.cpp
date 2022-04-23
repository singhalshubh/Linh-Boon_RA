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

int server_port;
string server_ip;
string server_address;

struct thread_info {
	pthread_t threadID;
	int connection_fd;
	string type = "";
};


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

void writeCommand(int sock_fd, kv::command &command){
    size_t comm_len = command.ByteSizeLong();
    write(sock_fd, &comm_len, sizeof(comm_len));
    char serialization[command.ByteSizeLong()];
    command.SerializeToArray(serialization, (int) command.ByteSizeLong());
    write(sock_fd, serialization, command.ByteSizeLong());

}

// Requires server-number, file name as argument

void processCommand(struct thread_info* node, kv::command &command) {

	if(command.comm_type().compare("Client:Job") == 0) {

		// see the DC that the job has to be allocated and then allocate it and move on.
		// Server is sending the request to the correct server and executing the request.

		// which data center does the job belong to?
		// extract the server number anbd port which the data center is corresponding to?
		int datacenterIndex = command.data_center()-1;
		string server_port = to_string(serverInfo[datacenterIndex] -> port);
		string server_ip = serverInfo[datacenterIndex] -> address;

		command.set_sender_address(server_ip + ":" + server_port);
		command.set_sender_type("server"); 
		command.set_comm_type("Server:Job");
		// send this to ther server!
		int sock_fd = socket(PF_INET, SOCK_STREAM, 0);
	    struct sockaddr_in servaddr = getSockAddr(command.sender_address());
	    if (connect(sock_fd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
			fprintf(stderr, "[Writing to the server]\n");
			writeCommand(sock_fd, command);
		}
		else {
			return;
		}
		
		close(sock_fd);

	}

	else if(command.comm_type().compare("Server:Job") == 0) {

		// Execute the job like DAG and record the times at individual DC using logs
		// Return the request to the server who send it.
		

	}
	else {
		// SM execution which is just executing the next thing in task queue.
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
		
		fprintf(stderr, "[Request received]%s\n", command.comm_type().c_str());
		
		processCommand(node, command);
    }
}


int main(int argc, char *argv[]) {

	GOOGLE_PROTOBUF_VERIFY_VERSION;

	int server_number = stoi(argv[1]) - 1;
	
	generate_server_info();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
	
	server_port = serverInfo[server_number] -> port;
	server_ip = serverInfo[server_number] -> address;

	fprintf(stderr, "Server is running at: %s:%d\n",serverInfo[server_number]->address.c_str(), serverInfo[server_number]->port);

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

