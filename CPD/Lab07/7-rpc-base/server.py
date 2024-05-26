"""
 Simple JSON-RPC Server

"""

import socket
import functions
import json


class JSONRPCServer:
    """The JSON-RPC server."""

    def __init__(self, host, port):
        self.host = host
        self.port = port

        # Map functions
        self.funcs = {}

    def register(self, name, function):
        self.funcs[name] = function

    def start(self):
        """Starts the server."""
        sock = socket.socket()
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        sock.bind((self.host, self.port))
        sock.listen(1)
        print('Listening on port %s ...' % self.port)

        while True:
            # Accept client
            conn, _ = sock.accept()

            # Receive message
            msg = conn.recv(1024).decode()
            print('Received:', msg)

            msg = json.loads(msg)
            method = msg['method']
            params = msg['params']

            # Execute function
            try:
                func = self.funcs[method]
                res = str(func(*params))
            except KeyError:
                res = 'Error'

            # Send response
            conn.send(json.dumps(res).encode())

            # Close client connection
            conn.close()


if __name__ == "__main__":
    # Test the JSONRPCServer class
    server = JSONRPCServer('0.0.0.0', 8000)
    server.register('add', functions.add)
    server.register('hello', functions.hello)
    server.register('hello2', functions.hello2)
    server.register('greet', functions.greet)
    server.register('mul', functions.mul)
    server.register('sub', functions.sub)
    server.register('div', functions.div)
    server.start()
