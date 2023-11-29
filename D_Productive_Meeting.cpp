#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    set<pair<int, int>> st;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if(x)
        st.insert({x, i});
    }
    vector<tuple<int, int>> ans;
    int total = 0;
    while (st.size() > 1)
    {
        auto [f, fp] = *st.begin();
        auto [s, sp] = *st.rbegin();

        total += 1;
        ans.emplace_back(fp, sp);
        int a = s - 1, b = sp;
        int aa = f - 1, bb = fp;
        st.erase(*st.begin());
        st.erase(*st.rbegin());
        if(a)
        st.insert({a, b});
        if(aa)
        st.insert({aa, bb});
        // debug(), dbg(st);
    }
    cout << total << '\n';
    for (auto [l, r] : ans)
    {

        cout << l << ' ' << r << '\n';
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