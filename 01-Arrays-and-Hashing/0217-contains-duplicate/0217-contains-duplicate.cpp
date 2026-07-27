class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = 1;
        for(right; right < nums.size(); right++){
            if(nums[left]!=nums[right]){
                left++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};