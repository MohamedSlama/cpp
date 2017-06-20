#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
int main()
{
    /*string x ;
    string y ;
    cin >> x >> y;*/
    string x("mmmmoerwerhamm31dsmmed"),y("srwerew123daslama");
    string l;
    for(int i=0;i<x.size();i++)
    {
        for(int j=0;j<y.size();j++)
        {
            if(x[i]==y[j])
                l.push_back(x[i]);
        }
    }
    cout << l << l.size() <<endl;
    string str1;str1.push_back(l[0]);
    int siz=l.size();
    bool z=false;
    for (int i=1;i<siz;i++)
    {
        int x=str1.size();
        z=true;
        for (int j=0;j<x;j++)
        {
            if(l[i]==str1[j])
            {z=false; break;}
        }
        if(z){str1.push_back(l[i]);}
    }
    cout << str1;

    return 0;
}
