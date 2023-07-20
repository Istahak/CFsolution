#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
int query(int x, int y)
{
    cout << "? " << x << " " << y << endl;
    int q;
    cin >> q;
    return q;
}
void solve()
{
    int n;
    cin >> n;
    int x = 1, y = 2;
    for (int i = 3; i <= n; i++)
    {
        int q1 = query(x, i);
        int q2 = query(y, i);
        if (q1 < q2)
            x = i;
        if (q1 > q2)
            y = i;
    }
    cout << "! " << x << " " << y << endl;
    int q;
    cin >> q;
    assert(q == 1);
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}