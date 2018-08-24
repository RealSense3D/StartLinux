#ifndef _RS_SOCK_AF_UNIX_H_
#define _RS_SOCK_AF_UNIX_H_
/*******************************************************************************
    Include Files
*******************************************************************************/


#include <stdlib.h>
#ifdef __cplusplus
extern "C"
{
#endif

int af_unix_server(void);
int af_unix_client(void);

/*@}*/
#ifdef __cplusplus
}
#endif
#endif // _RS_SOCK_AF_UNIX_H_