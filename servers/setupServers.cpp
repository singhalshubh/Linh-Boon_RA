#include <json/json.h>
#include <fstream>
#include <iostream>

using namespace std;

struct servers {

	int serverId;
	int port;
	string address = "";
	int computeSlots;
	int inputVol;
};


vector<struct servers *> serverInfo;

void printMessage(bool flag, const char *message) {

	fprintf(stderr, "%s\n", message);
	if(flag) {
		exit(EXIT_SUCCESS);
	}
	else {
		exit(EXIT_FAILURE);
	}

}

void readFromServerJson(string server_config_fileName) {

	// Check if the fileName is json type or not.
	ifstream server_config(server_config_fileName, ifstream::binary);
	Json::Value server;
	server_config >> server;

	string tracker = "1";

	while( stoi(tracker) <= server.size() ) {

		struct servers *ss = new servers();
		ss->serverId = stoi(tracker);
		ss->computeSlots = server[tracker]["compute"].asInt();
		ss->inputVol = server[tracker]["input"].asInt();
		ss->port = server[tracker]["port"].asInt();
		ss -> address = server[tracker]["address"].asString();

		serverInfo.push_back(ss);

		tracker = to_string(stoi(tracker)+1);
	}

}

void generate_server_info(string fileName = "server_config.json") {

	if(fileName.find(".json")) {
		readFromServerJson(fileName);
	}
	else {
		printMessage(false, "server json file not found\n");
	}

}