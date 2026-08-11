class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n= nums.size();
        int left=0;
        int currentsum=0;

        int minl= INT_MAX;

        for( int right =0 ; right<n ; right++){
            currentsum += nums[right];


            while (currentsum >= target){
                minl = min(minl , right-left+1);
                currentsum -=nums[left];
                left++;
                
            }
        }

        return minl == INT_MAX? 0: minl;

    }
};