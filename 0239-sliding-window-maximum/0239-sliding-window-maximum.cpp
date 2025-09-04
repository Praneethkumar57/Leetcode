class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> qe;
        int n = nums.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            while(!qe.empty() && qe.front()<=i-k){
                qe.pop_front();
            }
            while(!qe.empty() && nums[i]>nums[qe.back()]){
                qe.pop_back();
            }
            qe.push_back(i);
            if(i>=k-1){
                res.push_back(nums[qe.front()]);
            }
        }
        return res;
    }
};