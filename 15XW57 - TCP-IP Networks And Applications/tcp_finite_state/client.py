from tcp_statemachine import TCPStateMachine, Data
import socket


class Client:
  """
  Client class
  """
  def __init__(self, statemachine, data):
    self.ME = 'client'
    self.HOST = '127.0.0.1'
    self.PORT = 22085
    self.ADDRESS = (self.HOST, self.PORT)
    self.client_socket = socket.socket()

  def run(self):
    self.client_socket.connect(self.ADDRESS)
    self.statemachine.send_syn(self.client_socket, self.statemachine)
    self.statemachine.conn_estb_client()

    data.receive(self.client_socket, statemachine)		
    while statemachine.is_established:
      data.send(self.client_socket, statemachine)
      data.receive(self.client_socket, statemachine)

    self.client_socket.close()	

  def whoami(self):
    return self.ME


def main():
    tcp_fsm = TCPFiniteStateMachine()
    data = Data(12345)
    client = Client(tcp_fsm, data)


if __name__ == '__main__':
    main()
