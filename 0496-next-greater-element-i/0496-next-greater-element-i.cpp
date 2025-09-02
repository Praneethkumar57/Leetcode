class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge;
        stack<int> st;
        int n=nums2.size();
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                nge.push_back(-1);
                st.push(nums2[i]);
            }
            else{
                while(!st.empty()){
                    if(st.top()>nums2[i]){
                        nge.push_back(st.top());
                        st.push(nums2[i]);
                        break;
                    }
                    else{
                        st.pop();
                    }
                }
                if(st.empty()){
                    nge.push_back(-1);
                    st.push(nums2[i]);
                }
                
            }
        }
        reverse(nge.begin(),nge.end());
        for(auto it:nge){
            cout<<it<<" ";
        }
        vector<int> res;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<n;j++){
                if(nums1[i]==nums2[j]){
                    res.push_back(nge[j]);
                    break;
                }
            }
        }
        return(res);
    }
};