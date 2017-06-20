#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> vec;
    int key;
    while(cin>>key)
    {
        if(key==0)
        {system("cls");break;}
        vec.push_back(key);
    }
    sort(vec.begin(),vec.end());
    cout <<vec[vec.size()-1]-vec[0];

    return 0;
}
