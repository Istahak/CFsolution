#include <bits/stdc++.h>
using namespace std;
void solve()
{
    set<char> st;
    st.insert('m');
    st.insert('n');
    st.insert('b');
    st.insert('v');
    st.insert('c');
    st.insert('x');
    st.insert('z');
    string s, ans;
    cin >> s;
    for (auto c : s)
    {
        if (st.count(c) == 0)
            ans.push_back(c);
    }
    cout << ans << endl;
}
int main()
{

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

    return 0;
}