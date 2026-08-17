class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestval = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            
            bestval = max(nums[i], bestval + nums[i]);
           
            ans = max(ans, bestval);
        }

        return ans;
    }
};