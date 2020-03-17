//
// Created by ybw on 2020/3/15.
//

#ifndef SORT_ARITHMETIC_SORT_H
#define SORT_ARITHMETIC_SORT_H

#include <iostream>
#include <vector>
#include <ctime>
//冒泡排序
template <class Type>
std::vector<Type> bubbleSort(std::vector<Type>& res)
{
    std::vector<Type> array = res;

    if(array.size() == 0)
        return array;

    for (int i = 0; i < array.size(); ++i) {
        //j = 队列长度 - 1 是因为两个元素比较，最后一个元素不需要比较
        //又 - i ，是因为每一次循环过后，都会把目前array的最大元素确定在后面。
        for (int j = 0; j < array.size() - 1 - i; ++j) {
            if(array[j] > array[j + 1])
            {
                auto temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    return array;
}

//选择排序
template <class Type>
std::vector<Type> selectionSort(std::vector<Type>& res)
{
    std::vector<Type> array = res;
    if(array.size() == 0)
        return array;
    for (int i = 0; i < array.size(); ++i) {
        int min_index = i;
        for (int j = i; j < array.size(); ++j) {
            if(array[j] < array[min_index])
                min_index = j;
        }
        Type temp = array[min_index];
        array[min_index] = array[i];
        array[i] = temp;
    }

    return array;
}


//插入排序
template <class Type>
std::vector<Type> insertionSort(std::vector<Type>& res)
{
    std::vector<Type> array = res;
    if(array.size() == 0)
        return array;

    Type current;
    for (int i = 0; i < res.size() - 1; ++i) {
        //设该段最后一个的后面一个元素为current
        current = array[i + 1];
        //设置该段最后一个元素索引为lastIndex
        int lastIndex =  i;
        while(lastIndex >= 0 && current < array[lastIndex])
        {
            array[lastIndex + 1] = array[lastIndex];
            --lastIndex;
        }
        //此时lastIndex + 1的位置，就是current该插入的位置
        array[lastIndex + 1] = current;
    }

    return array;
}


//归并排序

/**
 * 合并数组
 * @tparam Type
 * @param res
 * @return
 */
template <class Type>
std::vector<Type> Merge(std::vector<Type> left,std::vector<Type> right)
{
    std::vector<Type> temp(left.size()+right.size(),0);
    int i=0,j=0;
    for(int index = 0;index < temp.size();++index)
    {
        //这里为什么会先写这两行，让这两个先判断就可以省略判断条件
        if(i >= left.size())
            temp[index] = right[j++];
        else if(j >= right.size())
            temp[index] = left[i++];
        else if(left[i] < right[j])
            temp[index] = left[i++];
        else
            temp[index] = right[j++];
    }
    return temp;
}

/**
 * 归并排序
 * @tparam Type
 * @param res
 * @return
 */
template <class Type>
std::vector<Type> MergeSort(std::vector<Type>& array)
{
//    std::vector<Type> array = res;
    //这里是MergeSort递归的终止条件
    if(array.size() < 2)
        return array;
    int mid = array.size() / 2;
    //一直采用[n,m)这种方式取范围
    std::vector<Type> left(array.begin(),array.begin()+mid);
    std::vector<Type> right(array.begin()+mid,array.end());
    return Merge(MergeSort<Type>(left),MergeSort<Type>(right));
}

//快速排序
/**
 * 交换数组内两个元素
 * @tparam Type
 * @param array
 * @param i
 * @param j
 */
template <class Type>
void swap(std::vector<Type>& array,int i,int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

/**
 * 快速排序算法——partition
 * @tparam Type
 * @param array
 * @param start
 * @param end
 * @return
 */
template <class Type>
int partition(std::vector<Type>& array,int start,int end)
{
    srand(time(0));
    int pivot = start + rand() % (end - start + 1);
    int smallIndex = start - 1;
    swap(array, pivot, end);
    for (int i = start; i <= end; i++)
    {
        if(array[i] <= array[end])
        {
            ++smallIndex;
            if(i > smallIndex)
                swap(array,i,smallIndex);
        }
    }
    return smallIndex;
}

/**
 * 快速排序方法
 * @tparam Type
 * @param array
 * @param start
 * @param end
 * @return
 */
template <class Type>
std::vector<Type> QuickSort(std::vector<Type>& array,int start,int end)
{
//    std::vector<Type> array = res;
    //这里是QuickSort递归的终止条件
    if (array.size() < 1 || start < 0 || end >= array.size() || start > end) return std::vector<Type>();

    int smallIndex = partition(array,start,end);

    //smallIndex 就是基准的索引，左边小于等于基准，右边大于基准
//    for (int i = 0; i < array.size(); ++i) {
//        std::cout<<array[i]<<" ";
//    }
//    std::cout<<std::endl;
    //左边发生移动的次数小于等于1
    if(smallIndex > start)
        QuickSort(array, start, smallIndex - 1);
    if(smallIndex < end)
        QuickSort(array,smallIndex + 1,end);
    return array;
}





#endif //SORT_ARITHMETIC_SORT_H
