//https://www.codingninjas.com/studio/problems/next-greater-permutation_6929564?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0


#include<bits/stdc++.h>

void Backtrack(vector<int> &nums, vector<int> &currNums, 
vector<bool> &used, set<vector<int>> &result) {
    
    if (currNums.size() == nums.size()) {
        result.insert(currNums);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {

        if (used[i]) {
            continue;
        }

        currNums.push_back(nums[i]);
        used[i] = true;
        Backtrack(nums, currNums, used, result);

        currNums.pop_back();
        used[i] = false;
    }
}

set<vector<int>> FindPermutation(vector<int> nums) {
    sort(nums.begin(), nums.end());
    set<vector<int>> result;
    vector<bool> used(nums.size());
    vector<int> currNums;

    Backtrack(nums, currNums, used, result);

    return result;
}

vector<int> nextGreaterPermutation(vector<int> &a) {  
    
    set<vector<int>> permutations = FindPermutation(a);

    auto it = permutations.upper_bound(a);
    if (it != permutations.end()) {
        return *it;
    }

   
    sort(a.begin(), a.end());
    return a;
}
