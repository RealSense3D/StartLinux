#ifndef SIM_FCW_H
#define SIM_FCW_H

#include "base_type.h"
#include "sim_io.h"

/*******************************************************************************
    Variable  Definition
*******************************************************************************/
typedef enum
{
    SIM_FCW_NORM = 0,
//    SIM_FCW_DOWNHILL,
//    SIM_FCW_UPHILL,
    SIM_FCW_CASE_MAX,
}sim_FCW_type_e;

sim_result_e sim_fcw_norm(bool_t *iswarn, sim_hv_rv_dist_st hv_rv_dist);

#endif // SIM_FCW_H
