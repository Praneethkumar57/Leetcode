class Solution {
public:
    string strWithout3a3b(int a, int b) {
        int s=0;
        string ans="";
        if(b>a)s=1;
        while(a || b){
            if(s==0){
                if(a>=b && a>=2){
                    ans+="aa";
                    a-=2;
                }
                else{
                    int k = b/2 + b%2;
                    if(a>k && a>=2){
                        ans+="aa";
                        a-=2;
                    }
                    else{
                        ans+='a';
                        a-=1;
                    }
                }
                s=1;
            }
            else{
                if(b>=a && b>=2){
                    ans+="bb";
                    b-=2;
                }
                else{
                    int k = a/2 + a%2;
                    if(b>k && b>=2){
                        ans+="bb";
                        b-=2;
                    }
                    else{
                        ans+='b';
                        b-=1;
                    }
                }
                s=0;
            }
        }
        return ans;
    }
};