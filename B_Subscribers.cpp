#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif
void approximate_N(int N) {
    if (N <= 1e3 - 1) {
        std::cout << N << std::endl;
    } else if (N <= 1e4 - 1) {
        std::cout << (N / 10) * 10 << std::endl;
    } else if (N <= 1e5 - 1) {
        std::cout << (N / 100) * 100 << std::endl;
    } else if (N <= 1e6 - 1) {
        std::cout << (N / 1000) * 1000 << std::endl;
    } else if (N <= 1e7 - 1) {
        std::cout << (N / 10000) * 10000 << std::endl;
    } else if (N <= 1e8 - 1) {
        std::cout << (N / 100000) * 100000 << std::endl;
    } else if (N <= 1e9 - 1) {
        std::cout << (N / 1000000) * 1000000 << std::endl;
    }
}
void solve()
{
    int n; cin >> n;
    approximate_N(n);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}