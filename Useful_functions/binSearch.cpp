#include <stdio.h>
#include <iostream>
#include <vector>

int binSearch(const std::vector<int> &sortedArray, int searchNum) {
    int left = 0;
    int right = sortedArray.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;;
        if (sortedArray[mid] > searchNum) {
            right = mid - 1;
        } else if (sortedArray[mid] < searchNum) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> sortedArray = {1, 4, 9, 16, 20, 24, 28, 32};
    int searchNum = 1;
    int searchIdx = binSearch(sortedArray, searchNum);
    
    std::cout << searchIdx;

    return 0;
}