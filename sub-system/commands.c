#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/unistd.h>
#include "lib/files.h"
#include "lib/simple_coms.h"

#define T_RED "\033[38;2;255;0;0m"
#define T_GREEN "\033[38;2;0;255;0m"
#define T_BLUE "\033[38;2;0;0;255m"
#define T_YELLOW "\033[38;2;255;255;0m"
#define T_CYAN "\033[38;2;0;255;255m"
#define T_RESET "\033[0m"
#define T_MAGENTA "\033[0;35m"

#define MAX_LINES 512
#define MAX_LINE_LENGTH 1024
#define MAX_CONTENT_LENGTH 1024

#ifndef COMMANDS_H
#define COMMANDS_H

// struct DexStructure {
//     char lines[MAX_LINES][MAX_LINE_LENGTH];
//     char inputLine[MAX_LINE_LENGTH];
//     char filename[100];
//     char mode;
//     int lineCount;
//     FILE * file;
// };

void editorLogo()
{
    printf(T_MAGENTA "_________     \n" T_RESET);
    printf(T_MAGENTA "| |===X X        ________           __\n" T_RESET);
    printf(T_MAGENTA "| |    X X      / /    XX    XX    / /  \n" T_RESET);
    printf(T_MAGENTA "| |     X X    / /      XX    XX  / / \n" T_RESET);
    printf(T_MAGENTA "| |      X X  / /        XX    XX/ /   \n" T_RESET);
    printf(T_MAGENTA "| |      / /  X X________xx     / /XX   \n" T_RESET);
    printf(T_MAGENTA "| |     / /    X X             / /  XX  \n" T_RESET);
    printf(T_MAGENTA "|_|____/_/      X X_____/_/   /_/    XX \n" T_RESET);
}

void editor()
{
    char lines[MAX_LINES][MAX_LINE_LENGTH];
    char inputLine[MAX_LINE_LENGTH];
    char filename[100];
    char mode;
    int lineCount;
    FILE * file;

    system("clear");
    editorLogo();
    printf(T_BLUE "[🗒 текстовый редактор]\n" T_RESET);

    // Запрос имени файла
    printf(T_CYAN "[Введите имя файла для редактирования]: " T_RESET);
    scanf("%s", filename);
    getchar(); // Удаляем символ новой строки после ввода имени файла

    // Открытие файла для чтения
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, T_RED "[err]: [не удалось открыть файл: %s]\n" T_RESET, filename);
        return;
    }

    // Чтение содержимого файла
    while (fgets(lines[lineCount], sizeof(lines[lineCount]), file) != NULL && lineCount < MAX_LINES) {
        lineCount++;
    }
    fclose(file);

    // Модальный ввод
    printf(T_CYAN "[нажмите 'w' для ввода текста, 'r' для чтения, 'q' для выхода]: \n" T_RESET);
    while ((mode = getchar()) != 'q') {
        if (mode == 'w') {
            printf(T_CYAN "[начните ввод (введите 'E' для выхода)]: \n" T_RESET);
            while (lineCount < MAX_LINES) {
                printf("%d: ", lineCount + 1);
                if (fgets(lines[lineCount], sizeof(lines[lineCount]), stdin) == NULL) {
                    fprintf(stderr, T_RED "[err]: [ошибка чтения строки.]\n" T_RESET);
                    break;
                }

                lines[lineCount][strcspn(lines[lineCount], "\n")] = 0;

                if (strlen(lines[lineCount]) == 0 || strcmp(lines[lineCount], "E") == 0) {
                    break;
                }

                strcpy(lines[lineCount], lines[lineCount]);
                lineCount++;

                if (lineCount >= MAX_LINES) {
                    printf(T_YELLOW "[warn]: [достигнуто максимальное количество строк. Завершите ввод]\n" T_RESET);
                    break;
                }
            }

            if (mode == 'r') {
                displayFile(filename);
            }
        }
    }

    // Сохранение изменений в файл
    file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, T_RED "[err]: [не удалось открыть файл для записи: %s]\n" T_RESET, filename);
        return;
    }

    for (int i = 0; i < lineCount; i++) {
        fprintf(file, "%s\n", lines[i]);
    }
    fclose(file);

    printf(T_CYAN "[Редактор завершил работу]\n" T_RESET);
    system("clear");
    welcome();
}

void print_fetch()
{
    printf(T_CYAN "      _____            User:        DeltaDev\n" T_RESET);
    printf(T_CYAN "      / /\\ \\          ---------------------------\n" T_RESET);
    printf(T_CYAN "     / /  \\ \\          🖫 OS:          DeltaOS Linux\n" T_RESET);
    printf(T_CYAN "    / /    \\ \\         🗃 Kernel:      Linux\n" T_RESET);
    printf(T_CYAN "   / /      \\ \\        🗔 Shell:       bash\n" T_RESET);
    printf(T_CYAN "  / /        \\ \\       🗂 PKGS:        no\n" T_RESET);
    printf(T_CYAN " / /          \\ \\      🖷 Terminal:    DeltaTerminal\n" T_RESET);
    printf(T_CYAN "/_/____________\\_\\     🖳 Host:        Laptop\n" T_RESET);
}

#endif
