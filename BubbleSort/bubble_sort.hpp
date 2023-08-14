#pragma once

#include <vector>

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for(int i=0; i< nums.size()-1;++i){
            for(int j=i+1;j<nums.size();++j)
                if(nums[j]<nums[i])
                    std::swap(nums[i],nums[j]);
        }
        return nums;
    }
};
