#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "lib/commands.h"

#define T_RED "\033[38;2;255;0;0m"
#define T_GREEN "\033[38;2;0;255;0m"
#define T_BLUE "\033[38;2;0;0;255m"
#define T_YELLOW "\033[38;2;255;255;0m"
#define T_CYAN "\033[38;2;0;255;255m"
#define T_RESET "\033[0m"
#define T_MAGENTA "\033[0;35m"

#ifndef ADD_H
#define ADD_H

#define MFNL 256 //maximum file name length
#define MAX_TOKEN_LENGTH 128
#define MAX_FOLDER_NAME_LENGTH 128
#define MAX_CONTENT_LENGTH 1024
#define MAX_LINES 512
#define MAX_LINE_LENGTH 1024

/*add file */
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

/*display content in file */
void displayFile(const char *fileName)
{
    FILE * file = fopen(fileName, "r");
    char line[MAX_LINES];

    if (file == NULL) {
        printf(T_RED "[ошибка открытия файла для чтения]\n" T_RESET);
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        printf("%s\n", line);
    }
    fclose(file);
}

/*delete file */
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

/*edit content in file */
void redactFile()
{
    /*variables */

    char fileName[MFNL];
    char token[MAX_TOKEN_LENGTH];
    FILE * file = fopen(fileName, "w");

    printf(T_CYAN "[впешите что будем редактировать]: \n" T_RESET);
    scanf("%s\n", token);
    if (strcmp(token, "file") == 0) {
        printf(T_CYAN "[впешите имя файла для редактирования]: \n" T_RESET);
        scanf("%s\n", fileName);
        editor();
    }
    if (file == NULL) {
        printf(T_RED "[ошибка открытия файла]\n" T_RESET);
        return;
    }
    else {
        printf(T_GREEN "[файл '%s' успешно открыт]\n" T_RESET, fileName);
    }
}

/*list files*/
void list()
{

}

#endif
