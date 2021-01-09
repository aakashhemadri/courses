import socket
import sys
import json
from time import sleep

TCP_PACKET = {'seq':0,'ack':0,'flag':{'U':0,'A':0,'P':0,'R':0,'S':0,'F':0},'data':''}

def connEstd(cliSoc,seq):
    print("SERVER PASSIVE OPEN")
    print("STATE : LISTEN")
    sleep(3)
    data = clisoc.recv(1024)
    print("STATE : SYN RCVD")
    sleep(3)
    data = json.loads(data.decode('ascii'))
    if data['flag']['S'] == 1 :
        TCP_PACKET['seq'] = seq
        TCP_PACKET['ack'] = data['seq']+1
        TCP_PACKET['flag']['S'] = 1
        TCP_PACKET['flag']['A'] = 1
        data = json.dumps(TCP_PACKET)
        clisoc.sendall(data.encode('ascii'))
    data = clisoc.recv(1024)
    data = json.loads(data.decode('ascii'))
    if data['flag']['A'] == 1:
        print("STATE : CONNECTION ESTD")

def dataTrans(clisoc):

    print('STATE : ESTABLISHED')
    data = clisoc.recv(1024)
    data = json.loads(data.decode('ascii'))
    print(data['data'])
    TCP_PACKET['seq'] = data['ack'] - 1
    TCP_PACKET['ack'] = data['seq'] + 1
    TCP_PACKET['flag'] = {'U':0,'A':1,'P':0,'R':0,'S':0,'F':0}
    data = json.dumps(TCP_PACKET)
    clisoc.sendall(data.encode('ascii'))


def connTerm(cliSoc,seq,ack):
    cli_msg = clisoc.recv(1024)
    cli_msg = json.loads(cli_msg.decode('ascii'))
    if cli_msg['flag']['A'] == 1 and cli_msg['flag']['F'] == 1 :
        print('STATE : CLOSED WAIT')
        sleep(3)
        TCP_PACKET['seq'] = cli_msg['ack']
        TCP_PACKET['ack'] = cli_msg['seq'] + 1
        TCP_PACKET['flag']['F']=1
        TCP_PACKET['flag']['A']=1
        data = json.dumps(TCP_PACKET)
        clisoc.sendall(data.encode('ascii'))
        print('STATE : LAST ACK')
        sleep(3)
    cli_msg = clisoc.recv(1024)
    cli_msg = json.loads(cli_msg.decode('ascii'))
    if cli_msg['flag']['A'] == 1 and cli_msg['flag']['F'] == 0 :
        print('STATE : CONNECTION TERMINATED')


if __name__ == "__main__":
    HOST = "127.0.0.1"
    PORT = 9990
    # Create a socket (SOCK_STREAM means a TCP socket)
    soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    soc.bind((HOST,PORT))
    soc.listen()
    clisoc, addr = soc.accept()
    connEstd(clisoc,8000)
    dataTrans(clisoc)
    connTerm(clisoc,500,10001)
