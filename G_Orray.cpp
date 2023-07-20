#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), ans;
    for (auto &i : v)
        cin >> i;
    sort(v.rbegin(), v.rend());
    int mx = v[0];
    ans.push_back(mx);
    vector<bool> flag(n, true);
    flag[0] = false;
    for (int i = 1; i < min(n, 33); i++)
    {
        int index = -1;
        int tem = mx;
        bool ok = false;
        for (int j = 1; j < n; j++)
        {
            if (!flag[j])
                continue;
            if ((mx | v[j]) > tem)
            {
                tem = mx | v[j];
                index = j;
                ok = true;
            }
        }
        if (ok)
        {
            ans.push_back(v[index]);
            flag[index] = false;
            mx |= v[index];
        }
    }
    for (auto val : ans)
        cout << val << ' ';
    for (int i = 0; i < n; i++)
        if (flag[i])
            cout << v[i] << ' ';
    cout << endl;
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
