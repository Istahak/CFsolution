#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    if ((a != 0 && b != 0) || (a == 0 && b == 0))
    {
        cout << -1 << endl;
        return;
    }
    int k = max(a, b);

    if ((n - 1) % k != 0)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= n;)
    {
        if (i == 1)
        {
            for (int j = 0; j < k; j++)
                cout << i << ' ';
            i += (k + 1);
        }
        else
        {
            for (int j = 0; j < k; j++)
                cout << i << ' ';
            i += (k);
        }
    }
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
