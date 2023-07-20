#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> v;
    while (n != 1)
    {
        int x = (n - 1) / 2;

        if ((x & 1) & n != 1)
        {
            v.push_back(2);
            n = ((n - 1) / 2);
        }
        int y = (n + 1) / 2;
        if ((y & 1) && n != 1)
        {
            v.push_back(1);
            n = (n + 1) / 2;
        }
    }
    cout << v.size() << endl;
    reverse(v.begin(), v.end());
    for (auto x : v)
        cout << x << ' ';
    cout << endl;
}
int main()
{

    int t = 1;
    cin >> t;

    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }

    return 0;
}
