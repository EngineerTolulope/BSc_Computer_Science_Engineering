#!/usr/bin/env python
# encoding: utf-8

import sys

"""
The user gives the rgb color code in hexadecimal, this is then converted to decimal
"""
"""
The method i used is from ascii tables, if a value is a for example, in ascii it is 97,but hexadecimal it is 10, so i subtract 87
from 97 i will have 10, similar to the other ones like b in ascii is 98, but in hex is 11, i substract 87 from 98 i will have 11
"""


def main():
    s = input("Give me the color code... ")
    if len(s) == 6:  # it should be something like '6495ed'
        Red = s[:2]  # takes the hexadecimal for each respective colour
        Green = s[2:4]
        Blue = s[4:]
        hexv = "abcdef"  # Hexv contains all the possible hexdecimal letter values
        # For Red Colour
        s = Red  # takes red first
        if s[0] in hexv:  # checks if s[0]  is in hexv
            if s[1] in hexv:  # if s[0] and s[1] in hexv
                Red = (ord(s[0]) - 87) * 16 + (ord(s[1]) - 87)  # calculates the decimal value
            else:  # if s[0] is in hexv but not s[1]
                Red = (ord(s[0]) - 87) * 16 + int(s[1])
        elif s[1] in hexv:  # if s[0] is not in hexv but s[1] is in hexv
            Red = int(s[0]) * 16 + (ord(s[1]) - 87)
        else:  # if both s[0] and s[1] are not in hexv
            Red = int(s[0]) * 16 + int(s[1])

        # Does The Same For Colour Green
        s = Green
        if s[0] in hexv:
            if s[1] in hexv:
                Green = (ord(s[0]) - 87) * 16 + (ord(s[1]) - 87)
            else:
                Green = (ord(s[0]) - 87) * 16 + int(s[1])
        elif s[1] in hexv:
            Green = int(s[0]) * 16 + (ord(s[1]) - 87)
        else:
            Green = int(s[0]) * 16 + int(s[1])

            # Does The Same For Colour Blue
        s = Blue
        if s[0] in hexv:
            if s[1] in hexv:
                Blue = (ord(s[0]) - 87) * 16 + (ord(s[1]) - 87)
            else:
                Blue = (ord(s[0]) - 87) * 16 + int(s[1])
        elif s[1] in hexv:
            Blue = int(s[0]) * 16 + (ord(s[1]) - 87)
        else:
            Blue = int(s[0]) * 16 + int(s[1])

        print("Red:{}\nGreen:{}\nBlue:{} ".format(Red, Green, Blue))  # prints out decimal value for each colour



if __name__ == "__main__":
    main()
