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

using namespace std;

void printMessage(bool f, string s) {

	if(f) {
		fprintf(stderr, "%s\n", s.c_str());
		exit(EXIT_SUCCESS);
	}
	else {
		fprintf(stderr, "%s\n", s.c_str());
		exit(EXIT_FAILURE);		
	}

}

void writeCommand(int sock_fd, kv::command &command){
    size_t comm_len = command.ByteSizeLong();
    write(sock_fd, &comm_len, sizeof(comm_len));
    char serialization[command.ByteSizeLong()];
    command.SerializeToArray(serialization, (int) command.ByteSizeLong());
    write(sock_fd, serialization, command.ByteSizeLong());

}

kv::command readResponse(int sock_fd){
    size_t bytesToRead;
    read(sock_fd, &bytesToRead, sizeof(bytesToRead));
    char buffer[bytesToRead];
    read(sock_fd, buffer, bytesToRead);
    kv::command response;
    response.ParseFromArray(buffer, (int) bytesToRead);
    return response;
}

// void printResponse(kv::command &response){
//     if(response.has_val()){
//         std::cout << "Value: " + response.val() << std::endl;
//     }
//     std::cout << "Status: " + response.status() << std::endl;
// }

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


int main(int argc, char *argv[]) {

	GOOGLE_PROTOBUF_VERIFY_VERSION;

	std::string ip_port = argv[optind];

	int sock_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in servaddr = getSockAddr(ip_port);
    if (connect(sock_fd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    kv::command job;
    job.set_comm_type("Client:Job");
    job.set_job_id(1);
    job.set_data_center(2);
    writeCommand(sock_fd, job);
    //response = readResponse(sock_fd);
    //printResponse(response);
    job.Clear();
	
	

    return 0;
}