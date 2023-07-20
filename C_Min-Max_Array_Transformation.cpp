#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), ans1(n), ans2(n);

    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;

    int i = 0, j = 0;
    while (i < n)
    {
        while (b[j] >= a[i] && i < n)
        {
            ans1[i] = b[j] - a[i];
            i++;
        }
        j++;
    }
    for (auto i : ans1)
        cout << i << ' ';
    cout << endl;
    i = n - 1;
    j = n - 1;
    while (i >= 0)
    {
        if (i == n - 1)
        {
            ans2[i] = b[j] - a[i];
        }
        else
        {
            if (b[i] < a[i + 1])
            {
                j = i;
            }
            ans2[i] = b[j] - a[i];
        }
        i--;
    }
    for (auto i : ans2)
        cout << i << ' ';
    cout << endl;
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