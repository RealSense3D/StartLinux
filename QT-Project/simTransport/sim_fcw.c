#include <stdio.h>
#include <string.h>
#include "base_type.h"
#include "sim_paraset.h"
#include "sim_fcw.h"

sim_result_e sim_fcw_norm(bool_t *isSafe, sim_hv_rv_dist_st hv_rv_dist)
{
    sim_result_e result = SIM_FAILURE;
    sim_env_info_st env_info_tmp;
    float32 minBrakeDist = 0;
    float32 hv_vmps, rv_vmps;
    if (!isSafe)
    {
        printf("error[sim_fcw_norm]: invalid para!\n");
        return result;
    }
    else
    {
        /* No action */
    }

    memset(&env_info_tmp, 0, sizeof(sim_env_info_st));
    memcpy(&env_info_tmp, &g_env_info, sizeof(sim_env_info_st));

    hv_vmps = hv_rv_dist.hv / 3.6;
    rv_vmps = hv_rv_dist.rv / 3.6;

//    minBrakeDist = (env_info_tmp.reactionTs + env_info_tmp.coordTs + env_info_tmp.duraTs / 2) * hv_vmps\
//                + (hv_vmps * hv_vmps - rv_vmps * rv_vmps) / env_info_tmp.g / env_info_tmp.u / 2\
//                + env_info_tmp.safeDistm;
    minBrakeDist = (env_info_tmp.reactionTs + env_info_tmp.coordTs + env_info_tmp.duraTs / 2) * (hv_vmps - rv_vmps)\
                + (hv_vmps - rv_vmps) * (hv_vmps - rv_vmps) / env_info_tmp.g / env_info_tmp.u / 2\
                + env_info_tmp.safeDistm;

    printf("\tsafeDist[%.2f] ", minBrakeDist);
    if(minBrakeDist > hv_rv_dist.dist)
    {
        printf(">");
        *isSafe = FALSE;
    }
    else
    {
        printf("<=");
        *isSafe = TRUE;
    }
    printf(" nowDist[%.2f]\n", hv_rv_dist.dist);

    result = SIM_SUCCESS;
    return result;
}

