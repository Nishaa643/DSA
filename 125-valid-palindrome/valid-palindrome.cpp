class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;

        while (start < end) {
            // Skip non-alphanumeric characters for the start pointer
            while (start < end && !isalnum(s[start])) {
                start++;
            }

            // Skip non-alphanumeric characters for the end pointer
            while (start < end && !isalnum(s[end])) {
                end--;
            }

            // Compare the lowercase characters
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }

            // Move both pointers closer to the center
            start++;
            end--;
        }

        return true; // If the loop completes, it is a palindrome


    }
};