#include <stdio.h>

#define T_GREEN "\033[0;32m"
#define T_BLUE  "\033[0;34m"
#define T_RESET "\033[0m"
#define T_CYAN  "\033[0;36m"

#ifndef START_H
#define START_H

void welcome()
{
    const char frstln[] = ".____________________________.";
    const char newlin[] = "|                            |";
    const char scndln[] = "|FFFFFFFFFFFFFFFFFFFFFFFFFFFF|";
    const char thrdln[] = "|[ Welcome to the DeltaOS!  ]|";
    const char frthln[] = "|FFFFFFFFFFFFFFFFFFFFFFFFFFFF|";
    const char endlne[] = "|____________________________|";

    printf("%s\n", frstln);
    printf("%s\n", newlin);
    printf("%s\n", thrdln);
    printf("%s\n", endlne);
    printf(T_CYAN "[впешите help для того чтобы узнать большинство команд]\n" T_RESET);
}

void LoadScreen()
{
    printf(T_BLUE "[Start loading of OS]\n" T_RESET);
    printf(T_GREEN "[OK]: Compiling term.c\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading commands\n" T_RESET);
    printf(T_GREEN "[OK]: Commands is load\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command help\n" T_RESET);
    printf(T_GREEN "[OK]: Command help is load\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command calc\n" T_RESET);
    printf(T_GREEN "[OK]: Command calc is load\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command edit\n" T_RESET);
    printf(T_GREEN "[OK]: Command edit is load\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command dltfetch\n" T_RESET);
    printf(T_GREEN "[OK]: Command phnxfetch is load\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command ext\n" T_RESET);
    printf(T_GREEN "[OK]: Command ext is load\n");
    printf(T_GREEN "[OK]: Start loading command add\n" T_RESET);
    printf(T_GREEN "[OK]: Command add is load\n");
    printf(T_GREEN "[OK]: Start loading command lf\n" T_RESET);
    printf(T_GREEN "[OK]: Command lf is load\n");
    printf(T_GREEN "[OK]: Initialization working all commands\n" T_RESET);
    printf(T_GREEN "[OK]: Optimization working all commands\n" T_RESET);
    printf(T_BLUE "[Loading is end!]\n" T_RESET);
}

#endif
