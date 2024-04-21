public class SimpleThread extends Thread {
    @Override
    public void run() {
        for (int i=0; i<5; i++) {
            System.out.println(this.getName() + ": " + i);
            try {
                sleep(500);

            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }

    }
    public static void main(String[] args) {
        SimpleThread thread0 = new SimpleThread();
        SimpleThread thread1 = new SimpleThread();
        thread0.start();
        thread1.start();
    }
}
