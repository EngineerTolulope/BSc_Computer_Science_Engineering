#!/usr/bin/env python

import math


def main():
    sumofeach=0#The sum of the squares of the first 100 natural numbers is, 1^2+2^2....

    sumofall=0#The square of the sum of the first 100 natural numbers is, (1+2+...)^2
    for i in range(1,101):
        sumofeach+= i**2
        sumofall+=i
    sumofall*=sumofall
    print 'The difference between {} {} is:'.format(sumofeach,sumofall), abs(sumofall-sumofeach)

#############################################################################

if __name__ == "__main__":
    main()
