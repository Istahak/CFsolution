#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int ask(int r, int c)
{
    cout << "? " << r << " " << c << endl;
    int x;
    cin >> x;
    return x;
}
void print(int r, int c)
{
    cout << "! " << r << ' ' << c << endl;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    int k = ask(1, 1)-2;
    int l = ask(1, m);
    int r = (k + l) / 2, c = (k - l) / 2;
    print(r, c);
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