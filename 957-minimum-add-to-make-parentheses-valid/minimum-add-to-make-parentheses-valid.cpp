class Solution {
public:
    
       int minAddToMakeValid(string s) {
    int open = 0;   // unmatched '('
    int close = 0;  // unmatched ')'
    
    for (char c : s) {
        if (c == '(') {
            open++;
        } else {
            if (open > 0)
                open--;   // matched with previous '('
            else
                close++;  // no '(' to match, need to insert one
        }
    }
    
    return open + close;
 
    }
};