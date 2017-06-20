#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define SIZE 4
using namespace std;
struct Dir{
    char current,up,down,left,right,ur,ul,dr,dl;
};

struct cond{
    bool up,down,left,right,ur,ul,dr,dl;
};

void fun(char ch,Dir &d, int &in1,int &in2)
{
        char arr[3][4]={  {'a','a','c','d'},
                                    {'x','y','z','g'},
                                    {'a','a','c','d'}};

    for(signed int x=in1;x<SIZE-1;x++)
    {
        for(signed int y=in2;y<SIZE;y++)
            {
                if(arr[x][y]==ch)
                    {
                        int i=x,j=y;
                        in1=x,in2=y;
                        d.up      =arr[i-1][j];
                        d.down    =arr[i+1][j];
                        d.left    =arr[i][j-1];
                        d.right   =arr[i][j+1];
                        d.ul      =arr[i-1][j-1];
                        d.ur      =arr[i-1][j+1];
                        d.dl      =arr[i+1][j-1];
                        d.dr      =arr[i+1][j+1];
                        return;
                    }

            }
    }
}
void fun2(Dir d,string ch,int &i, int &j)
{
            if(d.up==ch[1])    {i=i-1;j=j;}
       else if(d.down==ch[1])  {i=i+1;j=j;}
       else if(d.left==ch[1])  {i=i;j=j-1;}
       else if(d.right==ch[1]) {i=i;j=j+1;}
       else if(d.dl==ch[1])    {i=i+1;j=j-1;}
       else if(d.dr==ch[1])    {i=i+1;j=j+1;}
       else if(d.ul==ch[1])    {i=i-1;j=j-1;}
       else if(d.ur==ch[1])    {i=i-1;j=j+1;}

}
void NumOfEl(char ch,vector<int> &vx,vector<int> &vy)
{
    char arr[SIZE-1][SIZE+1]={      {'a','a','c','d'},
                                    {'x','y','z','g'},
                                    {'a','a','c','d'}};
    for(signed int x=0;x<SIZE-1;x++)
    {
        for(signed int y=0;y<SIZE;y++)
            {
                if(arr[x][y]==ch)
                    {
                        vx.push_back(x);
                        vy.push_back(y);
                    }

            }
    }
}
void sear(int &i,int &j,string ch,int &pointer,cond c)
{
    char arr[SIZE-1][SIZE+1]={      {'a','a','c','d'},
                                    {'x','y','z','g'},
                                    {'a','a','c','d'}};
        //(1,1,'ayr',2,'dr',size=3)
            for(int x=pointer;x<ch.size();x++){
                if(arr[i][j]==ch[pointer])
                    {
                             if(c.up)i-=1;
                        else if(c.down)i+=1;
                        else if(c.left)j-=1;
                        else if(c.right)j+=1;
                        else if(c.dl){i+=1;j-=1;}
                        else if(c.dr){i+=1;j+=1;}
                        else if(c.ul){i-=1;j-=1;}
                        else if(c.ur){i-=1;j+=1;}
                        pointer+=1;
                        if(pointer>=ch.size())break;
                    }
            }
}
void test(string input,Dir &st2,cond &c,int &x,int &y)
{
    int i=0,j=0;
    fun2(st2,input,i,j);
         if(i<0&&j==0)/*up*/{c.up=true;x-=2;}
    else if(i>0&&j==0)/*down*/{c.down=true;x+=2;}
    else if(i==0&&j<0)/*left*/{c.left=true;y-=2;}
    else if(i==0&&j>0)/*right*/{c.right=true;y+=2;}
    else if(i>0&&j>0)/*dr*/{c.dr=true;x+=2;y+=2;}
    else if(i>0&&j<0)/*dl*/{c.dl=true;x+=2;y-=2;}
    else if(i<0&&j>0)/*ur*/{c.ur=true;x-=2;y+=2;}
    else if(i<0&&j<0)/*ul*/{c.ul=true;x-=2;y-=2;}

}

int main()
{

/*  {'a','a','c','d'},
    {'x','y','z','g'},
    {'a','a','c','d'}   */
    string input="aac";
    vector<int> vx,vy;
    NumOfEl(input[0],vx,vy);
    Dir st;
    int ll=0;
    while(ll<vx.size())
    {
    int i=vx[ll],j=vy[ll];
    fun(input[0],st,i,j);
    cond st2;
    st2.up=false,st2.down=false,st2.left=false,st2.right=false,st2.ur=false,st2.ul=false,st2.dr=false,st2.dl=false;
    test(input,st,st2,i,j);
    int p=2;
    sear(i,j,input,p,st2);
    if(p==input.size() || input.size()==1)
    {
        cout<<"Found in index ("<<vx[ll]<<","<<vy[ll]<<")\n";
    }
            ll++;
    }
    return 0;
}
