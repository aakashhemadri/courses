# -*- coding: utf-8 -*-
"""
Created on Thu Dec  6 11:02:43 2018

@author: Aakash Hemadri
"""    
import socket
import time

class echo_client:
    def __init__(self):
        """Init"""
        self.host = socket.gethostname()
        self.port = 9999
    def client(self):
        """Client"""
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect((self.host,self.port))
            s.sendall(b'Hello, World')
            data = s.recv(1024)            
        print('Received', repr(data))

def test():
    pass

if __name__=="__main__":
    test()