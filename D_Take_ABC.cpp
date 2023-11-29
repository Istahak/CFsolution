#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    string s;
    cin >> s;
    stack<char> st;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        if (st.size() < 2)
        {
            st.push(s[i]);
            continue;
        }
        char first = st.top();
        st.pop();
        char second = st.top();
        st.pop();
        string ss;
        ss.push_back(second);
        ss.push_back(first);
        ss.push_back(s[i]);

        if (ss == "ABC")
            continue;
        st.push(second);
        st.push(first);
        st.push(s[i]);
    }
    string ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
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