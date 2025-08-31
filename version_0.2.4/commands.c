#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define T_GREEN "\033[0;32m"
#define T_RED   "\033[0;31m"
#define T_CYAN  "\033[0;36m"
#define T_BLUE  "\033[0;34m"
#define T_YELLOW "\033[1;33m"
#define T_RESET "\033[0m"

#define MAX_LINES 512
#define MAX_LINE_LENGTH 1024

void edit()
{
    printf(T_BLUE "[текстовый редактор]\n" T_RESET);
    char lines[MAX_LINES][MAX_LINE_LENGTH];
    int lineCount = 0;
    char inputLine[MAX_LINE_LENGTH];
    bool emptyLineEntered = false;

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
        }

        strcpy(lines[lineCount], inputLine);
        lineCount++;

        if(lineCount >= MAX_LINES) {
            printf(T_YELLOW "[warn]: [достигнуто максимальное количество строк. Завершите ввод\n" T_RESET);
            break;
        }

        if (strcmp(inputLine, "x") == 0) {
            emptyLineEntered = true;
            break;
        }

    }

    printf(T_CYAN "[Редактор завершил работу]\n" T_RESET);
}


void files()
{
    const char term_dot_c[128] = T_CYAN " [файлы Си]: \n [term.c] \n" T_RESET;
    const char comm_dot_c[115] = T_CYAN " [commands.c] \n" T_RESET;
    const char strt_dot_c[115] = T_CYAN " [start.c] \n" T_RESET;
    const char strt_dot_h[115] = T_CYAN " [start_screen.h]" T_RESET;
    const char comm_dot_h[115] = T_CYAN " [commands.h] \n" T_RESET;
    const char start_dot_sh[115] = T_CYAN "[bash]: \n [DltOS.sh] \n" T_RESET;
    const char logo_dot_txt[115] = T_CYAN "[txt]: \n [logo.txt] \n" T_RESET;

    printf("%s", term_dot_c);
    printf("%s", comm_dot_c);
    printf("%s", comm_dot_h);
    printf("%s\n", strt_dot_h);
    printf("%s\n", strt_dot_c);
    printf("%s", start_dot_sh);
    printf("%s", logo_dot_txt);
}

void print_fetch()
{
    printf(T_CYAN "                 ____________________________ \n" T_RESET);
    printf(T_CYAN "      //XX       deltaOSuser@DeltaOS~$ \n" T_RESET);
    printf(T_CYAN "     // XX       ---------------------------- \n" T_RESET);
    printf(T_CYAN "    //   XX      [OS]: [DeltaOS v 0.2.4] \n" T_RESET);
    printf(T_CYAN "   //     XX     [Host]: [Delta Laptop 15-jd0xxs] \n" T_RESET);
    printf(T_CYAN "  //       XX    [Shell]: [bash] \n" T_RESET);
    printf(T_CYAN " //         XX   [Theme]: [dark-with-blur] \n" T_RESET);
    printf(T_CYAN "//___________XX  [Terminal]: [dltOS-termianl] \n" T_RESET);
}

void help()
{
    printf("[help page]\n");
    const char frame[128]= T_BLUE   "[============================================================================]" T_RESET;
    const char frm_2[128] = T_BLUE  "|                                                                            |" T_RESET;
    const char calc[250] = T_YELLOW "|      1.calc - калькулятор                                                  |" T_RESET;
    const char edit[250] = T_YELLOW "|      2.edit - примитивный текстовый редактор                               |" T_RESET;
    const char help[250] = T_YELLOW "|      3.help - вывод всех команд                                            |" T_RESET;
    const char ftch[250] = T_YELLOW "|      4.dltfetch - выводит логотип ОС а также информация о компьютере и ос  |" T_RESET;
    const char exit[250] = T_YELLOW "|      5.ext - выход и завершение работы терминала                           |" T_RESET;
    const char fils[250] = T_YELLOW "|      6.lf - список файлов в помощью которых работает ос                    |" T_RESET;
    const char frm_3[128] = T_BLUE  "|                                                                            |" T_RESET;
    const char frm_1[128] = T_BLUE  "[============================================================================]" T_RESET;

    printf("%s\n", frame);
    printf("%s\n", frm_2);
    printf("%s\n", calc);
    printf("%s\n", edit);
    printf("%s\n", help);
    printf("%s\n", ftch);
    printf("%s\n", exit);
    printf("%s\n", fils);
    printf("%s\n", frm_3);
    printf("%s\n", frm_1);
}
