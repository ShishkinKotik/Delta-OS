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
