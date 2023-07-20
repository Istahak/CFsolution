#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int cnt = 0;
    for (auto i : v)
    {
        if (i == 2)
            cnt++;
    }
    if (cnt & 1)
    {
        cout << -1 << endl;
        return;
    }
    if (cnt == 0)
    {
        cout << 1 << endl;
        return;
    }
    cnt /= 2;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 2)
        {
            cnt--;
        }
        if (!cnt)
        {
            cout << i + 1 << endl;
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}