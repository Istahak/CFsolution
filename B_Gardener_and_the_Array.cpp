#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 10;
int arr[N];
void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int tem = 0;
        for (int j = 0; j < x; j++)
        {
            int y;
            cin >> y;
            tem |= y;
        }
        cout<<tem<<endl;
    }cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}