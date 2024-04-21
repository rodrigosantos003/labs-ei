public class SimpleThread_c extends Thread {
    @Override
    public void run() {
        for (int i=0; i<5; i++) {
            System.out.println(this.getName() + ": " + i);
        }

    }
    public static void main(String[] args) {
        SimpleThread thread0 = new SimpleThread();
        SimpleThread thread1 = new SimpleThread();
        thread1.setPriority(MAX_PRIORITY);
        thread0.start();
        try {
            thread0.join();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        thread1.start();
    }
}
