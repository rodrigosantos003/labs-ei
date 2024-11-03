package pt.pa.adts;

/**
 * Stack specification
 * @param <T> Stack element type
 */
public interface Stack<T>  {
    /**
     * Adds an element to the top of the stack
     * @param element Element to add
     * @throws FullStackException if the stack is full
     */
    public void push(T element) throws FullStackException;

    /**
     * Removes the element on the top of the stack
     * @return Removed element
     * @throws EmptyStackException if the stack is empty
     */
    public T pop() throws EmptyStackException;

    /**
     * Returns the element on the top of the stack
     * @return Top element
     * @throws EmptyStackException if the stack is empty
     */
    public T peek() throws EmptyStackException;

    /**
     * Returns the current size of the stack
     * @return Size of the stack
     */
    public int size();

    /**
     * Checks if the stack is empty
     * @return True if the stack is empty, false otherwise
     */
    public boolean isEmpty();

    /**
     * Clears all stack elements
     */
    public void clear();
}