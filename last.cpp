#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    set<string> st;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (st.empty())
        {
            st.insert(s);
        }
        else
        {
            if (st.count(s))
                continue;
            reverse(s.begin(), s.end());

            if (st.count(s))
                continue;
            st.insert(s);
        }
    }
    cout << st.size() << endl;
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