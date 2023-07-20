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
    int zero = 0, one = 0;
    for (auto x : v)
    {
        zero += (x == 0);
        if (x > 1)
            one = 1;
    }
    if (zero == 0)
    {
        cout << zero << endl;
        return;
    }
    if (zero == n)
    {
        cout << 1 << endl;
        return;
    }
    int f = n - zero;
    if (zero - f > 1)
    {
        if (one)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
    else
        cout << 0 << endl;
    // cout << one << ' ' << zero << endl;
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