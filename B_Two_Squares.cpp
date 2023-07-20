#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll N = 1e7 + 1;
ll ok[N + 1];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (ll i = 0; i < 3200; i++)
    {
        for (ll j = 0; j < 3200; j++)
        {
            ll x = i * i + j * j;
            if (x >= N)
                continue;
            ok[x] = 1;
        }
    }
    for (int i = 1; i < N; i++)
        ok[i] += ok[i - 1];
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        int x;
        cin >> x;

        cout << ok[x] << endl;
    }

    return 0;
}