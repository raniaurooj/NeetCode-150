class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> freq;
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
        }

        vector<vector<int>> bucket(nums.size()+1);

        for(auto [val,count]:freq){
            bucket[count].push_back(val);
        }

        vector<int> result;
        for(int i = nums.size(); i>0; i--){
            if(bucket[i].size() > 0 ){
                for(int val: bucket[i]){
                    if(result.size()<k){
                        result.push_back(val);
                    }
                    else return result;
                }
            }
        }

        return result;
    }
};