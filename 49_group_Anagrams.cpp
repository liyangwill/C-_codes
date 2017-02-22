/**
 * unordered_map
 * 
 */
class Solution {
public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
                unordered_map<string, multiset<string>> mp;
                for (string s : strs) {
                        string t = s; 
                        sort(t.begin(), t.end());
                        mp[t].insert(s); //insert s into mp with label t.
                }
                vector<vector<string>> anagrams; //extract vector of strings from unordered_map
                for (auto m : mp) { 
                        vector<string> anagram(m.second.begin(), m.second.end()); //anagram function 
                        anagrams.push_back(anagram);
                }
                return anagrams;
        }
};