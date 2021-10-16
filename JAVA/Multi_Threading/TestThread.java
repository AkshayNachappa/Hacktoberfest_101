class RunnableDemo implements Runnable {
    private Thread t;
    private String threadName;

    RunnableDemo(String name) {
        this.threadName = name;
        System.out.println("Creating " + this.threadName);
    }

    public void run() {
        System.out.println("Running " + this.threadName);
        try {
            for (int i = 4; i > 0; i--) {
                System.out.println("Thread: " + this.threadName + " -> " + i);
                Thread.sleep(5000);
            }
        } catch (InterruptedException e) {
            System.out.println("Thread " + this.threadName + " Interrupted");
        }
        System.out.println("Thread " + this.threadName + " Existing");
    }

    public void start() {
        System.out.println("Starting " + this.threadName);
        if (t == null) {
            System.out.println("Thread Intialized of "+ this.threadName);
            t = new Thread(this, this.threadName);
            t.start();
        }
    }
}

public class TestThread {
    public static void main(String []args) {
        RunnableDemo r1 = new RunnableDemo("BIKE");
        r1.start();
        System.out.println("\n");

        RunnableDemo r2 = new RunnableDemo("ACTIVA");
        r2.start();
        System.out.println("\n");

        RunnableDemo r3 = new RunnableDemo("CAR");
        r3.start();
    }
}