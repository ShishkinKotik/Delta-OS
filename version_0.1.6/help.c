#include <stdio.h>

#define T_BLUE  "\033[0;34m"
#define T_YELLOW "\033[1;33m"
#define T_RESET "\033[0m"

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
