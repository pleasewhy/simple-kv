## Simple KV Guild

前面已经详细讲解了`线程池`和`protobuf`

该项目Github地址：https://github.com/pleasewhy/simple-kv

线程池教程：https://github.com/pleasewhy/thread-pool

protobuf教程：https://github.com/pleasewhy/protobuf-demo

这两个仓库中都包含详细的文档。

本文将会介绍C++的socket编程，以及如何利用线程池和`prototbuf`搭建一个KVServer。

### 1、C++ Socket编程

​	阅读本小节，读者需要知道`IP地址`、端口的定义，了解TCP/IP协议，上过计算机网络课程就OK了。

​	C++网络编程主要是利用`内核`的提供的接口，来进行网络通信。主要涉及的接口有`socket`，`bind`，`accept`，`listen`，`connect`，这些函数会返回负数代表失败，推荐使用`man`命令查看这些接口的描述，本文将不会介绍`epoll`，`select`，`poll`这些接口。

通常server像下面代码一样进行监听某个地址，等待客户端连接。

```c++
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>

int server(){
  // 建立一个流式套接字
  int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  
  struct sockaddr_in addr;
  addr.sin_family = AF_INET; // AF_INET代表IPV4
  addr.sin_port = htons(8000); // 8000端口
  addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // 本机地址
  bind(sock_fd, (struct sockaddr *)(&addr), sizeof(addr));

  char client_ip[INET_ADDRSTRLEN]; // 储存client IP字符串
  struct sockaddr_in client_addr; // 用于获取client IP地址(二进制)
  listen(sock_fd, 5); // 将连接队列的最大长度设置为5
  socklen_t client_addr_len = sizeof(client_addr);
  int connfd = accept(sock_fd, (struct sockaddr *)&client_addr, &client_addr_len);

  // 将client IP地址转换为字符串类型的，e.g. 192.168.7.2
  inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN); 
   //  do something
   close(connfd);
   close(sock_fd);
}
```

​	**socket(int domain, int type, int protocol)**函数会创建一个用于通信的的`endpoint`，并会返回一个关联到该`endpoint`的文件描述符，如果调用成功会返回一个当前进程为使用的最小文件描述符，可以使用`recv`/`send`和`read`/`write`读写`socket`。`domain`参数指定了endpoint的通信的域，`socket`会根据该参数选择通信协议族。`domain`的作用就是如何去解析地址，一些比较常用的`domain`及其含义如下表:

| 名称     | 含义     |
| -------- | -------- |
| AF_UNIX  | 本地通信 |
| AF_INET  | IPv4协议 |
| AF_INET6 | IPv6协议 |

`	socket`的第二个参数为`type`，它指定本次通信的`语义`，常用的`type`如下：

| 名称           | 含义                                                         |
| -------------- | ------------------------------------------------------------ |
| SOCK_STREAM    | 提供有序的，可靠的，双向的，基于连接的字节流，也就是TCP      |
| SOCK_DGRAM     | 支持数据报(无连接，不可靠)，也就是UDP                        |
| SOCK_SEQPACKET | 提供一个有顺序的、可靠的、基于双向连接的数据传输路径，用于传输最大长度固定的数据。消费者需要在每次读取系统调用时读取整个数据包。类似于 TCP，只不过传输单元不是数据流，而是数据报。 |

并不是所有的协议族都实现了这些协议类型。

`socket`的第三个参数为`protocol`，它用于指定socket使用的协议。通常来说一个协议族只包含一个协议类型，这种情况可以将其`protocol`设置为0。但对于一些包含了多种协议的协议族，需要指定一个`protocol`。

​	当通过`socket()`函数创建一个`socket`时，它并没有一个关联的地址，`bind`函数可以为`socket`绑定一个地址。

**bind(int sock_fd, const struct sockaddr *addr, socklen_t addrlen)**的第一个参数为`socket`对应的文件描述符，第二个参数为一个地址结构体，，第三个参数为地址结构体的大小。通常不直接使用`sockaddr`结构体，而是使用`sockaddr_in`结构体，它可以被强制转换为`sockaddr`结构体。

**listen(int sock_fd, int backlog)**函数将一个`socket`标记为被动的，也就是它只能被其他的通信`endpoint`连接，每有一个`endpoint`连接到该`socket`，他都会将其添加到一个连接队列中，`backlog`用于指定队列的最大长度，当达到最大长度时，之后到达的连接请求都会被抛弃。

