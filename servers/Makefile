all: masterDC testclient

%.o: %.cc
	g++ $^ -g -c -o $@

testclient: testclient.o ./common/kvcomm.pb.o
	g++ $^ -lpthread -lprotobuf -g -o $@

masterDC: masterDC.o ./common/kvcomm.pb.o
	g++ $^ -ljsoncpp -lpthread -lprotobuf -g -o $@
