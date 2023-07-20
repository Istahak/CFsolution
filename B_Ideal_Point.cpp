#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(52, 0);
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a <= k && k <= b)
        {
            v[a]++, v[b + 1]--;
            vp.push_back({a, b});
        }
    }
    for (int i = 1; i < 52; i++)
    {
        v[i] += v[i - 1];
    }
    // cout << v[k] << endl;
    if (v[k] == 0)
    {
        cout << "NO" << endl;
        return;
    }
    bool ok = true;
    int mk = v[k];
    int mx = INT_MIN;
    int cnt = 0;
    for (int i = 0; i < 52; i++)
    {
        if (mk == v[i])
            cnt++;
        mx = max(v[i], mx);
    }
    cout << ((v[k]==mx && cnt==1) ? "YES" : "NO") << endl;
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