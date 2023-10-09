//Lab 4 Var 10 Point 2
#include <iostream>
//Считаем нули в одном слове.
int count_char_in_word(char*& s, char c)
{   while(*s == ' ') ++s;
    int cnt = 0;
    while(*s != ' ' && *s != '\n' && *s)
    {   if(!isdigit(*s))
        {   while(*s != ' ' && *s != '\n' && *s) ++s;
            return 0;
        }
        if(*s++ == c) ++cnt;
    }
    while(*s == ' ') ++s;
    return cnt;
}

// Печатаем предопоследнее слово, если есть одинаковые результаты, или просто печатаем результат

void print_res_word_in_str(char* s, char c, int cnt_equal)
{   if(cnt_equal == 0)
    {   std::cout << "NO!\n\n";
        return;
    }

    char* last1 = NULL;
    char* last2 = NULL;
    while(*s)
    {   char* t = s;
        int cnt = count_char_in_word(s, c);
        if(cnt == cnt_equal)
        {   last1 = last2;
            last2 = t;
        }
    }

    if(last1) last2 = last1;

    s = last2;

    std::cout << "Maximum number of zeros in a word: ";
    while(*s == ' ') ++s;
    while(*s != ' ' && *s != '\n' && *s)
    {   std::cout << *s++;
    }
    std::cout << "\n\n";
}

int main()
{
    const int MAX(300);

    // true для ручного ввода
    std::cout << "Test string: ";
    char string[MAX] =
            {"dasydb02 200"}; //200

    std::cout << string << "\n\n";

    while(true) {
        int cntmax = 0;
        char *s = string;

        // Поиск макс кол-ва нулей для слова
        while (*s) {
            int cnt = count_char_in_word(s, '0');
            if (cnt > cntmax) {
                cntmax = cnt;
            }
        }

        std::cout << "cntmax: " << cntmax << '\n';

        print_res_word_in_str(string, '0', cntmax);

        std::cout << "Enter the string:\n";
        std::cin.getline(string, MAX, '\n');
        if(string[0] == 'q'){
            break;
        }
    }
    return 0;
}
