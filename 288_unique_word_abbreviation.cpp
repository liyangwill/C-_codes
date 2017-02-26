class ValidWordAbbr {
private:
    unordered_map<string, int> m_map;
    unordered_set<string> m_set;
    
public:
    ValidWordAbbr(vector<string> &dictionary) {
        
        for (auto word : dictionary) {
            m_set.insert(word);
            if (word.length() == 2) ++m_map[word];
            else ++m_map[word.front() + to_string(word.length() - 2) + word.back()];
        }
    }
    
    bool isUnique(string word) {
        string key;
        if (word.length() == 2) key = word;
        else key = word.front() + to_string(word.length() - 2) + word.back();
        
        // if word is not in the dictionary
        if (m_set.find(word) == m_set.end()) return m_map[key] < 1;
        // if word is in the dictionary
        else return m_map[key] < 2;
    }
};

