#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    bool ok = false;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x <= i)
            ok = true;
        v[i] = x;
    }

    cout << (ok ? "YES" : "NO") << endl;
}
int main()
{

    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }

    return 0;
}