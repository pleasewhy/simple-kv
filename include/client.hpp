#ifndef SIMPLEKV_CLIENT_HPP
#define SIMPLEKV_CLIENT_HPP
#include <string>

using std::string;
class KvClient {
public:
  KvClient(string ip, int port);
  KvClient(const char *ip, int port);
  string Get(const string& key);
  bool Put(const string &key, const string &val);

private:
  int Connect();

private:
  string ip_;
  int port_;
};
#endif