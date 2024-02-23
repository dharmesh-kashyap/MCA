#include <iostream>
using namespace std;


int removeDuplicates(int* nums, int size) {
    if (size <= 1) {
        return size;
    }
    
    int i = 0; 
    for (int j = 1; j < size; j++) {
        if (nums[j] != nums[i]) {
            
            i++;
            nums[i] = nums[j];
        }
    }
    
    
    for (int j = i + 1; j < size; j++) {
        nums[j] = 0;
    }
    
    return i+1; 
}

int main() {
    int nums[] = {1, 1, 3, 4, 4, 4, 5, 2};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    int numUnique = removeDuplicates(nums, size);
    
    for (int i = 0; i < numUnique; ++i) {
        cout<< nums[i] << " ";
    }
    cout << "\n The number of unique elements are : " << numUnique;
    return 0;
}