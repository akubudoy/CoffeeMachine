import java.util.Scanner;

public class CoffeeMachine {
	Scanner in = new Scanner(System.in);
	
	public CoffeeMachine(){
		pCashBox = new CashBox();
		pMixer = new Mixer();
		pSelector = new Selector(pCashBox, pMixer);
	}
	
	public boolean doOneAction(){
		String action;
		action = in.next();
		if(action.equals("insert")){
			int value;
			value = in.nextInt();
			pCashBox.deposit(value);
		}
		else if(action.equals("select")){
			String choice;
			choice = in.next();
			pSelector.select(Selection.valueOf(choice.toUpperCase()));
		}
		else if(action.equals("quit"))
			return false;
		return true;
	}
	
	private CashBox pCashBox;
	private Mixer pMixer;
	private Selector pSelector;
	
	public static void main(String[] args){

			CoffeeMachine cm = new CoffeeMachine();
			while(cm.doOneAction())
				;

	}
}
