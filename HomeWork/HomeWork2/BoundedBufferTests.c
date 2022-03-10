public class BoundedBufferTests {

    public static void main(String[] args) {
        BoundedBuffer test = new BoundedBuffer();
        
        class Producer extends Thread {
          public void run() {
            try {
              test.insert(5);
              System.out.println("Produce");
            } catch (InterruptedException e) {
              System.out.println("WAIT");
            }
          }
        }

        class Consumer extends Thread {
          public void run() {
            try {
              System.out.print("Consume");
              System.out.println(test.retrieve());
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
