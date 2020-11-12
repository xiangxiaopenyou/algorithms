//
//  array_algorithms.h
//  经典算法
//
//  Created by zhangdu_imac on 2020/10/23.
//

#ifndef array_algorithms_h
#define array_algorithms_h

enum sort_method {
    method_quick = 0   // 快速排序
};

#include <stdio.h>


/// 将int数组中的所有0移到末尾，并保持其他元素顺序不变（在原数组上操作）
/// @param nums 数组
/// @param numSize 数组大小
void moveZeroes(int *nums, int numSize);


/// 将int数组升序排列
/// @param nums 数组
/// @param numsSize 数组大小
int * sortArray(int *nums, int numsSize);

/// 合并两个有序数组
/// @param nums1 数组1
/// @param nums1Size 数组1大小
/// @param m 数组1元素数量
/// @param nums2 数组2
/// @param nums2Size 数组2大小
/// @param n 数组2元素数量
void mergeArrays(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n);

/// 两数之和：给定一个整数数组nums和一个目标值target，在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
/// @param nums 数组
/// @param numsSize 数组大小
/// @param target 目标值
int *twoSum(int* nums, int numsSize, int target);

#endif /* array_algorithms_h */
