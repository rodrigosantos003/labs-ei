import java.util.concurrent.Semaphore;

public class MyThread extends Thread {
    private static final Semaphore semaphore = new Semaphore(1, true);

    @Override
    public void run() {
        doJob(this.getName());
    }
    static void doJob(String name) {
        try {
            semaphore.acquire();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        System.out.println("Start: " + name);
        try {
            sleep(2000);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        System.out.println("End: " + name);

        semaphore.release();
    }
    public static void main(String[] args) {
        for (int i = 0; i < 5; i++) {
            new MyThread().start();
        }
    }
}