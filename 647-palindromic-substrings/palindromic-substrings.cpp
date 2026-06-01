class Solution {
public:
    int countSubstrings(string s) {
        int totalCount = 0;
        for (int i = 0; i < s.length(); i++) {
           
            totalCount += expandFromCenter(s, i,i);
            
        
            totalCount += expandFromCenter(s, i, i + 1);
        }
        
        return totalCount;
    }

private:
    int expandFromCenter(const string& s, int left, int right) {
        int count = 0;
        
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;
            left--;   // Move left pointer outward
            right++;  // Move right pointer outward
        }
        
        return count;

    }
};