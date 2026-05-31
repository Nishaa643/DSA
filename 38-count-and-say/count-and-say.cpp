class Solution {
public:
    string countAndSay(int n) {
        string current = "1";
        for (int i = 2; i <= n; ++i) {
            string nextString = "";
            int len = current.length();
            
            int j = 0;
            while (j < len) {
                char ch = current[j];
                int count = 0;
                while (j < len && current[j] == ch) {
                    count++;
                    j++;
                }
                nextString += to_string(count) + ch;
            }
            
            current = nextString;
        }
        
        return current;
    }
};