/*term.c - терминал на си(ну или переписывание Terminal.cpp на cи*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "headers/fetch.h"
#include "headers/welcome.h"
#include "headers/help.h"

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

void files()
{
    printf("[все важные файлы]\n");
    
    const char files[256] = T_CYAN "" T_RESET;
}

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

        if (strcmp(command, "dedit") == 0) {
            edit();
        }

        if (strcmp(command, "dltfetch") == 0) {
            printLogo();
            printInfoAboutUser();
        }

        if (strcmp(command, "help") == 0) {
            help();
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
