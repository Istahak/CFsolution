#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int ok = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == '0')
            cout << '-';
        else
        {
            cout << (ok ? '+' : '-');
            ok ^= 1;
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