#include <stdio.h>
#include <vector>
#include <iostream>

class MaxHeap {
    private:
        std::vector<int> data;
        
        int parent(int i) { return (i - 1) / 2;}
        int leftChild(int i) { return 2 * i + 1;}
        int rightChild(int i) { return 2 * i + 2;}
        
        void siftUp(int idx) {
            while (idx != 0 && data[idx] > data[parent(idx)]) {
                std::swap(data[idx], data[parent(idx)]);
                idx = parent(idx);
            }
        }
        
        void siftDown(int idx) {
            int maxIdx = idx;
            if (leftChild(idx) < data.size() && data[maxIdx] < data[leftChild(idx)]) {
                maxIdx = leftChild(idx);
            } 
            if (rightChild(idx) < data.size() && data[maxIdx] < data[rightChild(idx)]) {
                maxIdx = rightChild(idx);
            }
            
            if (maxIdx != idx) {
                std::swap(data[maxIdx], data[idx]);
                siftDown(idx);
            }
        }
        
    public:
        void insert(int element) {
            data.push_back(element);
            siftUp(data.size() - 1);
        }
        
        int extractMax() {
            if (data.size() == 0) {
                throw std::range_error("extractMax() called on empty heap");
            }
            
            int maxNum = data[0];
            data[0] = data.back();
            data.pop_back();
            siftDown(0);
            return maxNum;
        }
        
        void printHeap() {
            for (int i = 0; i < data.size(); ++i) {
                std::cout << data[i] << " ";
            }
            std::cout << "\n";
        }
};

int main() {
    MaxHeap heap;
    heap.insert(20);
    heap.insert(15);
    heap.insert(30);
    heap.insert(5);
    heap.insert(10);

    std::cout << "Initial heap: ";
    heap.printHeap();

    std::cout << "Extracted max: " << heap.extractMax() << std::endl;
    std::cout << "Heap after extracting max: ";
    heap.printHeap();

    return 0;
}