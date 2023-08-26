#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (c & 1)
        a++;
    cout << (a > b ? "First" : "Second") << endl;
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