#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
using namespace std;
void Sheft()
{
    char* x="Mohamed";
    int y=0;
    for(int i=0;i<7;i++)
    {
        y=(int)x[i];
        y+=3;
        printf("%c\n",y);
    }
}
void Reverse()
{
    char* x="Mohamed";
    vector<char>xx;
    for(int i=6;i>=0;i--)
    {
        xx.push_back(x[i]);
    }
}
void SheftHalfByOne()
{
     string x2="";
    string x="mmmmbbbbb";
    int y=0;
    for(int i=x.size()/2;i<x.size();i++)
    {
        y=(int)x[i];
        y-=1;
        x[i]=(char)y;
        x2.push_back(x[i]);
    }

    cout<<x2;
}
main()
{
}
