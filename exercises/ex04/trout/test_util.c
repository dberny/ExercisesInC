#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "util.h"
#include "../minunit.h"

static char *test1() {
    int res = endswith("endswith", "swith");
    char *message = "test1 failed: endswith(\"endswith\", \"swith\") should return 1";
    mu_assert(message, res == 1);
    return NULL;
}
