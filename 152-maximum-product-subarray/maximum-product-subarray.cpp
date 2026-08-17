class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int bestval = nums[0];
        int worstval = nums[0];
        int ans= nums[0];
        int a,b,c;


        for(int i=1; i<nums.size();i++){
            a = nums[i]*bestval;
            b= nums[i]*worstval;
            c= nums[i];

            bestval= max(a,max(b,c));
            worstval= min(a,min(b,c));
            ans= max(ans,bestval);

        }
        return ans;
    }
};