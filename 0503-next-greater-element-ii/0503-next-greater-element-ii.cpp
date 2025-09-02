class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int flag=0;
            for(int j=i+1;j<i+n;j++){
                int index=j%n;
                if(nums[index]>nums[i]){
                    res.push_back(nums[index]);
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                res.push_back(-1);
            }
        }
        return(res);
    }
};