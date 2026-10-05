class Solution {
public:
    int longestSubstring(string s, int k) {
        return helper(s, 0, s.size(), k);
    }

private:
    int helper(const string& s, int start, int end, int k) {
        if (end - start < k) return 0;

        int count[26] = {0};
        for (int i = start; i < end; ++i) {
            count[s[i] - 'a']++;
        }

        
        for (int mid = start; mid < end; ++mid) {
            if (count[s[mid] - 'a'] < k) {
               
                int nextMid = mid + 1;
                while (nextMid < end && count[s[nextMid] - 'a'] < k) {
                    nextMid++;
                }
                return max(helper(s, start, mid, k), helper(s, nextMid, end, k));
            }
        }

        return end - start;
    }
};