"""
 Implements a simple HTTP/1.0 Server

"""

import socket


def handle_request(request):
    lines = request.split('\n')
    resource = lines[0].split(' ')
    page = resource[1]
    method = resource[0]
    if page == '/':
        page = '/index.html'
    if method == 'POST':
        print(lines[len(lines)-1])
        data = lines[len(lines)-1].split('&')
        name = data[0].split('=')[1]
        age = data[1].split('=')[1]

        content = f"name: {name} <br/> age: {age}".encode()
        return b'HTTP/1.1 200 OK\n\n<h1>POST</h1>' + content
    try:
        response = b'HTTP/1.0 200 OK\n\n'
        with open('htdocs' + page, 'rb') as f:
            response += f.read()
            return response
    except FileNotFoundError:
        return b'HTTP/1.0 404 NOT FOUND\n\nFile not found.'


# Define socket host and port
SERVER_HOST = '0.0.0.0'
SERVER_PORT = 8000

# Create socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server_socket.bind((SERVER_HOST, SERVER_PORT))
server_socket.listen(1)
print('Listening on port %s ...' % SERVER_PORT)

while True:
    # Wait for client connections
    client_connection, client_address = server_socket.accept()

    # Handle client request
    request = client_connection.recv(1024).decode()
    response = handle_request(request)

    # Send HTTP response
    client_connection.sendall(response)
    client_connection.close()

# Close socket
server_socket.close()
