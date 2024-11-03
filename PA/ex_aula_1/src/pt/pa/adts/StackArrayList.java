package pt.pa.adts;

import java.util.Arrays;

/**
 * Implementation of a stack based on array
 *
 * @param <T> Stack element type
 */
public class StackArrayList<T> implements Stack<T> {

    /**
     * Default capacity of the stack
     */
    private static final int DEFAULT_CAPACITY = 40;

    /**
     * Array of elements
     */
    private T[] elements;

    /**
     * Size of the array
     */
    private int size;

    @SuppressWarnings("unchecked")
    public StackArrayList() {
        this.elements = (T[]) new Object[DEFAULT_CAPACITY];
        this.size = 0;
    }

    @Override
    public void push(T element) throws FullStackException {
        if (this.size >= this.elements.length)
            this.elements = Arrays.copyOf(this.elements, this.elements.length + DEFAULT_CAPACITY);

        this.elements[this.size++] = element;
    }

    @Override
    public T pop() throws EmptyStackException {
        if (this.size == 0) throw new EmptyStackException();

        T elem = this.elements[this.size - 1];
        this.elements[this.size - 1] = null; //Q: Strictly necessary? Why is it a good idea?
        this.size--;

        return elem;
    }

    @Override
    public T peek() throws EmptyStackException {
        if (isEmpty()) throw new EmptyStackException();

        return this.elements[this.size - 1];
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
}
