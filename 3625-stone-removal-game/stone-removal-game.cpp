class Solution {
public:
    bool canAliceWin(int n) {
       int remove = 10;
        bool aliceTurn = true;

        while (n >= remove) {
            n -= remove;
            remove--;
            aliceTurn = !aliceTurn;
        }

        // If aliceTurn is currently true, Bob made the last move and Alice cannot move.
        return !aliceTurn; 
    }
};