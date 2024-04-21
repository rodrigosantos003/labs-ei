public class Counter {
    static class CounterThread extends Thread {
        Counter counter;
        public CounterThread(Counter counter) {
            this.counter = counter;
        }
        @Override
        public void run() {
            counter.count(this.getName());
        }
    }
    public synchronized void count(String name) {
        for (int i=0; i<10; i++) {
            notify();
            System.out.println(name + ": " + i);
            try {
                wait();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
    public static void main(String[] args) {
        Counter counter = new Counter();
        CounterThread thread0 = new CounterThread(counter);
        CounterThread thread1 = new CounterThread(counter);
        thread0.start();
        thread1.start();
    }
}
