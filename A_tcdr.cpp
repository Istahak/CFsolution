#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    set<char> st;
    st.insert('a');
    st.insert('e');
    st.insert('i');
    st.insert('o');
    st.insert('u');
    string s;
    cin >> s;
    for (auto c : s)
    {
        if (st.count(c))
            continue;
        cout << c;
    }
    cout << endl;
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