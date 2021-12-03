#!/usr/bin/env python
# coding: utf8
 
# Copyright 2010 Google Inc.
# Licensed under the Apache License, Version 2.0
# http://www.apache.org/licenses/LICENSE-2.0
 
# Google's Python Class
# http://code.google.com/edu/languages/google-python-class/
 
# Additional basic list exercises
 
# D. Given a list of numbers, return a list where
# all adjacent == elements have been reduced to a single element,
# so [1, 2, 2, 3] returns [1, 2, 3]. You may create a new list or
# modify the passed in list.
def remove_adjacent(nums):
   
    uniqueList = []
 
    for n in nums:
        if not n in uniqueList:#So we add elements to uniqueList only once, make sure it wasn't present before appending
            uniqueList.append(n)
 
    return uniqueList
 
 
# E. Given two lists sorted in increasing order, create and return a merged
# list of all the elements in sorted order. You may modify the passed in lists.
# Ideally, the solution should work in "linear" time, making a single
# pass of both lists.
def list_merge(list1, list2):
    #list1.sort()
    #list2.sort()
    #return list1 + list2 #can't use this because the combination of the two lists should be return sorted, not individually

    #list3 = (list1 + list2).sort() #sort() doesn't return a value it just sorts the list, so nothing is stored in list3
    #return list3

    list3 = list1 + list2
    list3.sort()#sorts list3 and stores the result back in list3, 
    return list3


    #Alternative Method
    #return sorted(list1 + list2)#it takes two lists and sort the joint two list
 
# Simple provided test() function used in main() to print
# what each function returns vs. what it's supposed to return.
def test(got, expected):
    if got == expected:
        prefix = ' OK '
    else:
        prefix = '  X '
    print '{p} got: {g}; expected: {e}'.format(p=prefix, g=got, e=expected)
 
 
# Calls the above functions with interesting inputs.
def main():
    print 'remove_adjacent'
    test(remove_adjacent([1, 2, 2, 3]), [1, 2, 3])
    test(remove_adjacent([2, 2, 3, 3, 3]), [2, 3])
    test(remove_adjacent([]), [])
 
    print
    print 'list_merge'
    test(list_merge(['aa', 'xx', 'zz'], ['bb', 'cc']),
         ['aa', 'bb', 'cc', 'xx', 'zz'])
    test(list_merge(['aa', 'xx'], ['bb', 'cc', 'zz']),
         ['aa', 'bb', 'cc', 'xx', 'zz'])
    test(list_merge(['aa', 'aa'], ['aa', 'bb', 'bb']),
         ['aa', 'aa', 'aa', 'bb', 'bb'])
 
#############################################################################
 
if __name__ == '__main__':
    main()
 
 
 
 
