#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int ne = 0, p = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x == 1 ? p++ : ne++;
    }
    int ans = 0;
    while (ne > p)
    {
        p++, ne--;
        ans++;
    }
    if (ne & 1)
    {
        ans++;
    }

    cout << ans << endl;
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