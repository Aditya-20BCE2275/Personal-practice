import socket

s = socket.socket()

port = 9999
s.connect(("192.168.53.47", port))
data = "hello!"

s.send("harsh".encode())
s.send(data[0].encode())
# s.close()
back = s.recv(1024).decode()
for i in range(len(data)):
    # s.connect(("192.168.5.226", port))
    if (back == "ACK0") or (back == "ACK1"):
        s.send(data[i].encode())
        print(data[i])
        back = s.recv(1024).decode()
        print(back + "\n")
# s.close()
back = s.recv(1024).decode()
