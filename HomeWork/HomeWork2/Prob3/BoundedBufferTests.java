public class BoundedBufferTests {

    public static void main(String[] args) {
        BoundedBuffer test = new BoundedBuffer();
        Producer p = new Producer(test);
        Consumer c = new Consumer(test);

        p.start();
        c.start();

      }
    }

        class Producer extends Thread {
          private BoundedBuffer test;
          public Producer(BoundedBuffer test) {
              this.test = test;
            }

          public void run() {
            try {
              for(int i = 0;i< 30;i++){
                System.out.printf("Producer produces %d\n",i);
                test.insert(i);
                // sleep(1);
              }
            } catch (InterruptedException e) {
              System.out.println("WAIT");
            }

          }


      }


        class Consumer extends Thread {
          private BoundedBuffer test;
          public Consumer(BoundedBuffer test) {
              this.test = test;
            }

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
