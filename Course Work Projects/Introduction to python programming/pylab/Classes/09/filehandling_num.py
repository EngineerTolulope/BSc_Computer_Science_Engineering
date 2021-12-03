#!/usr/bin/env python


def main():
    f = open('num.txt','r')
    totalsum=0
    for line in f:
        line = line.rstrip('\n')
        n=int(line)
        totalsum+=n
    f.close()
    print str(totalsum)[:10]
if __name__ == "__main__":
    main()
