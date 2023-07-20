#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
struct p
{
    int x;
    int y;
};
void solve()
{
    struct p p1, p2, p3;
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;
    cout << p1.x + p3.y << endl;
    cout << p2.x + p1.y << endl;
    cout << p3.x + p2.y << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}