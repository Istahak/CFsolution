#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<ll> v;

void call(ll num, int last = 10)
{
    v.push_back(num);
    for (int d = last - 1; d >= 0; d--)
    {
        call(num * 10 + d, d);
    }
}
void solve()
{
    call(0);
    int l;
    cin >> l;
    sort(v.begin(), v.end());
    cout << v[l + 1] << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}