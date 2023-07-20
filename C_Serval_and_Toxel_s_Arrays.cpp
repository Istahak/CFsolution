#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> A(m + 1, a);
    for (int i = 0; i < m; i++)
    {
        int p, v;
        cin >> p >> v;
        A[i + 1] = A[i];
        A[i + 1][p - 1] = v;
    }

    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j <= m; j++)
        {
            unordered_set<int> s(A[i].begin(), A[i].end());
            s.insert(A[j].begin(), A[j].end());
            ans += s.size();
        }
    }

    cout << ans << endl;
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