class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> slidingWindowMax;
        int i = 0;
        
        for(i; i<nums.size(); i++){
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            
            if(i>=k-1){
                slidingWindowMax.push_back(nums[dq.front()]);
            }
            if(dq.front() == (i+1)-k){
                dq.pop_front();
            }
        }
        
        return slidingWindowMax; 
    }
};