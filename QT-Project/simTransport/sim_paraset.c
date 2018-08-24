#include <stdio.h>
#include <string.h>
#include "base_type.h"
#include "sim_paraset.h"

sim_env_info_st g_env_info;

sim_result_e sim_getParasetfromfile()
{
    sim_result_e result = SIM_FAILURE;

    /* default */
    sim_env_info_st env_info_tmp = {
        .g = 9.8,
        .u = 0.4,
        .reactionTs = 2.0,
        .coordTs = 0.5,
        .duraTs = 0.2,
        .safeDistm = 3,
    };

    memcpy(&g_env_info, &env_info_tmp, sizeof(sim_env_info_st));

    /* TODO */

    result = SIM_SUCCESS;
    return result;
}
