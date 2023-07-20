#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v1, v2;
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
            v1.push_back(i);
        else
            v2.push_back(i);
    }
    reverse(v2.begin(), v2.end());
    for (auto i : v1)
        cout << i << ' ';
    for (auto i : v2)
        cout << i << " ";
    cout << endl;
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
