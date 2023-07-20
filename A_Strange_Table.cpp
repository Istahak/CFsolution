#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        s.insert(x);
    }
    int cnt = 0;
    while (!s.empty())
    {
        auto it = s.end();
        it--;
        if ((*it) & 1)
            s.erase(it);
        else
        {
            int y = (*it) / 2;
            cnt++;
            s.erase(it);
            s.insert(y);
        }
    }
    cout << cnt << endl;
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