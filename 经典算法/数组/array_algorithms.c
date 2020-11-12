//
//  array_algorithms.c
//  经典算法
//
//  Created by zhangdu_imac on 2020/10/23.
//

#include "array_algorithms.h"
#include <stdlib.h>

void moveZeroes(int *nums, int numSize) {
//    int j = 0;
//    for (int i = 0; i < numSize; i++) {
//        if (nums[i] != 0) {
//            // 将不是0的元素放到最前
//            nums[j++] = nums[i];
//        }
//    }
//    // 末尾补0
//    for (int k = 0; k < j; k++) {
//        nums[k + j] = 0;
//    }
    
    int m = 0;
    for (int i = 0; i < numSize; i++) {
        if (nums[i] == 0) {
            m++;
        } else if (m > 0) {
            nums[i - m] = nums[i];
            nums[i] = 0;
        }
    }
    
    for (int i = 0; i < numSize; i++) {
        printf("%d\n", nums[i]);
    }
}

/// 快速排序数组
void quickSort(int *nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int first = left, last = right;
    // 中间数key
    int key = nums[left];
    while (first < last) {
        // 从后往前遍历，找到小于key的值，赋值给first
        while (first < last && nums[last] >= key) {
            last--;
        }
        nums[first] = nums[last];
        
        // 从前往后遍历，找到大于key的值，赋值给last
        while (first < last && nums[first] <= key) {
            first++;
        }
        nums[last] = nums[first];
    }
    
    // 当组内找完一遍以后就把中间数key回归
    nums[first] = key;
    
    quickSort(nums, left, first - 1);
    quickSort(nums, first + 1, right);
}

int * sortArray(int* nums, int numsSize) {
    quickSort(nums, 0, numsSize - 1);
    for (int i = 0; i < numsSize; i++) {
        printf("快排：%d\n", nums[i]);
    }
    return nums;
}



void mergeArrays(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
    // 数组1最后一个元素下标
    int last1 = m - 1;
    // 数组2最后一个元素下标
    int last2 = n - 1;
    // 合并以后数组最后元素下标
    int last = m + n - 1;
    while (last1 >= 0 && last2 >= 0) {
        // 每次比较两个数组最后一个元素，将大的保存到nums1
        if (nums1[last1] >= nums2[last2]) {
            nums1[last--] = nums1[last1--];
        } else if (nums1[last1] < nums2[last2]) {
            nums1[last--] = nums2[last2--];
        }
    }
    while (last2 >= 0) {
        // 如果nums2还有剩余元素，逐个保存
        nums1[last--] = nums2[last2--];
    }
    for (int i = 0; i < n + m; i++) {
        printf("合并有序数组：%d\n", nums1[i]);
    }
}

int *twoSum(int* nums, int numsSize, int target) {
    for (int i = 0; i < numsSize; i++) {
        // 需要查找的数值
        int needSearchNum = target - nums[i];
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] == needSearchNum) {
                int *result = malloc(sizeof(int) * 2);
                result[0] = i;
                result[1] = j;
                printf("两数之和：%d, 两数之和%d\n", i, j);
                return result;
            }
        }
    }
    return NULL;
}
