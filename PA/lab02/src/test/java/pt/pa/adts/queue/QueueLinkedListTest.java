package pt.pa.adts.queue;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class QueueLinkedListTest {
    protected Queue<Integer> queue;

    @BeforeEach
    void setUp(){
        queue = new QueueLinkedList<>();
    }

    @Test
    void enqueue() {
        int newElem = 5;
        queue.enqueue(newElem);
        assertEquals(1, queue.size());
        assertEquals(newElem, queue.front());
    }

    @Test
    void dequeue() {
        queue.enqueue(5);
        queue.enqueue(10);
        int elem = queue.dequeue();
        assertEquals(1, queue.size());
        assertEquals(5, elem);

        queue.dequeue();

        assertThrows(QueueEmptyException.class, ()->{
            queue.dequeue();
        });
    }

    @Test
    void front() {
        int elem = 27;

        queue.enqueue(elem);

        assertEquals(elem, queue.front());
    }

    @Test
    void size() {
        assertEquals(0, queue.size());

        int elem1 = 1;
        int elem2 = 2;
        int elem3 = 3;

        queue.enqueue(elem1);
        queue.enqueue(elem2);
        queue.enqueue(elem3);

        assertEquals(3, queue.size());
    }

    @Test
    void isEmpty() {
        int elem = 32;

        queue.enqueue(elem);
        queue.dequeue();

        assertTrue(queue.isEmpty());
    }

    @Test
    void clear() {
        int elem1 = 1;
        int elem2 = 2;
        int elem3 = 3;

        queue.enqueue(elem1);
        queue.enqueue(elem2);
        queue.enqueue(elem3);

        queue.clear();

        assertEquals(0, queue.size());
    }
}