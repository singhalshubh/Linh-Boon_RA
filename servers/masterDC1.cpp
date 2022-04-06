/* Master Data center acts as the following: 

1. In case of decentralised platform, it acts like any other data center (given by the flag data center = true) but in case of centralised, it acts as the master which will be denoted by the following address only "127.0.0.1:8000/8001/8002" as the set of replicas working together(replica number = 2).

2. Like other DCs, it knows the network toplogy adjacent to the data center assuming the topology denoted by mesh, ring, or shape given by the optional request flag denoting the adj matrix/adj list of the other DC's omn user's choice on paper, given by the flag = NetworkTypeTopology; 
var NetworkTopology: mesh, ring, adj_matrix, adj_list where the partition of which DC gets what is done at the bash script level. 

3. DC's individual struct computeThatCanBeExecutedUser, totalVolumeThatCanBeStored User by mentioning it in either way by providing "-all<struct>", or "--pair <struct>", where we read the data from the user file provided: DC_info.protobufp, json, apache-thrift,xml-rpc, php, which will be provided by the client support given in clients/ directory. 

4.	  From server_config.json<server-id = 1(for master in case of centralised)>: 
		queueLength; //Scheduler Characteristics
		policyOfScheduler given by functionName=policyFileName (in case of centralised, have a separate flag which contains our communication protocol.)
		Centralised(should be same for all servers (pjm only) -> Record and send the tasks using estimation module!!) otherwise,
		Decentralised-type(scheduler is "same" for (1,2) or "functionName=policyFileName" for 2.  
			1. client request job subtask received, 
			2. allocated by other pjms of other DC's)
		

	

*/

string server_address;
string server_ip;
string server_port;

string policyOfScheduler;

