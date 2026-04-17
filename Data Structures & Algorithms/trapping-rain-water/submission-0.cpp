class Solution {
public:
    int trap(vector<int>& height) {
        int leftmax = 0;
        int rightmax = 0;
        int total = 0;
        int n = height.size();
        int left = 0;
        int right = n-1;

        while(left<right){
            if(height[left] <= height[right]){
                if(leftmax > height[left]){
                    total += leftmax - height[left];
                }
                else{
                    leftmax = height[left];
                }
                 left = left + 1;
            }
           

            else{
                if(rightmax>height[right]){
                    total += rightmax - height[right];
                }
                else{
                    rightmax = height[right];
                }
                 right = right - 1;
            }
           
        }
        return total;
    }
};
