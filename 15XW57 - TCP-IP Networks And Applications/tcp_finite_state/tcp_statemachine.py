from statemachine import StateMachine, State
import pickle

class Data:
    """
    A Class for handling data used in server client connection
    """
    def __init__(self, seqNo):
        self.packet = {
                "seqNo":seqNo,
                "ackNo":0,
                "syn":False,
                "fin":False,
                "ack":False,
                "rst":False,
                "psh":False,
                "urg":False,
                "data":"some data"
                }

    def receive(self, sock, tcp_state):
        self.packet = pickle.loads(sock.recv(2014))

        if self.packet['fin']:
            if sock.whoami() == 'server': tcp_state.close_wait()
            if sock.whoami() == 'client': tcp_state.fin_wait()

        print(self.packet)

    def send(self, sock, tcp_state):
        sock.send(pickle.dumps(self.packet))

class TCPStateMachine(StateMachine):
  """
  States
  """
  closed = State('CLOSED', initial=True)
  listen = State('LISTEN')
  syn_send = State('SYN_SEND')
  syn_rcvd = State('SYN_RCVD')
  established = State('ESTABLISHED')
  fin_wait_1 = State('FIN_WAIT_1')
  fin_wait_2 = State('FIN_WAIT_2')
  close_wait = State('CLOSE_WAIT')
  time_wait = State('TIME_WAIT')
  last_ack = State('LAST_ACK')
  closing = State('CLOSING')

  """
  State Transitions 
  """

  listening = closed.to(listen)
  syn_acked = listen.to(syn_rcvd)
  conn_estb_server = syn_rcvd.to(established)
  close = established.to(close_wait)
  last_ack = close_wait.to(closed)

  send_syn = closed.to(syn_sent)
  conn_estb_client = syn_sent.to(established)
  fin_wait = established.to(fin_wait_1)
  fin_wait_final = fin_wait_1.to(fin_wait_2)
  time_wait = fin_wait_2.to(closed)

  def on_listening(self):
    print('Server port is listening for request from clients')
    
  def on_syn_acked(self, sock, tcp_state):
    data = pickle.loads(sock.recv(1024))
    if data['syn']:
      self.packet['syn'] = True
      self.packet['ack'] = True
      sock.packet(pickle.dumps(self.packet))
            
    data = pickle.loads(sock.recv(1024))
    if data['syn'] == False and data['ack']:
      print('Connection request acknowledged')
      tcp_state.conn_estb_server()
    else:
      print('Connection reset due to invalid acknowledgment packet')
      sock.close()

  def on_conn_estb_server(self):
    print('Connection established with client\n')

  def on_close_wait(self):
    pass

  def on_last_ack(self):
    pass

  def on_send_syn(self, sock, tcp_state):
    self.packet['syn'] = True
    sock.send(pickle.dumps(self.packet))
    data = pickle.loads(sock.recv(1024))
    if data['syn'] and data['ack']:
      self.packet['syn'] = False
      self.packet['ack'] = True
      sock.send(pickle.dumps(self.packet))
      print('Connection request sent to server')

  def on_conn_estb_client(self):
    print('Connection established with server\n')

  def on_fin_wait(self):
    print('FIN WAIT')

  def on_fin_wait_final(self):
    print('FIN WAIT FINAL')

  def on_time_wait(self):
    pass


def test():
  print("Initialized StateMachine!")

if __name__ == '__main__':
  test()