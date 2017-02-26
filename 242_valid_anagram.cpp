// s = "anagram", t = "nagaram", return true.
// s = "rat", t = "car", return false.

// hash table stores number of appearance of each char, ++ for s, -- for t.
// hash.first, hash.second;

class Solution {
public:
    bool isAnagram(string s, string t){
        if (s.length()!=t.length()) return false;
        int n=s.length();
        unordered_map<char, int> counts;
        for (int i=0; i<n; i++) {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        // traverse a hash table
        for (auto count:counts) {
            if (count.second) {
                return false;
            }
        }
        return true;
    }
};

// only lowercase
// use a vector instead of a hash table, index:char, index = s[i]-'a';

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        int counts[26] = {0};
        for (int i = 0; i < n; i++) {
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (counts[i]) return false;
        return true;
    }
};