#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""OSI model representation

Created on Wed Dec 12 11:05:47 2018
@author: Aakash Hemadri
"""
import sys
import socket

from osi import message, application_layer, transport_layer, network_layer, data_link_layer, physical_layer 

def main():
    """Begins script's execution
    
    """
    serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    host = socket.gethostname()
    port = 9995
    serversocket.bind((host,port))
    serversocket.listen(5)
    
    clientsocket,addr = serversocket.accept()
    print('Connected to address: ' + str(addr))
    clientsocket.send(physical_layer(data_link_layer(network_layer(transport_layer(application_layer(message()))))).encode('ascii'))
    clientsocket.close()

if __name__=='__main__':
    main()