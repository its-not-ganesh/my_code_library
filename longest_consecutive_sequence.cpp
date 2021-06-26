/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.
*/

int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        set<int> s;
        set<int, greater<int>> ans;
        for(auto x : nums)
            s.insert(x);
        int count = 1;
        int flag = 0;
        int x;
        for(auto itr = s.begin(); itr != s.end(); itr++)
        {
            if(flag == 0)
            {
                flag = 1;
                x = *itr;  
                continue;
            }
            
            if((*itr - x) == 1)
                count++;
            else
            {
                ans.insert(count);
                count = 1;
            }
            
            x = *itr;
        }
        ans.insert(count);
        flag = *ans.begin();
        return flag;
    }
