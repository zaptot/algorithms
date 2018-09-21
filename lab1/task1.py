#!/usr/bin/env python
# coding: utf-8
import re
import time

def readArrayFromFile(name):
    file = open(name, "r")
    values = file.read().split("\n")
    data = []
    for key in values:
        value = re.findall(r"[-+]?\d*\.\d+|\d+", key)
        if value != []:
            data.append(value)
    for i in range(len(data)):
        data[i] = list(map(int, data[i]))
    return data


def insertionSort(arr):
    for i in range(len(arr)):
        tmp = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > tmp:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = tmp
    return arr


def merge(left, right):
    result = []
    i , j = 0 , 0
    ln, rn = len(left), len(right)
    while i < ln and j < rn:
        if left[i] <= right [j]:
            result.append(left[i])
            i+=1
        else:
            result.append(right[j])
            j+=1
    result += left[i:]
    result += right[j:]
    return result


def mergesort(lst):
    if len(lst) <= 1:
        return lst
    middle = len(lst) // 2
    if(len(lst) > 50):
        left = mergesort(lst[:middle])
        right = mergesort(lst[middle:])
    else:
        left = insertionSort(lst[:middle])
        right = insertionSort(lst[middle:])
    return merge(left, right)


if __name__ == '__main__':
    a = readArrayFromFile("test")
    t = time.time()
    for i in range(len(a)):
        mergesort(a[i])
    print((time.time() - t))
