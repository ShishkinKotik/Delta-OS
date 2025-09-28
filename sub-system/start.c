#include <stdio.h>

#define T_RED "\033[38;2;255;0;0m"
#define T_GREEN "\033[38;2;0;255;0m"
#define T_BLUE "\033[38;2;0;0;255m"
#define T_YELLOW "\033[38;2;255;255;0m"
#define T_CYAN "\033[38;2;0;255;255m"
#define T_RESET "\033[0m"
#define T_MAGENTA "\033[0;35m"

#define MAX_CONTENT_LENGTH 2048
#define MAX_LINES 256

#ifndef START_H
#define START_H

void title()
{
    printf(T_CYAN " ___________       ___________  ___          _________________            ____ \n" T_RESET);
    printf(T_CYAN " | |      XX       | |     | |  |  |         |______   ______|            //XX  \n" T_RESET);
    printf(T_CYAN " | |       XX      | |     | |  |  |                | |                  //  XX  \n" T_RESET);
    printf(T_CYAN " | |        XX     | |     | |  |  |                | |                 //    XX  \n" T_RESET);
    printf(T_CYAN " | |         XX    |_|_____|_|  |  |                | |                //      XX  \n" T_RESET);
    printf(T_CYAN " | |          XX   | |          |  |                | |               //        XX  \n" T_RESET);
    printf(T_CYAN " | |           XX  | |          |  |                | |              //==========XX  \n" T_RESET);
    printf(T_CYAN " | |           //  | |     ___  |  |      ___       | |             //            XX  \n" T_RESET);
    printf(T_CYAN " | |          //   | |     | |  |  |      | |       | |            //              XX  \n" T_RESET);
    printf(T_CYAN " | |_________//    |_|_____|_|  |__|______|_|       |_|           //                XX  \n" T_RESET);
}

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
    printf(T_GREEN "[OK]: Start loading command display\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command display\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command redact\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command redact\n" T_RESET);
    printf(T_GREEN "[OK]: Command calc is load\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command edit\n" T_RESET);
    printf(T_GREEN "[OK]: Command editor is load\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command dltfetch\n" T_RESET);
    printf(T_GREEN "[OK]: Command dltfetch is load\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command ext\n" T_RESET);
    printf(T_GREEN "[OK]: Command ext is load\n");
    printf(T_GREEN "[OK]: Start loading command add\n" T_RESET);
    printf(T_GREEN "[OK]: Command add is load\n");
    printf(T_GREEN "[OK]: Start loading command lsf\n" T_RESET);
    printf(T_GREEN "[OK]: Command lsf is load\n");
    printf(T_GREEN "[OK]: Initialization working all commands\n" T_RESET);
    printf(T_GREEN "[OK]: Optimization working all commands\n" T_RESET);
    printf(T_BLUE "[Loading is end!]\n" T_RESET);
}

#endif

