#!/usr/bin/env python
# coding: utf-8 



def main():
  
    txt="""
Bcyp Qml,

G fytc y dyrfcpjw ybtgac dmp wms:
jcypl rfc Nwrfml npmepykkgle jylesyec!

Jmtc,

Byb
"""
    
    newlist=[]#new list to store the chars
    #li=raw_input("Give me a text")
    for c in txt: #we could go through a string as well  "for c in txt" works the same
        if (ord(c)>=ord('A') and ord(c)<=ord('Z')) or (ord(c)>=ord('a') and ord(c)<=ord('z')):#checks if the char is a letter
            if ord(c)==ord('y'):#if it's y it puts a
                newlist.append('a')
            elif ord(c) ==ord('z'):
                newlist.append('b')
            else:              
                newlist.append(chr(ord(c)+2))#stores the char + 2, so g is i for example
        else:
            newlist.append(c)#other chars that are not letters are just added to the newlist
    FinalString= "".join(newlist)
    print FinalString

if __name__=="__main__":
    main()
