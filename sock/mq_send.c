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

int main(int argc, char *argv[]) {

    /* init variables */
    int8_t   log_type        = -1;
    int8_t   log_mod_id      = -2;
    int8_t   log_priority    = -3;
    int32_t  log_expiry_date = -4;

    int msgid = -1;
    struct msg_st data;
    memset(&data, 0, sizeof(struct msg_st));

    /* create message queue */ 
    msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if(msgid == -1)
    {
        fprintf(stderr, "msgget failed with error: %d\n", errno);
        exit(1);
    }
    data.msg_type = 1;

    /* set parameter to msg */
    data.send_msg_head.param1 = log_type;
    data.send_msg_head.param2 = log_mod_id;
    data.send_msg_head.param3 = log_priority;
    data.send_msg_head.param4 = log_expiry_date;

    if(msgsnd(msgid, (void*)&data, sizeof(msg_head_t), 0) == -1)  {
        fprintf(stderr, "msgsnd failed\n");
        exit(1);
    }
    else {
        printf("[LOG-TOOLS]log tools command (type=logfile) send ok\n");
        printf("[LOG-TOOLS]log_type       : %d\n",  data.send_msg_head.param1);
        printf("[LOG-TOOLS]log_mod_id     : %d\n",  data.send_msg_head.param2);
        printf("[LOG-TOOLS]log_priority   : %d\n",  data.send_msg_head.param3);
        printf("[LOG-TOOLS]log_expiry_date: %d\n",  data.send_msg_head.param4);
    }
    return 0;
}

