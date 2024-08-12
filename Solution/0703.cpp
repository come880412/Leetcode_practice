class KthLargest {
public:
    // minHeap keeps k elements, which represent the 1st largest, 2nd largest, ... kth largest
    KthLargest(int k, vector<int>& nums) {
        for (const int num : nums) {
            if (this->minHeap.size() < k)
                this->minHeap.push(num);
            else {
                if (num > this->minHeap.top()) {
                    this->minHeap.pop();
                    this->minHeap.push(num);
                }
            }
        }
        this->k_ = k;
    }
    
    int add(int val) {
        if (this->minHeap.size() < this->k_)
            this->minHeap.push(val);
        else {
            if (val > this->minHeap.top()) {
                    this->minHeap.pop();
                    this->minHeap.push(val);
                }
        }
        return this->minHeap.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */