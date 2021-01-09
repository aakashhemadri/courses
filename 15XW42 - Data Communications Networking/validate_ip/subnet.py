# -*- coding: utf-8 -*-
"""
Created on Thu Jun 27 11:35:58 2019

@author: 17pw01
"""

from validate import request, validate
from class_identification import identify
from bitarray import bitarray

def request_mask(x):
    if(x):
        return x
    return str(input('#! Enter the subnet mask you\'d like to use! : '))
def subnet(ip_cls, sub):
    ip = ip_cls[0]
    cls = ip_cls[1]
    cls_ip = ip_cls[2]
    #print(bin(int(ip[0])) & bin(int((sub[0]))))
    for i in range(4):
        ip[i] = format(int(ip[i]),'08b')
        sub[i] = format(int(sub[i]),'08b')
        cls_ip[i] = format(int(cls_ip[i]),'08b')
    ip = bitarray(''.join(ip))
    sub = bitarray(''.join(sub))
    cls_ip = bitarray(''.join(cls_ip))
    #x = (~(cls_ip | sub))
    print(cls_ip)
    hosts = (int((~(cls_ip | sub)).to01(),2))+1
    start = hosts
    limit = (int(((cls_ip ^ sub)).to01(),2))
    while(start<limit):
        print('[',start,']:[',start+1,'-',start+hosts-2,']:[',start+hosts-1,']')
        start = start + hosts

def test():
    if(subnet(identify(validate(request('210.0.0.0'))),validate(request_mask('255.255.255.240')))):
        pass
    else:
        pass
        

if __name__=='__main__':
    test()