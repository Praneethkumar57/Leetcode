int counting_ways(int index,vector<int>& dynamic){
    if(index == 0){
        return 1;
    }
    if(index<0){
        return 0;
    }
    
    if(dynamic[index]!=-1){
        return dynamic[index];
    }
    int left = counting_ways(index-1,dynamic);
    int right = counting_ways(index-2,dynamic);
    dynamic[index] = left+right;
    return (dynamic[index]);
}

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dynamic(n+1,-1);
        int res = counting_ways(n,dynamic);
        return(res);
    }
};