**int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)**函数从`socket`的连接队列中取出一个连接，若当前队列没有连接，则它会一直等待，直到有新的连接到达。获取到连接后，会返回一个与该连接关联的文件描述符。`addr`参数用于存放本次连接的地址，`addrlen`用于存放地址的长度，可以使用**inet_top**函数将`addr`转换为字符串形式。

客户端通常像下面这样连接服务器端

```c++
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
  // ....
  close(sock_fd);
}
```

**connect(int sockfd, const struct *addr, socklen_t addrlen)**将`sockfd`对应的`socket`连接到`addr`对应的server端。连接之后就通过sock_fd来和server端进行通信。

### 2、Server端实现

​	server端的基本思路很简单，首先创建一个`socket`用于监听某个IP地址，然后再循环`accept`，获取来自客户端的连接，并将**该连接**交由线程池处理。循环部分代码如下：

```c++
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
```

​	上述代码涉及到一个`Context`类，它主要用于在`master`线程向`worker`线程传递数据。目前它只包含`ip`和`port`两个字段。`ServeClient`函数用于处理一个客户端连接，它获取客户端发送过来的请求，根据请求类型，做相应的处理：

+ Put：向`map_`中存入一个键值对，`SafeGet`为线程安全的`get`操作。
+ Get：在`map_`中获取`key`对应的`value`,`SafePut`为线程安全的`put`操作。

，处理之后返回给客户端，然后就关闭该连接，结束本次服务。

```C++
void KvServer::ServeClient(int connfd, Context *ctx) {
  KvMsg::Request req;
  KvMsg::Response resp;

  cout << "client:" << ctx->ip_ << ":" << ctx->port_ << endl;

  char buf[512];
  int readn = read(connfd, buf, 512);
  req.ParseFromArray(buf, readn);
  // 使用ParseFromFileDescriptor解析，会卡住，目前不知道原因
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
```

Server和Client使用`protobuf`协议通信，`SimpleKv`的`Request`和`Response`定义如下：

```protobuf
message Request {
  string key = 1;
  enum OpType {
    GET = 0;
    PUT = 1;
  }
  string val = 2;
  OpType op_type = 3;
}

message Response {
  int32 code = 1;     // 0为成功，小于0失败
  string data = 2;
}
```

目前支持最简单的Get/Put操作。

目前的`Server`的优化空间很大，一些优化点:

+ 采用epoll，提升高负载下的性能，这可能需要改变`ServeClient`的逻辑。
+ 完成一次请求后，不关闭连接，等待客户端关闭或超时关闭。
+ 采用高性能的多线程map实现。
+ 增加更多的操作，使其具有一定的实用性。
+ 使用`redis`和`memcache`的一些优化方式

### 3、Client端实现

​	客户端的实现比较简单，只包含两个接口`Put`、`Get`。每次调用该函数时，都会新建一个连接，来完成本次操作。

Client通常像下面这样使用：

```c++
KvClient client("127.0.0.1", 8000);
client.Put("aa","BB");
client.Get("aa");
```

`Get`的实现如下：

```c++
string KvClient::Get(const string &key) {
  int connfd = this->Connect();
  KvMsg::Request req;
  KvMsg::Response resp;
  req.set_key(key);
  req.set_op_type(req.GET);
  req.SerializeToFileDescriptor(connfd);
  char buf[1024];

  // 等待server回复
  int n = read(fd, buf, sizeof(buf));
  resp.ParseFromArray(buf, n);
  close(connfd);
  return std::move(resp.data());
}
```

​	`Get`首先会调用`Connect`获取一个连接，然后设置`req`，并将其序列化到`connfd`中，然后就等待获取server的返回数据，并将其解析到`resp`中。最后返回`resp.data()`就可以了。`Put`和`Get`的流程类似，这里就不介绍了。

​	Client可以采用连接池的方式来缓存一些连接，这样可以提高Get和Put的响应速度。

### 4、问题记录

​	在子线程中使用`printf`输出时，如果不包含`\n`，可能不会输出到控制台，原因可能是没有`flush`到控制台中去。

```c++
printf("sometime\n"); // 控制台打印something
printf("sometime"); // 控制台不打印something
```

​	启动时`bind`失败，可能原因是当退出程序时，上次运行的`socket`可能正在处于`TIME_WAIT`状态，可以像下面这样，使`socket`可以重用`TIME_WAIT`状态的`socket`。

```c++
int reuse = 1;
setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
```

