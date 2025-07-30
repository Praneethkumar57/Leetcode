class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int>mpp;
        mpp[0]=-1;
        int sum = 0;
        int maxi = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                sum = sum -1;
            }
            else{
                sum = sum + 1;
            }
            if(mpp.find(sum)==mpp.end()){
               mpp[sum]=i;
            }
            else{
                maxi = max(maxi,(i-mpp[sum]));
            }
            
        }
        return maxi;
        
    }
};