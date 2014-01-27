
public class CashBox {
	public CashBox(){
		credit = 0;
	}
	
	public void deposit(int amount){
		credit += amount;
		System.out.printf("\tCashBox: Depositing %d cents.",amount);
		System.out.printf("\tYou now have %d cents credit.\n",credit);
		System.out.println("");
	}
	
	public void returnCoins(){
		System.out.printf("\tCashBox: Returning %d cents\n",credit);
		System.out.println("");
		credit = 0;
	}
	
	public boolean haveYou(int amount){
		return credit >= amount;
	}
	
	public void deduct(int amount){
		credit -= amount;
		returnCoins();
	}
	
	private int credit;
}
