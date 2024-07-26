class Solution {
public:
    // Quick Sort O(nlogn)
    // vector<int> sortArray(vector<int>& nums) {
    //     int n = nums.size();
    //     quickSort(nums, 0, n - 1);
    //     return nums;
    // }

    // void quickSort(vector<int> &nums, int start, int end) {
    //     if (start < end) {
    //         int swapIdx = partition(nums, start, end);
    //         quickSort(nums, start, swapIdx - 1);
    //         quickSort(nums, swapIdx + 1, end);
    //     }
    // }

    // int partition(vector<int> &nums, int start, int end) {
    //     int pivot = nums[end];
    //     int swapIdx = start;
    //     for (int i = start; i < end; ++i) {
    //         if (nums[i] <= pivot) {
    //             swap(nums[swapIdx], nums[i]);
    //             swapIdx++;
    //         }
    //     }
    //     swap(nums[swapIdx], nums[end]);
    //     return swapIdx;
    // }

    // Merge Sort O(nlogn)
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return nums;
    }

    void mergeSort(vector<int> &nums, int start, int end) {
        if (start < end) {
            int mid = (start + end) / 2;
            mergeSort(nums, start, mid);
            mergeSort(nums, mid + 1, end);
            merge(nums, start, mid, end);
        }
    }

    void merge(vector<int> &nums, int start, int mid, int end) {
        vector<int> leftArr;
        vector<int> rightArr;
        for (int i = 0; i < mid - start + 1; ++i) leftArr.push_back(nums[start + i]);
        for (int i = 0; i < end - mid; ++i) rightArr.push_back(nums[mid + i + 1]);
        leftArr.push_back(INT_MAX);
        rightArr.push_back(INT_MAX);

        int leftIdx = 0, rightIdx = 0;
        for (int i = start; i <= end; ++i) {
            if (leftArr[leftIdx] <= rightArr[rightIdx]) {
                nums[i] = leftArr[leftIdx];
                leftIdx++;
            } else {
                nums[i] = rightArr[rightIdx];
                rightIdx++;
            }
        }
    }
};