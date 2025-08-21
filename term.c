/*term.c - терминал на си(ну или переписывание Terminal.cpp на cи*/
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

//=================================
//|         константы             |
//=================================
#define MAX_LINES 512
#define MAX_LINE_LENGTH 1024

void printLogo()
{
    printf(T_YELLOW "  ______                                                 \n" T_RESET);
    printf(T_YELLOW " ||    ||                         _____       ________// \n" T_RESET);
    printf(T_YELLOW " ||____||                       //     XX     XX         \n" T_RESET);
    printf(T_YELLOW " ||                            //       XX     XX        \n" T_RESET);
    printf(T_YELLOW " ||  ||      ||XX  || XX  //  //         XX     XX___    \n" T_RESET);
    printf(T_YELLOW " ||  ||==||  || XX ||  XX//   XX         //        //    \n" T_RESET);
    printf(T_YELLOW " ||  ||  ||  ||  XX||  //XX    XX       //        //     \n" T_RESET);
    printf(T_YELLOW " ||  ||  ||  ||    || //  XX    XX_____//   XX___//      \n" T_RESET);
}

void printInfoAboutUser()
{
    printf(T_YELLOW "____________________________ \n" T_RESET);
    printf(T_YELLOW "phoenixOSuser@PhoenixOS~$ \n" T_RESET);
    printf(T_YELLOW "---------------------------- \n" T_RESET);
    printf(T_YELLOW "[OS]: [PhoenixOS v 1.0.2] \n" T_RESET);
    printf(T_YELLOW "[Host]: [HP Laptop 15-bs0xx] \n" T_RESET);
    printf(T_YELLOW "[Kernel]: [6.8.0-71-generic] \n" T_RESET);
    printf(T_YELLOW "[Packages]: [0] \n" T_RESET);
    printf(T_YELLOW "[Shell]: [bash] \n" T_RESET);
    printf(T_YELLOW "[Theme]: [dark-with-blur] \n" T_RESET);
    printf(T_YELLOW "[Terminal]: [phnxOS-termianl] \n" T_RESET);
    printf(T_YELLOW "[CPU]: [Intel core i5 7th gen] \n" T_RESET);
    printf(T_YELLOW "[GPU]: [Radeon Graphics] \n" T_RESET);
}

void welcome()
{
    const char frstln[] = ".____________________________.";
    const char newlin[] = "|                            |";
    const char scndln[] = "|FFFFFFFFFFFFFFFFFFFFFFFFFFFF|";
    const char thrdln[] = "|[ Welcome to the PhoenixOS!]|";
    const char frthln[] = "|FFFFFFFFFFFFFFFFFFFFFFFFFFFF|";
    const char endlne[] = "|____________________________|";

    printf("%s\n", frstln);
    printf("%s\n", newlin);
    printf("%s\n", thrdln);
    printf("%s\n", endlne);
}

int main()
{
    welcome();
    char command[256];
    while (true) {
        printf("phoenixOSuser$~: ");
        if (scanf("%255s", command) != 1) {
            fprintf(stderr, T_RED "[err]: [ошибка ввода команды!]\n" T_RESET);
        }

        if (strcmp(command, "calc") == 0) {
            printf(T_BLUE "[калькулятор]\n" T_RESET);
            double FRST_NUMBER;
            double SCND_NUMBER;
            char SYMBOL;

            int inputResult = scanf("%lf\n %c\n %lf", &FRST_NUMBER, &SYMBOL, &SCND_NUMBER);
            if (inputResult != 3) {
                fprintf(stderr, T_RED "[ERR]: [Неверный ввод]\n" T_RESET);
                while (getchar() != '\n');
                continue;
            }

            double RES;

            if (SYMBOL != '+' && SYMBOL != '-' && SYMBOL == '*' && SYMBOL != '/') {
                fprintf(stderr, T_RED "[err]: [неизвестный оператор!]\n" T_RESET);
                continue;
            }

            if (SYMBOL == '+') {
                RES = FRST_NUMBER + SCND_NUMBER;
            }

            if (SYMBOL == '-') {
                RES = FRST_NUMBER - SCND_NUMBER;
            }

            if (SYMBOL == '*') {
                RES = FRST_NUMBER * SCND_NUMBER;
            }

            if (SYMBOL == '/') {
                if (SCND_NUMBER == 0) {
                    fprintf(stderr, T_RED "[err]: [деление на ноль!]\n" T_RESET);
                    continue;
                }
                RES = FRST_NUMBER / SCND_NUMBER;
            }

            printf(T_GREEN "[результат]: " T_RESET);
            printf("%.2lf \n", RES);
            printf(T_CYAN "[калькулятор завершил работу]\n" T_RESET);
        }

        if (strcmp(command, "phedx") == 0) {
            printf(T_BLUE "[текстовый редактор]\n" T_RESET);
            char lines[MAX_LINES][MAX_LINE_LENGTH];
            int lineCount = 0;
            char inputLine[MAX_LINE_LENGTH];
            bool emptyLineEntered = false;

            printf(T_CYAN "[начните ввод(введите 'x' для выхода)]: \n" T_RESET);

            getchar();

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

                strcpy(lines[lineCount], inputLine);
                lineCount++;

                if(lineCount >= MAX_LINES) {
                    printf(T_YELLOW "[warn]: [достигнуто максимальное количество строк. Завершите ввод\n" T_RESET);
                    break;
                }

                if (strcmp(inputLine, "x") == 0) {
                    emptyLineEntered = true;
                    break;
                }

            }

            printf(T_CYAN "[Редактор завершил работу]\n" T_RESET);
        }

        if (strcmp(command, "phnxfetch") == 0) {
            printLogo();
            printInfoAboutUser();
        }

        if (strcmp(command, "help") == 0) {
            const char calc[250] = "1.calc - калькулятор";
            const char edit[250] = "2.phedx - примитивный текстовый редактор";
            const char help[250] = "3.help - вывод всех команд";
            const char ftch[250] = "4.phnxfetch - выводит логотип ОС а также информация о компьютере и ос";
            const char exit[250] = "5.ext - выход и завершение работы терминала";

            printf("%s\n", calc);
            printf("%s\n", edit);
            printf("%s\n", help);
            printf("%s\n", ftch);
            printf("%s\n", exit);
        }

        if (strcmp(command, "ext") == 0) {
            printf(T_GREEN "[завершение программы]\n" T_RESET);
            break;
        }
    }

    return 0;
}
