
class BankAccount{
    private int balance = 1000;

    public int getBalance(){
        return balance;
    }

    public void setBalance(int balance){
        this.balance = balanace;
    }
    
    public void withdraw(int amount){
        if(amount>balance){
            System.out.println("Insufficient balance!");
        } else{
            System.out.println("Withdrawn Successfully");
            balance -= amount;
            System.out.println("Remaining Balance: " + balance);
        }
    }
}

class ATM extends Thread{
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

    public void run(){
        account.withdraw(this.amount);
    }

}

public class Main{
    public static void main(String[] args){

    }
}