

public class paddyField {
	int rows;
	int columns;
	plant myPlant;
	
	public paddyField(int r, int c)
	{
		rows=r;
		columns=c;
		
	}
	
	public plant [][] makeField()
	{
		
		plant [][] plantField = new plant[rows][columns]; 
		for(int i=0; i<plantField[i].length; i++)
		{
			for(int j =0; j< plantField[j].length; j++)
			{
				
				plant newPlant = new plant(false);
				plantField[i][j]=newPlant;
			}
		}
		return plantField;
	} 
	
//	public void printField(plant [][] field)
//	{
//		//String theString = new String();
//		for(int i=0; i<field.length; i++)
//		{
//			for(int j=0; j <field.length ;j++)
//			{
//				System.out.print(" | ");
//				System.out.print(field[i][j].bugs[0]);
//				System.out.print(" | ");
//				System.out.println(" ");
//			}
//		}
//		
//	}

	
}
