/*
Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
In one move, you can increment or decrement an element of the array by 1.
*/

int minMoves2(vector<int>& nums) {
  int median;
  sort(nums.begin(), nums.end());
  median = nums[nums.size()/2];
  int ans = 0;
  for(auto i: nums){
      ans += abs(i-median);
  }
  return ans;
}
