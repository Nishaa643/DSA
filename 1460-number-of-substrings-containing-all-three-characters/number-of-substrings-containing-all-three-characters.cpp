class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = static_cast<int>(s.size());
        int count[3] = {0, 0, 0};
        int left = 0;
        long long total = 0;

        for (int right = 0; right < n; ++right) {
            count[s[right] - 'a']++;

            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                total += (n - right);
                count[s[left] - 'a']--;
                left++;
    }
        }
        return static_cast<int>(total);
    }
};