#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1), va;
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        s.insert(v[i]);
    }
    if (s.size() == 1)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int flag = 0;

    for (int i = 2; i <= n; i++)
    {
        if (v[1] == v[i])
        {
            va.push_back(i);
        }
        else
        {
            cout << 1 << ' ' << i << endl;
            flag = i;
        }
    }
    for (int i = 0; i < va.size(); i++)
    {
        cout << flag << ' ' << va[i] << endl;
    }
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
