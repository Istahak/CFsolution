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
        for (int i = 1; i <= n; i++)
        {
            cout << 5 << ' ';
        }
        cout << endl;
        return;
    }
    cout << 3 << ' ' << 1 << ' ';
    for (int i = 1; i <= n - 2; i++)
        cout << 2 << ' ';
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