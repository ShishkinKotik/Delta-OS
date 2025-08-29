#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//==================================
//|            ЦВЕТА               |
//==================================
#define T_GREEN "\033[0;32m"
#define T_RED   "\033[0;31m"
#define T_CYAN  "\033[0;36m"
#define T_BLUE  "\033[0;34m"
#define T_YELLOW "\033[1;33m"
#define T_RESET "\033[0m"

#define MAX_LINES 512
#define MAX_LINE_LENGTH 1024

void edit()
{
    printf(T_BLUE "[текстовый редактор]\n" T_RESET);
    char lines[MAX_LINES][MAX_LINE_LENGTH];
    int lineCount = 0;
    char inputLine[MAX_LINE_LENGTH];

    printf(T_CYAN "[начните ввод(введите 'x' для выхода)]: \n" T_RESET);
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    while (lineCount < MAX_LINES) {
        printf("%d: ", lineCount + 1);
        if (fgets(inputLine, sizeof(inputLine), stdin) == NULL) {
            fprintf(stderr, T_RED "[err]: [ошибка чтения строки.]\n" T_RESET);
            break;
        }

        inputLine[strcspn(inputLine, "\n")] = 0;

        if (strlen(inputLine) == 0) {
            break;
        }

        if (strcmp(inputLine, "x") == 0) {
            break;

        strcpy(lines[lineCount], inputLine);
        lineCount++;

        if(lineCount >= MAX_LINES) {
            printf(T_YELLOW "[warn]: [достигнуто максимальное количество строк. Завершите ввод\n" T_RESET);
            break;
        }

    }

    printf(T_CYAN "[Редактор завершил работу]\n" T_RESET);
}

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

void help()
{
    printf("[help page]\n");
    const char frame[128]= T_BLUE   "[============================================================================]" T_RESET;
    const char frm_2[128] = T_BLUE  "|                                                                            |" T_RESET;
    const char calc[250] = T_YELLOW "|      1.calc - калькулятор                                                  |" T_RESET;
    const char edit[250] = T_YELLOW "|      2.edit - примитивный текстовый редактор                               |" T_RESET;
    const char help[250] = T_YELLOW "|      3.help - вывод всех команд                                            |" T_RESET;
    const char ftch[250] = T_YELLOW "|      4.dltfetch - выводит логотип ОС а также информация о компьютере и ос  |" T_RESET;
    const char exit[250] = T_YELLOW "|      5.ext - выход и завершение работы терминала                           |" T_RESET;
    const char fils[250] = T_YELLOW "|      6.lf - список файлов в помощью которых работает ос                    |" T_RESET;
    const char frm_3[128] = T_BLUE  "|                                                                            |" T_RESET;
    const char frm_1[128] = T_BLUE  "[============================================================================]" T_RESET;

    printf("%s\n", frame);
    printf("%s\n", frm_2);
    printf("%s\n", calc);
    printf("%s\n", edit);
    printf("%s\n", help);
    printf("%s\n", ftch);
    printf("%s\n", exit);
    printf("%s\n", fils);
    printf("%s\n", frm_3);
    printf("%s\n", frm_1);
}


void files()
{
    printf("[все важные файлы]\n");
    const char term_dot_c[125] = "[c lang]: \n [term.c]\n";
    const char comm_dot_c[115] = "[commands.c]\n";
    const char strt_dot_c[115] = "[start.c]\n";
    const char strt_dot_h[115] = "[start_screen.c]\n";
    const char comm_dot_h[115] = "[commands.h]\n";

    printf("%s", term_dot_c);
    printf("%s", comm_dot_c);
    printf("%s", strt_dot_c);
    printf("%s", strt_dot_h);
    printf("%s", comm_dot_h);
}
