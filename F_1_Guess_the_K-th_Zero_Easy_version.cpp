#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int ask(int l, int r)
{
    cout << "? " << l << ' ' << r << endl;
    int x;
    cin >> x;
    return x;
}
void print(int x)
{
    cout << "! " << x << endl;
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    cin >> n >> t;
    int k;
    cin >> k;
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int totalones = ask(l, mid);
        int totalzero = (mid - l + 1) - totalones;
        if (k > totalzero)
        {
            k -= totalzero;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    print(l);
    return 0;
}