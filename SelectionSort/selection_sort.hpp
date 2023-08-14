#pragma once

#include <vector>

// https://leetcode.com/problems/sort-an-array/
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                std::swap(nums[i], nums[minIndex]);
            }
        }
        return nums;
    }
};

