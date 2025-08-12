class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
            return false;
        }
        set<int> arr;
        arr.insert(nums[0]+nums[1]);
        for(int i=1;i<n-1;i++){
            int sum = nums[i]+nums[i+1];
            if(arr.find(sum)!=arr.end()){
                return true;
            }
            else{
                arr.insert(sum);
            }
        }
        return false;
        
    }
};