
public class Player {
	int i;
	int j;
	boolean trapped;
	boolean won;
	int id;

	public Player(int startI, int startJ, int id, boolean trapp, boolean won)
	{
		this.i=startI;
		this.j=startJ;
		this.trapped=trapp;
		this.won=won;
		this.id=id;
	}
	
	public void move(int i, int j, int R, int C, Cell maze[][])
	{
		if(this.trapped==false)
		{
			if(this.checkWrap(this.i, this.j, R, C, maze))
			{
				
			}
			else
			{
				this.i=this.i+i;
				this.j=this.j+j;
			}
		}
		
		
	}
	
	
	public boolean checkWrap(int i, int j, int R, int C, Cell maze[][])
	{
		Player test = this;
		test.i+=maze[i][j].displaceI;
		test.j+=maze[i][j].displaceJ;
		boolean change = false;
		if(test.i<0) // too north
		{
			this.i=R+test.i;
			this.j=test.j;
			change=true;
		} 
		if(test.i>=R)
		{
			test.i=test.i-R;
			this.i=test.i;
			this.j=test.j;
			change = true;
		}
		if(test.j<0)
		{
			this.i=test.i;
			this.j=C+test.j;
			change = true;
		}
		if(test.j>=C)
		{
			test.j=test.j-C;
			this.i=test.i;
			this.j=test.j;
			change = true;
		}
		if(change=true)
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}

}
