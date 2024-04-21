import threading
import random
import queue


def task(list, queue):
    s = 0
    for n in list:
        s += n
    print(s)
    queue.put(s)


l = [random.randint(0, 100) for _ in range(0, 1000)]

half_l = len(l) // 2

q = queue.Queue()

t1 = threading.Thread(target=task, args=[l[0:half_l], q])
t2 = threading.Thread(target=task, args=[l[half_l:], q])

t1.start()
t2.start()
t1.join()
t2.join()

res = 0

while not q.empty():
    res += q.get()

print(res / 1000)
