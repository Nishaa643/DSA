class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize!= 0){
            return false;
        }
    std :: map<int,int> cardCounts;
    for(int card: hand){
        cardCounts[card]++;
    }
    for (auto const& [card, count] : cardCounts) {
            if (cardCounts[card] > 0) {
                int currentCount = cardCounts[card];
                
                // We need to form 'currentCount' number of groups starting with 'card'
                for (int i = 0; i < groupSize; ++i) {
                    int nextCard = card + i;
                    
                    // If the required consecutive card is unavailable in sufficient quantity
                    if (cardCounts[nextCard] < currentCount) {
                        return false;
                    }
        cardCounts[nextCard] -= currentCount;
                }
            }
        }
        
        return true;
    }
};