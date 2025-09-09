#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "lib/commands.h"

#define T_GREEN "\033[0;32m"
#define T_RED   "\033[0;31m"
#define T_CYAN  "\033[0;36m"
#define T_BLUE  "\033[0;34m"
#define T_YELLOW "\033[1;33m"
#define T_RESET "\033[0m"

#ifndef ADD_H
#define ADD_H

#define MFNL 256
#define MAX_TOKEN_LENGTH 128
#define MAX_FOLDER_NAME_LENGTH 128

void add()
{
    /*variables*/
    char fileName[MFNL];
    char token[MAX_TOKEN_LENGTH];
    char folderName[MAX_FOLDER_NAME_LENGTH];
    FILE * file;

    printf(T_CYAN "[введите что будем добавлять]: \n" T_RESET);
    scanf("%s\n", &*token);
    if (strcmp(token, "file") == 0) {
        printf(T_CYAN "[введите имя файла]: \n" T_RESET);
        scanf("%s\n", &*fileName);
        printf(T_CYAN "[файл '%s' создан]\n" T_RESET, fileName);

        int isCreated = 0;
        file = fopen(fileName, "w");
        if (file == NULL) {
            printf(T_RED "[ошибка создания файла]\n" T_RESET);
            isCreated = 1;
        }
        else {
            fclose(file);
            isCreated = 1;
        }
    }
}

void del()
{
    /*variables*/
    char fileName[MFNL];
    char token[MAX_TOKEN_LENGTH];
    char folderName[MAX_FOLDER_NAME_LENGTH];
    FILE * file;

    printf(T_CYAN "[введите что будем удалять]: \n" T_RESET);
    scanf("%s\n", &*token);
    if (strcmp(token, "file") == 0) {
        printf(T_CYAN "[введите имя файла]: \n" T_RESET);
        scanf("%s\n", &*fileName);

        int isDeleted = 0;
        if (remove(fileName) == 0) {
            printf(T_GREEN "[файл '%s' удалён!]\n" T_RESET, fileName);
        }
        else {
            printf(T_RED "[ошибка удаления файла]\n" T_RESET);
        }
    }
}

void redact()
{
    char fileName[MFNL];
    char token[MAX_TOKEN_LENGTH];
    FILE * file = fopen(fileName, "w");

    printf(T_CYAN "[впешите что будем редактировать]: \n" T_RESET);
    scanf("%s\n", token);
    if (strcmp(token, "file") == 0) {
        printf(T_CYAN "[впешите имя файла для редактирования]: \n" T_RESET);
        scanf("%s\n", fileName);
        edit();
    }
    if (file == NULL) {
        printf(T_RED "[ошибка открытия файла]\n" T_RESET);
        return;
    }
    else {
        printf(T_GREEN "[файл '%s' успешно открыт]\n" T_RESET, fileName);
    }

}

#endif
