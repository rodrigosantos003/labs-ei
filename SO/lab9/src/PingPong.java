import java.util.concurrent.Semaphore;

public class PingPong {
    private static final Semaphore doPing = new Semaphore(1, true);
    private static final Semaphore doPong = new Semaphore(0, true);

    public static class Ping extends Thread {
        @Override
        public void run(){
            while (true){
                try {
                    doPing.acquire();
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
                System.out.println("Ping");

                doPong.release();
            }
        }
    }

    public static class Pong extends Thread{
        @Override
        public void run(){
            while (true){
                try {
                    doPong.acquire();
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }

                System.out.println("Pong");

                doPing.release();
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
         Ping ping = new Ping();
         Pong pong = new Pong();

         ping.start();
         pong.start();
    }
}
