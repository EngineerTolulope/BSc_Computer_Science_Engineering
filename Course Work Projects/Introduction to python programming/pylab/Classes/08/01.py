#!/usr/bin/env python
"""Remove duplicates and sort a list"""

def main():
    li = [5,2,3,5,1,4,-200,5,1,3,2,2,5]
    sets=set(li)
    li=list(sets)
    print sorted(li)
    
if __name__ == "__main__":
    main()
