#include <bits/stdc++.h>
using namespace std;

const long long LIMIT = 1e18;

long long calculateTraillingZeros(long long number) {
    long long traillingZeros = 0;
    // finds the number of trailling zeros in number factorial
    for (long long i = 5; i <= number; i *= 5) {
        traillingZeros += (number / i);
    }
    return traillingZeros;
}

int main() {
    int testCase;
    scanf("%d", &testCase);
    for (int test = 1; test <= testCase; test++) {
        long long requiredTraillingZeros;
        scanf("%lld", &requiredTraillingZeros);
        // answer is set to a value -1, which can't be a valid answer
        long long low = 1, high = LIMIT, answer = -1;
        while (low <= high) {
            // select the mid, find its trailling zeros & decide what to do.
            long long mid = (low + high) / 2;
            long long traillingZeros = calculateTraillingZeros(mid);

            if (traillingZeros > requiredTraillingZeros) {
                // if traillingZeros is greater than requiredTraillingZeros, then we should try smaller values
                high = mid - 1;
            } else if (traillingZeros < requiredTraillingZeros) {
                // if traillingZeros is smaller than requiredTraillingZeros, then we should try bigger values
                low = mid + 1;
            } else {
                // if traillingZeros is equal to requiredTraillingZeros, it's a possible answer
                // so, we store it in answer & try the smaller values as we need to find the minimum possible value
                answer = mid;
                high = mid - 1;
            }
        }
        // if answer is still -1, then we haven't found any possible answer
        if (answer == -1) printf("Case %d: impossible\n", test);
        else printf("Case %d: %lld\n", test, answer);
    }
    return 0;
}