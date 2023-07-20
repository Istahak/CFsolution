#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int mipos = min_element(v.begin(), v.end()) - v.begin();

    bool flag = true;

    for (int i = 0; i < mipos; i++)
    {
        if (v[i] < v[i + 1])
            flag = false;
    }
    for (int i = mipos; i < n - 1; i++)
    {
        if (v[i] > v[i + 1])
            flag = false;
    }

    cout << (flag ? "YES" : "NO") << endl;
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