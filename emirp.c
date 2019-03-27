#include <stdio.h>
#include "reverse.h"
#include <gmp.h>

typedef int bool;

#define TRUE 1
#define FALSE 0

void emirp (mpz_t n, mpz_t p);

int main (int argc, char *argv[])
{
    mpz_t n, p;
    mpz_inits(n, p, NULL);

    mpz_inp_str(n, stdin, 10);  

    emirp(n, p);

    gmp_printf("%Zd\n", p);
	mpz_clear(p);
    return 0;
}

void emirp (mpz_t n, mpz_t p)
{
    mpz_t i, r; //Justify
    mpz_inits(r, NULL); //Justify
    mpz_init_set_ui(i, 1);
    mpz_set_ui(p, 13);

    while (mpz_cmp(i, n) < 0)
    {
        mpz_add_ui(p, p, 1);
        reversen(p, r);
        if (mpz_probab_prime_p(r, 50) > 0 
            && mpz_probab_prime_p(p, 50) > 0 
            && mpz_cmp(r, p) != 0)
        {
            mpz_add_ui(i, i, 1);
        }

    }
    mpz_clears(i, r, n, NULL); //Justify
}

