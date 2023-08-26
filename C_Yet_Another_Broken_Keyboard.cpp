#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll cal(ll n)
{
    return n * (n + 1) / 2;
}
void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    set<char> st;
    for (int i = 0; i < k; i++)
    {
        char c;
        cin >> c;
        st.insert(c);
    }
    ll cnt = 0, ans = 0;
    for (auto c : s)
    {
        if (st.count(c))
            cnt++;
        else
        {
            ans += cal(cnt);
            cnt = 0;
        }
    }

    cout << ans + cal(cnt) << endl;
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