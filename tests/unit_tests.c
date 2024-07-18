#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/panoramix.h"

Test(start, valid_arguments)
{
    char *args[] = {"./panoramix", "5", "10", "15", "2", NULL};
    int res = start(5, args);
    cr_assert_eq(res, 0);
}

Test(start, invalid_arguments)
{
    char *args[] = {"./panoramix", "-5", "10", "15", "2", NULL};
    int res = start(5, args);
    cr_assert_neq(res, 0);
}

Test(start, usage)
{
    char *args[] = {"./panoramix", "-h", NULL};
    int res = start(2, args);
    cr_assert_neq(res, 84);
}
