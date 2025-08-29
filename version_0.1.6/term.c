/*term.c - терминал на си(ну или переписывание Terminal.cpp на cи*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "headers/commands.h"

//==================================
//|            ЦВЕТА               |
//==================================
#define T_GREEN "\033[0;32m"
#define T_RED   "\033[0;31m"
#define T_CYAN  "\033[0;36m"
#define T_BLUE  "\033[0;34m"
#define T_YELLOW "\033[1;33m"
#define T_RESET "\033[0m"

int main()
{
    LoadScreen();
    welcome();
    char command[256];
    while (true) {
        printf("deltaOSuser$~: ");
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

        if (strcmp(command, "edit") == 0) {
            edit();
        }

        if (strcmp(command, "dltfetch") == 0) {
            printLogo();
            printInfoAboutUser();
        }

        if (strcmp(command, "help") == 0) {
            help();
        }

        if (strcmp(command, "lf") == 0) {
            files();
        }

        if (strcmp(command, "ext") == 0) {
            printf(T_GREEN "[завершение программы]\n" T_RESET);
            break;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    return 0;
}
