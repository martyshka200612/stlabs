//Lab 4 Var 10 Point 1
#include <iostream>
#include <cstring>
using namespace std;

size_t _strspn(const char *str1, const char *str2);
size_t my_strlen(const char *s) {
    const char* cur = s;
    for (; *cur; ++cur);
    return cur - s;
}

int main()
{
    const char *string = "123463acdef";
    const char *digits = "0123456789";
    size_t length = _strspn(string, digits);
    printf("Initial Substring Length: %zu\n", length);
    return 0;
}

size_t _strspn(const char *str1, const char *str2) {
    size_t initial_length = 0;
    size_t len1 = my_strlen(str1);
    size_t len2 = my_strlen(str2);
    for (size_t i = 0; i < len1; i++) {
        bool found_match = false;
        for (size_t j = 0; j < len2; j++) {
            if (str2[j] == str1[i]) {
                found_match = true;
                break;
            }
        }
        if (!found_match)
            break;
        else
            initial_length++;
    }

    return initial_length;

}
