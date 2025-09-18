class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int> st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        vector<int> arr;
        for(auto it:st){
            arr.push_back(it);
        }
        
        sort(arr.begin(),arr.end());
        for(auto it:arr){
            cout<<it<<" ";
        }
        int m=arr.size();
        cout<<m;
        int i=m-1;
        vector<int> res;
        while(k>0 && i>=0){
            res.push_back(arr[i]);
            i--;
            k--;
        }
        return res;
    }
};