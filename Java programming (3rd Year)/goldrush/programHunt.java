import java.util.Scanner;

public class programHunt {

	public static void main(String [] args)
	{
		Scanner s = new Scanner(System.in);
		int rows= s.nextInt();
		int columns = s.nextInt();
		String ssss = " ";
		Cell [][] maze = new Cell[rows][columns]; 
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<columns;j++)
			{
				String sString =s.next();
				if(sString.equals("D")) // displacement cell
				{
					int dI =s.nextInt();
					int dJ= s.nextInt();
					Cell n = new Cell(dI, dJ, true, false, false);
					maze[i][j]=n;
					
					
				}
				else if(sString.equals("T"))
				{
					
					Cell n = new Cell(0, 0, false, true, false);
					maze[i][j]=n;
				} 
				else
				{
					Cell n = new Cell(0, 0, false, false, true);
					maze[i][j]=n;
				}
								
			}
		}
		
		int playerNumber=s.nextInt();
		Player [] players = new Player[playerNumber];
		for(int i=0; i<playerNumber; i++)
		{
			int id = s.nextInt();
			Player p = new Player(s.nextInt(), s.nextInt(), id ,false, false);
			players[i]=p;
		}
		
		boolean found=false;
		while(found==false)
		{
			for(int i=0; i<players.length; i++)
			{
				players[i].move(players[i].i, players[i].j, rows, columns, maze);
				if(maze[players[i].i][players[i].j].trap == true) /////Problem yo x
				{
					players[i].trapped=true;
				}
				if(maze[players[i].i][players[i].j].gold)
				{
					players[i].won=true;
					found=true;
				}
				
			}
		}
		
		for(int i=0; i<players.length; i++)
		{
			if(players[i].won==true)
			{
				System.out.println(players[i].id + "");
			}
		}
		
		
	
		
	}
}
