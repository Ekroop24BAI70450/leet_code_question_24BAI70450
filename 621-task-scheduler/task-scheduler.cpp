class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};

        for (char task : tasks) {
            freq[task - 'A']++;
        }

        int maxFreq = 0;
        for (int f : freq) {
            maxFreq = max(maxFreq, f);
        }

        int maxCount = 0;
        for (int f : freq) {
            if (f == maxFreq) {
                maxCount++;
            }
        }

        int slots = (maxFreq - 1) * (n + 1) + maxCount;

        return max((int)tasks.size(), slots);
    }
};
