// lab 5 Var 10
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
 
int main()
{
    ifstream fin("input1.txt");
    ofstream fout("output1.txt");
    if (!fin.is_open())
    {
        fout << "Error opening file" << endl;
    }
    else
    {
        string str;
        bool notagroup = true;
        bool group = false;
        while (getline(fin, str))
        {
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] != ' ')
                {
                    if ((str[i] == '/') && (str[i + 1] == '/'))
                    {
                        str.erase(0, i);
                        group = true;
                        if ((notagroup) && (group))
                        {
                            fout << "Comments" << endl;
                            group = false;
                            notagroup = false;
                        }
                        fout << str << endl;
                        break;
                    }
                    else
                    {
                        notagroup = true;
                        group = false;
                        break;
                    }
 
                }
            }
        }
        fin.close();
        fout.close();
    }
 
    return 0;
}
