/*
88. Merge Sorted Array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// #define A88
#ifdef A88

#include "MyArray.h"

void merge(int* nums1, int m, int* nums2, int n) {
	int i = m - 1, j = n - 1, k = m + n - 1;
	while (i>=0 && j>=0)
	{
		if (nums1[i] <= nums2[j]){
			nums1[k] = nums2[j--];
		}
		else{
			nums1[k] = nums1[i--];
		}
		k--;
	}
	while (j>=0)
	{
		nums1[k--] = nums2[j--];
	}
}

int main(){
	int a[] = { 8, 9, 3, 4, 5, 0, 0, 0, 0, 0 };
	int b[] = { 1,2,3,4,5,6, 7, };
	merge(a, 2, b, 4);
	printArray(a, 6);

	return 0;
}

#endif