class MyCircularDeque {
public:
    MyCircularDeque(int k) : k_(k) {};
    
    bool insertFront(int value) {
        if (deque_.size() < k_) {
            deque_.insert(deque_.begin(), value);
            return true;
        } else {
            return false;
        }
    }
    
    bool insertLast(int value) {
        if (deque_.size() < k_) {
            deque_.insert(deque_.end(), value);
            return true;
        } else {
            return false;
        }
    }
    
    bool deleteFront() {
        if (deque_.size() == 0) return false;
        else {
            deque_.erase(deque_.begin());
            return true;
        }
    }
    
    bool deleteLast() {
        if (deque_.size() == 0) return false;
        else {
            deque_.erase(deque_.end());
            return true;
        }
    }
    
    int getFront() {
        if (deque_.size() == 0) return -1;
        else return deque_[0];
    }
    
    int getRear() {
        if (deque_.size() == 0) return -1;
        else return deque_[deque_.size()-1];
    }
    
    bool isEmpty() {
        return deque_.size() == 0;
    }
    
    bool isFull() {
        return deque_.size() == k_;
    }
private:
    int k_;
    vector<int> deque_;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */