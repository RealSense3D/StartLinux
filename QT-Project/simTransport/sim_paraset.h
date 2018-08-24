#ifndef SIM_PARASET_TYPE_H
#define SIM_PARASET_TYPE_H

#include "base_type.h"

typedef struct
{
    float32 g;
    float32 u;
    float32 reactionTs;
    float32 coordTs;
    float32 duraTs;
    float32 safeDistm;
}sim_env_info_st;

extern sim_env_info_st g_env_info;

sim_result_e sim_getParasetfromfile();

#endif // SIM_PARASET_TYPE_H
