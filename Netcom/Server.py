import socket
import os 

# itr = 0
host = socket.gethostbyname("")
port = 9999
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((host,port))
s.listen(2)
itr = 0

conn,addr=s.accept()
while(True):
    print("connection from "+str(addr))
    data = conn.recv(1024).decode()
    if( data == "!"):
        break
    print(data)
    if(itr%2 == 0):
        conn.send("ACK0".encode())
    else:
        conn.send("ACK1".encode())
    itr=itr+1
    if(data=="!"):
        s.close()

# s.close()