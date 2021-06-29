#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>


int server(){
  int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(8000);
  addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // 本机地址
  bind(sock_fd, (struct sockaddr *)(&addr), sizeof(addr));

  char client_ip[INET_ADDRSTRLEN];
  struct sockaddr_in client_addr; // 用于获取client IP地址
  socklen_t client_addr_len = sizeof(client_addr);
  int connfd = accept(sock_fd, (struct sockaddr *)&client_addr, &client_addr_len);
  // 接下来就可以通过connfd与客户端进行通信

  // 将client IP地址转换为字符串类型的，e.g. 192.168.7.2
  inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
}

void client(){
  // 创建一个套接字
  int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  // 设置地址
  struct sockaddr_in serverAddr;
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(8000);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  // connect
  connect(sock_fd, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
  // 接下来就可以通过sock_fd与服务器端进行通信
}