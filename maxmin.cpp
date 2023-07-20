#include <bits/stdc++.h>
using namespace std;
#include <stdio.h>
#define Max(x, y) x > y ? x : y

/*int max(int x,int y)
{
    if(x>y) return x;
    else return y;
}*/

int main()
{
    int x = 11, y = 19, z = 3;

    cout << ((x + y) >> z ^ (y - z) << x) << endl;
    return 0;
}