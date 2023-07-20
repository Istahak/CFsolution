#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int ask(int a, int b)
{
    cout << "? " << a << ' ' << b << endl;
    int x;
    cin >> x;
    return x;
}
void print(int ans)
{
    cout << "! " << ans << endl;
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int l = 1, r = n;
    while (l != r)
    {
        int p = ask(l, r);
        int mid = (l + r + 1) / 2;
        if (p >= mid)
        {
            if (r != mid && ask(mid, r) == p)
                l = mid;
            else
                r = mid - 1;
        }
        else
        {
            if (l != (mid - 1) && ask(l, mid - 1) == p)
                r = mid - 1;
            else
                l = mid;
        }
    }
    print(l);
    return 0;
}