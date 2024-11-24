## 封面

![image-20241124230300308](D:\BOOK\Hands-On Network Programming with C\assets\image-20241124230300308.png)



## 第一章： Introducing Networks and Protocols

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

> 最简单的方法是访问一个能为你报告IP地址的网站。例如http://api.ipify.org/、http://ifconfig.me/ip等。

### Q7: 操作系统是如何知道哪个应用程序负责处理传入的数据包的？

> 每个IP数据包都有一个本地地址、远程地址、本地端口号、远程端口号和协议类型。操作系统通过记忆这五个属性来确定哪个应用程序应该处理任何给定的传入数据包。

