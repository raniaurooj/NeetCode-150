class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int w = 0;
        int h = 0;
        int maxArea = 0;
        
        while(left<right){
            w = right - left;
            h = min(height[left],height[right]);
            
            maxArea = max(maxArea,(w*h));
            
            if(h == height[left]) left++;
            else right--;
        }
        
        return maxArea;
    }
};