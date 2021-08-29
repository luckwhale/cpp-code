#pragma once
template <class T>
void ShellSort(T arr[], const int left, const int right)     //这种参数传递方式怎么样？const int 和 &相比怎么样
{
    int i, j, gap, temp;   // gap为增量
    gap = right - left + 1; // 增量的初始值
    do
    {                              // 直到增量值为1
        gap = gap / 3 + 1; // 求下一增量值
        for (i = left + gap; i <= right; i++)
        {
            if (arr[i] < arr[i - gap])
            {
                temp = arr[i];
                j = i - gap;
                do
                {
                    arr[j + gap] = arr[j]; // 后移元素
                    j = j - gap;           // 再比较前一元素
                }
                while (j >= left && temp < arr[j]);
                arr[j + gap] = temp; // 回填
            
            }
        } // for
    }
    while (gap > 1);
}