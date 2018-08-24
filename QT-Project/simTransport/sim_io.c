#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

#include "base_type.h"
#include "sim_io.h"

#define FILEBUFFER_LENGTH (5000)
#define EMPTY_STR ""

sim_result_e get_lineNumber_file(uint16 *lineNum, const char* filename)
{
    sim_result_e result = SIM_FAILURE;
    int fd;
    register int linect = 0;
    char buf[FILEBUFFER_LENGTH];
    int len;
    char *p = NULL;

    if((lineNum == NULL) || (filename == NULL))
    {
        printf("error[get_lineNumber_file]: invalid para!\n");
        return SIM_FAILURE;
    }

    if(filename)
    {
        if((fd = open(filename, O_RDONLY)) < 0)
        {
            fprintf(stderr, "open %s\n",strerror(errno));
            return SIM_FAILURE;
        }

        while(1)
        {
            if((len = read(fd,buf,FILEBUFFER_LENGTH)) == -1) {
                return SIM_FAILURE;
            }
            if(len == 0){
                break;
            }
            for( p = buf; len--; ){
                if( *p == '\n' ){
                   ++linect;
                }
                ++p;
            }
        }
    }
    *lineNum = linect;

    return SIM_SUCCESS;
}

sim_result_e get_Str_fileline(char *str,char *fileName,int lineNumber)
{
    FILE *filePointer;
    int i=0;
    char buffer[FILEBUFFER_LENGTH];
    char *temp;

    memset(buffer,'\0',FILEBUFFER_LENGTH*sizeof(char));
    strcpy(buffer,EMPTY_STR);

    if((fileName==NULL)||(str==NULL))
    {
        printf("error[get_Str_fileline]: invalid para!\n");
        return SIM_FAILURE;
    }

    if(!(filePointer=fopen(fileName,"rb")))
    {
        return SIM_FAILURE;
    }

    while((!feof(filePointer))&&(i<lineNumber))
    {
        if(!fgets(buffer,FILEBUFFER_LENGTH,filePointer))
        {
            return SIM_FAILURE;
        }
        i++;
    }

    if(0!=fclose(filePointer))
    {
        return SIM_FAILURE;
    }

    if(0!=strcmp(buffer,EMPTY_STR))
    {
        while(NULL!=(temp=strstr(buffer,"\n")))
        {
            *temp='\0';
        }

        while(NULL!=(temp=strstr(buffer,"\r")))
        {
            *temp='\0';
        }

        strcpy(str,buffer);
    }
    else
    {
        strcpy(str,EMPTY_STR);
        return SIM_FAILURE;
    }

    return SIM_SUCCESS;
}

sim_result_e spliteStr(sim_hv_rv_dist_st *hv_rv_dist, char_t *theStr)
{
    sim_result_e result = SIM_FAILURE;
    char_t *token, *saveptr1;
    uint16 j = 0;
    if((hv_rv_dist == NULL) || (theStr == NULL))
    {
        printf("error[spliteStr]: invalid para!\n");
        return SIM_FAILURE;
    }

    for (j = 1; ; j++, theStr = NULL) {
        token = strtok_r(theStr, " ", &saveptr1);
        if (token == NULL)
            break;
        switch (j) {
        case 1:
            hv_rv_dist->hv = atoi(token);
//            printf("\thv: %.2f\n", hv_rv_dist->hv);
            break;
        case 2:
            hv_rv_dist->rv = atoi(token);
//            printf("\trv: %.2f\n", hv_rv_dist->rv);
            break;
        case 3:
            hv_rv_dist->dist = atoi(token);
//            printf("\tdist: %.2f\n", hv_rv_dist->dist);
            break;
        default:
            break;
        }
//        printf("%d: %s\n", j, token);
    }

    return SIM_SUCCESS;
}

sim_result_e getValue(sim_hv_rv_dist_st *hv_rv_dist, uint16 *lines, char *fileName)
{
    sim_result_e result = SIM_FAILURE;
    uint16 i;
    sim_hv_rv_dist_st hv_rv_speed_tmp;
    char buffer[FILEBUFFER_LENGTH];
    memset(buffer,'\0',FILEBUFFER_LENGTH*sizeof(char));

    if((hv_rv_dist == NULL)||(lines == NULL)||(fileName == NULL))
    {
        printf("error[getValue]: invalid para!\n");
        return SIM_FAILURE;
    }
    result = get_lineNumber_file(lines, fileName);
    for(i = 0; i < *lines; i++)
    {
//        printf("line: %d\n", i);
        result = get_Str_fileline(buffer, fileName, i + 1);
        result = spliteStr(&hv_rv_speed_tmp, buffer);
        memcpy(&(hv_rv_dist[i]), &hv_rv_speed_tmp, sizeof(sim_hv_rv_dist_st));
    }

    return result;
}
