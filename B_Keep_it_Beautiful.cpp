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
    int mx = v[0], mi = v[0], f = v[0];
    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        if (v[i] >= f and ok)
        {
            cout << 1;
            f = v[i];
        }
        else
        {
            if (ok)
            {
                if (v[i] <= mx)
                {
                    cout << 1;
                    mi = v[i];
                    ok = false;
                    f = v[i];
                }
                else
                {
                    cout << 0;
                }
            }
            else
            {
                if (v[i] >= mi and v[i] <= mx and f <= v[i])
                {
                    cout << 1;
                    f = v[i];
                }
                else
                    cout << 0;
            }
        }
    }
    cout << endl;
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