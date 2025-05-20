// Mobile OS Task Manager.
// Fore ground apps get higher priority with background processes are throttled. Task schedulers balance performane and battery life
// Create class -> attributes --> name, priority (int)
// use Set priority
// in main function -> create thread, execute it


class Task extends Thread{
    private String name;
    private int priority;

    public Task(String name, int priority) {
        this.name = name;
        this.priority = priority;
        setPriority(priority);
    }

    public void run() {
        System.out.println(getName() + " is running with priority " + getPriority());
    }
}


public class Main {
    public static void main(String[] args) {
        Task foregroundApp = new Task("ForegroundApp", Thread.MAX_PRIORITY);
        Task backgroundApp = new Task("BackgroundApp", Thread.MIN_PRIORITY);
        backgroundApp.start();
        foregroundApp.start();
    }
}
