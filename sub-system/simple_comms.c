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
    const char frame[250]= T_BLUE   "[==========================================================================================================]" T_RESET;
    const char frm_2[250] = T_BLUE  "|                                                                            |                             |" T_RESET;
    const char intr[250] = T_YELLOW "|      1.intro - инструкция по работе с ОС                                   | 12.gtd - переход в папку.   |" T_RESET;
    const char calc[250] = T_YELLOW "|      2.calc - калькулятор                                                  | 13.std - вод текущей папки. |" T_RESET;
    const char edit[250] = T_YELLOW "|      3.dex - примитивный текстовый редактор                                |                             |" T_RESET;
    const char help[250] = T_YELLOW "|      4.help - вывод всех команд                                            |                             |" T_RESET;
    const char ftch[250] = T_YELLOW "|      5.dlt-fetch - выводит логотип ОС а также информация о компьютере и ос |                             |" T_RESET;
    const char exit[250] = T_YELLOW "|      6.quit - выход и завершение работы терминала                          |                             |" T_RESET;
    const char fils[250] = T_YELLOW "|      7.lsf - список файлов в помощью которых работает ос                   |                             |" T_RESET;
    const char add[250] =  T_YELLOW "|      8.add - добавление с файлов                                           |                             |" T_RESET;
    const char del[250] =  T_YELLOW "|      9.del - удаление файлов                                               |                             |" T_RESET;
    const char list[250] = T_YELLOW "|      10.list - список файлов которые вы создали                            |                             |" T_RESET;
    const char dcf[250] = T_YELLOW  "|      11.display - просмотр содержимого файла                               |                             |" T_RESET;
    const char frm_3[250] = T_BLUE  "|                                                                            |                             |" T_RESET;
    const char frm_1[250] = T_BLUE  "[==========================================================================================================]" T_RESET;

    printf("%s\n", frame);
    printf("%s\n", frm_2);
    printf("%s\n", intr);
    printf("%s\n", calc);
    printf("%s\n", edit);
    printf("%s\n", help);
    printf("%s\n", ftch);
    printf("%s\n", exit);
    printf("%s\n", fils);
    printf("%s\n", add);
    printf("%s\n", del);
    printf("%s\n", list);
    printf("%s\n", dcf);
    printf("%s\n", frm_3);
    printf("%s\n", frm_1);
}

void files()
{
    const char frame[128] =        T_CYAN    "[===================]\n" T_RESET;
    const char c_lang[128] =       T_CYAN    "| [C language]      |\n" T_RESET;
    const char term_dot_c[128] =   T_CYAN    "|  [term.c]         |\n" T_RESET;
    const char comm_dot_c[115] =   T_CYAN    "|  [commands.c]     |\n" T_RESET;
    const char strt_dot_c[115] =   T_CYAN    "|  [start.c]        |\n" T_RESET;
    const char add_dot_c[115] =    T_CYAN    "|  [files.c]        |\n" T_RESET;
    const char add_dot_h[115] =    T_CYAN    "|  [files.h]        |\n" T_RESET;
    const char strt_dot_h[115] =   T_CYAN    "|  [start_screen.h] |\n" T_RESET;
    const char comm_dot_h[115] =   T_CYAN    "|  [commands.h]     |\n" T_RESET;
    const char bash[115] =         T_GREEN   "| [bash]            |\n" T_RESET;
    const char start_dot_sh[115] = T_GREEN   "|  [build.sh]       |\n" T_RESET;
    const char text[115] =         T_YELLOW  "| [txt]             |\n" T_RESET;
    const char logo_dot_txt[115] = T_YELLOW  "|   [logo.txt]      |\n" T_RESET;
    const char bin[115] =          T_MAGENTA "| [binary]          |\n" T_RESET;
    const char bin_file[115] =     T_MAGENTA "|  [term.o]         |\n" T_RESET;
    const char end_frame[114] =    T_CYAN    "[===================]\n" T_RESET;

    printf("%s", frame);
    printf("%s", c_lang);
    printf("%s", term_dot_c);
    printf("%s", comm_dot_c);
    printf("%s", comm_dot_h);
    printf("%s", add_dot_c);
    printf("%s", add_dot_h);
    printf("%s", strt_dot_h);
    printf("%s", strt_dot_c);
    printf("%s", bash);
    printf("%s", start_dot_sh);
    printf("%s", text);
    printf("%s", logo_dot_txt);
    printf("%s", bin);
    printf("%s", bin_file);
    printf("%s", end_frame);
}


