#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s.size() % 2 == 1)
    {
        cout << -1 << '\n';
        return;
    }
    string ans;
    int cnt = 0;
    vector<int> a;
    while (1)
    {
        int sz = s.size();
        int pos = -1;
        char c;
        for (int i = 0; i < sz / 2; i++)
        {
            if (s[i] == s[sz - i - 1])
            {
                pos = i;
                c = s[i];
                break;
            }
        }
        if (pos == -1)
        {
            break;
        }
        // cout<<pos<<
        string ss;
        if (c == '0')
        {
            for (int i = 0; i < sz; i++)
            {
                if (i == sz - pos - 1)
                {
                    ss.push_back(s[i]);
                    ss += "01";
                    a.push_back(i);
                }
                else
                {
                    ss.push_back(s[i]);
                }
            }
        }
        else
        {
            for (int i = 0; i < sz; i++)
            {
                if (i == pos)
                {
                    ss += "01";
                    // if()
                    a.push_back(i-1);
                }
                ss.push_back(s[i]);
            }
        }
        if (a.size() > 300)
        {
            cout << -1 << '\n';
            return;
        }
        // cout << ss << '\n';
        s = ss;
    }
    cout << a.size() << '\n';
    for (auto &x : a)
        cout << x + 1 << ' ';
    cout << '\n';
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