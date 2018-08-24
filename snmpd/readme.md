# 基于snmp的主代理与子代理手顺

本手顺参考诸位前辈与同仁摸索出来，希望对来者有所裨益，少走一些弯路与辛苦。

时间仓促，现将初版呈上，待明后将步骤精简优化。

## 安装net-snmp

### 当前环境

#### 当前路径

> pwd
>
> /home/intel

#### 系统信息

> uname -a
>
> Linux ubuntu 3.19.0-25-generic #26~14.04.1-Ubuntu SMP Fri Jul 24 21:16:20 UTC 2015 x86_64 x86_64 x86_64 GNU/Linux

### 源码压缩包

#### 获取net-snmp源码

> $ wget http://nchc.dl.sourceforge.net/project/net-snmp/net-snmp/5.7.3/net-snmp-5.7.3.tar.gz
>
> --2018-06-07 18:23:38--  http://nchc.dl.sourceforge.net/project/net-snmp/net-snmp/5.7.3/net-snmp-5.7.3.tar.gz
> Resolving nchc.dl.sourceforge.net (nchc.dl.sourceforge.net)... 211.79.60.17, 2001:e10:ffff:1f02::17
> Connecting to nchc.dl.sourceforge.net (nchc.dl.sourceforge.net)|211.79.60.17|:80... connected.
> HTTP request sent, awaiting response... 200 OK
> Length: 6382428 (6.1M) [application/x-gzip]
> Saving to: ‘net-snmp-5.7.3.tar.gz’
> 100%[======================================>] 6,382,428    191KB/s   in 32s 
> 2018-06-07 18:24:11 (193 KB/s) - ‘net-snmp-5.7.3.tar.gz’ saved [6382428/6382428]

#### 解压缩

> cd ~
>
> tar zxvf net-snmp-5.7.3.tar.gz

#### 进入解压目录

> cd net-snmp-5.7.3/

### 安装snmp

#### 安装依赖包

> sudo apt-get install libperl-dev

#### 配置

> ./configure --with-default-snmp-version="3" --prefix="/usr/local/net-snmp" --with-sys-contact="@@no.where" --with-sys-location="Unknown" --with-logfile="/var/log/snmpd.log"   --with-persistent-directory="/var/net-snmp"

