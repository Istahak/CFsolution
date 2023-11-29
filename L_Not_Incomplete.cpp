#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void custom_algorithm()
{
    int x, y, z, n;
    cin >> x >> y >> z >> n;
    int remaining_x = x - z;

    int extra_items = 0;
    double probability = 1.0 * n / (x * y);
    while (probability < 0.6)
    {
        extra_items++;
        probability = 1.0 * (n + extra_items) / (x * y);
    }

    if (remaining_x * y < extra_items)
    {
        cout << "No\n";
    }
    else
    {
        vector<int> distribution;
        while (remaining_x--)
        {
            int count = min(extra_items, y);
            distribution.push_back(count);
            extra_items -= count;
        }
        reverse(distribution.begin(), distribution.end());
        cout << "Yes\n";
        for (int i : distribution)
            cout << i << ' ';
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_cases = 1;
    // cin >> test_cases;
    for (int case_number = 1; case_number <= test_cases; case_number++)
    {
        // cout << "Case #" << case_number << ": ";
        custom_algorithm();
    }
    return 0;
}
