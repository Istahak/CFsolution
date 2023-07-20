#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<char> st;
    st.insert('m');
    st.insert('e');
    st.insert('o');
    st.insert('w');

    for (auto &c : s)
        c = tolower(c);
    // cout << s << endl;
    int m = 0, e = 0, o = 0, w = 0;
    int i = 0;
    for (; i < n;)
    {
        if (s[i] == 'm')
            m++, i++;
        else
            break;
    }
    for (; i < n;)
    {
        if (s[i] == 'e')
            e++, i++;
        else
            break;
    }
    for (; i < n;)
    {
        if (s[i] == 'o')
            o++, i++;
        else
            break;
    }
    for (; i < n;)
    {
        if (s[i] == 'w')
            w++, i++;
        else
            break;
    }
    cout << ((i == n && m && e && o && w && m + e + o + w == n) ? "YES" : "NO") << endl;
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