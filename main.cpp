#include <iostream>
#include<vector>

#define max(x,y) (x>y?x:y)

using namespace std;


void cut_rod1(int p[],int n)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n-i; j++)
        {
            if(p[i+j] < p[i] + p[j])
            {
                p[i+j] = p[i] + p[j];
            }
        }
    }
}

int cut_rod2(int p[],int n)
{
    int q = 0;

    if(n==0)
    {
        return 0;
    }

    for(int i = 1; i <= n; i++)
    {
        q = max(q,p[i] + cut_rod2(p,n-i));
    }

    return q;
}

int cut_rod_memorized_aux(int p[],int n,int r[])
{
    int q = 0;

    if(r[n] > 0)
    {
        return r[n];
    }

    if(n == 0)
    {
        return 0;
    }

    for(int i = 1;i <= n; i++)
    {
        q = max(q,p[i]+cut_rod_memorized_aux(p,n-i,r));
    }

    r[n] = q;

    return q;
}


int cut_rod_memorized(int p[],int n)
{
    int *r = new int[n];
    return cut_rod_memorized_aux(p,n,r);
}

int cut_rod_bottom_up(int p[], int r[],int n)
{
    for(int i = 1; i <= n; i++)
    {
        r[i] = p[i];

        for(int j = 1; j <= i; j++)
        {
            if(r[i] < r[j] + r[i-j])
            {
                r[i] = r[j] + r[i-j];
            }
        }
    }

    return r[n];
}

int main()
{
    int p[50] = {0,1,5, 8, 9, 10, 17, 17, 20, 24, 30};
    int r[50] = {0};

    cut_rod1(p,40);
//    cut_rod_bottom_up(p,r,40);

    for(int i = 1; i <= 40; i++)
    {
        cout << p[i] <<" " <<endl;
    }

//    cout << cut_rod2(p,20) << endl;
    return 0;
}
