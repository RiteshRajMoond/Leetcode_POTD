class CustomStack {
private:
    vector<int> st;
    int size;
    int MAX;

public:
    CustomStack(int maxSize) {
        size = 0;
        MAX = maxSize;
    }

    void push(int x) {
        if(size <  MAX) {
            st.push_back(x);
            size++;
        }
    }

    int pop() {
        if(size == 0) return -1;

        int num = st.back();
        st.pop_back();
        size--;
        return num;
    }

    void increment(int k, int val) {
        for(int i = 0; i < min(k, size); i++) {
            st[i] += val;
        }
    }
};
