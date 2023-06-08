import socket

# create a socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# define the server's IP address and port number
server_address = ("192.168.188.226", 5000)

# connect to the server
client_socket.connect(server_address)

# send the password to the server
password = 'You are more suicidal everyday arent you'
client_socket.sendall(password.encode())

# receive the server's response
response = client_socket.recv(1024)
print(response.decode())

# close the socket
client_socket.close()
