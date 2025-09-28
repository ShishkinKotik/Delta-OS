/*term.c - терминал на си(ну или переписывание Terminal.cpp на cи*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "lib/commands.h"
#include "lib/start_screen.h"
#include "lib/files.h"

//==================================
//|            ЦВЕТА               |
//==================================
#define T_RED "\033[38;2;255;0;0m"
#define T_GREEN "\033[38;2;0;255;0m"
#define T_BLUE "\033[38;2;0;0;255m"
#define T_YELLOW "\033[38;2;255;255;0m"
#define T_CYAN "\033[38;2;0;255;255m"
#define T_RESET "\033[0m"
#define T_MAGENTA "\033[0;35m"

#define MCL 256 // Максимальная длинна строки

int main(void)
{
    //title();
    //LoadScreen();
    welcome();
    char command[MCL];
    printf(T_GREEN "[input 'delta-install']\n" T_RESET);
    while (true) {
        printf("(DeltaOS) ❯ ");
        if (scanf("%255s", command) != 1) {
            fprintf(stderr, T_RED "[err]: [ошибка ввода команды!]\n" T_RESET);
        }

        if (strcmp(command, "delta-install") == 0) {
            LoadScreen();
        }

        if (strcmp(command, "intro") == 0) {
            intro();
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

            switch (SYMBOL) {
                case '+':
                    RES = FRST_NUMBER + SCND_NUMBER;
                    break;
                case '-':
                    RES = FRST_NUMBER - SCND_NUMBER;
                    break;
                case '*':
                    RES = FRST_NUMBER * SCND_NUMBER;
                    break;
                case '/':
                    if (SCND_NUMBER == 0) {
                        fprintf(stderr, T_RED "[ERR]: [Деление на ноль!]\n" T_RESET);
                        while (getchar() != '\n');
                        continue;
                    }
                    RES = FRST_NUMBER / SCND_NUMBER;
                    break;
                default:
                    fprintf(stderr, T_RED "[ERR]: [Неверный символ операции!]\n" T_RESET);
                    while (getchar() != '\n');
                    continue;
            }

            printf(T_GREEN "[результат]: " T_RESET);
            printf("%.2lf \n", RES);
            printf(T_CYAN "[калькулятор завершил работу]\n" T_RESET);
        }

        else if (strcmp(command, "dex") == 0) {
            editor();
        }

        if (strcmp(command, "dltfetch") == 0) {
            print_fetch();
        }

        if (strcmp(command, "help") == 0) {
            help();
        }

        if (strcmp(command, "lsf") == 0) {
            printf(T_CYAN "[все файлы для работы ОС]\n" T_RESET);
            files();
        }

        if (strcmp(command, "add") == 0) {
            printf(T_CYAN "[добавление файла]\n" T_RESET);
            add();
        }

        if (strcmp(command, "del") == 0) {
            printf(T_CYAN "[удаление файла]\n" T_RESET);
            del();
        }

        if (strcmp(command, "redact") == 0) {
            redactFile();
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
