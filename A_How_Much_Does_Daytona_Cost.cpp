#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    bool ok = false;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == k)
            ok = true;
    }
    cout << (ok ? "YES" : "NO") << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}