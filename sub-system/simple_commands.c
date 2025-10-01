#include <stdio.h>

#define T_RED "\033[38;2;255;0;0m"
#define T_GREEN "\033[38;2;0;255;0m"
#define T_BLUE "\033[38;2;0;0;255m"
#define T_YELLOW "\033[38;2;255;255;0m"
#define T_CYAN "\033[38;2;0;255;255m"
#define T_RESET "\033[0m"
#define T_MAGENTA "\033[0;35m"

void intro()
{
    printf(T_CYAN "[==================================================================================]\n" T_RESET);
    printf(T_CYAN "|                       [Инструкция по использованию ОС]                           |\n" T_RESET);
    printf(T_CYAN "[==================================================================================]\n" T_RESET);
    printf(T_CYAN "Чтобы узнать команды просто напишите help и вы увидите большинство базовых комнад для работы с ОС.\n" T_RESET);
    printf(T_CYAN "Главное! Не пытайтесь установить пакет через команду install,  \n" T_RESET);
    printf(T_CYAN "она просто устанавлювает доп команды и всё.\n" T_RESET);
    printf(T_CYAN "И помните ОС предназначена для упрощённого использования терминала.\n" T_RESET);
}

void help()
{
    printf("[help page]\n");
    const char frame[128]= T_BLUE   "[================================================================================]" T_RESET;
    const char frm_2[128] = T_BLUE  "|                                                                                |" T_RESET;
    const char intr[250] = T_YELLOW "|      1.intro - иснтрукция по работе с ОС                                       |" T_RESET;
    const char calc[250] = T_YELLOW "|      🖩 2.calc - калькулятор                                                    |" T_RESET;
    const char edit[250] = T_YELLOW "|      🗒 3.dex - примитивный текстовый редактор                                  |" T_RESET;
    const char help[250] = T_YELLOW "|      ǂ 4.help - вывод всех команд                                               |" T_RESET;
    const char ftch[250] = T_YELLOW "|      🖮 5.dlt-fetch - выводит логотип ОС а также информация о компьютере и ос   |" T_RESET;
    const char exit[250] = T_YELLOW "|      6.ext - выход и завершение работы терминала                                |" T_RESET;
    const char fils[250] = T_YELLOW "|      🗉 7.lsf - список файлов в помощью которых работает ос                      |" T_RESET;
    const char add[250] =  T_YELLOW "|      🖹 8.add - добавление с файлов                                              |" T_RESET;
    const char del[250] =  T_YELLOW "|      🖹 9.del - удаление файлов                                                  |" T_RESET;
    const char list[250] = T_YELLOW "|      🗉 10.list - список файлов которые вы создали                               |" T_RESET;
    const char red[250] = T_YELLOW  "|      🖹 11.redact - редактирование файла                                         |" T_RESET;
    const char dcf[250] = T_YELLOW  "|      🖹 12.display - просмотр содержимого файла                                  |" T_RESET;
    const char frm_3[128] = T_BLUE  "|                                                                                 |" T_RESET;
    const char frm_1[128] = T_BLUE  "[==================================================================================]" T_RESET;

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
