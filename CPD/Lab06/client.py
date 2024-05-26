"""
 Implements a simple socket client

"""

import socket
import threading


def listening_thread(client_socket):
    while True:
        # Read response
        res = client_socket.recv(1024).decode()
        print(res)

        if res.startswith("Goodbye"):
            break


# Define socket host and port
SERVER_HOST = '127.0.0.1'
SERVER_PORT = 8000

# Create socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to server
client_socket.connect((SERVER_HOST, SERVER_PORT))

user = input("Introduza o nome de utilizador> ")
client_socket.sendall(user.encode())
#greeting = client_socket.recv(1024).decode()
#print(greeting)

thread = threading.Thread(target=listening_thread, args=[client_socket])
thread.start()

while True:
    # Send message
    msg = input('> ')
    client_socket.sendall(msg.encode())

    if msg == 'exit':
        break

thread.join()

# Close socket
client_socket.close()
