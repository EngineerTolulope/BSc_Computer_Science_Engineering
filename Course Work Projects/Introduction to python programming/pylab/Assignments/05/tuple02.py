#!/usr/bin/env python

import math


def distance(p1, p2):
    # TODO...
    a=p2[0]-p1[0]
    b=p2[1]-p1[1]
    c=math.sqrt(a**2+b**2)
    return c


def main():
    p1 = (1, 2)
    p2 = (6, 5)
    print 'The distance between the two points:', distance(p1, p2)

#############################################################################

if __name__ == "__main__":
    main()
