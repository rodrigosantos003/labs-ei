package pt.pa.adts;


public class StackLinkedList<T> implements Stack<T> {

    private Node top; //sentinel of linked list
    private int size;

    public StackLinkedList() {
        /*
        The configuration of an empty singly linked list is the sentinel
        pointing to null.
         */
        this.top = new Node(null, null);
        this.size = 0;
    }

    @Override
    public void push(T element) throws FullStackException {
        /*
        Element should be stored in a new node which is pointed by top sentinel.
        Must maintain the chaining of all nodes.
         */
        this.top.next = new Node(element, this.top.next);
        this.size++;
    }

    @Override
    public T pop() throws EmptyStackException {
        /*
        The element at the top of the stack is the element stored in the
        node immediately after the top sentinel.
         */
        if(isEmpty()) throw new EmptyStackException();

        T elem = this.top.next.element;
        this.top.next = this.top.next.next;
        this.size--;

        return elem;
    }

    @Override
    public T peek() throws EmptyStackException {
        if(isEmpty()) throw new EmptyStackException();

        return this.top.next.element;
    }

    @Override
    public int size() {
      return this.size;
    }

    @Override
    public boolean isEmpty() {
        return this.size == 0;
    }

    @Override
    public void clear() {
       this.size = 0;
    }

    /**
     * Inner class representing a linked list node.
     * Only recognized in the context of this class (private).
     */
    private class Node {
        private T element;
        private Node next;

        public Node(T element, Node next) {
            this.element = element;
            this.next = next;
        }
    }
}
