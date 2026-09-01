class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       
        unordered_map<int, int> rem_map;
        rem_map[0] = -1; 

        int running_sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            running_sum += nums[i];
            int remainder = running_sum % k;

            if (rem_map.count(remainder)) {
            
                if (i - rem_map[remainder] >= 2) {
                    return true;
                }
            } else {
              
                rem_map[remainder] = i;
            }
        }

        return false;
    }
};