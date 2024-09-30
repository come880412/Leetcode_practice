class CustomStack {
public:
    CustomStack(int maxSize) {
        capacity_ = maxSize;
    }
    
    void push(int x) {
        if (s_.size() >= capacity_) return;
        else s_.emplace_back(x);
    }
    
    int pop() {
        if (s_.empty()) return -1;
        int num = s_.back();
        s_.pop_back();
        return num;
    }
    
    void increment(int k, int val) {
        int idx = k >= s_.size() ? s_.size(): k;
        for (int i = 0; i < idx; ++i) s_[i] += val;
    }
private:
    int capacity_;
    vector<int> s_;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */