#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int k, n, t;
    cin >> k >> n >> t;
    int flag = (t + n) % (2 * k);

    cout << ((flag < k) ? "Thiago" : "Nathan") << endl;
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