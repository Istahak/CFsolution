#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    string s;
    cin >> s;
    vector<int> v;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            cnt++;
        }
        else
        {
            if (cnt)
                v.push_back(cnt);
            cnt = 0;
        }
    }
    if (s[s.size() - 1] == '1')
        v.push_back(cnt);
    if (v.size() == 0)
    {
        cout << 0 << endl;
        return;
    }
    sort(v.rbegin(), v.rend());
    int ans = 0;
    for (int i = 0; i < v.size(); i += 2)
    {
        ans += v[i];
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}