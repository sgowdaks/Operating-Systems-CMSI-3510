public class BoundedBuffer {
private Object[] buffer = new Object[20];
private int numOccupied = 0;
private int firstOccupied = 0;

public synchronized void insert(Object o)
throws InterruptedException {
  while(numOccupied == buffer.length) {
    wait();
  }
  buffer[(firstOccupied + numOccupied) % buffer.length] = o;
  numOccupied++;
  notifyAll();
}


public synchronized Object retrieve()
throws InterruptedException
{
    while(numOccupied == 0){
      wait();
    }
    Object retrieved = buffer[firstOccupied];
    buffer[firstOccupied] = null;
    firstOccupied = (firstOccupied + 1) % buffer.length;
    numOccupied--;
    notifyAll();
  // System.out.printf("Consumer consumes: %d\n",retrieved);
    return retrieved;
}
}
