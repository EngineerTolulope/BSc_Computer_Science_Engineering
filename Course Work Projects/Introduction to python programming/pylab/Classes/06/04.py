#!/usr/bin/env python
# coding: utf-8
import math 

def get_movie_info():
    #say we read it from a database
    #return ("Total Recall",1990,7.5)
    return ["Total Recall",1990,7.5] #we can also return a list, and it works the same
def main():
    title,year,score = get_movie_info() #Parallel Assignment
    print "Title: {}, Year: {}, Score: {}".format(title,year,score)    


if __name__=="__main__":
    main()
