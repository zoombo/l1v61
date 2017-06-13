#include <stdio.h>
#include <complex.h>
#include <ctype.h>
#include <dlfcn.h>
/// Для функции getfnc2 .
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

void stolw(char *str, int len) {
    for (int i = 0; i < len; i++)
        str[i] = tolower(str[i]);
}

double complex getcmp() {
    double tmp_a, tmp_b;
    printf("Enter real part: ");
    scanf("%lf", &tmp_a);
    printf("Enter imag part: ");
    scanf("%lf", &tmp_b);
    double complex tcomp = tmp_a + tmp_b * I;
    return tcomp;
}

/// Достает функцию из указанной библиотеки.
/// \param fnc_handl - адрес указателя, описателя открываемой библиотеки.
/// \param fnc_ptr - адрес указателя принимающего найденную функцию.
/// \param lib_name - име библиотеки с расширением.
/// \param fnc_name - имя искомой функции.
void getfnc(void **fnc_handl, void (**fnc_ptr)(void), char *lib_name, char *fnc_name) {
    // Переменная для хранения кода ошибки.
    // int err;
    *fnc_handl = dlopen(lib_name, RTLD_LAZY);
    if (*fnc_handl != NULL)
        *fnc_ptr = dlsym(*fnc_handl, fnc_name);
    else {
        *fnc_ptr = NULL;
        printf("%s\n", dlerror());
    }
}


