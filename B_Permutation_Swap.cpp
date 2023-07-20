#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<int> p;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == i)
            continue;
        else
        {
            p.push_back(abs(i - v[i]));
        }
    }
    int gc = 0;
    for (auto x : p)
    {
        gc = __gcd(gc, x);
    }
    cout << gc << endl;
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