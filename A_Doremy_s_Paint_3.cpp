#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    set<int> st;
    for (auto &x : v)
        cin >> x, mp[x]++, st.insert(x);
    if (mp.size() > 2)
    {
        cout << "No" << '\n';
        return;
    }
    if (st.size() == 1)
    {
        cout << "Yes"
             << "\n";
        return;
    }
    int on = *st.begin();
    int nn = *st.rbegin();
    int dif = abs(mp[on] - mp[nn]);
    cout << (dif <= 1 ? "Yes" : "No") << "\n";

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