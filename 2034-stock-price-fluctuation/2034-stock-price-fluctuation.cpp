class StockPrice {
public:
    unordered_map<int,int> mpp; 
    multiset<int> st;
    int curr,stamp;
    StockPrice() {
        curr=0;
        stamp=0;
    }
    
    void update(int time, int price) {
        if(mpp.count(time)){
            auto it = st.find(mpp[time]);
            st.erase(it);
        }

        mpp[time] = price;
        st.insert(price);
        if(time>=stamp){
            curr = price;
        }
        stamp = max(stamp,time);
    }
    
    int current() {
        return curr;
    }
    
    int maximum() {
        return *st.rbegin();
    }
    
    int minimum() {
        return *st.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */