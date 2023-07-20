#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        v[x] = i;
    }
    if (v[1] < v[n] and v[2] < v[n])
    {
        if (v[1] < v[2])
        {
            cout << v[2] << ' ' << v[n] << endl;
        }
        else
        {
            cout << v[1] << ' ' << v[n] << endl;
        }
        return;
    }

    if (v[1] > v[n] and v[2] > v[n])
    {
        if (v[1] < v[2])
        {
            cout << v[1] << ' ' << v[n] << endl;
        }
        else
        {
            cout << v[2] << ' ' << v[n] << endl;
        }
        return;
    }
    cout << 1 << ' ' << 1 << endl;
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