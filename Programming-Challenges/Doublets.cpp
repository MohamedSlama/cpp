#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> vec;
    string word[4]={"boosted","roaster","coasted","roosted"};
    string x="boosted",y="roaster";
    vec.push_back(x);vec.push_back(y);
    char com1=x[0],com2=y[0];
    x[0]=com2;
    y[0]=com1;
   // cout << x << endl << y;
    for (unsigned int i=0 ; i< 4 ;i++)
    {
        string dd=word[i];
        if(x==dd)
            vec.push_back(dd);
        if(y==dd)
            vec.push_back(dd);
    }
    if(vec.size()-2<=0)
        cout << "No Solution" ;
    else{
        for (unsigned int i=0;i<vec.size();i++)
            {cout << vec[i] <<endl;}
    }
    return 0;
}
