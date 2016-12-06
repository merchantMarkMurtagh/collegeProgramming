import javax.swing.JOptionPane;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class riceBugSimulation {
	public static void main(String [] args)
	{
		BufferedReader br = null;
		try {

			br = new BufferedReader(new InputStreamReader(System.in));
			//System.out.print("Enter size paddy field: ");
			String input = br.readLine();
			String[] sArray = input.split(" ");
			int rows = Integer.parseInt(sArray[0]);
			int columns = Integer.parseInt(sArray[1]);
			//paddyField field = new paddyField(rows, columns);
			plant[][] theField = new plant[columns][rows];

			for(int i=0; i<theField.length; i++)
			{
				for(int j=0; j<theField.length;j++)
				{
					plant newPlant = new plant(false);
					theField[i][j]=newPlant;

				}
			} 


			//System.out.print("Enter simulation period: ");
			String time = br.readLine();
			int seconds = Integer.parseInt(time);

			//System.out.print("Enter the number of rice bugs: ");
			String bugs = br.readLine();
			int riceBugNumber = Integer.parseInt(bugs);
			RiceBug riceArray [] = new RiceBug[riceBugNumber];




			for(int i=0; i<riceBugNumber ; i++)
			{
				int bugRow = 0;
				int bugColumn = 0;
				boolean validInfo = false;
				//System.out.print("Enter bug " + i + " position, start time and direction : ");
				String bugsStuff = br.readLine();
				String[] bugInfoArray = bugsStuff.split(" ");
				bugRow = Integer.parseInt(bugInfoArray[0]);
				bugColumn = Integer.parseInt(bugInfoArray[1]);

				int timeT = Integer.parseInt(bugInfoArray[2]);
				String direction = bugInfoArray[3];
				RiceBug bug = new RiceBug(bugRow, bugColumn, timeT, direction, 0);
				riceArray[i]= bug;
				theField[bug.startColumn][bug.startRow].add(bug);



			}

			int i=0;
			while(i<seconds)
			{


				//System.out.println("" + i);
				//printField(theField);
				for(int a=0; a<riceBugNumber; a++) // move loop
				{
					if(riceArray[a].startTime<=i)
					{
						if((riceArray[a].dead==false) && riceArray[a].startTime<=i)
						{
							if(riceArray[a].startTime==i)
							{
								riceArray[a].tryEat(theField[riceArray[a].startColumn][riceArray[a].startRow]);
							}
							else if(riceArray[a].startTime!=i)
							{
								theField[riceArray[a].startColumn][riceArray[a].startRow].leave(riceArray[a]); // leave (delete from old plants array)
							}

							if(riceArray[a].startTime!=i) // move
							{
								riceArray[a].move(); 
								if(riceArray[a].startRow<0 || riceArray[a].startColumn<0 || riceArray[a].startRow>rows-1 || riceArray[a].startColumn>columns-1) //out of bounds
								{
									riceArray[a].dead=true;
								}

								if(riceArray[a].dead==false)
								{
									theField[riceArray[a].startColumn][riceArray[a].startRow].add(riceArray[a]); // (add to new plant array) 
									riceArray[a].tryEat(theField[riceArray[a].startColumn][riceArray[a].startRow]);
								}
							}
						}
					}
				}
				i++; // tick tock

			}

			int countPlant=0;
			int countBugs=0;
			for(int b=0; b<riceArray.length; b++)
			{
				if(riceArray[b].dead==false)
				{
					countBugs++;
				}
			}
			for(int b=0; b<theField.length; b++)
			{
				for(int c=0; c<theField.length; c++)
				{
					if(theField[c][b].infected==false)
					{
						countPlant++;
					}
				}
			}

			System.out.print("" + countPlant + " ");
			System.out.print("" + countBugs);

		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			if (br != null) {
				try {
					br.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		}
	}

	public static void printField(plant [][] theField)
	{
		for(int i=0; i<theField.length; i++)
		{
			for(int j=0; j<theField.length; j++)
			{
				System.out.print(" |" + theField[i][j].infected  + " | ");
			}
			System.out.println("");

		}
		System.out.println("");
		System.out.println("");

	}

}
