class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int total_sum = 0;
        int max_sum = nums[0];
        int cur_max = 0;
        int min_sum = nums[0];
        int cur_min = 0;

        for(int x : nums){
            cur_max= max( x, cur_max+x);
            max_sum= max(max_sum, cur_max);


            cur_min= min(x,cur_min+x);
            min_sum= min(min_sum, cur_min);

            total_sum +=x;


        }

        if(max_sum <0){
            return max_sum;
        }
        return max(max_sum,total_sum- min_sum);



        
    }
};