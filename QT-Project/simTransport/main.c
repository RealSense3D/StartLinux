#include <stdio.h>
#include "base_type.h"
#include "sim_paraset.h"
#include "sim_fcw.h"
#include "sim_io.h"

sim_result_e (*const sim_fcw[SIM_FCW_CASE_MAX])(bool_t *isSafe, sim_hv_rv_dist_st hv_rv_dist) =
{
    sim_fcw_norm,
};

int main(int argc, char *argv[])
{
    sim_result_e result = SIM_FAILURE;
    bool_t isSafe = FALSE;
    uint16 lines, i;
    sim_hv_rv_dist_st hv_rv_dist[10];
//    char_t *path = NULL;
//    path = (char_t *)get_current_dir_name();
//    printf("path: %s\n", path);
    result = sim_getParasetfromfile();
    result = getValue(hv_rv_dist, &lines, "/home/hostname/Github/StartLinux/QT-Project/simTransport/sim_hv_rv_dist");
    for (i = 0; i < lines; i++)
    {
        printf("%02d: hv[%.2f]  rv[%.2f]  dist[%.2f]\n", i, hv_rv_dist[i].hv, hv_rv_dist[i].rv, hv_rv_dist[i].dist);
        result = sim_fcw[SIM_FCW_NORM](&isSafe, hv_rv_dist[i]);
        printf("%02d: isSafe[%d]\n", i, isSafe);
    }
    return result;
}
