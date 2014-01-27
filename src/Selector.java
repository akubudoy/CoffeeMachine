public class Selector {
	public Selector(CashBox pC, Mixer pM){
		pCashBox = pC;
		pMixer = pM;
	}
	
	public void select(final Selection s){
		int amount = s.priceOf();
		if(pCashBox.haveYou(amount)){
			pMixer.make(s);
			pCashBox.deduct(amount);
		}
		else{
			System.out.println("\tSelector: Insufficient funds");
			System.out.println("");
		}
	}
	
	private CashBox pCashBox;
	private Mixer pMixer;
}
