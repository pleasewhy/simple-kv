## 简介

该项目是一个简单的`kvserver` ，支持最简单的`Get`，`Put`操作，主要使用的技术`protobuf`，`线程池`，`socket`，也包含一个用于测试的`client`

## 运行

输入`make server`启动`server`，新建一个终端输入`make client`启动一个client，你可以输入`put key val`，来设置一个键值对，输入`get key`来获取`key`对应的`val`。

