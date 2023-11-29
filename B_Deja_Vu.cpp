#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;

    vector<int> cnt(31, 0);
    for (int k = 0; k < q; k++)
    {
        int x;
        cin >> x;
        if (cnt[x])
            continue;

        int i = x;
        int cur = (1 << i);

        for (int i = 0; i < n; i++)
        {
            if (v[i] % cur == 0)
            {
                int ans = v[i] + cur / 2;
                v[i] = ans;
            }
        }

        cnt[x] = 1;
    }
    for (auto &x : v)
        cout << x << ' ';
    cout << '\n';
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