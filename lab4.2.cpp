#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[300];
    cin >> str;

    for(int i = 0; i < strlen(str);)
    {
        char* word_start = str + i;
        char* word_end = str + i;
        while (*word_end != ' ' || *word_end != '\0'){
            ++word_end;
            ++i;
    }


      bool isOnlyDigits = true;
      int zerosCount = 0;
      for (i = 0; str[i] != '\0'; i++) {
          if ( str[i]>= '0' && str[i]<= '9'){
              isOnlyDigits = true;
          } else { isOnlyDigits = false;}
      }
      while  (isOnlyDigits == true){
      if (str[i] == '0') {
      zerosCount++;
     }
     }

        while(str[i] == ' '){
            ++i;
        }
}
    return 0;
}

