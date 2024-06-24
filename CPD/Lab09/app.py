"""
 Basic webservice application

"""

import json

USERS = [
    {
        "id": 1,
        "name": "Ana",
        "age": 22,
    },
    {
        "id": 2,
        "name": "Paulo",
        "age": 25,
    }
]


def controller(request):
    """Handles a request and returns a response."""
    print(request)

    url = request['url']
    if url == '/users/':
        response_ok(USERS)
    elif url.startswith('/users/'):
        try:
            user_id = int(url.split('/')[2])
            user = next((user for user in USERS if user['id'] == user_id), None)
            if user:
                response_ok(user)
            else:
                not_found({"error": "user not found"})
        except (IndexError, ValueError):
            return {
                'status': '400 Bad Request',
                'headers': {
                    'Content-Type': 'application/json'
                },
                'body': '{"error": "invalid user id"}',
            }

    not_found({"error": "not found"})


def response_ok(body):
    """Returns 200 Ok"""
    return {
        'status': '200 OK',
        'headers': {
            'Content-Type': 'application/json',
        },
        'body': json.dumps(body)
    }


def not_found(body):
    """Returns 404 Not Found"""
    return {
        'status': '404 Not Found',
        'headers': {
            'Content-Type': 'application/json'
        },
        body: json.dumps(body)
    }