# -*- coding: utf-8 -*-
"""
Created on Thu Mar 14 12:30:00 2019

@author: Aakash Hemadri
"""

import sys
import socket
from string import ascii_letters
from itertools import repeat
from itertools import cycle
from math import ceil

def get_message():
    """Validate Input

    :param:
    :return str:
    """
    while(True):
        x = input("## Enter the message you would like encrypt!").lower()
        if(x):
            return x
        else:
            print("!! Invalid Input!")

def caesers_cipher(operation, message, cipherkey):
    """Caeser's Cipher

    :param operation straakash
    :
    :return str:
    """
    temp = ascii_letters
    if operation == "encrypt":
        return (''.join([temp[temp.find(i)+cipherkey] if i.isalpha() else i for i in message])).upper()
    elif operation == "decrypt":
        return (''.join([temp[temp.find(i)-cipherkey] if i.isalpha() else i for i in message])).upper()        
    else:
        return "!! Incorrect Operation"

def vigenere_cipher(operation,message,cipherkey):
    """Vigenere's Cipher

    """
    cipheriter = repeat((cipherkey), ceil(len(message)/len(cipherkey)))
    #[print(k) for j in cipheriter for k in j]
    #cipheriter = cycle((cipherkey)[:len(message)]
    temp = ascii_letters
    if operation == "encrypt":
        return (''.join([temp[temp.find(i)+ord(k)-64] if i.isalpha() else i for i in message for j in cipheriter for k in j])).upper()
    elif operation == "decrypt":
        return (''.join([temp[temp.find(i)+ord(k)+64] if i.isalpha() else i for i in message for j in cipheriter for k in j])).upper()
    else:
        return "!! Incorrect Operation"

def encrypt(cipher,message,cipherkey):
    """Encryption
    
    """
    if cipher == "caeser":
        return caesers_cipher("encrypt",message,cipherkey)
    elif cipher == "vigenere":
        return vigenere_cipher("encrypt",message,cipherkey)
    else:
        return "!! Incorrect Cipher!"

def decrypt(cipher,ciphertext,cipherkey):
    """Decryption
    
    """
    if cipher == "caeser":
        return caesers_cipher("decrypt",ciphertext,cipherkey)
    elif cipher == "vigenere":
        return vigenere_cipher("decrypt",ciphertext,cipherkey)
    else:
        return "!! Incorrect Cipher!"

def test():
    """Test
    
    :param:
    :return:
    """
    print('!! Begin Test!..')
    return encrypt("vigenere","hello","lemon")

def client():
    """Client
    
    :param:
    :return:
    """
    print('!! Initializing client application... ')

def server():
    """Server
    
    :param:
    :return:
    """
    print('!! Initializing server application... ')

if __name__=='__main__':
    if(len(sys.argv) > 1):
        if(sys.argv[1] == 'client'):
            client()
        elif(sys.argv[1] == 'server'):
            server()
        elif(sys.argv[1] == 'test' ):
            print(test())
    else:
        test()