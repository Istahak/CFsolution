#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
ll prefix[1002][1002];
void solve()
{
    memset(prefix, 0, sizeof(prefix));
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        ll h, w;
        cin >> h >> w;
        prefix[h][w] += (h * w);
    }
    for (int i = 1; i <= 1001; i++)
        for (int j = 1; j <= 1001; j++)
        {
            prefix[i][j] += (prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1]);
        }
    while (q--)
    {
        ll hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;
        cout << prefix[hb - 1][wb - 1] - prefix[hb - 1][ws] - prefix[hs][wb - 1] + prefix[hs][ws] << endl;
    }
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