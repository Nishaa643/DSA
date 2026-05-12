class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // Step 1: Sort the array to make it easier to work with sliding window
        sort(nums.begin(), nums.end());
        
        long long total = 0; // Total operations needed for the current window
        int left = 0;         // Left pointer of the sliding window
        int maxFreq = 1;      // Initialize maximum frequency

        // Step 2: Iterate through the array with the right pointer
        for (int right = 1; right < nums.size(); right++) {
            // Calculate the total operations needed to make all elements in the window equal to nums[right]
            total += static_cast<long long>(nums[right] - nums[right - 1]) * (right - left);
            
            // Step 3: If total operations exceed k, shrink the window from the left
            while (total > k) {
                total -= nums[right] - nums[left];
                left++;
            }
            
            // Step 4: Update the maximum frequency
            maxFreq = max(maxFreq, right - left + 1);
        }
        
        return maxFreq;

    }
};