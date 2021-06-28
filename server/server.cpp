#include "../include/server.hpp"
#include "../proto/simple_kv_msg.pb.h"
#include <arpa/inet.h>
#include <cstring>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

KvServer::KvServer(const char *ip, int port)
    : thread_pool_(5), ip_(ip), port_(port) {}

void KvServer::Run() {
  if (Start() < 0) {
    cout << "KvServer start failed" << endl;
    exit(-1);
  }
}

int KvServer::Start() {
  int listenfd = socket(AF_INET, SOCK_STREAM, 0);
  if (listenfd == -1) {
    cout << "sokcet() error" << endl;
    return -1;
  }

  int reuse = 1;
  setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(this->port_);
  addr.sin_addr.s_addr = inet_addr(this->ip_);

  // bind
  if (bind(listenfd, (struct sockaddr *)(&addr), sizeof(addr)) < 0) {
    cout << "bind() error" << endl;
    return -1;
  }

  if (listen(listenfd, 5) < -1) {
    cout << "listen() error" << endl;
    return -1;
  }

  int connfd;
  char client_ip[INET_ADDRSTRLEN];
  struct sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);
  while (true) {
    connfd =
        accept(listenfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (connfd < 0) {
      cout << "accetp() error" << endl;
    }
    // 获取ip地址
    inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);

    Context *ctx = new Context(client_ip, int(ntohs(client_addr.sin_port)));
    thread_pool_.Execute(bind(&KvServer::ServeClient, this, connfd, ctx));
  }
}

// 注意:不知道为什么，在线程使用printf时，
// 如果没有换行符，不会输出
void KvServer::ServeClient(int connfd, Context *ctx) {
  KvMsg::Request req;
  KvMsg::Response resp;

  cout << "client:" << ctx->ip_ << ":" << ctx->port_ << endl;

  char buf[512];
  int readn = read(connfd, buf, 512);
  req.ParseFromArray(buf, readn);

  // 使用ParseFromFileDescriptor解析，会卡住
  // bool ok = req.ParseFromFileDescriptor(connfd);
  switch (req.op_type()) {
  case req.GET:
    resp.set_code(0);
    resp.set_data(SafeGet(req.key()));
    break;
  case req.PUT:
    resp.set_code(0);
    SafePut(req.key(), req.val());
    break;
  default:
    resp.set_code(-1);
    break;
  }
  resp.SerializeToFileDescriptor(connfd);
  close(connfd);
  delete ctx;
  return;
}

void KvServer::SafePut(const string &key, const string &val) {
  map_lock_.lock();
  map_[key] = val;
  map_lock_.unlock();
}

const string &KvServer::SafeGet(const string &key) {
  map_lock_.lock();
  const string &val = map_[key];
  map_lock_.unlock();
  return val;
}

int main() {
  KvServer server("127.0.0.1", 8000);
  server.Run();
  return 0;
}