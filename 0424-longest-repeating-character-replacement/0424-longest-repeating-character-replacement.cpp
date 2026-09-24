class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        int end = 0;
        int subStr = 0;
        unordered_map<char, int> freq;
        int maxFreq = 0;
        int change = 0; 

        for(end; end<s.length(); end++){
            freq[s[end]]++;
            maxFreq = max(maxFreq, freq[s[end]]);
            change = (end - start + 1) - maxFreq;
            if( change > k){
                subStr = max(subStr, end - start);
                freq[s[start]]--;
                start++;
            }
            else if((change <= k) && end == s.length()-1){
                subStr = max(subStr, end - start +1);
            }
            
        }

        return subStr;
    }
};