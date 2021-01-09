#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Created on Wed Dec 26 10:36:22 2018

@author: Aakash Hemadri
"""
from bitarray import bitarray

def ask():
    message = input("-- Enter the message you would like to send: ")
    bit_string_message = bitarray(endian='big')
    bit_string_message.fromstring(message)
    return bit_string_message

def hamming():
    original_message = ask()
    #n for n in range(len(original_message) + 1)
    #n = list(range(len(original_message) + 1))
    #n = n*
    n = 10
    [i for i in range(n+1)]
    for i in (n):
        print(i)

def test():
    pass

if __name__=='__main__':
    hamming()
