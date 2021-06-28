#ifndef SIMPLEKV_SERVER
#define SIMPLEKV_SERVER
#include "thread_pool.hpp"
#include <mutex>
#include <string>
#include <unordered_map>

class KvServer {
  class Context {
  public:
    std::string ip_;
    int port_;

  public:
    Context(std::string &&ip, int port) : ip_(ip), port_(port){};
    Context(char *ip, int port) : ip_(ip), port_(port){};
    ~Context() { cout << "context deconstruct" << endl; }
  };

public:
  KvServer(const char *ip, int port);
  void Run();
  void ServeClient(int connfd, Context *ctx);

private:
  int Start();
  void SafePut(const string &key, const string &val);
  const string &SafeGet(const string &key);

private:
  ThreadPool thread_pool_;
  unordered_map<string, string> map_;
  mutex map_lock_;
  const char *ip_;
  int port_;
};

#endif