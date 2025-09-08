class Solution {
public:
    int minOperations(vector<int>& nums) {
        int change=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]!=nums[i]){
                change = 1;
                break;
            }
        }
        if(change==0){
            return 0;
        }
        return 1;
    }
};