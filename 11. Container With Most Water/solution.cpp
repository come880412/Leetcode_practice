class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0, maxArea=0,end=height.size()-1;
        
        int area;
        while(start < end){
            area = min(height[start], height[end]) * (end - start);
            if(area >= maxArea) maxArea = area;
            
            if(min(height[start], height[end]) == height[start])
                start++;
            else
                end--;
            
        }
        return maxArea;
        
    }
};