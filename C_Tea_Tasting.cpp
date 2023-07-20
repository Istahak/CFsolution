#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n), preb(n + 1), ans(n + 1), cnt(n + 1);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    for (int i = 0; i < n; i++)
    {
        preb[i + 1] = preb[i] + b[i];
    }
    // for (auto i : preb)
    //     cout << i << ' ';
    // cout << endl;
    for (int l = 0; l < n; l++)
    {
        int r = lower_bound(preb.begin(), preb.end(), preb[l] + a[l]) - preb.begin();
        cnt[l]++, cnt[r - 1]--;
        ans[r - 1] += (a[l] - (preb[r - 1] - preb[l]));
    }
    for (int i = 1; i < n; i++)
        cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++)
    {
        ans[i] += (cnt[i] * b[i]);
        cout << ans[i] << ' ';
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}