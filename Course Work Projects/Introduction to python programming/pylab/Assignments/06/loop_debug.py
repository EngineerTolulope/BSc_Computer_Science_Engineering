#!/usr/bin/env python


def loop(num, debug=False):
    
    if (debug == True):
        print "\n#Start loop"
        for n in range(1,num+1):
            print n,        
        print "\n#End loop"

    else:
        for n in range(1,num+1):
            print n,
            
def main():
    loop (10)
    loop(10,debug=True)
    
if __name__ == "__main__":
    main()
