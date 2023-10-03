#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int query(int x)
{
    cout << x << endl;
    int y;
    cin >> y;
    return y;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        st.insert(v[i]);
    }
    int ans = n, cur = 0;
    for (auto x : st)
    {
        if (x == cur)
            cur++;
        else
        {
            ans = cur;
            break;
        }
    }
    int p = query(ans);
    if (p == -1)
        return;
    for (int i = 0;; i++)
    {
        int q = query(p);
        if (q == -1)
            return;
        p = q;
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