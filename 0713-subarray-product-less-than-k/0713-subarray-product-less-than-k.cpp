class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<k){
                cnt++;
                int j=i-1;
                int prod=nums[i];
                while(j>=0){
                    prod = prod*nums[j];
                    if(prod < k){
                        cnt++;
                    }
                    else{
                        break;
                    }
                    j--;
                }
            }
        }
        return cnt;
    }
};