public class BoundedBufferTests {

    public static void main(String[] args) {
        BoundedBuffer test = new BoundedBuffer();

        class Producer extends Thread {
          public void run() {
            try {
              for(int i = 0;i< 30;i++){
                System.out.printf("Producer produces %d\n",i);
                test.insert(i);
              }
            } catch (InterruptedException e) {
              System.out.println("WAIT");
            }
          }
        }

        class Consumer extends Thread {
          public void run() {
            try {
              for(int i = 0;i<30;i++){
              System.out.printf("Consumer consumes: %d\n",test.retrieve());
            }
            } catch (InterruptedException e) {
              System.out.println("WAIT");
            }
          }
        }

        Producer p = new Producer();
        Consumer c = new Consumer();

        p.start();
        c.start();

        try {
          p.join();
          c.join();
        } catch (InterruptedException e) {
          System.out.println("STOP");
        }

      }

}
