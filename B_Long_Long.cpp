#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 0)
            continue;
        sum += abs(x);
        v.push_back(x);
    }
    int nn = v.size();
    int op = 0;
    int i = 0;
    bool ok = false;
    while (i < nn)
    {
        while (i < nn and v[i] <= 0)
            i++, ok = true;
        i++;
        op += ok;
        ok = false;
    }
    cout << sum << ' ' << op << endl;
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