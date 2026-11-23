class ProductOfNumbers {
public:
    vector<int> st;
    int i = -1;
    int n;
    ProductOfNumbers() {
        n = 0;
    }
    
    void add(int num) {
        st.push_back(num);
        n++;
        i++;
    }
    
    int getProduct(int k) {
        int p = 1;
        for(int j = n-k; j < n; j++) p *= st[j];
        return p;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */