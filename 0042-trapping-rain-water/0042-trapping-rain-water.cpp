class Solution {
public:
    int trap(vector<int>& height) {
        int total =0;
        int n=height.size();
        int prefixMax[n];
        int suffixMax[n];
        prefixMax[0]=height[0];
        for(int i=1;i<n;i++){
            prefixMax[i]=max(prefixMax[i-1],height[i]);
        }
        suffixMax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            suffixMax[i]=max(suffixMax[i+1],height[i]);
        }
        for(int i=0;i<n;i++){
            int leftmax = prefixMax[i];
            int rightmax = suffixMax[i];
            if(height[i]<leftmax && height[i]<rightmax){
                total += min(leftmax,rightmax)-height[i];
            }
        }
        return total;
    }
};