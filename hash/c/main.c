#include <stdio.h>

#include "strmap.h"



int main(int argc, char const *argv[])

{

    /* code */

    StrMap *sm;

    char buf[255];

    int result;

    unsigned char *str[] = {"encry", "decry", "sign", "verify"};



    sm = sm_new(10);

    if (sm == NULL) {

    /* Handle allocation failure... */

    }

    /* Insert a couple of string associations */

    sm_put(sm, "application name", "Test Application");

    sm_put(sm, "application version", "1.0.0");

    sm_put(sm, "encry", "encry 1.0.0");

    sm_put(sm, "decry", "decry 1.0.0");

    sm_put(sm, "sign", "sign 1.0.0");

    sm_put(sm, "verify", "verify 1.0.0");

    /* Retrieve a value */

    result = sm_get(sm, "application name", buf, sizeof(buf));

    if (result == 0) {

    /* Handle value not found... */

    }

    printf("value: %s\n", buf);

    int i = 0;

    for(i = 0; i < 4; i++) {

        result = sm_get(sm, str[i], buf, sizeof(buf));

        printf("value: %s\n", buf);

    }



    /* When done, destroy the StrMap object */

    sm_delete(sm);



    return 0;

}

