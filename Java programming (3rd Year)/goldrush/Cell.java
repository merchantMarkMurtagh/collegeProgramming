
public class Cell {

	String type;
	int i;
	int j;
	int displaceI;
	int displaceJ;
	boolean displacementCell;
	boolean trap;
	boolean gold;
	
	public Cell(int dI, int dJ, boolean displacementCell,  boolean trap, boolean gold)
	{
		this.displaceI=dI;
		this.displaceJ=dJ;
		this.trap=trap;
		this.gold=gold;
		this.displacementCell=displacementCell;
		
	}
}
