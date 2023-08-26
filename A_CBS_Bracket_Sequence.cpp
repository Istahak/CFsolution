#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    string s;
    cin >> s;
    stack<char> st;
    for (auto c : s)
    {
        if (st.empty())
            st.push(c);
        else
        {
            if (c == '(')
                st.push(c);
            else
            {
                if (st.top() == '(')
                    st.pop();
                else
                    st.push(c);
            }
        }
    }
    int open = 0, close = 0;
    while (!st.empty())
    {
        st.top() == '(' ? open++ : close++;
        st.pop();
    }
    int ans = max(open, close);
    if ((open + close) % 2)
        ans = -1;
    cout << ans << endl;
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