class Solution {
public:
    int getsum(int n){
        int totalsum=0;
        while(n>0){
            int digit = n% 10;
            totalsum += digit * digit;
            n/=10;
        }
        return totalsum;
    }
public:
    bool isHappy(int n) {
        int slow =n;
        int fast = getsum(n);

        while(fast != 1 && slow!= fast){
            slow= getsum(slow);
            fast = getsum(getsum(fast));

        }

        return fast==1;
        
    }
};