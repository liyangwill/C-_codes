class WordDistance{
public:
    wordDistance(vector<srting>& words){
        for (int i=0; i<words.size(); i++) {
            map[words[i]].push_back(i);
        }
        int shortestDistance(srting word1, string word2){
            int res = INT_MAX;
            vector<int>& v1 = map[word1];
            vector<int>& v2 = map[word2];
            
            int i=0, j=0;
            while (i<v1.size()&&j<v2.size()) {
                res=min(res, abs(v1[i]-v2[j]));
                v1[i] > v2[j] ? j++ : i++;
            }
            return res;
        }
    }
private:
    unordered_map<string, vector<int>> map;
};