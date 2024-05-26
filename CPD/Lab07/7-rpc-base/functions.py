"""
 Some functions

"""


def hello():
    return 'Hi!'


def greet(*params):
    return 'Hello ' + params[0]


def add(*params):
    a = int(params[0])
    b = int(params[1])
    return str(a + b)


def sub(*params):
    return params[0] - params[1]


def mul(*params):
    return params[0] * params[1]


def div(*params):
    return params[0] / params[1]


def hello2():
    return 'Hello2'
