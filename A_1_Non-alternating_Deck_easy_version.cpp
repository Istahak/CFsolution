#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    n--;
    // cout<<n<<endl;
    int i = 2;
    int a_w = 1, a_b = 0, b_w = 0, b_b = 0;
    int k = 1;
    while (n > 0)
    {
        if (k & 1)
        {
            if ((n - i) > 0)
            {
                b_w += (i / 2);
                b_b += (i / 2);
                n -= i;
            }
            else
            {
                b_w += (n / 2);
                b_b += ((n + 1) / 2);
                n = 0;
            }
            i++;
            if ((n - i) > 0)
            {
                b_w += (i / 2);
                b_b += ((i + 1) / 2);
                n -= i;
            }
            else
            {
                b_w += (n / 2);
                b_b += ((n + 1) / 2);
                n = 0;
            }
            i++;
        }
        else
        {
            if ((n - i) > 0)
            {
                a_w += (i / 2);
                a_b += (i / 2);
                n -= i;
            }
            else
            {
                a_b += (n / 2);
                a_w += ((n + 1) / 2);
                n = 0;
            }
            i++;
            if ((n - i) > 0)
            {
                a_b += (i / 2);
                a_w += ((i + 1) / 2);
                n -= i;
            }
            else
            {
                a_b += (n / 2);
                a_w += ((n + 1) / 2);
                n = 0;
            }
            i++;
        }
        k++;
    }
    cout << a_w << ' ' << a_b << ' ' << b_w << ' ' << b_b << endl;
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