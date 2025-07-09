int max_val(vector<vector<int>>& mat, int mid, int n){
    int val=INT_MIN, index = -1;
    for(int i=0;i<n;i++){
        if(mat[i][mid]>val){
            val = mat[i][mid];
            index = i;
        }
    }
    return index;
}

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m-1;
        while(low<=high){
            int mid = (low + high)/2;
            int row = max_val(mat,mid,n);
            int left,right;

            // assign left value
            if(mid-1>=0){
                left = mat[row][mid-1];
            }
            else{
                left = -1;
            }

            // assign right value
            if(mid+1 <m ){
                right = mat[row][mid+1];
            }
            else{
                right = -1;
            }

            if(mat[row][mid]>left && mat[row][mid]>right){
                return{row,mid};
            }
            else if(mat[row][mid]<left){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return{-1,-1};
    }
};