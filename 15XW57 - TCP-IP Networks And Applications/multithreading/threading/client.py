import socket

class Client()
  def __init__(self, host, port):
    self.host = host
    self.port = port
    self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
  
  def send(self, host, port):
    self.sock.connect((host, port))
    host = subprocess.check_output(['arp','-a',data.decode('ascii')])