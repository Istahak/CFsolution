#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    for (auto &i : va)
        cin >> i;
    for (auto &i : vb)
        cin >> i;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (vb[i] < va[i])
        {
            flag = true;
            break;
        }
        if (vb[i] == va[i])
            continue;
        if (((vb[(i + 1) % n])) > vb[i] || (vb[i] - (vb[(i + 1) % n])) <= 1)
            continue;
        else
        {
            flag = true;
            break;
        }
    }

    if (flag)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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