#include <iostream>
#include <vector>

void generateMultisets(std::vector<int>& multiset, int targetSum, int currentSum, int currentElement) {
    if (currentSum == targetSum) {
        // Found a valid multiset
       
        for (int element : multiset) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
        return;
    }

    if (currentSum > targetSum || currentElement > 41) {
        // The current multiset cannot reach the target sum
        return;
    }

    // Include the current element in the multiset
    multiset.push_back(currentElement);
    generateMultisets(multiset, targetSum, currentSum + currentElement, currentElement);

    // Exclude the current element from the multiset
    multiset.pop_back();
    generateMultisets(multiset, targetSum, currentSum, currentElement + 1);
}

int main() {
    int targetSum = 41;
    std::vector<int> multiset;
     freopen("input.txt", "r", stdin);
     freopen("3.txt", "w", stdout);
    generateMultisets(multiset, targetSum, 0, 1);

    return 0;
}
