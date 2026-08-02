class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(int i=0; i<strs.size(); i++){
            encoded += to_string(strs[i].length());
            encoded.push_back('#');
            encoded.append(strs[i]);
        }

       return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded; 
        int len = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='#'){
                string no = s.substr(len,i-len);
                len = stoi(no);
                decoded.push_back(s.substr(i+1, len));
                i = len = i+len+1; 
            }
        }
        return decoded;
    }
};
