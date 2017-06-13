#pragma once
#include <complex.h>

void stolw(char *str, int len);
double complex getcmp();
void getfnc(void **fnc_handl, void (**fnc_ptr)(void), char *lib_name, char *fnc_name);


