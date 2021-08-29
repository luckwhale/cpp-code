//文件夹可以直接include吗？
//KMP 字符串匹配的改进算法，时间复杂度 O(m+n)
//算法到底放到什么文件里
#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//假如说pattern串是aaba，那么pattern数组的内容便是{0, 1, 0, 1}，
//这里面0代表从pattern头部到该位置的子字符串的没有公共前缀和后缀
vector<int> getTempArray(string pattern) //这个函数的作用next函数
{
	vector<int> result; //声明要返回的vector
	if (pattern.size() == 0)
		return result;		 //如果字符串的长度为0，直接返回空的vector
	result.push_back(0);	 //首先在里面压入0
	if (pattern.size() == 1) //如果说字符串的长度为1，直接返回此时的vector
		return result;

	int i = 0;
	int j = 1;
	while (i <= pattern.size() - 1 && j <= pattern.size() - 1)
	{
		if (pattern[j] == pattern[i])
		{
			result.push_back(i + 1);
			i++;
			j++;
		}
		else
		{
			if (i == 0)
			{
				result.push_back(0);
				j++;
			}
			else
			{
				while (i >= 1 && pattern[i] != pattern[j])   //这不是有问题吗
				{
					i = result[i - 1];
				}
				if (pattern[i] == pattern[j])
				{
					result.push_back(i + 1);
					i++;
					j++;
				}
				else
				{
					result.push_back(0);
					j++;
				}
			}
		}
	}
	return result;
}
int kmp(string t, string p) //t代表原字符串，p代表要匹配的字符串
{
	vector<int> next = getTempArray(p);
	int j = 0;
	for (int i = 0; i < t.length(); i++)
	{
		while (j > 0 && t[i] != p[j])
			j = next[j - 1];
		if (t[i] == p[j])
			j++;
		if (j == p.length())
			return i - p.length() + 1;
	}
	return -1;
}
