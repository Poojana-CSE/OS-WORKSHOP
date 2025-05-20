class BankAccount {
    private int balance = 1000;

    public int getBalance() {
        return balance;
    }

    public void setBalance(int balance) {
        this.balance = balance;
    }

    public synchronized void withdraw(int amount) {
        if (amount > balance) {
            System.out.println("Insufficient balance!");
        } else {
            System.out.println("Withdrawn Successfully");
            balance -= amount;
            System.out.println("Remaining Balance: " + balance);
        }
    }
}

class ATM extends Thread {
    private String username;
    private long acct_no;
    private BankAccount account;
    private int amount;

    public ATM(String username, long acct_no, BankAccount account, int amount) {
        this.username = username;
        this.acct_no = acct_no;
        this.account = account;
        this.amount = amount;
    }

    public void run() {
        account.withdraw(this.amount);
    }
}

public class Main {
    public static void main(String[] args) {
        BankAccount acct = new BankAccount();
        ATM atm1 = new ATM("user1", 1001, acct, 500);
        ATM atm2 = new ATM("user2", 1002, acct, 700);
        ATM atm3 = new ATM("user3", 1003, acct, 1500);

        atm1.start();
        atm2.start();
        atm3.start();
    }
}
