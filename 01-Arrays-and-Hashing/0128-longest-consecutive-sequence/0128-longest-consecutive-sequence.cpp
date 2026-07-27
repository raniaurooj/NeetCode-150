class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> temp;
        int result = 0;
        
        for(int i=0; i<nums.size(); i++){
            temp.insert(nums[i]);
        }
        
        for(int item: temp){
            int num = item;
            int count = 0;
            if(temp.find(item-1) == temp.end()){
                while(temp.find(num) != temp.end()){
                    num=num+1;
                    count++;
                }
                result = max(count,result); 
            }
        }
        
        return result;
    }
};