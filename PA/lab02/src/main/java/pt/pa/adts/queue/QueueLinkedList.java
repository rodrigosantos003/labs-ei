package pt.pa.adts.queue;

import org.w3c.dom.Node;

import java.util.List;

/**
 * This class must implement the Queue interface
 * @param <T>
 */
public class QueueLinkedList<T> implements Queue<T>  {

    private ListNode header, trailer;
    private int size;

    public QueueLinkedList() {
        this.header = new ListNode(null, null, null);
        this.trailer = new ListNode(null, this.header, null);
        this.header.prev = this.trailer;
        this.size = 0;
    }

    /**
     * Add an element to the queue
     * @param elem element to store
     *
     * @throws QueueFullException
     * @throws NullPointerException
     */
    @Override
    public void enqueue(T elem) throws QueueFullException, NullPointerException {
        try{
            if(elem == null) throw new NullPointerException();

            ListNode prevNode = this.trailer.prev;
            ListNode newNode = new ListNode(elem, prevNode, this.trailer);
            this.trailer.prev = newNode;
            prevNode.next = newNode;

            this.size++;
        } catch (OutOfMemoryError e) {
            throw new QueueFullException();
        }
    }

    /**
     * Remove an element from the queue
     * @return Removed element
     * @throws QueueEmptyException
     */
    @Override
    public T dequeue() throws QueueEmptyException {
        if(isEmpty()) throw new QueueEmptyException();

        ListNode removedNode = this.header.next;

        this.header.next = removedNode.next;
        removedNode.next.prev = this.header;

        this.size--;

        return removedNode.element;
    }

    /**
     * Return the element on the front
     * @return ELement on the front
     * @throws QueueEmptyException
     */
    @Override
    public T front() throws QueueEmptyException {
        if(isEmpty()) throw new QueueEmptyException();

        return this.header.next.element;
    }

    /**
     * Return the size of the queue
     * @return Size of the queue
     */
    @Override
    public int size() {
        return this.size;
    }

    /**
     * Check if the queue is empty
     * @return True if the queue is empty, false otherwise
     */
    @Override
    public boolean isEmpty() {
        return this.size == 0;
    }

    /**
     * Clears all the elements of the queue
     */
    @Override
    public void clear() {
        this.header.next = this.trailer;
        this.trailer.prev = this.header.next;
        this.size = 0;
    }

    //TODO: implementar métodos da interface à custa da estrutura de dados fornecida

    private class ListNode {
        private T element;
        private ListNode next;
        private ListNode prev;

        public ListNode(T element, ListNode prev, ListNode next) {
            this.element = element;
            this.next = next;
            this.prev = prev;
        }
    }
}
