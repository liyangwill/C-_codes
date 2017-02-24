//word1 and word2 can be same.

int shortestWordDistance(vector<string>& words, string word1, string word2) {
    int res = INT_MAX;
    int idx1 = -1, idx2 = -1;
    for (int i = 0; i < words.size(); i++) {
        if (word1 != word2) {
            if (words[i] == word1) {
                idx1 = i;
            }
            else if (words[i] == word2) {
                idx2 = i;
            }
        }
        else {
            if (words[i] == word1) {
                idx2 = idx1;
                idx1 = i;
            }
        }
        if (idx1 != -1 && idx2 != -1) {
            res = min(res, abs(idx1 - idx2));
        }
    }
    return res;
}