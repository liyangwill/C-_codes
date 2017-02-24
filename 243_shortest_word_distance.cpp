// O(n) space O(1)
public class Solution{
    public int shortestDistance(vector<string> words, string word1, string word2){
        int idx1 = -1, idx2 = -1, distance = INT_MAX;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                idx1 = i;
                if (idx2 != -1) distance=min(distance, idx1-idx2);
            }
            if (words[i] == word2) {
                idx2 = i;
                if (idx1 != -1) distance=min(distance, idx2-idx1);
            }
        }
        return distance;
    }
};
