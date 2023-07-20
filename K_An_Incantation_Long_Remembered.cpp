#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<string> ss(n);
    for (auto &x : ss)
        cin >> x;
    string S;
    cin >> S;
    vector<int> index(26, -1);
    for (int i = 0; i < n; i++)
    {
        for (auto c : ss[i])
            index[c - 'a'] = i;
    }
    stack<pair<int, int>> st;
    int ans = 0;
    for (auto c : S)
    {
        int curindex = index[c - 'a'];
        if (curindex == -1)
        {
            cout << "No" << endl;
            return;
        }
        string curstr = ss[curindex];
        int sz = curstr.size();
        if (c == curstr[0])
        {
            ans++;

            if (sz != 1)
            {
                st.push({curindex, 1});
            }
        }
        else
        {
            if (st.empty())
            {
                cout << "No" << endl;
                return;
            }
            auto &[x, y] = st.top();
            if (curindex != x or c != curstr[y])
            {
                cout << "No" << endl;
                return;
            }
            y++;
            if (y == sz)
                st.pop();
        }
    }
    if (st.empty())
    {
        cout << "Yes\n"
             << ++ans << endl;
    }
    else
        cout << "No" << endl;
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