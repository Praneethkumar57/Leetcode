int binary2decimal(string s){
    long long p2=1;
    int sum = 0;
    int l=s.size();
    for(int i=l-1;i>=0;i--){
        if(s[i]=='1'){
            sum = sum + (p2);
        }
        p2 = p2*2;
    }
    return sum;
}

class Solution {
public:
    int reverseBits(int n) {
        string s ="";
        for(int i=0;i<32;i++){
            if(n%2==1) s+='1';
            else s+='0';
            n=n/2;
        }
        
        int num = binary2decimal(s);
        return num;
    }
};