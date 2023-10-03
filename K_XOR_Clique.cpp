#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(32, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int lastsetbitpos = log2(x) + 1;
        v[lastsetbitpos] += 1;
    }
    cout << *max_element(v.begin(), v.end()) << endl;
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