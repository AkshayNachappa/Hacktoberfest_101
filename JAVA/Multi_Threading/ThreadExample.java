class MyClass implements Runnable{
    private Thread thread;
    private String threadName;
    
    MyClass(String threadName){
        this.threadName = threadName;
        System.out.println("Creating "+ threadName);
    }
    public void run(){
        System.out.println("Running " + this.threadName);
    }
    public void start(){
        if(this.thread == null){
           this.thread = new Thread(this,this.threadName);
           this.thread.start();
        }
    }
}
public class ThreadExample {
   public static void main(String[] args) {
       MyClass t1 = new MyClass("Thread 1");
       t1.start();
       MyClass t2 = new MyClass("Thread 2");
       t2.start();
       MyClass t3 = new MyClass("Thread 3");
       t3.start();
   }       
}
