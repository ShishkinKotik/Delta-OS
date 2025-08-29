#include <stdio.h>

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
}

void LoadScreen()
{
    printf(T_BLUE "[Start loading OS]\n" T_RESET);
    printf(T_GREEN "[OK]: Compiling term.c\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading commands\n" T_RESET);
    printf(T_GREEN "[OK]: Commands is load\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command help\n" T_RESET);
    printf(T_GREEN "[OK]: Command help is load\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command calc\n" T_RESET);
    printf(T_GREEN "[OK]: Command calc is load\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command edit\n" T_RESET);
    printf(T_GREEN "[OK]: Command edit is load\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command phnxfetch\n" T_RESET);
    printf(T_GREEN "[OK]: Command phnxfetch is load\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command ext\n" T_RESET);
    printf(T_GREEN "[OK]: Command ext is load\n");
    printf(T_GREEN "[OK]: Initialization working all commands\n" T_RESET);
    printf(T_GREEN "[OK]: Optimization working all ocmmands\n" T_RESET);
    printf(T_BLUE "[Loading is end!]\n" T_RESET);
}
