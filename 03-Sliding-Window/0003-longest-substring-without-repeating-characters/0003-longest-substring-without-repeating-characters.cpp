class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> subStr;
        int result = 0;
        int start = 0;
        
        for(int i=0; i<s.length(); i++){
            if(subStr.find(s[i]) == subStr.end()){
                subStr[s[i]] = i;
            }
            else{
                if(subStr[s[i]] >= start){
                    start = subStr[s[i]]+1;
                }
                subStr[s[i]] = i;
            }
            result = max(result, i - start+1);
        }
        return result;
    }
};