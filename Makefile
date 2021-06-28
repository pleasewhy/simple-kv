.PHONY: server client
T 	:= target
SRV := server
CLIENT := client
LINK_LIB = `pkg-config --cflags --libs protobuf`
LINK_LIB += -pthread

proto_cpp_file := proto/simple_kv_msg.pb.cc
server_file := $(SRV)/server.cpp
client_file := $(CLIENT)/client.cpp

%.pb.cc: %.proto
	protoc --cpp_out=. $^

$T/server: $(server_file) $(proto_cpp_file)
	g++ -std=c++11 $(server_file) $(proto_cpp_file) -I. -Iinclude -Iproto -o $T/server $(LINK_LIB)


server: $T/server
	./target/server

$T/client: $(client_file)
	g++ -std=c++11 $(client_file) $(proto_cpp_file) -I. -Iinclude -Iproto -o $T/client $(LINK_LIB)


client: $T/client
	./target/client
