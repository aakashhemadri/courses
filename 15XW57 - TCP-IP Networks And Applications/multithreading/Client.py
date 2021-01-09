# -*- coding: utf-8 -*-
"""
Created on Wed Jul 10 16:18:27 2019

@author: 17pw01
"""

import socket

class Client(object):
    def __init__(self, host, port):
        self.host = host
        self.port = port
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        
    def send(self,ip):
        self.sock.connect((self.host,self.port))
        self.sock.send(ip.encode('ascii'))
        print(self.sock.recv(1024).decode('ascii'))
if __name__=='__main__':
    Client('127.0.0.1', 5000).send('127.0.0.1')