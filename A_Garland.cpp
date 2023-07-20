#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    string s;
    cin >> s;
    map<char, int> st;
    for (auto c : s)
        st[c]++;
    int sz = st.size();
    if (sz == 1)
    {
        cout << -1 << endl;
    }
    else if (sz == 2)
    {
        for (auto [x, y] : st)
        {
            if (y == 3)
            {
                cout << 6 << endl;
                return;
            }
        }
        cout << 4 << endl;
    }
    else
    {
        cout << 4 << endl;
    }
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
