int cnt=0;

void fn(int n,vector<int>& arr,int index){
    if(index>n){
        cnt++;
        return; 
    }

    for(int i=1;i<=n;i++){
        if(arr[i]==0 && (i%index==0 || index%i==0)){
            arr[i]=1;
            fn(n,arr,index+1);
            arr[i]=0;
        } 
    }
    return;
}

class Solution {
public:
    int countArrangement(int n) {
        cnt=0;
        vector<int> arr(n+1,0);
        fn(n,arr,1);
        return cnt;
    }
};