// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int l = 0, r = n - 1;
        while (l < r) {
            if (knows(l, r)) ++l;
            else --r;
        }// if there is a celebrity, index shoud be r.
        
        // if he doesn't know others, and no boday doesn't know him.
        for (int i = 0; i < n; ++i) if (i != l) {
            if (knows(l, i) || !knows(i, l)) return -1;
        }
        return l;
    }
};