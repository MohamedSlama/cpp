#include <iostream>

using namespace std;

int main()
{
    while(1){
    int x;
    cin>>x;
    int sum=0;
    int loop=1;
    do
    {
        sum+=loop;
        loop++;
    }while(x>sum);

    if(sum>x)loop-=1;
    cout<<loop-1<<endl;
    }
    return 0;
}
