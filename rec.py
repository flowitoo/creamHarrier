#==================================#
#                                  #
#  Client --> Server --> time.ldb  #
#                                  #
#==================================#
# Taken and modified from https://docs.python.org/3/library/socket.html
import socket
import time
import sys
HOST = ''
PORT = 50007
while True:
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.bind((HOST, PORT))
        s.listen(5)
        conn, addr = s.accept()
        with conn:
            print('Connected by', addr)
            while True:
                data = conn.recv(50000)
                if(data):
                    with open(f"{int(time.time())}.ldb","wb") as f:
                        f.write(data)
                        f.close()
                    print('Recived by', addr)
                    break
                else:
                     break
            conn.close()
        s.close()
    except KeyboardInterrupt:
        break
sys.exit()
