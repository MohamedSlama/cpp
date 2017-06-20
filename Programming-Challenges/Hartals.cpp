#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<int> GenerateNumbers(const int value,const int limit)
{
    vector<int> x;
    for(int i=value;i<=limit;i+=value)
    {
        x.push_back(i);
    }
    return x;
}
vector<int> Final(const int value,const int limit)
{

    vector<int> x=GenerateNumbers(value,limit);
    vector<int> global;
    for(unsigned int i=0; i< x.size(); i++)
    {
        if(x[i]%7 !=0 && (x[i]-6)%7 !=0)
            global.push_back(x[i]);
    }
    return global;
}
list<int> l;
void Result(vector<int> r)
{
    for(unsigned int i=0;i<r.size();i++)
    {
        l.remove(r[i]);
        l.push_back(r[i]);
    }
}
int main()
{
    int input , limit;
    cout<<"Enter Number Of Days: ";
    cin>> limit;
    cout<<"Enter Number Of strikes: ";
    cin>> input ;
    while(input!=0)
    {
        int h;
        cout<<"h:";
        cin>>h;
        Result(Final(h,limit));
        input--;
    }
    cout << "Output= " << l.size() << endl;
    return 0;
}
