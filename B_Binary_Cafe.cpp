#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int ok(int d, vector<int> &v)
{
    if (d >= v.size())
        return 0;
    if (v[d] == 1)
        return ok(d + 1, v) + (1 << (v.size() - d - 1));
    else
        return ok(d + 1, v);
}
void solve()
{
    int n, k;
    cin >> n >> k;
    int st = __builtin_popcount(n);
    int xx = log2(n) + 1;
    if (xx > k)
    {
        cout << (1 << k) << endl;
    }
    else
    {
        vector<int> v;
        int gg = n;
        while (gg)
        {
            v.push_back(gg % 2);
            gg /= 2;
        }
        reverse(v.begin(), v.end());
        int ans = ok(0, v) + 1;
        cout << ans << endl;
    }
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