#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    ll sum = 0;
    for (auto &i : a)
    {
        cin >> i;
        sum += i;
    }
    for (auto &i : b)
    {
        cin >> i;
        sum += i;
    }
    int mx = *max_element(b.begin(), b.end());
    sum -= mx;
    cout << sum << endl;
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