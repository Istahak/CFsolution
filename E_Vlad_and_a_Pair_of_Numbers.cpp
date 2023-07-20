#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    if (n & 1)
    {
        cout << -1 << endl;
        return;
    }
    int x = n, s = 2 * n;
    int a = (s - x) / 2;
    int ansa = 0, ansb = 0;
    for (int i = 0; i < 30; i++)
    {
        int ai = (a & (1 << i));
        int xi = (x & (1 << i));
        if (xi == 0 && ai == 0)
            continue;
        else if (xi == 0 && ai > 0)
        {
            ansa = (ansa | (1 << i));
            ansb = (ansb | (1 << i));
        }
        else if (xi > 0 && ai == 0)
        {
            ansa = (ansa | (1 << i));
        }
        else
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << ansa << ' ' << ansb << endl;
    // cout<<(ansa^ansb)<<' '<<ansa+ansb<<endl;
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