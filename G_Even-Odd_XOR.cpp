#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    if (n == 3)
    {
        cout << 2 << ' ' << 1 << ' ' << 3 << endl;
        return;
    }
    if (n == 6)
    {
        cout << 4 << ' ' << 1 << ' ' << 2 << ' ' << 12 << ' ' << 3 << ' ' << 8 << endl;
        return;
    }
    if (n % 4 == 0)
    {
        int add = 1 << 26;
        int i = 0;
        while (n)
        {
            cout << i << ' ' << i + add << ' ';

            i++;
            n -= 2;
        }
    }
    else if (n % 4 == 1)
    {
        cout << 0 << ' ';
        n--;
        int add = 1 << 26;
        int i = 1;
        while (n)
        {
            cout << i << ' ' << i + add << ' ';

            i++;
            n -= 2;
        }
    }
    else if (n % 4 == 2)
    {

        cout << 4 << ' ' << 1 << ' ' << 2 << ' ' << 12 << ' ' << 3 << ' ' << 8 << ' ';
        n -= 6;
        int add = 1 << 26;
        int i = 13;
        while (n)
        {
            cout << i << ' ' << i + add << ' ';

            i++;
            n -= 2;
        }
    }
    else
    {
        cout << 2 << ' ' << 1 << ' ' << 3 << ' ';
        n -= 3;
        int add = 1 << 26;
        int i = 4;
        while (n)
        {
            cout << i << ' ' << i + add << ' ';

            i++;
            n -= 2;
        }
    }

    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}