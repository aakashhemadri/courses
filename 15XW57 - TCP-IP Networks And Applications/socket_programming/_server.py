# -*- coding: utf-8 -*-
"""
Created on Thu Dec  6 10:51:06 2018

@author: Aakash Hemadri
"""

import socket

class echo_server:
    def __init__(self):
        """Init"""
        print("-- Initializing Client.")
        self.local_hostname = socket.gethostname()
        self.host = self.local_hostname
        #i = input("-- Enter the port to connect."
        self. port = 9999

    def ask(self):  
        """Request input/interface"""
        print("-- Hallo.")
    def server(self):
        """Server"""
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.bind((self.host, self.port))
            s.listen()
            conn, addr = s.accept()
            with conn:
                print("-- Connected by", addr)
                while True:
                    message = conn.recv(1024)
                    if not message:
                        break
                    conn.sendall(message)
        
def test():
    """Test"""
    e = echo_server()
    e.server()

if __name__=="__main__":
    test()