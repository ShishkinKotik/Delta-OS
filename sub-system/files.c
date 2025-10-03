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
#define MAX_FOLDER_LENGTH 128

struct FileExplorer {
    /*variables*/
    char fileName[MFNL];
    char token[MAX_TOKEN_LENGTH];
    char line[MAX_LINES];
    char folderName[MAX_FOLDER_LENGTH];
    FILE * file;
    int isCreated;
    int isDeleted;
};

/*add file */
void add()
{
    struct FileExplorer var = {0};

    printf(T_CYAN "[введите что будем добавлять]: \n" T_RESET);
    scanf("%s\n", var.token);
    if (strcmp(var.token, "file") == 0) {
        printf(T_CYAN "[🖹 введите имя файла]: \n" T_RESET);
        scanf("%s\n", var.fileName);
        printf(T_CYAN "[файл '%s' создан]\n" T_RESET, var.fileName);

        int isCreated = 0;
        var.file = fopen(var.fileName, "w");
        if (var.file == NULL) {
            printf(T_RED "[ошибка создания файла]\n" T_RESET);
            isCreated = 1;
        }
        else {
            fclose(var.file);
            isCreated = 1;
        }
    }
}

/*display content in file */
void displayFile(const char *fileName)
{
    struct FileExplorer var = {0};

    if (var.file == NULL) {
        printf(T_RED "[ошибка открытия файла для чтения]\n" T_RESET);
        return;
    }

    while (fgets(var.line, sizeof(var.line), var.file)) {
        printf("%s\n", var.line);
    }
    fclose(var.file);
}

/*delete file */
void del()
{
    struct FileExplorer var = {0};

    printf(T_CYAN "[введите что будем удалять]: \n" T_RESET);
    scanf("%s\n", &*var.token);
    if (strcmp(var.token, "file") == 0) {
        printf(T_CYAN "[🖹 введите имя файла]: \n" T_RESET);
        scanf("%s\n", &*var.fileName);

        int isDeleted = 0;
        if (remove(var.fileName) == 0) {
            printf(T_GREEN "[файл '%s' удалён!]\n" T_RESET, var.fileName);
        }
        else {
            printf(T_RED "[ошибка удаления файла]\n" T_RESET);
        }
    }
}

/*list files*/
void list()
{

}

#endif
