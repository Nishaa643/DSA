class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> lower_set;
        unordered_set<char> upper_set;
        
        for (char c : word) {
            if (islower(c)) {
                lower_set.insert(c);
            } else {
                upper_set.insert(c);
            }
        }
        
        int special_count = 0;
    
        for (char c = 'a'; c <= 'z'; ++c) {
            if (lower_set.count(c) && upper_set.count(toupper(c))) {
                special_count++;
            }
        }
        
        return special_count;

    }
};