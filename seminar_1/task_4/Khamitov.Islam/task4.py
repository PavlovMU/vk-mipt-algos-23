#!/usr/bin/env python
# coding: utf-8

def find2IndexesOfSum(a , s):
    
    last = len(a) - 1
    first = 0
    
    while last != first:
        if a[first] + a[last] == s:            
            return (first, last)
        
        elif a[first] + a[last] > s:
            last -= 1
            
        else:
            first += 1
             
    return None

# arr = list(range(1, 11))
# print(find2IndexesOfSum(arr, 15))







