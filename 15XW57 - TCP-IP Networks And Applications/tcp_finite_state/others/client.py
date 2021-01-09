import socket
import sys
import json
from time import sleep

TCP_PACKET = {'seq':0,'ack':0,'flag':{'U':0,'A':0,'P':0,'R':0,'S':0,'F':0},'data':''}

def connEstd(cliSoc,seq,ack):
    print('STATE : CLOSED')
    print("Client Active Open")
    sleep(3)
    TCP_PACKET['seq'] = seq
    TCP_PACKET['ack'] = ack
    TCP_PACKET['flag'] = {'U':0,'A':0,'P':0,'R':0,'S':1,'F':0}
    data = json.dumps(TCP_PACKET)
    clisoc.sendall(data.encode('ascii'))
    print('STATE : SYN SENT')
    sleep(3)
    serv_msg = clisoc.recv(1024)
    serv_msg = json.loads(serv_msg.decode('ascii'))
    if serv_msg['flag']['S'] == 1 and serv_msg['flag']['A'] == 1 :
        print('Connection established and sending ACK')
        sleep(3)
        TCP_PACKET['ack']=serv_msg['seq']+1
        TCP_PACKET['flag']['S']=0
        TCP_PACKET['flag']['A']=1
        data = json.dumps(TCP_PACKET)
        clisoc.sendall(data.encode('ascii'))
    

def dataTrans(clisoc, seq, ack):
    print('STATE : ESTABLISHED')
 
    sleep(3)
    TCP_PACKET['seq'] = seq + 1
    TCP_PACKET['ack'] = ack
    TCP_PACKET['flag'] = {'U':0,'A':1,'P':1,'R':0,'S':0,'F':0}
    TCP_PACKET['data'] = '3'
    data = json.dumps(TCP_PACKET)
    clisoc.sendall(data.encode('ascii'))
    print("DATA")

    serv_msg = clisoc.recv(1024)
    serv_msg = json.loads(serv_msg.decode('ascii'))
    print("DATA TRANS COMPLETED")
    sleep(3)

def connTerm(cliSoc,seq,ack):
    TCP_PACKET['seq'] = seq + 1
    TCP_PACKET['ack'] = ack
    TCP_PACKET['flag'] = {'U':0,'A':1,'P':0,'R':0,'S':0,'F':1}
    data = json.dumps(TCP_PACKET)
    clisoc.sendall(data.encode('ascii'))
    print('STATE : FIN WAIT 1')
    sleep(3)
    serv_msg = clisoc.recv(1024)
    serv_msg = json.loads(serv_msg.decode('ascii'))
    if serv_msg['flag']['A'] == 1 and serv_msg['flag']['F'] == 1 :
        print('STATE : TIME WAIT(2 MSL)')
        sleep(3)
        TCP_PACKET['ack'] = serv_msg['seq']+1
        TCP_PACKET['flag']['F']=0
        TCP_PACKET['flag']['A']=1
        data = json.dumps(TCP_PACKET)
        clisoc.sendall(data.encode('ascii'))
        sleep(3)
    print('STATE : CONNECTION TERMINATED')
    

if __name__=="__main__":
    HOST, PORT = "localhost", 9990
    # Create a socket (SOCK_STREAM means a TCP socket)
    clisoc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # Connect to server and send data
    clisoc.connect((HOST, PORT))
    connEstd(clisoc,1000,0)
    dataTrans(clisoc,1001,100)
    connTerm(clisoc,10000,500)
