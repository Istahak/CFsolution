#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> l(k), r(k);
    for (auto &x : l)
        cin >> x;
    for (auto &x : l)
        cin >> x;
    map<int, int> id;
    for (int i = 0; i < k; i++)
    {
        for (int j = l[i]; j <= r[i]; j++)
        {
            id[j] = l[j] + r[j] - j;
        }
    }
    int q;
    cin >> q;
    vector<int> diff(n, 0);
    while (q--)
    {
        int x;
        cin >> x;
        diff[x]++;
        diff[id[x]]++;
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = l[i]; j <= (l[i] + r[i]) / 2; j++)
        {
            if (diff[j] % 2)
            {
                swap(s[j], s[id[j]]);
            }
        }
    }
    cout << s << '\n';
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