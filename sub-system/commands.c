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

void intro()
{
    printf(T_CYAN "[==================================================================================]\n" T_RESET);
    printf(T_CYAN "                        [Инструкция по использованию ОС]                          \n" T_RESET);
    printf(T_CYAN "[==================================================================================]\n" T_RESET);
    printf(T_CYAN "Чтобы узнать команды просто напишите help и вы увидите большинство базовых комнад для работы с ОС.\n" T_RESET);
    printf(T_CYAN "Главное! Не пытайтесь установить пакет через команду install,  \n" T_RESET);
    printf(T_CYAN "она просто устанавлювает доп команды и всё.\n" T_RESET);
    printf(T_CYAN "И помните ОС предназначена для упрощённого использования терминала.\n" T_RESET);
}

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
    editorLogo();
    printf(T_BLUE "[текстовый редактор]\n" T_RESET);
    char lines[MAX_LINES][MAX_LINE_LENGTH];
    int lineCount = 0;
    char inputLine[MAX_LINE_LENGTH];
    char filename[100];

    // Запрос имени файла
    printf(T_CYAN "[Введите имя файла для редактирования]: " T_RESET);
    scanf("%s", filename);
    getchar(); // Удаляем символ новой строки после ввода имени файла

    // Открытие файла для чтения
    FILE *file = fopen(filename, "r");
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
    char mode;
    while ((mode = getchar()) != 'q') {
        if (mode == 'w') {
            printf(T_CYAN "[начните ввод (введите 'E' для выхода)]: \n" T_RESET);
            while (lineCount < MAX_LINES) {
                printf("%d: ", lineCount + 1);
                if (fgets(inputLine, sizeof(inputLine), stdin) == NULL) {
                    fprintf(stderr, T_RED "[err]: [ошибка чтения строки.]\n" T_RESET);
                    break;
                }

                inputLine[strcspn(inputLine, "\n")] = 0;

                if (strlen(inputLine) == 0 || strcmp(inputLine, "E") == 0) {
                    break;
                }

                strcpy(lines[lineCount], inputLine);
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
}

void print_fetch()
{
    printf(T_CYAN "                 ____________________________ \n" T_RESET);
    printf(T_CYAN "       //XX       deltaOSuser@DeltaOS~$ \n" T_RESET);
    printf(T_CYAN "      // XX       ---------------------------- \n" T_RESET);
    printf(T_CYAN "     //   XX      [OS]: [DeltaOS v 0.0.0.9-a] \n" T_RESET);
    printf(T_CYAN "    //     XX     [Host]: [Delta Laptop 15-jd0xxs] \n" T_RESET);
    printf(T_CYAN "   //       XX    [Shell]: [bash, dlt-shell] \n" T_RESET);
    printf(T_CYAN "  //         XX   [Theme]: [non-gui] \n" T_RESET);
    printf(T_CYAN " //           XX  [Terminal]: [dltOS-termianl] \n" T_RESET);
    printf(T_CYAN "//_____________XX [Icons]: [non-gui] \n" T_RESET);
}

void help()
{
    printf("[help page]\n");
    const char frame[128]= T_BLUE   "[============================================================================]" T_RESET;
    const char frm_2[128] = T_BLUE  "|                                                                            |" T_RESET;
    const char intr[250] = T_YELLOW "|      1.intro - иснтрукция по работе с ОС                                   |" T_RESET;
    const char calc[250] = T_YELLOW "|      2.calc - калькулятор                                                  |" T_RESET;
    const char edit[250] = T_YELLOW "|      3.dex - примитивный текстовый редактор                             |" T_RESET;
    const char help[250] = T_YELLOW "|      4.help - вывод всех команд                                            |" T_RESET;
    const char ftch[250] = T_YELLOW "|      5.dltfetch - выводит логотип ОС а также информация о компьютере и ос  |" T_RESET;
    const char exit[250] = T_YELLOW "|      6.ext - выход и завершение работы терминала                           |" T_RESET;
    const char fils[250] = T_YELLOW "|      7.lsf - список файлов в помощью которых работает ос                   |" T_RESET;
    const char add[250] =  T_YELLOW "|      8.add - добавление с файлов                                           |" T_RESET;
    const char del[250] =  T_YELLOW "|      9.del - удаление файлов                                               |" T_RESET;
    const char list[250] = T_YELLOW "|      10.list - список файлов которые вы создали                            |" T_RESET;
    const char red[250] = T_YELLOW  "|      11.redact - редактирование файла                                      |" T_RESET;
    const char dcf[250] = T_YELLOW  "|      12.display - просмотр содержимого файла                               |" T_RESET;
    const char frm_3[128] = T_BLUE  "|                                                                            |" T_RESET;
    const char frm_1[128] = T_BLUE  "[============================================================================]" T_RESET;

    printf("%s\n", frame);
    printf("%s\n", frm_2);
    printf("%s\n", intr);
    printf("%s\n", calc);
    printf("%s\n", edit);
    printf("%s\n", help);
    printf("%s\n", ftch);
    printf("%s\n", exit);
    printf("%s\n", add);
    printf("%s\n", del);
    printf("%s\n", red);
    printf("%s\n", dcf);
    printf("%s\n", fils);
    printf("%s\n", frm_3);
    printf("%s\n", frm_1);
}

void files()
{
    const char term_dot_c[128] = T_CYAN " [файлы Си]: \n [term.c] \n" T_RESET;
    const char comm_dot_c[115] = T_CYAN " [commands.c] \n" T_RESET;
    const char strt_dot_c[115] = T_CYAN " [start.c] \n" T_RESET;
    const char add_dot_c[115] = T_CYAN " [files.c] \n" T_RESET;
    const char add_dot_h[115] = T_CYAN " [files.h] \n" T_RESET;
    const char strt_dot_h[115] = T_CYAN " [start_screen.h]\n" T_RESET;
    const char comm_dot_h[115] = T_CYAN " [commands.h] \n" T_RESET;
    const char start_dot_sh[115] = T_GREEN "[bash]: \n [build.sh] \n" T_RESET;
    const char logo_dot_txt[115] = T_CYAN "[txt]: \n [logo.txt] \n" T_RESET;
    const char bin_file[115] = T_MAGENTA "[bin]: \n [term.o]\n" T_RESET;

    printf("%s", term_dot_c);
    printf("%s", comm_dot_c);
    printf("%s", comm_dot_h);
    printf("%s", add_dot_c);
    printf("%s", add_dot_h);
    printf("%s", strt_dot_h);
    printf("%s", strt_dot_c);
    printf("%s", start_dot_sh);
    printf("%s", logo_dot_txt);
    printf("%s", bin_file);
}

#endif
