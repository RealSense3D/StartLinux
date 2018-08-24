主机字节序与网络字节序有差异。

字节序转换函数：
``` c
#include <netinet/in.h>

/* host to network, long */
unsigned long int htonl(unsigned long int hostlong);
/* host to network, short */
unsigned short int htons(unsigned short int hostshort);
/* network to host, long */
unsigned long int ntohl(unsigned long int netlong);
/* network to host, short */
unsigned short int ntohs(unsigned short int netshort);

```