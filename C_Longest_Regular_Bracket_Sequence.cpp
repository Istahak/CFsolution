#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n, 0);
    stack<int> st;
    int mxlen = 0, cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.emplace(i);
            continue;
        }
        if (!st.empty())
        {
            int p = st.top();
            st.pop();
            dp[i] = i - p + 1;
            if (p != 0)
                dp[i] += dp[p - 1];

            if (dp[i] == mxlen)
                cnt++;
            if (dp[i] > mxlen)
            {
                mxlen = dp[i];
                cnt = 1;
            }
        }
    }
    cout << mxlen << ' ' << cnt << endl;
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