package pt.pa.adts.queue;

public class NullNotAllowedException extends RuntimeException {
    public NullNotAllowedException() {
       super("Null não permitido");
    }

    public NullNotAllowedException(String message) {
        super(message);
    }
}
