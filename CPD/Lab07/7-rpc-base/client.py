"""
 Simple JSON-RPC Client

"""

import socket
import json


class JSONRPCClient:
    """The JSON-RPC client."""

    def __init__(self, host, port):
        self.sock = socket.socket()
        self.sock.connect((host, port))

    def send(self, msg):
        """Sends a message to the server."""
        self.sock.sendall(msg.encode())
        return self.sock.recv(1024).decode()

    def invoke(self, method, params):
        req = {
            'method': method,
            'params': params
        }

        res = client.send(json.dumps(req))

        if 'None' in res or 'Error' in res:
            raise AttributeError('Remote method unavailable')
        else:
            return res

    def __getattr__(self, name):
        """Invokes a generic function."""

        def inner(*params):
            try:
                return self.invoke(name, params)
            except AttributeError as e:
                print('Error: ', e)

        return inner


if __name__ == "__main__":
    # Test the JSONRPCClient class
    client = JSONRPCClient('127.0.0.1', 8000)
    res = client.add(2, 3)
    print(res)
