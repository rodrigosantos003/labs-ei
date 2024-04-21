"""
 Thumbnail file generator

"""

import concurrent.futures
import multiprocessing.pool
import threading
import time

from PIL import Image, ImageFilter

images = [
    'images/image0.jpg',
    'images/image1.jpg',
    'images/image2.jpg',
    'images/image3.jpg',
    'images/image4.jpg',
    'images/image5.jpg',
    'images/image6.jpg',
    'images/image7.jpg',
    'images/image8.jpg',
]


def timeit(fn):
    start = time.time()
    fn()
    print(time.time() - start, 'seconds')


def task(filename):
    """Executes an image processing task."""
    with Image.open(filename) as img:
        img.filter(ImageFilter.SHARPEN)
        img.thumbnail((128, 128))
        img.show()

        thumbName = filename + ".thumbnail.jpg"
        img.save(thumbName)
    print(filename, 'done')


def serial_thumbnails():
    """Processes images in series."""
    for file in images:
        task(file)


def threading_thumbnails():
    """Processses images using threads."""
    threads = []

    for image in images:
        t = threading.Thread(target=task, args=[image])
        t.start()
        threads.append(t)

    for t in threads:
        t.join()


def pool_thumbnails():
    """Processses images using ThreadPool."""
    with multiprocessing.pool.ThreadPool(processes=len(images)) as pool:
        res = pool.map_async(task, images)
        res.wait()


def executor_thumbnails():
    """Processses images using ThreadPoolExecutor."""
    with concurrent.futures.ThreadPoolExecutor(max_workers=len(images)) as executor:
        executor.map(task, images)


if __name__ == '__main__':
    #timeit(serial_thumbnails)
    #timeit(threading_thumbnails)
    #timeit(pool_thumbnails)
    timeit(executor_thumbnails)
