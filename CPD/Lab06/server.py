"""
 Implements a simple socket server

"""

import socket
import threading


def handle_client(connections, client_connection):
    user = client_connection.recv(1024).decode()
    greet_user = "You are now connected, " + user + "!"
    client_connection.sendall(greet_user.encode())

    for con in connections:
        if con != client_connection:
            send_msg = user + " joined the chat"
            con.sendall(send_msg.encode())

    while True:
        # Print message from client
        msg = client_connection.recv(1024).decode()
        print('Received:', msg)

        # Terminate connection
        if msg == 'exit':
            exit_msg = "Goodbye " + user + "!"
            client_connection.sendall(exit_msg.encode())
            break

        # Send response to client
        for con in connections:
            send_msg = "(" + user + ")" + msg
            con.sendall(send_msg.encode())

    # Close client connection
    print('Client disconnected...')
    for con in connections:
        if con != client_connection:
            send_msg = user + " exit the chat"
            con.sendall(send_msg.encode())
    connections.remove(client_connection)
    client_connection.close()


# Define socket host and port
SERVER_HOST = '0.0.0.0'
SERVER_PORT = 8000

# Create socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server_socket.bind((SERVER_HOST, SERVER_PORT))
server_socket.listen(1)
print('Listening on port %s ...' % SERVER_PORT)

# Wait for client connections
connections = []

while True:
    client_connection, client_address = server_socket.accept()
    connections.append(client_connection)

    thread = threading.Thread(target=handle_client, args=[connections, client_connection])
    thread.start()

# Close socket
server_socket.close()
