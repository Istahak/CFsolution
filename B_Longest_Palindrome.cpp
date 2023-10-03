#include <iostream>
#include <vector>

using namespace std;

int longest_palindrome_substring_length(string S) {
    int n = S.size();
    // Initialize a table to store whether substrings are palindromes
    vector<vector<bool>> is_palindrome(n, vector<bool>(n, false));

    int max_length = 1;  // At least, each character itself is a palindrome

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; i++) {
        is_palindrome[i][i] = true;
    }

    // Check for palindromes of length 2
    for (int i = 0; i < n - 1; i++) {
        if (S[i] == S[i + 1]) {
            is_palindrome[i][i + 1] = true;
            max_length = 2;
        }
    }

    // Check for palindromes of length 3 or more
    for (int length = 3; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            if (is_palindrome[i + 1][j - 1] && S[i] == S[j]) {
                is_palindrome[i][j] = true;
                max_length = max(max_length, length);
            }
        }
    }

    return max_length;
}

int main() {
    string S;
    // cout << "Enter a string: ";
    cin >> S;

    int result = longest_palindrome_substring_length(S);
    cout <<  result << endl;

    return 0;
}
