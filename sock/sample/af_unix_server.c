/*
 * client.c
 * domain: AF_UNIX
 * type: SOCK_STREAM
 * protocol: 0
 */

#include <sys/types.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>

#include "rs_sock_af_unix.h"


int main(void)
{
    int result;
    result = af_unix_service();
    exit(0);
}
