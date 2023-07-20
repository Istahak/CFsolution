#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int move = 0, alice = 0, bob = 0, ap = 0, bp = 0;
    int i = 0, j = n - 1, flag = 1;
    while (i <= j)
    {
        if (flag)
        {
            ap = 0;
            while (ap <= bp && i <= j)
            {
                ap += v[i];
                i++;
            }

            move++;
            alice += ap;
            flag = 0;
        }
        else
        {
            bp = 0;
            while (bp <= ap && !flag && i <= j)
            {
                bp += v[j];
                j--;
            }

            move++;
            bob += bp;
            flag = 1;
        }
    }
    cout << move << ' ' << alice << ' ' << bob << endl;
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
