class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<long long> preMax;
        vector<long long> sufMax;
        stack<int> st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(nums[i]);
                preMax.push_back(-1);
            }
            else{
                preMax.push_back(st.top());
                if(nums[i]>st.top()){
                    st.push(nums[i]);
                }
            }
        }
        stack<int> st1;
        for(int i=n-1;i>=0;i--){
            if(st1.empty()){
                st1.push(nums[i]);
                sufMax.push_back(-1);
            }
            else{
                sufMax.push_back(st1.top());
                if(nums[i]>st1.top()){
                    st1.push(nums[i]);
                }
            }
        }
        reverse(sufMax.begin(),sufMax.end());
        long long maxi = 0;
        for(int i=1;i<n-1;i++){
            long long val = ((long long)preMax[i]-(long long)nums[i])*(long long)sufMax[i];
            maxi = max(maxi,val);
        }
        return(maxi);
    }
};