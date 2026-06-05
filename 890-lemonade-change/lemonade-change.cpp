class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int YourTenCount = 0; // Keeping track of $10 bills

        for (int bill : bills) {
            if (bill == 5) {
                five++;
            } 
            else if (bill == 10) {
                // To give change for a $10 bill, we need exactly one $5 bill
                if (five == 0) return false;
                five--;
                YourTenCount++;
            } 
            else { // bill == 20
                // Greedy strategy: try giving a $10 and a $5 first
                if (YourTenCount > 0 && five > 0) {
                    YourTenCount--;
                    five--;
                } 
                // Fallback strategy: try giving three $5 bills
                else if (five >= 3) {
                    five -= 3;
                } 
                // If neither option is available, we can't provide change
                else {
                    return false;
                }
            }
        }
        
        return true;
    
    }
};