#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void checkTriplets()
{
    ll x, y, z;
    cin >> x >> y >> z;
    vector<ll> nums = {x, y, z};
    sort(nums.begin(), nums.end());

    bool isPossible = false;

    if (nums[0] == nums[1] && nums[1] == nums[2])
        isPossible = true;
    else if (nums[0] == nums[1] && nums[1] * 2 == nums[2])
        isPossible = true;
    else if (nums[1] == 2 * nums[0] && nums[2] == 2 * nums[0])
        isPossible = true;
    else if (nums[0] == nums[1] && nums[0] * 3 == nums[2])
        isPossible = true;
    else if (nums[0] == nums[1] && nums[0] * 4 == nums[2])
        isPossible = true;
    else if (nums[2] == 3 * nums[0] && nums[1] == 2 * nums[0])
        isPossible = true;

    cout << (isPossible ? "YES" : "NO") << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases = 1;
    cin >> testCases;

    for (int caseNumber = 1; caseNumber <= testCases; caseNumber++)
    {
        checkTriplets();
    }

    return 0;
}
