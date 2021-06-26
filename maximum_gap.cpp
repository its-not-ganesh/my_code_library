/*
Given an integer array nums, return the maximum difference between two successive elements in its sorted form. 
If the array contains less than two elements, return 0.
You must write an algorithm that runs in linear time and uses linear extra space.
*/    
int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int ans = INT_MIN;
        if(nums.size() < 2)
            return 0;
        for(int i = 1; i < nums.size(); i++)
            ans = max(ans, nums[i-1] - nums[i]);
        return ans;
    }
