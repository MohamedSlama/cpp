#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
using namespace std;

int main()
{
        string st="",c;
        while(1)
        {
            getline(cin,c);
            if (c=="")break;
            st+='\\';
            st+=c;
        }
        string z="";
        for(int i=0;i<st.size();i++)
        {

            char ch=st[i];
            switch(ch)
            {
                case 'a': ch='x';break;
                case 'b': ch='k';break;
                case 'c': ch='q';break;
                case 'd': ch='s';break;
                case 'e': ch='u';break;
                case 'f': ch='p';break;
                case 'g': ch='m';break;
                case 'h': ch='j';break;
                case 'i': ch='f';break;
                case 'j': ch='g';break;
                case 'k': ch='d';break;
                case 'l': ch='b';break;
                case 'm': ch='e';break;
                case 'n': ch='h';break;
                case 'o': ch='c';break;
                case 'p': ch='a';break;
                case 'q': ch='y';break;
                case 'r': ch='r';break;
                case 's': ch='v';break;
                case 't': ch='o';break;
                case 'u': ch='i';break;
                case 'v': ch='n';break;
                case 'w': ch='z';break;
                case 'x': ch='t';break;
                case 'y': ch='l';break;
                case 'z': ch='w';break;
                case ' ': ch=' ';break;
                case '\\':ch='\n';break;
                default : continue;
            }
            z.push_back(ch);
        }
        if(z=="" || z=="\n")cout<<"No solution";
        cout<<z;
    return 0;
}
