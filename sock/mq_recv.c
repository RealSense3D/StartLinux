#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>   
#include <errno.h>
#include <string.h>

typedef struct
{  
    int32_t param1;  
    int32_t param2;  
    int32_t param3;  
    int32_t param4;  
} msg_head_t; 

struct msg_st  
{  
    long int    msg_type;
    msg_head_t  send_msg_head;
}; 

int main( )
{
    int msgid = -1;
    struct msg_st data = {0};

    /* create mq */
    msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if(msgid == -1)
    {
        fprintf(stderr, "msgget failed with error: %d\n", errno);
        exit(1);
    }

        if(msgrcv(msgid, (void*)&data, sizeof(msg_head_t), 0, 0) == -1)  {
            fprintf(stderr, "msgrcv failed with errno: %d\n", errno);
            printf("msgrcv()  is error!\n");
        }
        else
        {
            printf("receive msg\n");
            printf("data.send_msg_head.param1: %d\n",data.send_msg_head.param1);
            printf("data.send_msg_head.param2: %d\n",data.send_msg_head.param2);
            printf("data.send_msg_head.param3: %d\n",data.send_msg_head.param3);
            printf("data.send_msg_head.param4: %d\n",data.send_msg_head.param4);
		}

    /* delete mq */
    if(msgctl(msgid, IPC_RMID, 0) == -1)  {
        fprintf(stderr, "msgctl(IPC_RMID) failed\n");
        exit(1);
    }
    return 0;
}

