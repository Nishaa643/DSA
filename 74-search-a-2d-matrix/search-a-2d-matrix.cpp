class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();      // Number of rows
        int n = matrix[0].size();   // Number of columns
        
        int low = 0;
        int high = (m * n) - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            
            int mid_element = matrix[mid / n][mid % n];
            
            if (mid_element == target) {
                return true;
            } else if (mid_element < target) {
                low = mid + 1; // Search the right half
            } else {
                high = mid - 1; // Search the left half
            }
        }
        
        return false;
        
    }
};