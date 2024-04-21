import multiprocessing
import random


def task(lst, index_a, index_b, que):
    print("Executing task...")

    s = sum(lst[index_a:index_b])
    que.put(s)

    return s


if __name__ == '__main__':
    with multiprocessing.Manager() as manger:
        l = manger.list(range(30_000_000))

        queue = multiprocessing.Queue()

        print("Creating processes...")
        p1 = multiprocessing.Process(target=task, args=[l, 0, len(l) // 2, queue])
        p2 = multiprocessing.Process(target=task, args=[l, len(l) // 2, len(l), queue])

        p1.start()
        p2.start()

        p1.join()
        p2.join()

        s = 0

        while not queue.empty():
            s += queue.get()

        m = s / len(l)
        print("Mean: ", m)
