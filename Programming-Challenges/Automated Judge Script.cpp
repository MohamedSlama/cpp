#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string x="mohamed2 0 1 55";
    string y="mohamed2 0 1 55 5";
    if(x==y)
    {
        cout << "Correct Answer";
        return 0;
    }
    vector<int>vx,vy;
    for (int i=0;i<x.size();i++)
        if(isdigit((int)x[i]))vx.push_back(x[i]);
    for (int i=0;i<y.size();i++)
        if(isdigit((int)y[i]))vy.push_back(y[i]);

    if(vx.size() != vy.size())
    {
            cout << "Wrong Answer";
            return 0;
    }
    for (int i=0;i<vx.size();i++)
    {
        if(vx[i] != vy[i])
        {
            cout << "Wrong Answer";
            return 0;
        }
    }
    cout << "Presentation Error" << endl;
    return 0;
}
