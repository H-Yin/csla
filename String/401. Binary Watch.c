/*
401. Binary Watch
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
Each LED represents a zero or one, with the least significant bit on the right.
Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.
Example:
Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


// #define A401
#ifdef A401

unsigned int bit_count(unsigned int n)
{
	unsigned int tmp = n - ((n >> 1) & 033333333333) - ((n >> 2) & 011111111111);
	return ((tmp + (tmp >> 3)) & 030707070707) % 63;
}

char** readBinaryWatch(int num, int* returnSize) {
	if (num > 8 || num < 0){
		*returnSize = 0;
		return NULL;
	}
	int i = 0;
	int hour_nums[] = { 1, 4, 5, 2 };
	int seconds_nums[] = { 1, 6, 15, 20, 14, 4 };
	int nums = 0;
	char **ret = NULL;
	for (i = 0; i < 4; i++)
	{
		if (num - i <=5)
		{
			nums += hour_nums[i] * seconds_nums[num - i];
		}
	}
	*returnSize = nums;
	ret = (char**)malloc(sizeof(char*)*nums);
	printf("%d", nums);
	return ret;
}

int main(){
	int len =0 ;
	readBinaryWatch(5, &len);
	return 0;
}

#endif