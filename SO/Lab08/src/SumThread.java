public class SumThread extends Thread {
//    int[] array;
//    int res;
//    public SumThread(int array[]) {
//        this.array = array;
//    }
//    @Override
//    public void run() {
//        for (int j : array) {
//            res += j;
//        }
//    }
//    public static int sum(int array[]) throws InterruptedException {
//        SumThread thread = new SumThread(array);
//        thread.start();
//        thread.join();
//        return thread.res;
//    }
//    public static void main(String[] args) throws InterruptedException {
//        int[] arr = new int[]{1, 2, 3, 4, 5, 6, 7, 8};
//        System.out.println(sum(arr));
//    }

    int[] array;
    int res, startIndex, endIndex;

    static int max;

    public SumThread(int array[], int startIndex, int endIndex) {
        this.array = array;
        this.startIndex = startIndex;
        this.endIndex = endIndex;
    }
    @Override
    public void run() {
//        for(int i = startIndex; i <= endIndex; i++){
//            res += array[i];
//        }
        for(int i = startIndex; i <= endIndex; i++){
        if(array[i] > max){
            max = array[i];
        }
      }
    }
    public static int sum(int array[], int numberThreads) throws InterruptedException {
        SumThread[] threads = new SumThread[numberThreads];

        int numberAmount = array.length / threads.length;

        int res = 0;

        for(int i = 0; i < numberThreads; i++){
            threads[i] = new SumThread(array, i * numberAmount, i == numberThreads - 1 ? array.length - 1
                    : ((i+1)*numberAmount-1));
            threads[i].start();
        }

        for(int j = 0; j < numberThreads; j++){
            threads[j].join();
        }

        for(int x = 0; x < numberThreads; x++){
            res += threads[x].res;
        }

        return res;
    }

    public static int max(int array[], int numberThreads){
        SumThread[] threads = new SumThread[numberThreads];

        int numberAmount = array.length / threads.length;

        for(int i = 0; i < numberThreads; i++){
            threads[i] = new SumThread(array, i * numberAmount, i == numberThreads - 1 ? array.length - 1
                    : ((i+1)*numberAmount-1));
            threads[i].start();
        }

        for(int j = 0; j < numberThreads; j++){
            try {
                threads[j].join();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
        return max;
    }

    public static void main(String[] args) throws InterruptedException {
        int[] arr = new int[]{1, 2, 3, 19, 5, 6, 7, 8};
        System.out.println(sum(arr, 5));
        System.out.println(max(arr, 5));
    }
}