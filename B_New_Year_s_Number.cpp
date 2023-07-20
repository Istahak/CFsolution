#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int x = n % 2020;
    int y = n / 2020;
    cout << (y >= x ? "YES" : "NO") << endl;
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
