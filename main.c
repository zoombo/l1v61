#include <stdio.h>
#include <complex.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dlfcn.h>
#include "helper_funcs.h"

#define nl getchar(); printf("\n")  
#define byte char

/*
 * 
 */

int main(void) {

    // Буфер для комманд.
    char cmd[20];

    // Код команды.
    byte cmd_num;

    // Указатели на функции.
    void (*add)(void);
    void (*sub)(void);
    void (*mul)(void);
    void (*div)(void);

    // ID открытых библиотек.
    void *add_handl, *sub_handl, *mul_handl, *div_handl;

    // Пытаемся достать функции из библиотек.
    getfnc(&add_handl, &add, "libaddfnc.so", "add");
    getfnc(&sub_handl, &sub, "libsubfnc.so", "sub");
    getfnc(&mul_handl, &mul, "libmulfnc.so", "mul");
    getfnc(&div_handl, &div, "libdivfnc.so", "div");


    while (1) {
        cmd_num = 0;
        printf(":::> ");

        *cmd = getchar();
        if (*cmd == '\n') {
            continue;
        }
        scanf("%19s", cmd + 1);
        getchar();
        stolw(cmd, 20);

        if (!strcmp(cmd, "add"))
            cmd_num = 1;
        if (!strcmp(cmd, "sub"))
            cmd_num = 2;
        if (!strcmp(cmd, "mul"))
            cmd_num = 3;
        if (!strcmp(cmd, "div"))
            cmd_num = 4;
        if (!strcmp(cmd, "quit"))
            cmd_num = 5;
        if (!strcmp(cmd, "help"))
            cmd_num = 6;
        if (cmd_num == 0)
            continue;

        switch (cmd_num) {
            case 1:
                if (add != NULL)
                    (*add)();
                nl;
                break;

            case 2:
                if (sub != NULL)
                    (*sub)();
                nl;
                break;

            case 3:
                if (mul != NULL)
                    (*mul)();
                nl;
                break;

            case 4:
                if (div != NULL)
                    (*div)();
                nl;
                break;

            case 5:
                exit(0);
                break;

            case 6:
                if (add != NULL)
                    printf("1)Add\n");
                if (sub != NULL)
                    printf("2)Sub\n");
                if (mul != NULL)
                    printf("3)Mul\n");
                if (div != NULL)
                    printf("4)Div\n");

                printf("5)Quit\n");
                break;
        }

    }

}