> 参数介绍：
>
> * prefix:安装路径
> * with-default-snmp-version(3): 3（在这里版本通常有三种形式：1,2c,3）
> * with-sys-contact（配置该设备的联系信息）: heaven（也可以是邮箱地址）
> * with-sys-location(该系统设备的地理位置):BEIJING P.R China
> * Location to write logfile (日志文件位置): /var/log/snmpd.log
> * Location to Write persistent(数据存储目录): /var/net-snmp
> * (此处，除了安装路径不是默认的，其余参数皆为默认设置。）

#### 编译与安装

> sudo make
>
> sudo make install

#### 添加环境变量

> cd ~
>
> echo export PATH="$PATH:/usr/local/net-snmp/bin:/usr/local/net-snmp/sbin" >> .bashrc
>
> echo export LD_LIBRARY_PATH=/usr/local/net-snmp/lib >> .bashrc
>
> source .bashrc

### 验证

> snmpget --version
>
> NET-SNMP version: 5.7.3

## 安装snmpd

### 安装

> sudo apt-get install snmpd snmp snmp-mibs-downloader

### 修改snmpd.conf

> cd /etc/snmpd.conf
>
> sudo gedit snmpd.conf


 (input below code)

``` shell
master agentx 
rocommunity public 
rwcommunity public
```

### 检查状态

> service snmpd status
>
>  * snmpd is running

### 测试

> intel@ubuntu:~$ snmpget -v2c -c public localhost sysUpTime.0
> 
> DISMAN-EVENT-MIB::sysUpTimeInstance = Timeticks: (169782) 0:28:17.82

## 自己扩展的MIB

### 创建MIB

现在自己手写一个简单的MIB

> cd ~
>
> gedit Test-MIB.my

```asn.1
  -- Test-MIB.my
  Test-MIB DEFINITIONS ::= BEGIN

            IMPORTS
            OBJECT-GROUP, MODULE-COMPLIANCE, NOTIFICATION-GROUP    
                FROM SNMPv2-CONF    
            enterprises, Integer32, Unsigned32, OBJECT-TYPE, MODULE-IDENTITY, 
            NOTIFICATION-TYPE    
                FROM SNMPv2-SMI    
            DisplayString    
                FROM SNMPv2-TC;

-- October 09, 2002 at 14:50 GMT
        -- 1.3.6.1.4.1.16535
        Test MODULE-IDENTITY 
            LAST-UPDATED "200210091450Z"        -- October 09, 2002 at 14:50 GMT
            ORGANIZATION 
                ""  
            CONTACT-INFO 
                ""  
            DESCRIPTION 
                "Video's Server MIB."
            ::= { enterprises 16535 }
    
--  Node definitions
-- This part will include all details about the Test.
        -- 1.3.6.1.4.1.16535.1
        Time OBJECT IDENTIFIER ::= { Test 1 } 


        -- 1.3.6.1.4.1.16535.1.1
        GetTime OBJECT-TYPE
            SYNTAX DisplayString (SIZE (0..100))
            MAX-ACCESS read-only
            STATUS current
            DESCRIPTION
                "Example : 2013/4/11"
            ::= { Time 1 }
    END

-- Test-MIB.my
```

### 移动MIB

>  sudo cp Test-MIB.my /usr/local/net-snmp/share/snmp/mibs

### 重启snmpd

> sudo service snmpd restart
### 测试snmptool

注意，需要重开终端

> snmptranslate -Tp -IR Test-MIB::Test
> +--Test(16535)
>    |
>    +--Time(1)
>       |
>       +-- -R-- String    GetTime(1)
>                Textual Convention: DisplayString
>                Size: 0..100
### 生成代码

#### 创建文件夹

> cd ~
> mkdir Test-MIB
#### 生成代码框架

``` shell
env MIB=+Test-MIB mib2c Test
writing to -
mib2c has multiple configuration files depending on the type of
code you need to write.  You must pick one depending on your need.

You requested mib2c to be run on the following part of the MIB tree:
  OID:                            Test
  numeric translation:            .1.3.6.1.4.1.16535
  number of scalars within:         1
  number of tables within:          0
  number of notifications within:   0

First, do you want to generate code that is compatible with the
ucd-snmp 4.X line of code, or code for the newer Net-SNMP 5.X code
base (which provides a much greater choice of APIs to pick from):

  1) ucd-snmp style code
  2) Net-SNMP style code

Select your choice : 2

**********************************************************************
       GENERATING CODE FOR SCALAR OBJECTS:
**********************************************************************

  It looks like you have some scalars in the mib you requested, so I
  will now generate code for them if you wish.  You have two choices
  for scalar API styles currently.  Pick between them, or choose not
  to generate any code for the scalars:

  1) If you're writing code for some generic scalars
     (by hand use: "mib2c -c mib2c.scalar.conf Test")

  2) If you want to magically "tie" integer variables to integer
     scalars
     (by hand use: "mib2c -c mib2c.int_watch.conf Test")

  3) Don't generate any code for the scalars

Select your choice: 1
    using the mib2c.scalar.conf configuration file to generate your code.
writing to Test.h
writing to Test.c



**********************************************************************
* NOTE WELL: The code generated by mib2c is only a template.  *YOU*  *
* must fill in the code before it'll work most of the time.  In many *
* cases, spots that MUST be edited within the files are marked with  *
* /* XXX */ or /* TODO */ comments.                                  *
**********************************************************************
running indent on Test.c
running indent on Test.h

```

### 修改代码

> ls 
>
> Test.c  Test.h

> gedit Test.c

``` c

/*

 \* Note: this file originally auto-generated by mib2c using

 \*        $

 */

\#include <net-snmp/net-snmp-config.h>

\#include <net-snmp/net-snmp-includes.h>

\#include <net-snmp/agent/net-snmp-agent-includes.h>

\#include "Test.h"

\#include "time.h" /* 添加所需的头文件 */

/** Initializes the Test module */

void

init_Test(void)

{

    const oid GetTime_oid[] = { 1,3,6,1,4,1,16535,1,1 };

  DEBUGMSGTL(("Test", "Initializing\n"));

    netsnmp_register_scalar(

        netsnmp_create_handler_registration("GetTime", handle_GetTime,

                               GetTime_oid, OID_LENGTH(GetTime_oid),

                               HANDLER_CAN_RONLY

        ));

}

int

handle_GetTime(netsnmp_mib_handler *handler,

                          netsnmp_handler_registration *reginfo,

                          netsnmp_agent_request_info   *reqinfo,

                          netsnmp_request_info         *requests)

{

    /* We are never called for a GETNEXT if it's registered as a

       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so

       we don't need to loop over a list of requests; we'll only get one. */

    time_t t;/* 定义时间变量 */

    switch(reqinfo->mode) {

        case MODE_GET:

            time(&t);  // 获取时间

            char szTime[100];  // 定义buf

            snprintf(szTime,100,"%s",ctime(&t)); // 保存时间

            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,

                                     szTime/* XXX: a pointer to the scalar's data */,// 将指针传入

                                     strlen(szTime)/* XXX: the length of the data in bytes */);// 传入数据长度

            break;

        default:

            /* we should never get here, so this is a really bad error */

            snmp_log(LOG_ERR, "unknown mode (%d) in handle_GetTime\n", reqinfo->mode );

            return SNMP_ERR_GENERR;

    }

    return SNMP_ERR_NOERROR;

}

```

### 编译与生成

> net-snmp-config --compile-subagent --norm Test Test.c
>
> ~/Test-Mib$ ls
>
> netsnmptmp.47538.c  Test  Test.c  Test.c~  Test.h

>参数解释
>
> * net-snmp-config： 让Test程序变成了守护进程在后台运行
> * --norm ：禁止删除程序自动生成的mian()文件

### 测试

#### 运行主代理

> service snmpd restart

####  运行子代理
>
> cd ~/Test-MIB
>
> sudo ./Test
>
> ps -ef | grep Test

#### 请求OID

> snmpget -v2c -c public localhost 1.3.6.1.4.1.16535.1.1.0
> 
> SNMPv2-SMI::enterprises.16535.1.1.0 = STRING: "Thu Jun  7 17:02:54 2018"

#### 请求MIB

> snmpget -v2c -c public localhost Test-MIB:GetTime.0
> 
> Test-MIB::GetTime.0 = STRING: Thu Jun  7 17:03:15 2018

#### 完成MIB扩展、参数获取及通信