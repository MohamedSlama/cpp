#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Rate{
    private:
        int height,weight;
        string Fname,Lname;
    public:
        Rate(int h,int w,string F,string L){
            height=h,weight=w,Fname=F,Lname=L;
        }
        int Getheight(){return height;}
        int Getweight(){return weight;}
        string GetLname(){return Lname;}
        string GetFname(){return Fname;}
        void Print()
        {
            cout << height << "," << weight << "," << Lname << "," << Fname;
        }
};
bool stsort(string w1,string w2)
{
    for(unsigned int i=0;i<w1.size();i++)
    {
            if(w1[i]>w2[i])
                return 1;
    }
    return 0;
}
int main()
{
    vector<Rate> vec;
    Rate r1(180,100,"gorge","bash");
    Rate r2(180,100,"koko","bosh");
    Rate r3(180,100,"lolo","bosh");
    Rate r4(180,100,"gorgr","bash");
    vec.push_back(r1);vec.push_back(r2);vec.push_back(r3);vec.push_back(r4);

    for(unsigned int i=0;i<vec.size();i++)
    {
        for(unsigned int j=0; j<vec.size();j++)
        {
            if(vec[i].Getheight()>vec[j].Getheight())
                {swap(vec[i],vec[j]);}
            else if(vec[i].Getheight()==vec[j].Getheight())
            {
                if (vec[i].Getweight()>vec[j].Getweight())
                    {swap(vec[i],vec[j]);}
                else if(vec[i].Getweight() == vec[j].Getweight())
                {
                    if(stsort(vec[i].GetLname(),vec[j].GetLname()))
                        {swap(vec[i],vec[j]);}
                    else if(vec[i].GetLname()==vec[j].GetLname())
                    {
                        if(stsort(vec[i].GetFname(),vec[j].GetFname()))
                                {swap(vec[i],vec[j]);}
                    }
                }
            }
        }

    }
    for (unsigned int o=0;o<vec.size();o++)
    {
        vec[o].Print();
        cout << endl;
    }
    return 0;
}
