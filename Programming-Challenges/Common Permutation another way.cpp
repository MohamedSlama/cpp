#include <iostream>
#include <string>

using namespace std;
int main()
{
    string x,y;
    getline(cin,x);
    getline(cin,y);
    string z="";
    bool cond=false;
    char letter='\0';
    int coun=0;
    for(unsigned int i=0;i<x.size();i++)
    {
        for(unsigned int j=0;j<y.size();j++)
        {
            if(x[i]==y[j])
            {
                letter=y[j];
                y[j]='\0';
                cond=true;
            }
        }
        if(cond){z.push_back(letter);cond=false;
        coun+=1;if(coun>=26)break;
        }
    }
    cout << z;

    return 0;
}


