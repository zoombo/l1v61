#include <stdio.h>
#include <complex.h>
#include "../helper_funcs.h"

void mul() {
    double complex acomp, bcomp;
    acomp = getcmp();
    bcomp = getcmp();
    printf("Произведение : %lf + %lf", creal(acomp * bcomp), cimag(acomp * bcomp));
}
