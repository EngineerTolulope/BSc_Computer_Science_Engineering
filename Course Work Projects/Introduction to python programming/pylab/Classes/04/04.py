#!/usr/bin/env python
# coding: utf-8 

def main():
    li = [2,1,2,5,8,2,9]
    small=[]
    
    for num in li:
        if (num<=2):
            small.append(num) #we want to filter out num . less than 3 and put in the list small

     
    print small       
            


if __name__=="__main__":
    main()
