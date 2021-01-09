from tcpfsm import TCPFiniteStateMachine
from tcpfsm import Data
import socket


class Server:
    """
    Server class
    """
    def __init__(self, tcp_state, data):
        self.ME = 'server'
        self.HOST = '127.0.0.1'
        self.PORT = 22085
        self.ADDRESS = (self.HOST, self.PORT)

        self.serverSock = socket.socket()
        self.serverSock.bind(self.ADDRESS)
 
        tcp_state.listening()
        self.serverSock.listen(1)

        clientSock, addr = self.serverSock.accept()

        choice = str(input("Connection requested: do you want to acknowledge?[Y/n]"))
        if choice == 'Y':
            tcp_state.syn_acked(clientSock, tcp_state)

            while tcp_state.is_established:
                data.send(clientSock, tcp_state)
                data.receive(clientSock, tcp_state)

        else:
            tcp_state.reset_conn(clientSock, tcp_state)
            
        self.serverSock.close()

    def whoami(self):
        return self.ME


def main():
    tcp_fsm = TCPFiniteStateMachine()
    data = Data(12344)
    server = Server(tcp_fsm, data)


if __name__ == '__main__':
    main()


