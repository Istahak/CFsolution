#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    if (n & 1)
    {   
        cout<<1<<' ';
        for (int i = n - 2; i >= 2; i--)
        {
            cout << i << ' ';
        }
        cout << n - 1 << ' ' << n << endl;
    }
    else
    {
        for (int i = n - 2; i >= 1; i--)
        {
            cout << i << ' ';
        }
        cout << n - 1 << ' ' << n << endl;
    }
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