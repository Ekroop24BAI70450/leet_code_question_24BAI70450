class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0, n = s.length();

        for (int target = 1; target <= 26; target++) {
            vector<int>freq(26,0);
            int left = 0, right = 0, unique = 0, numvalid = 0;

            while (right < n) {
                if (unique <= target) {
                     int c = s[right++] - 'a';
                    if (++freq[c] == 1)
                     unique++;
                    if (freq[c] == k) 
                     numvalid++;
                } else {
                     int c = s[left++] - 'a';
                    if (freq[c]-- == k) 
                     numvalid--;
                    if (freq[c] == 0) 
                     unique--;
                }

                if (unique == target && unique == numvalid ) {
                    ans = max(ans, right - left);
                }
            }
        }

        return ans;
    }
};