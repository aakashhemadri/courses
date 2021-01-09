#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Created on Thu Dec 13 11:18:25 2018

@author: Aakash Hemadri
"""

import socket

from osi import message, application_layer, transport_layer, network_layer, data_link_layer, physical_layer 

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
port = 9995
s.connect((host,port))
msg = s.recv(1024)
s.close

message(application_layer(transport_layer(network_layer(data_link_layer(physical_layer(msg.decode('ascii'),True),True),True),True),True),True)
