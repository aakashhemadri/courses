#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""OSI

Created on Thu Dec 13 11:43:33 2018

@author: Aakash Hemadri
"""
import socket
import time
from uuid import getnode

def message(data = None, parse = False):
    """Return's message on users's input."""
    if parse == False:
        if data == None:
            data = input('Enter the message you would like to send: ')
        return str('[-- [' + time.ctime() + ']: ' + data + ']')
    else:
        if data != None:
            temp = data.split('||')
            print("The message is: " + str(temp[0]))
            return True

def application_layer(data, parse = False):
    """Adds application layer header, return':
    test()s header.
    
    Uses telnet protocol
    """
    if parse == False:
        return 'telnet' + '||' + data
    else:
        temp = data.split('||')
        print("Application Layer: " + str(temp[0]))
        return '||'.join(temp[1:])

def presentation_layer(data, parse = False):
    """Adds presentation layer header, return header.
    
    Uses ASCII for the presentation layer
    """
    if parse == False:
        return 'ASCII' + '||' + data
    else:
        temp = data.split('||')
        print("Presentation Layer: " + str(temp[0]))
        return '||'.join(temp[1:])

def session_layer(data, parse = False):
    """Session Layer.

    Session control protocol
    """
    if parse == False:
        return 'SCP' + '||' + data
    else:
        temp = data.split('||')
        print("Session Layer: " + str(temp[0]))
        return '||'.join(temp[1:])

def transport_layer(data, parse = False):
    """Transport layer."""
    if parse == False:
        port = 9994
        return str(port) + '||' + data
    else:
        temp = data.split('||')
        print("Transport Layer: " + str(temp[0]))
        return '||'.join(temp[1:])

def network_layer(data, parse = False):
    """Network layer."""
    if parse == False:
        host_ip = socket.gethostbyname(socket.gethostname())
        dest_ip = input('Enter destination ip address: ')
        return str(host_ip) + '|' + dest_ip + '||' + data
    else:
        temp = data.split('||')
        print("Network Layer: " + str(temp[0]))
        return '||'.join(temp[1:])

def data_link_layer(data, parse = False):
    """Data link layer.
    
    Appends source and destination mac address
    """
    if parse == False:
        source_mac = getnode()
        source_mac = ':'.join(("%012X" % source_mac)[i:i + 2] for i in range(0, 12, 2))
        dest_mac = input("Enter the destination mac address: ")
        return str(source_mac) + '|' + dest_mac + '||' + data
    else:
        temp = data.split('||')
        print("Data Link Layer: " + str(temp[0]))
        return '||'.join(temp[1:])

def physical_layer(data, parse = False):
    """Physical layer"""
    data = str(data)
    if parse == False:
        return '[Nil]' + '||' + data
    else:
        temp = data.split('||')
        print("Physical Layer: " + str(temp[0]))
        return str('||'.join(temp[1:]))

def test():
    pass

if __name__ == '__main__':
    test()