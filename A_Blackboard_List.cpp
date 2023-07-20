#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    set<int> st;
    for (auto &i : v)
        cin >> i, st.insert(i);
    for (int i = 0; i < n; i++)
    {
        if (v[i] < 0)
        {
            cout << v[i] << endl;
            return;
        }
    }
    cout << (*max_element(v.begin(), v.end())) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}