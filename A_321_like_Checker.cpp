#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int MAX_DIGITS = 10;

// DP table to store the count of 321-like numbers
long long dp[MAX_DIGITS][MAX_DIGITS][MAX_DIGITS];

// Function to count the number of 321-like numbers with the given digits
long long count321Numbers(int pos, int num3, int num2, bool tight, const vector<int>& digits) {
    if (pos == 0) {
        return 1; // Reached the end, a 321-like number is found
    }

    if (dp[pos][num3][num2] != -1 && !tight) {
        return dp[pos][num3][num2];
    }

    int upper_limit = tight ? digits[pos] : 9;
    long long count = 0;

    for (int digit = 0; digit <= upper_limit; ++digit) {
        if (digit == 3 && num2 > 0) {
            continue; // Skip numbers with consecutive 3's
        }

        if (digit == 2 && num3 > 0) {
            continue; // Skip numbers with consecutive 32's
        }

        int new_num3 = (digit == 3) ? num2 + 1 : 0;
        int new_num2 = (digit == 2) ? num3 + 1 : 0;
        bool new_tight = (digit == digits[pos]) ? tight : false;

        count += count321Numbers(pos - 1, new_num3, new_num2, new_tight, digits);
    }

    if (!tight) {
        dp[pos][num3][num2] = count;
    }

    return count;
}

// Function to find the k-th smallest 321-like number
long long findKth321Number(int k) {
    if (k <= 0) {
        return -1; // Invalid input
    }

    vector<int> digits;
    while (k > 0) {
        digits.push_back(k % 10);
        k /= 10;
    }

    memset(dp, -1, sizeof(dp));
    return count321Numbers(digits.size() - 1, 0, 0, true, digits);
}

int main() {
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    long long result = findKth321Number(k);

    if (result != -1) {
        cout << "The " << k << "-th smallest 321-like number is: " << result << endl;
    } else {
        cout << "Invalid input or k is less than 1." << endl;
    }

    return 0;
}
