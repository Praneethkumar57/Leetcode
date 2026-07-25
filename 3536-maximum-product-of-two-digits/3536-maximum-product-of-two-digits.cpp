class Solution {
public:
    int maxProduct(int n) {
        vector<int> arr;
        while(n){
            int k = n%10;
            arr.push_back(k);
            n=n/10;
        }
        int maxi=0;
        for(int i=0;i<arr.size();i++){
            int a=arr[i];
            for(int j=i+1;j<arr.size();j++){
                int b=arr[j];
                maxi = max(maxi,a*b);
            }
        }
        return maxi;
    }
};