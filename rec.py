#==================================#
#                                  #
#  Client --> Server --> time.ldb  #
#                                  #
#==================================#
# Taken and modified from https://docs.python.org/3/library/socket.html
import socket
import time
HOST = ''
PORT = 50007
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen(1)
    conn, addr = s.accept()
    with conn:
        print('Connected by', addr)
        while True:
            data = conn.recv(25000)
            if(data):
                print(data.decode("ISO-8859-1"))
                with open(f"{int(time.time())}.ldb","wb") as f:
                    f.write(data)
                    f.close()
                s.close()
