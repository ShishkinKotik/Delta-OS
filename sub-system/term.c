/*term.c - терминал на си(ну или переписывание Terminal.cpp на cи*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include "lib/commands.h"
#include "lib/simple_coms.h"
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

#define MCL 255 // Максимальная длинна строки

struct console {
    char command[MCL];
    unsigned int numberOfCommands;
    char *fileName;
    char *folderName;
};

int main(void)
{
    welcome();
    struct console console;

    while (true) {
        printf("#> ");
        if (scanf("%255s", console.command) != 1) {
            fprintf(stderr, T_RED "[err]: [ошибка ввода команды!]\n" T_RESET);
        }

        if (strcmp(console.command, "intro") == 0) {
            intro();
        }

        else if (strcmp(console.command, "calc") == 0) {
            printf(T_BLUE "[🖩 калькулятор]\n" T_RESET);
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

        else if (strcmp(console.command, "dex") == 0) {
            editor();
        }

        else if (strcmp(console.command, "dlt-fetch") == 0) {
            print_fetch();
        }

        else if (strcmp(console.command, "help") == 0) {
            console.numberOfCommands = 13;
            printf(T_CYAN "[всего команд]: '%d'\n" T_RESET, console.numberOfCommands);
            help();
        }

        else if (strcmp(console.command, "lsf") == 0) {
            printf(T_CYAN "[все файлы для работы ОС]\n" T_RESET);
            files();
        }

        else if (strcmp(console.command, "list") == 0 ) {
            list();
        }

        else if (strcmp(console.command, "std") == 0) {
            showThisDir();
        }

        else if (strcmp(console.command, "gtd") == 0) {
            const char *dirPath = console.folderName;
            goToDir(dirPath);
        }

        else if (strcmp(console.command, "add-file") == 0) {
            printf(T_CYAN "[добавление файла]\n" T_RESET);
            add_file();
        }

        else if (strcmp(console.command, "add-dir") == 0) {
            printf(T_CYAN "[добавление папки]\n" T_RESET);
            add_dir();
        }

        else if (strcmp(console.command, "del") == 0) {
            printf(T_CYAN "[удаление файла]\n" T_RESET);
            del();
        }

        else if (strcmp(console.command, "display") == 0) {
            printf(T_CYAN "[содержимое файла]\n" T_RESET);
            displayFile(console.fileName);
        }

        else if (strcmp(console.command, "quit") == 0) {
            printf(T_GREEN "[завершение программы]\n" T_RESET);
            break;
        }

        else {
            printf(T_RED "[err]: [неизвестная команда!]\n" T_RESET);
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    return 0;
}
