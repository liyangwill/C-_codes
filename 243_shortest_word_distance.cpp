// For example, Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

// Given word1 = "coding", word2 = "practice", return 3. Given word1 = "makes", word2 = "coding", return 1.

// traverse string list, maintain two indice, idx1 and idx2 of last appearance.

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
