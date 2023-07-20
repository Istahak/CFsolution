#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int cnt1 = count(s.begin(), s.end(), '(');
    int cnt2 = count(s.begin(), s.end(), ')');
    if (cnt1 != cnt2)
    {
        cout << -1 << endl;
        return;
    }
    stack<char> s1, s2;
    vector<int> ans;
    int c = 1;
    for (int i = 0; i < n; i++)
    {
        if (s1.empty() and s2.empty())
        {
            if (s[i] == '(')
            {
                s1.emplace(s[i]);
                c = 1;
                ans.push_back(1);
            }
            else
            {
                s2.emplace(s[i]);
                c = 2;
                ans.push_back(2);
            }
            continue;
        }
        if (!s1.empty())
        {
            if (s[i] == ')')
                s1.pop();
            else
                s1.emplace(s[i]);
            ans.push_back(c);
        }
        if (!s2.empty())
        {
            if (s[i] == '(')
                s2.pop();
            else
                s2.emplace(s[i]);
            ans.push_back(c);
        }
    }
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(ans[i]);
    }
    if (st.size() == 2)
    {
        cout << 2 << endl;
        for (int i = 0; i < n; i++)
        {
            if (ans[i] & 1)
                cout << 1 << ' ';
            else
                cout << 2 << ' ';
        }
        cout << endl;
    }
    else
    {
        cout << 1 << endl;
        for (int i = 0; i < n; i++)
            cout << 1 << ' ';
        cout << endl;
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