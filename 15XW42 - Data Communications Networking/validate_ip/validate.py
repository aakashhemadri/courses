# -*- coding: utf-8 -*-
"""
Created on Wed Jun 19 15:20:24 2019

@author: tc
"""

def request(x):
    if(x):
        return x
    return str(input('#! Enter the ip you\'d like to validate : '))
def validate(ip):
    ip = ip.strip().split('.')
    if(len(ip) == 4):
        for decimal in ip:
            try:
                decimal = int(decimal)
            except(ValueError):
                return False
            if(decimal < 0 or decimal > 255):
                return False
        return ip
    else:
        return False

def run():
    if(validate(request())):
        print('#! It is a valid IP Address')
    else:
        print('#! It is not a valid IP Address')

if __name__=='__main__':
    run()