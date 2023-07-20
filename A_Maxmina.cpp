#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n,k;
    cin >> n>>k;
    vector<int> v(n);
    bool flag = true;
    for (auto &i : v)
    {
        cin >> i;
        if (i == 1)
            flag = false;
    }
    cout<<(flag? "NO":"YES")<<endl;
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
