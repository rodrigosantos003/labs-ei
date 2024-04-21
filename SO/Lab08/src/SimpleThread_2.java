public class SimpleThread_2 extends Thread {
    @Override
    public void run() {
        System.out.println(this.getName());

        try {
            sleep((long) Math.random() * 1000);
            System.out.println(this.getName() + " is exiting...");
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

    }
    public static void main(String[] args) {
        SimpleThread_2[] threads = new SimpleThread_2[5];

        for(int i = 0; i < threads.length; i++){
            threads[i] = new SimpleThread_2();
            threads[i].start();
        }

        for(int i = 0; i < threads.length; i++){
            try {
                threads[i].join();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }

        System.out.println("Program is ending...");
    }
}
