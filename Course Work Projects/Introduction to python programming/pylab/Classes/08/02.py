#!/usr/bin/env python
"""Remove duplicates and sort a list"""

def prod(s):
    product=1
    for i in s:
        product*=int(i)
    return product
    
    
def main():
    print prod("32768")
    print prod("")
    
if __name__ == "__main__":
    main()
