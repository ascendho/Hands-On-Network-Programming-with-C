## 封面

<div align="center">
	<img src="assets\image-20241124230300308.png">
</div>





## 第一章：Introducing Networks and Protocols

### Q1: IPv4 和 IPv6 之间的主要区别是什么？

> IPv4 仅支持40亿个独特的地址，并且由于它们分配得不够高效，我们现在正在耗尽这些地址。IPv6 支持 $3.4 * 10^{38}$ 个可能的地址。IPv6 提供了许多其他改进（比如增加了scope和lifetime等属性），但这是我们网络编程直接受到影响的一个。

### Q2: 通过 ipconfig 和 ifconfig 命令获得的 IP 地址，是你连接到远程服务器时服务器看到的同一个 IP 地址吗？

> 有时候，这些地址会匹配，但并不总是如此。如果你处于一个私有的 IPv4 网络中，那么你的路由器很可能执行了网络地址转换（NAT）。在这种情况下，远程服务器看到的是转换后的地址。如果你拥有一个公开可路由的 IPv4 或 IPv6 地址，那么远程服务器看到的地址将与你通过 ipconfig 和 ifconfig 命令报告的地址相匹配。

### Q3: IPv4环回地址是什么？

> IPv4的环回地址是127.0.0.1，它允许在同台机器上执行的网络程序相互通信。

### Q4: IPv6环回地址是什么？

> IPv6的环回地址是::1。它的工作原理与IPv4的环回地址相同。

### Q5: 域名（例如，example.com）是如何解析成IP地址的？

> DNS用于将域名解析成IP地址。这个协议在第5章“主机名解析和DNS”中有详细说明。

### Q6: 你如何找到你的公网IP地址？

> 最简单的方法是访问一个能为你报告IP地址的网站。例如：
>
> 1. http://api.ipify.org/ 
>
> 2. http://ifconfig.me/ip等

### Q7: 操作系统是如何知道哪个应用程序负责处理传入的数据包的？

> 每个IP数据包都有一个本地地址、远程地址、本地端口号、远程端口号和协议类型。操作系统通过记忆这五个属性来确定哪个应用程序应该处理任何给定的传入数据包。



## 第二章：Getting to Grips with Socket APIs

### Q1: 什么是socket？

> 套接字是一个抽象概念，它代表了系统之间通信链路的一个端点。

### Q2: 什么是无连接协议？什么是面向连接的协议？

> 面向连接的协议在更大的数据流的上下文中发送数据包。无连接协议独立地发送每个数据包，与之前的或之后的任何数据包无关。

### Q3: UDP是一个无连接还是面向连接的协议？

> UDP被认为是一个无连接协议。每个消息都是独立于它之前或之后的消息发送的。

### Q4: TCP是无连接还是面向连接的协议？

> TCP被认为是一个面向连接的协议。数据是按照顺序作为流发送和接收的。

### Q5: 哪些类型的应用程序通常从使用UDP协议中受益？

> UDP应用程序在牺牲可靠性的同时，能够获得更好的实时性能。它们还能够利用IP多播的优势。

### Q6: 通常哪些类型的应用程序会从使用TCP协议中受益？

> 需要可靠数据流传输的应用程序会从TCP协议中受益。

### Q7: TCP是否保证数据会成功传输？

> TCP提供了一些关于可靠性的保证，但没有什么是能够真正保证数据成功传输的。例如，如果有人拔掉了你的调制解调器，没有任何协议能够克服这种情况。

### Q8: 伯克利套接字和WinSock套接字之间的一些主要区别是什么？

> 头文件是不同的。套接字本身被表示为有符号整数与无符号整数。当socket()或accept()调用失败时，返回值是不同的。伯克利套接字也是标准文件描述符。这并不总是适用于WinSock。错误代码是不同的，并且以不同的方式检索。还有其他的区别，但这些是我们程序受影响的主要区别。

### Q9: bind()函数是做什么的？

> bind()函数将一个套接字与特定的本地网络地址和端口号关联起来。它几乎总是需要在服务器上使用，而客户端通常不需要。

### Q10: accept()函数是做什么的？

> accept()函数会阻塞，直到新的TCP客户端连接。然后它返回这个新连接的套接字。

### Q11: 在TCP连接中，是客户端还是服务器先发送应用程序数据？

> 客户端或服务器都可以先发送数据。它们甚至可以同时发送数据。在实践中，许多客户端-服务器协议（如HTTP）的工作方式是客户端先发送请求，然后服务器发送响应。
