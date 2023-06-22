int maximumNonAdjacentSum(vector<int> &nums){
    
    int n = nums.size()-1;

    prev2 = nums[0];
    prev = max(nums[1], nums[0]);
    
    
    for(int i=2; i<=n; i++)
    {
        curr = max(nums[i]+prev2, prev);
        prev2 = prev;
        prev = curr;
    }
 
    return prev;
}