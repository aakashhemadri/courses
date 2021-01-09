#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Created on Wed Dec 19 11:06:54 2018

@author: Aakash Hemadri
"""
from bitarray import bitarray

def ask():
    message = input("-- Enter the message you would like to send: ")
    bit_string_message = bitarray(endian='big')
    bit_string_message.fromstring(message)
    return bit_string_message
def crc():
    """Cyclic Redundancy Check"""
    divisor = bitarray(endian='big')
    divisor.extend([1,0,1,1,1])
    original_dataword = ask()
    dataword = original_dataword
    dataword.extend([i^i for i in range(divisor.count())])
    remainder = dataword
    remainder = remainder[:divisor.length()]
    for i in range(divisor.length(),dataword.length()):
        if remainder[0] == True:
            remainder = remainder ^ divisor
        else:
            remainder = remainder ^ (divisor ^ divisor)
        remainder = remainder[1:]
        if i < dataword.length():
            remainder.append(dataword[i])
    original_dataword.extend(remainder)
    return original_dataword
    
def test():
    """Test function"""
    x = ask()
    print(x)
    print(x ^ [False])

if __name__=='__main__':
    print(crc())
