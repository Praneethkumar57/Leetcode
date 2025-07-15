int min(int n1, int n2){
    if(n1<=n2){
        return n1;
    }
    else{
        return n2;
    }
}

class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = INT_MAX;
        int low = 0;
        int high = nums.size()-1;

        while(low<=high){
            int mid = (low + high)/2;
            if(nums[low]==nums[mid] && nums[mid] == nums[high]){
                if(nums[mid]<mini){
                    mini = nums[mid];
                }
                low++;
                high--;
            }
            else if(nums[low]<=nums[mid]){
                mini = min(nums[low],mini);
                low = mid + 1;
            }
            else{
                mini = min(nums[mid],mini);
                high = mid - 1; 
            }
        }
        return mini;
    }
};