#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int cur = 1e6;
    stack<int> st;
    int sz = s.size();
    bool ok = false;
    char pre = '+';
    for (int i = 0; i < sz; i++)
    {
        if (s[i] == '+')
        {
            st.emplace(cur);
            pre = s[i];
        }
        else if (s[i] == '-')
        {
            int cc = st.top();
            if (cc == cur + 1)
                ok = false;
            st.pop();
            pre = s[i];
        }
        else if (s[i] == '0')
        {
            if (st.size() == 1 or st.size() == 0)
            {
                cout << "NO" << endl;
                return;
            }
            else if (st.size() >= 2)
            {
                int lst = st.top();
                st.pop();
                int secondlast = st.top();
                st.pop();
                if (ok and st.size() != 1)
                {
                    st.emplace(secondlast);
                    st.emplace(lst);
                }
                else
                {
                    secondlast = cur + 1;
                    lst = cur;
                    st.emplace(secondlast);
                    st.emplace(lst);
                    ok = true;
                }
            }
        }
        else
        {

            if (st.size() == 1 or st.size() == 0)
            {
                continue;
            }
            if(ok and st.size()==2 and pre=='+') continue;
            if (ok and st.size() >= 2)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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