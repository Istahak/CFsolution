#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<int, int> ma, mb;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ma[x]++;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mb[x]++;
    }
    int ans = 0;
    int k = n;
    for (auto &[x, y] : ma)
    {
        if (mb[x])
        {
            int mi = min(mb[x], y);
            y -= mi;
            mb[x] -= mi;
            ans += (mi * x);
            k -= mi;
        }
    }

    while (k--)
    {
        vector<int> a, b;
        for (auto [x, y] : ma)
        {
            while (y--)
                a.push_back(x);
        }
        for (auto [x, y] : mb)
        {
            while (y--)
                b.push_back(x);
        }
        int mxa = *max_element(a.begin(), a.end());
        int mxb = *max_element(b.begin(), b.end());
        if (mxa == mxb)
        {
            ans += mxa;
            ma[mxa]--;
            mb[mxb]--;
        }
        else if (mxa > mxb)
        {
            int gc = 0;
            int el = 0;
            for (auto x : b)
            {
                int f = __gcd(mxa, x);
                if (gc < f)
                {
                    gc = f;
                    el = x;
                }
            }
            ans += gc;
            mb[el]--;
            ma[mxa]--;
        }
        else if (mxa < mxb)
        {
            int gc = 0;
            int el = 0;
            for (auto x : a)
            {
                int f = __gcd(mxb, x);
                if (gc < f)
                {
                    gc = f;
                    el = x;
                }
            }
            ans += gc;
            ma[el]--;
            mb[mxb]--;
        }
        //cout<<ma.size()<<endl;
        for (auto x : a)
            cout << x << ' ';
        cout << endl;
        for (auto x : b)
            cout << x << ' ';
        cout << endl;
        cout << endl;
    }

    cout << ans << endl;
    return 0;
}
