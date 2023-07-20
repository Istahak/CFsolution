#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll ask(int a, int b)
{
    cout << "? " << a << ' ' << b << endl;
    ll x;
    cin >> x;
    return x;
}
void print(ll ans)
{
    cout << "! " << ans << endl;
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a = 1, b = 2;
    while (a <= 50)
    {
        ll sza = ask(a, b);
        ll szb = ask(b, a);
        if (sza == -1 || szb == -1 || sza == szb)
        {
            a++, b++;
        }
        else
        {
            print(sza + szb);
        }
    }

    return 0;
}