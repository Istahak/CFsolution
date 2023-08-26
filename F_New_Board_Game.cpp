#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int g[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        set<int> st;
        for (int j = 0; j < n; j++)
        {
            st.insert(g[i][j]);
        }
        if (st.size() != n)
            ok = false;
    }
    for (int i = 0; i < n; i++)
    {
        set<int> st;
        for (int j = 0; j < n; j++)
        {
            st.insert(g[j][i]);
        }
        if (st.size() != n)
            ok = false;
    }
    cout << (ok ? "YES" : "NO") << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}