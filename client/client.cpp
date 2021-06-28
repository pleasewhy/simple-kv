#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include "../include/client.hpp"
#include "../proto/simple_kv_msg.pb.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;
KvClient::KvClient(string ip, int port) : ip_(ip), port_(port) {}
KvClient::KvClient(const char *ip, int port) : ip_(ip), port_(port) {}

string KvClient::Get(const string &key) {
  int fd = Connect();
  KvMsg::Request req;
  KvMsg::Response resp;
  req.set_key(key);
  req.set_op_type(req.GET);
  req.SerializeToFileDescriptor(fd);
  char buf[1024];
  int n = read(fd, buf, sizeof(buf));
  resp.ParseFromArray(buf, n);
  return std::move(resp.data());
}

bool KvClient::Put(const string &key, const string &val) {
  int sock_fd = Connect();
  KvMsg::Request req;
  KvMsg::Response resp;
  req.set_key(key);
  req.set_val(val);
  req.set_op_type(req.PUT);
  req.SerializeToFileDescriptor(sock_fd);
  char buf[1024];
  int n = read(sock_fd, buf, sizeof(buf));
  resp.ParseFromArray(buf, n);
  if (resp.code() < 0) {
    return false;
  }
  return true;
}

int KvClient::Connect() {
  // socket
  int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_fd == -1) {
    std::cout << "Error: socket" << std::endl;
    return 0;
  }
  // connect
  struct sockaddr_in serverAddr;
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(port_);
  serverAddr.sin_addr.s_addr = inet_addr(ip_.c_str());
  if (connect(sock_fd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) <
      0) {
    std::cout << "Error: connect" << std::endl;
    return 0;
  }
  return sock_fd;
}

int main() {
  KvClient client("127.0.0.1", 8000);
  string op;
  while (true) {
    // cmdline使用空格隔开
    // put aaa bbb
    // get aaa
    cout << "simple kv: ";
    cin >> op;
    if (op.compare("put") == 0) {
      string key;
      string val;
      cin >> key;
      cin >> val;
      bool ok = client.Put(key, val);
      if (ok) {
        cout << "put success" << endl;
      } else {
        cout << "put failed" << endl;
      }
    } else if (op.compare("get") == 0) {
      string key;
      cin >> key;
      string val = client.Get(key);
      cout << "val=" << val << endl;
    } else {
      cout << "only support put/get operation" << endl;
    }
  }
  return 0;
}
