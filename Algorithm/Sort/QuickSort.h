#pragma once
#include <vector>
//快速排序（从小到大）
using namespace std;
void quickSort(int left, int right, vector<int>& arr)
{
	if(left >= right)
	{
        return ;
	}
	int i, j, base, temp;
	i = left, j = right;
	base = arr[left];  //取最左边的数为基准数，有些情况下不好，例如有序的。
	while (i < j)
	{
		while (arr[j] >= base && i < j)  //从右侧找到小于base的数字
			j--;
		while (arr[i] <= base && i < j)  //从左侧找到大于base的数字
			i++;
		if(i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//基准数归位
	arr[left] = arr[i];
	arr[i] = base;
	quickSort(left, i - 1, arr);//递归左边
	quickSort(i + 1, right, arr);//递归右边
    }