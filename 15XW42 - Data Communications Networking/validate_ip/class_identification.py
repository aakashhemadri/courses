# -*- coding: utf-8 -*-
"""
Created on Thu Jun 20 11:55:16 2019

@author: 17pw01
"""
from validate import validate,request

def identify(ip):
    if(ip == False):
        return False
    else:
        #ip = '.'.join(ip)
        netid = format(int(ip[0]),'08b')
        if(netid[:1] == '0'):
            cls = 'A'
            cls_ip = [255,0,0,0]
        elif(netid[:2] == '10'):
            cls = 'B'
            cls_ip = [255,255,0,0]
        elif(netid[:3] == '110'):
            cls = 'C'
            cls_ip = [255,255,255,0]
        elif(netid[:4] == '1110'):
            cls = 'D'
            cls_ip = [255,255,255,255]
        elif(netid[:4] == '1111'):
            cls = 'E'
            cls_ip = [255,255,255,255]
    return (ip, cls, cls_ip)

def test():
    print('Running Test..')
    message = identify(validate(request()))
    if(message != False):
        print(message)
    else:
        print('Invalid IP Address! Try Again!')

if __name__=='__main__':
    test()
