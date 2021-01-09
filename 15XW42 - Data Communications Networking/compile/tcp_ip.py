"""
Created on Wed Jun 12 15:31:37 2019

@author: Aakash

"""
import sys
import os
import socket

def client():
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
                s.connect(('localhost',9999))
                f = open("program.c","rb")
                l = f.read(1024)
                while(l):
                        s.send(l)
                        l = f.read(1024)
                file = conn.recv(1024)
                print('Client Received!')
                conn.send('File received!')
        s.close()
        return 'Client Exiting'

def server():
        s = socket.socket()
        port = 9999
        host = socket.gethostname()
        s.bind((host,port))
        s.listen(5)
        print('Server Listening...')
        while True:
                conn, addr = s.accept()
                print('Connection Established! Address:', addr)
                blob = conn.recv(1024)
                print('Server received file')
                filename = 'received_file.c'
                with open(filename, 'wb') as f:
                        print('File Opened')
                        while True:
                                f.write(data)
                                os.system('cc ' + filename + ' -o binary >2 error_log')
                                if (os.path.isfile('error_log')
                                        print('Sending error log...')
                                        with open('error_log', 'rb') as e:
                                                l = f.read(1024)
                                                while(l):
                                                        s.send(l)
                                                        l = f.read(1024)
                                                os.remove('error_log')
                                                e.close()
                                        print('Deleted log in server')
                                elif (os.path.isfile('binary'))
                                        print('Sending Binary..')
                                        with open('binary', 'rb') as b:
                                                l = f.read(1024)
                                                while(l):
                                                        s.send(l)
                                                        l = f.read(1024)
                                                os.remove('binary')
                                                b.close()
                                else
                                        print('Error')
        return 'Server Exiting'

def test():
        filename = 'program.c'
        os.system('cc ' + filename + ' -o binary 2> error_log')

if __name__=='__main__':
    if(len(sys.argv) > 1):
        if(sys.argv[1] == 'client'):
            print(client())
        elif(sys.argv[1] == 'server'):
            print(server())
        else:
            print(test())
    else:
        test()
