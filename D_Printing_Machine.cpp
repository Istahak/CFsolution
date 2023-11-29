#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int N; // Number of products
    cin >> N;

    vector<pair<ll, ll>> products; // Each product's (T[i], D[i])
    map<ll, int> mp;
    for (int i = 0; i < N; i++)
    {
        ll T, D;
        cin >> T >> D;
        products.push_back(make_pair(T, T + D));
        mp[T]++;
    }

    sort(products.begin(), products.end(), [](pair<ll, ll> a, pair<ll, ll> b)
         { return a.second < b.second; });

    int maxPrinted = 0;
    int currentTime = 0;

    for (int i = 0; i < N; i++)
    {
        if (products[i].first > currentTime)
        {
            currentTime = products[i].second + 1;
            maxPrinted += mp[products[i].first];
        }
    }

    cout << maxPrinted << endl;

    return 0;
}
