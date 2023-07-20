#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    int mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        mx = max(mx, (int)c - 'a');
    }
    cout << mx + 1 << endl;
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