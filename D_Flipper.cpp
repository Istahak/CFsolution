#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    int mxi = INT_MAX;
    int sc;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        if (v[i] == n)
            mxi = i;
        if (v[i] == n - 1)
            sc = i;
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    auto print = [&](int scmxi)
    {
        for (int i = scmxi; i <= n; i++)
        {
            cout << v[i] << ' ';
        }

        scmxi--;
        if (scmxi != n - 1)
        {
            cout << v[scmxi] << ' ';
            scmxi--;
        }
        // cout << v[scmxi] << ' ' << v[1] << endl;
        while (v[scmxi] > v[1] and scmxi > 0)
            cout << v[scmxi--] << ' ';
        for (int i = 1; i <= scmxi; i++)
            cout << v[i] << ' ';
        cout << endl;
        return;
    };
    if (mxi == 1)
    {
        print(sc);
    }
    else
        print(mxi);
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