#include <iostream>
using namespace std;

int lcm(int x,int y, int z);

int main(int argc, char const *argv[])
{
    int a,b,c;
    cin >> a >> b >> c;
    cout << lcm(a,b,c);
    return 0;
}

int lcm(int x,int y, int z)
{
        long max,lcom, count, flag=0;
        if(x>=y&&x>=z)
                max=x;
        else if(y>=x&&y>=z)
                max=y;
        else if(z>=x&&z>=y)
                max=z;
        for(count=1;flag==0;count++)
        {
                lcom=max*count;
                if(lcom%x==0 && lcom%y==0 && lcom%z==0)
                {
                        flag=1;
                }
        }
        return lcom;
}