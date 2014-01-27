public enum Selection {
	BLACK("black",35), WHITE("white",35), SWEET("sweet",35), BOTH("both",35), BOUILLION("bouillion",25);
	String text;
	int price;
	
	Selection(String pText, int pPrice){
		text = pText;
		price = pPrice;
	}
	
	int priceOf(){
		return price;
	}
	
}
