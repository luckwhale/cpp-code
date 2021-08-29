#pragma once
// 假设数组中存储的都是非负整数
void Counting_Sort(int data[], int n)
{
    if (n <= 1)
    {
        return;
    }

    // 寻找数组的最大值
    int max = data[0];
    for (int i = 1; i < n; i++)
    {
        if (data[i] > max)
        {
            max = data[i];
        }
    }

    // 定义一个计数数组, 统计每个元素的个数
    int c[max+1];
    for(int i=0;i<max+1;i++)
    {
        c[i]=0;
    }
    for (int i = 0; i < n; i++)
    {
        c[data[i]]++;
    }

    // 对计数数组累计求和
    for (int i = 1; i <= max; i++)
    {
        c[i] = c[i] + c[i-1];
    }

    // 临时存放排好序的数据
    int r[n];
    for(int i=0;i<n;i++)
    {
        r[i]=0;
    }
    // 倒序遍历数组，将元素放入正确的位置
    for (int i = n-1; i >= 0; i--)
    {
        r[c[data[i]] - 1] = data[i];
        c[data[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        data[i] = r[i];
    }

}