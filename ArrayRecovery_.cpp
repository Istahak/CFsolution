#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), va(n);
    for (auto &i : v)
        cin >> i;
    va[0] = v[0];
    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        if (v[i] != 0 && va[i - 1] - v[i] >= 0)
        {
            flag = true;
            break;
        }
        va[i] = va[i - 1] + v[i];
    }
    if (flag)
    {
        cout << -1 << endl;
        return;
    }
    for (auto i : va)
        cout << i << ' ';
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
