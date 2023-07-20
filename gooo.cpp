#include <bits/stdc++.h>
using namespace std;
#include <stdio.h>
int a = 50, gc = 0, lc = 0;
int pma(int b)
{
    cout << ++gc << ' ' << ++b << endl;
    return a++;
}
int pm(int a)
{
    cout << ++lc << ' ' << ++a << endl;
    return pma(a);
}
int MAX(int num1, int num2);
struct student
{
    int roll;
    double cgpa;
    char c;
};
union emni
{
    int i;
    char c;
};

void swapr(student *s1, student *s2)
{
    // student st1 = *s1, st2 = *s2;

    if ((*s1).roll > (*s2).roll)
    {
        student tem = *s1;
        *s1 = *s2;
        *s2 = tem;
    }
}
void swapc(student *s1, student *s2)
{
    // student st1 = *s1, st2 = *s2;

    if ((*s1).c > (*s2).c)
    {
        student tem = *s1;
        *s1 = *s2;
        *s2 = tem;
    }
}
int n, r;
int vis[1000006];
void com(int i, int sz)
{
    if (sz > r)
        return;
    if (sz == r)
    {
        for (int j = 1; j <= n; j++)
        {
            if (vis[j])
            {
                cout << j << ' ';
            }
        }
        cout << endl;
        return;
    }
    if (i > n)
        return;

    vis[i] = 1;
    com(i + 1, sz + 1);
    vis[i] = 0;
    com(i + 1, sz);
}
double di(int n)
{
    int d=2;
    return (double)n/d;
}
int main()
{
    cin >> n >> r;
    //com(1, 0);
    cout<<di(n)<<endl;
    student a;
    
    cout<<sizeof(a)<<endl;
    cout<<sizeof(a.cgpa)<<' '<<sizeof(a.roll)<<' '<<sizeof(a.c)<<endl;
    return 0;
}