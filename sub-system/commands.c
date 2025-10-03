#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "lib/files.h"

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

struct DexStructure {
    char lines[MAX_LINES][MAX_LINE_LENGTH];
    char inputLine[MAX_LINE_LENGTH];
    char filename[100];
    char mode;
    int lineCount;
    FILE * file;
};

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
    struct DexStructure *dex = malloc(sizeof(struct DexStructure));
    struct DexStructure *var = {0};

    editorLogo();
    printf(T_BLUE "[🗒 текстовый редактор]\n" T_RESET);

    // Запрос имени файла
    printf(T_CYAN "[Введите имя файла для редактирования]: " T_RESET);
    scanf("%s", var->filename);
    getchar(); // Удаляем символ новой строки после ввода имени файла

    // Открытие файла для чтения
    var->file = fopen(var->filename, "r");
    if (var->file == NULL) {
        fprintf(stderr, T_RED "[err]: [не удалось открыть файл: %s]\n" T_RESET, var->filename);
        return;
    }

    // Чтение содержимого файла
    while (fgets(var->lines[var->lineCount], sizeof(var->lines[var->lineCount]), var->file) != NULL && var->lineCount < MAX_LINES) {
        var->lineCount++;
    }
    fclose(var->file);

    // Модальный ввод
    printf(T_CYAN "[нажмите 'w' для ввода текста, 'r' для чтения, 'q' для выхода]: \n" T_RESET);
    while ((var->mode = getchar()) != 'q') {
        if (var->mode == 'w') {
            printf(T_CYAN "[начните ввод (введите 'E' для выхода)]: \n" T_RESET);
            while (var->lineCount < MAX_LINES) {
                printf("%d: ", var->lineCount + 1);
                if (fgets(var->lines[var->lineCount], sizeof(var->lines[var->lineCount]), stdin) == NULL) {
                    fprintf(stderr, T_RED "[err]: [ошибка чтения строки.]\n" T_RESET);
                    break;
                }

                var->lines[var->lineCount][strcspn(var->lines[var->lineCount], "\n")] = 0;

                if (strlen(var->lines[var->lineCount]) == 0 || strcmp(var->lines[var->lineCount], "E") == 0) {
                    break;
                }

                strcpy(var->lines[var->lineCount], var->lines[var->lineCount]);
                var->lineCount++;

                if (var->lineCount >= MAX_LINES) {
                    printf(T_YELLOW "[warn]: [достигнуто максимальное количество строк. Завершите ввод]\n" T_RESET);
                    break;
                }
            }

            if (var->mode == 'r') {
                displayFile(var->filename);
            }
        }
    }

    // Сохранение изменений в файл
    var->file = fopen(var->filename, "w");
    if (var->file == NULL) {
        fprintf(stderr, T_RED "[err]: [не удалось открыть файл для записи: %s]\n" T_RESET, var->filename);
        return;
    }

    for (int i = 0; i < var->lineCount; i++) {
        fprintf(var->file, "%s\n", var->lines[i]);
    }
    fclose(var->file);

    printf(T_CYAN "[Редактор завершил работу]\n" T_RESET);
}

void print_fetch()
{
    printf(T_CYAN "      _____            User        DeltaDev\n" T_RESET);
    printf(T_CYAN "  /L  / /L L  /L       ---------------------------\n" T_RESET);
    printf(T_CYAN "  L L/ /  L L/ /       🖫 OS          DeltaOS Linux\n" T_RESET);
    printf(T_CYAN "   L/ /    L L/        🗃 Kernel      Linux\n" T_RESET);
    printf(T_CYAN "   / /      L L        🗔 Shell       dshell, bash\n" T_RESET);
    printf(T_CYAN "  / /  UwU   L L       🗂 PKGS        non\n" T_RESET);
    printf(T_CYAN " / /__________L L      🖷 Terminal    DeltaTerminal\n" T_RESET);
    printf(T_CYAN "/_/____________L_L     🖳 Host        Laptop\n" T_RESET);
}

#endif