void title()
{
    printf(T_CYAN " ___________       ___________  ___          _________________            ____ \n" T_RESET);
    printf(T_CYAN " | |      XX       | |     | |  |  |         |______   ______|            //XX  \n" T_RESET);
    printf(T_CYAN " | |       XX      | |     | |  |  |                | |                  //  XX  \n" T_RESET);
    printf(T_CYAN " | |        XX     | |     | |  |  |                | |                 //    XX  \n" T_RESET);
    printf(T_CYAN " | |         XX    |_|_____|_|  |  |                | |                //      XX  \n" T_RESET);
    printf(T_CYAN " | |          XX   | |          |  |                | |               //        XX  \n" T_RESET);
    printf(T_CYAN " | |           XX  | |          |  |                | |              //==========XX  \n" T_RESET);
    printf(T_CYAN " | |           //  | |     ___  |  |      ___       | |             //            XX  \n" T_RESET);
    printf(T_CYAN " | |          //   | |     | |  |  |      | |       | |            //              XX  \n" T_RESET);
    printf(T_CYAN " | |_________//    |_|_____|_|  |__|______|_|       |_|           //                XX  \n" T_RESET);
}

void welcome()
{
    const char frstln[] = ".____________________________.";
    const char newlin[] = "|                            |";
    const char scndln[] = "|FFFFFFFFFFFFFFFFFFFFFFFFFFFF|";
    const char thrdln[] = "|[ Welcome to the DeltaOS!  ]|";
    const char frthln[] = "|FFFFFFFFFFFFFFFFFFFFFFFFFFFF|";
    const char endlne[] = "|____________________________|";

    printf("%s\n", frstln);
    printf("%s\n", newlin);
    printf("%s\n", thrdln);
    printf("%s\n", endlne);
    printf(T_CYAN "[впешите help для того чтобы узнать большинство команд]\n" T_RESET);
}

void LoadScreen()
{
    printf(T_BLUE "[Start loading of OS]\n" T_RESET);
    printf(T_GREEN "[OK]: Compiling term.c\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading commands\n" T_RESET);
    printf(T_GREEN "[OK]: Commands is load\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command help\n" T_RESET);
    printf(T_GREEN "[OK]: Command help is load\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command calc\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command display\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command display\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command redact\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command redact\n" T_RESET);
    printf(T_GREEN "[OK]: Command calc is load\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command edit\n" T_RESET);
    printf(T_GREEN "[OK]: Command editor is load\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command dltfetch\n" T_RESET);
    printf(T_GREEN "[OK]: Command dltfetch is load\n" T_RESET);
    printf(T_GREEN "[OK]: Start loading command ext\n" T_RESET);
    printf(T_GREEN "[OK]: Command ext is load\n");
    printf(T_GREEN "[OK]: Start loading command add\n" T_RESET);
    printf(T_GREEN "[OK]: Command add is load\n");
    printf(T_GREEN "[OK]: Start loading command lsf\n" T_RESET);
    printf(T_GREEN "[OK]: Command lsf is load\n");
    printf(T_GREEN "[OK]: Initialization working all commands\n" T_RESET);
    printf(T_GREEN "[OK]: Optimization working all commands\n" T_RESET);
    printf(T_BLUE "[Loading is end!]\n" T_RESET);
}
