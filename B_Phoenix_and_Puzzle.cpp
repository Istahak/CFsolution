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
        cout << "NO" << endl;
        return;
    }
    int x = sqrt(n);
    int y = sqrt(n / 2);
    cout << ((x * x == n || y * y == n / 2) ? "YES" : "NO") << endl;
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