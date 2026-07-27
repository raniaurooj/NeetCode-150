class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char, int> need;
        unordered_map<char, int> windowCount;
        
        for(char c: t) need[c]++;
        
        int required = need.size();
        int formed = 0;
        int right = 0, left = 0;
        int minLength = INT_MAX;
        int length = 0;
        
        for(right; right<s.length(); right++){
             windowCount[s[right]]++;
            
             if(need.count(s[right]) && windowCount[s[right]] == need[s[right]]){
                 formed++;
             }
             while(formed == required){
                 if(right-left + 1 < minLength){
                     minLength = right - left + 1;
                     length = left;
                 }
                 
                 windowCount[s[left]]--;
                 if(need.count(s[left]) && windowCount[s[left]]<need[s[left]]){
                     formed--;
                 }
                 left++;
             }
        }
        
        return minLength == INT_MAX ? "" : s.substr(length , minLength);
        
        
    }
};