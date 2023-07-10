// gpt wrote this but while thing of solution i found that way myself but couldn't
// code although after seeing this wroty it myself while working on next permution
//problem.
#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& currPerm, vector<vector<int>>& result) {
    // Base case: if the current permutation has the same size as the input array, add it to the result
    if (currPerm.size() == nums.size()) {
        result.push_back(currPerm);
        return;
    }

    // Recursive backtracking
    for (int i = 0; i < nums.size(); i++) {
        // Skip if the element is already used
        if (used[i]) {
            continue;
        }
        // Add the element to the current permutation
        currPerm.push_back(nums[i]);
        used[i] = true;
        // Recursive call for the next position
        backtrack(nums, used, currPerm, result);
        // Backtrack: remove the last added element
        currPerm.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> findPermutations(vector<int>& nums) {
    vector<vector<int>> result;
    vector<bool> used(nums.size(), false); // Keeps track of used elements
    vector<int> currPerm; // Stores the current permutation in each recursive call

    backtrack(nums, used, currPerm, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7}; // Example input array
    vector<vector<int>> permutations = findPermutations(nums);

    // Print the permutations
    for (const auto& perm : permutations) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
