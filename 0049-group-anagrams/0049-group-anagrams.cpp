class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;
        unordered_map<string, vector<string>> strings;

        for(int i=0; i<strs.size(); i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            strings[s].push_back(strs[i]);
        }
        
        for(const auto[key,val]:strings){
            anagrams.push_back(val);
        }
        return anagrams;
    }
};