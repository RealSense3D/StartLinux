#ifndef SIM_IO_H
#define SIM_IO_H
#include "base_type.h"

typedef struct{
    float32 hv;
    float32 rv;
    float32 dist;
}sim_hv_rv_dist_st;
sim_result_e getValue(sim_hv_rv_dist_st *hv_rv_dist, uint16 *lines, char *fileName);

#endif // SIM_IO_H
