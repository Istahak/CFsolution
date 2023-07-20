#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define debug(x) cerr << (#x) << ' ' << x << endl;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), s(n);
    for (auto &i : v)
        cin >> i;
    for (auto &i : s)
        cin >> i;
    int ansl = 0, ansr = n - 1;
    int ans = INT_MIN;
    int l = 0, r = 0;
    int cnt = 0;
    while (l < n and r < n - 1)
    {
        while (r < n - 1 and s[r] <= s[r + 1])
            r++, cnt++;
        bool ok = false;
        for (int i = l; i <= r; i++)
        {
            if (v[i] != s[i])
                ok = true;
        }
        if (cnt >= ans and ok)
        {
            ans = cnt;
            ansl = l, ansr = r;
        }
        cnt = 0;
        l = ++r;
    }
    cout << ++ansl << ' ' << ++ansr << endl;
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