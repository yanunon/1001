#! /usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright © 2013 Yang Junyong <yanunon@gmail.com>

import random

def quickSort(data, low, high):
    if low >= high:
        return
    l = low
    h = high
    while l < h:
        if data[l+1] < data[l]:
            data[l], data[l+1] = data[l+1], data[l]
            l += 1
        else:
            data[h], data[l+1] = data[l+1], data[h]
            h -= 1
    if low < l-1:
        quickSort(data, low, l-1)

    if high > l+1:
        quickSort(data, l+1, high)

def QuickSort(data):
    quickSort(data, 0, len(data)-1)


def main():
    l = [random.randrange(1000) for i in range(100)]
    print l
    QuickSort(l)
    print l

if __name__ == '__main__':
    main()

