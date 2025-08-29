#include <stdio.h>

//==================================
//|            ЦВЕТА               |
//==================================
#define T_GREEN "\033[0;32m"
#define T_RED   "\033[0;31m"
#define T_CYAN  "\033[0;36m"
#define T_BLUE  "\033[0;34m"
#define T_YELLOW "\033[1;33m"
#define T_RESET "\033[0m"

void printLogo()
{
    printf(T_CYAN "____________                                                             \n" T_RESET);
    printf(T_CYAN "||        XX                 ||===||                                        _____         ________   \n" T_RESET);
    printf(T_CYAN "||         XX                ||   ||        ||       //===XX  ||          //     XX      XX     ||   \n" T_RESET);
    printf(T_CYAN "||          XX    //===XX         ||     ===||===   //     XX ||         //       XX      XX         \n" T_RESET);
    printf(T_CYAN "||           XX  //     XX        ||        ||     //       XX||        //         XX      XX____    \n" T_RESET);
    printf(T_CYAN "||           //  XX_____XX        ||        ||      XX      //||        XX         //          //    \n" T_RESET);
    printf(T_CYAN "||          //    XX              ||        ||       XX    // ||   XX    XX       //  XX      //     \n" T_RESET);
    printf(T_CYAN "||_________//      XX__//   ||____||____||   XX===__  XX__//  ||__XX      XX_____//    XX____//       \n" T_RESET);
}

void printInfoAboutUser()
{
    printf(T_YELLOW "____________________________ \n" T_RESET);
    printf(T_YELLOW "deltaOSuser@DeltaOS~$ \n" T_RESET);
    printf(T_YELLOW "---------------------------- \n" T_RESET);
    printf(T_YELLOW "[OS]: [DeltaOS v 0.2.2] \n" T_RESET);
    printf(T_YELLOW "[Host]: [Delta Laptop 15-jd0xxs] \n" T_RESET);
    printf(T_YELLOW "[Kernel]: [6.8.0-71-generic] \n" T_RESET);
    printf(T_YELLOW "[Packages]: [1(dltp)] \n" T_RESET);
    printf(T_YELLOW "[Shell]: [bash] \n" T_RESET);
    printf(T_YELLOW "[Theme]: [dark-with-blur] \n" T_RESET);
    printf(T_YELLOW "[Terminal]: [dltOS-termianl] \n" T_RESET);
    printf(T_YELLOW "[All lines]: [dohuya] \n" T_RESET);
    printf(T_YELLOW "[CPU]: [Gamma 1 7th gen] \n" T_RESET);
    printf(T_YELLOW "[GPU]: [Gamma GPU] \n" T_RESET);
}


