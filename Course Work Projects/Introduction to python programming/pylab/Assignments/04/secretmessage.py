#!/usr/bin/env python
# encoding: utf-8
 
def main():
 
    TEXT = """
Bcyp Qml,
 
G fytc y dyrfcpjw ybtgac dmp wms:
jcypl rfc Nwrfml npmepykkgle jylesyec!
 
Jmtc,
 
Byb
    """
 
    charList = list(TEXT)
    replaceList = []
   
    lowera = ord('a')
    lowerz = ord('z')
    uppera = ord('A')
    upperz = ord('Z')
 
    for ch in charList:
        if ord(ch) >= lowera and ord(ch) <= lowerz:
           
            if ord(ch) == ord('y'): replaceList.append('a')
            elif ord(ch) == ord('z'): replaceList.append('b')
            else: replaceList.append(chr(ord(ch) + 2))
       
        elif ord(ch) >= uppera and ord(ch) <= upperz:
           
            if ord(ch) >= ord('y'): replaceList.append('A')
            elif ord(ch) >= ord('z'): replaceList.append('Z')
            else: replaceList.append(chr(ord(ch) + 2))
       
        else: replaceList.append(ch)
 
    print ''.join(replaceList)
 
##############################################################################
 
if __name__ == "__main__":
    main()
