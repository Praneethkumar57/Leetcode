class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mini = INT_MAX;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum = sum+nums[i];
            mini = min(mini,sum);
        }
        if(mini>=0){
            return 1;
        }
        
        else{
            return((-1*mini)+1);
        }
    }
};