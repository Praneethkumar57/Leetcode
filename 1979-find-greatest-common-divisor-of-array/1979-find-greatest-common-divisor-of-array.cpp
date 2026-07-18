class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int a=nums[0], b=nums[n-1];
        return gcd(a,b);
    }
};