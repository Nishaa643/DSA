class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> min_suffix(n);
        
      
        min_suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            min_suffix[i] = std::min(nums[i], min_suffix[i + 1]);
        }
        
        int max_prefix = nums[0];
        
        
        for (int i = 0; i < n; ++i) {
            max_prefix = std::max(max_prefix, nums[i]);
            if (max_prefix - min_suffix[i] <= k) {
                return i;
            }
        }
        
        return -1;
    }
};