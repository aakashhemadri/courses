# -*- coding: utf-8 -*-
"""
Created on Wed Jan 30 10:37:46 2019

@author: Aakash Hemadr
"""

from bitarray import bitarray

def bit_stuffing(message):
    """Bit Stuffing!!
    
    :param message: str
    :return message: str
    """
    if message == None:
        return 'Bye! Bye!'
    else:
        print('-- Initial message!\n##', message)
        temp = list()
        for i in message:
            temp.append(bitarray(i))
        message = temp
        print('-- Byte Stuffed Message:\n##', message)
        for i in message:
            pos = i.search(bitarray('111111'))
            if len(pos) >= 1:
                i.insert(pos[0]+5, False)
        print("-- Bit Array that is going to be sent!\n##", message)
        #return '0111111010100011101000111010001101111101001111110'
        print(message)
        return message

def bit_unstuffing(message):
    """Bit Unstuffing
    
    :param message: str
    :return message:
    """
    temp = bitarray(message)
    print("-- Unstuffing Message:\n##", temp)
    try:
        pos = temp.search(bitarray('01111110'))
        temp = temp[pos[0]+8:pos[1]]
    except IndexError:
        pass
    #print(temp)
    pos = temp.search(bitarray('1111101'))
    for i in pos:
        temp.pop(i+5)
    #print(temp)
    msg = []
    for i in range(int(len(temp)/8)):
        msg.append(temp[i*8:i*8+8])
    print("-- Byte and Bit Unstuffed Message\n--", msg)
    i = 0
    while i < len(msg):
        if msg[i] == bitarray('10100011') and msg[i+1] == bitarray('10100011'):
            msg.pop(i)
        elif msg[i] == bitarray('10100011') and msg[i+1] == bitarray('01111110'):
            msg.pop(i)
        i = i + 1
    print('-- List of Bitarray ready to be parsed:\n##', msg)
    return(msg)
        
def get_message():
    """Message Interface For Parsing
    
    :param None:
    :return x: list
    """
    msg = str(input('-- Input the message: '))
    msg = msg.split()
    x = []
    for i in msg:
        if  i == 'ESC':
            x.append('10100011')
            x.append('10100011')
        elif i == 'FLAG':
            x.append('10100011')
            x.append('01111110')
        else:
            try:
                x.append(format(ord(i),'08b'))
            except(TypeError):
                print(Exception)
                print("Entered non char value in message")
                return None
    return x

def parse_message(message):
    """
    
    Parse list of bitarray into human readable message
    """
    temp = ""
    for i in message:
        if i == bitarray('10100011'):
            temp += 'ESC' + ' '
        elif i == bitarray('01111110'):
            temp += 'FLAG' + ' '
        else:
            temp += i.tobytes().decode('ascii') + ' '
    return temp.strip()    

def test():
    print(parse_message(bit_unstuffing(bit_stuffing(get_message()))))

if __name__ == '__main__':
    test()
