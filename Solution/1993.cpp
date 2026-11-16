class LockingTree {
public:
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        this->parent = parent;
        this->locked.assign(n, -1);
        for (int i = 1; i < n; ++i) {
            this->childs[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if (this->locked[num] != -1) return false;
        this->locked[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if (this->locked[num] != user) return false;
        this->locked[num] = -1;
        return true; 
    }
    
    bool upgrade(int num, int user) {
        if (this->locked[num] != -1) return false;
        int tmp = this->parent[num];
        while (tmp != -1) {
            if (this->locked[tmp] != -1) return false;
            tmp = this->parent[tmp];
        }

        int lockedDescendant = 0;
        queue<int> q;
        q.push(num);
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            if (this->childs.find(tmp) != this->childs.end()) {
                for (int& child : this->childs[tmp]) {
                    q.push(child);
                    if (this->locked[child] != -1) lockedDescendant++;
                    this->locked[child] = -1;
                }
            }
        }
        if (lockedDescendant > 0) {
            this->locked[num] = user;
            return true;
        } 
        else return false;

    }
private:
    vector<int> locked;
    vector<int> parent;
    unordered_map<int, vector<int>> childs;
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */