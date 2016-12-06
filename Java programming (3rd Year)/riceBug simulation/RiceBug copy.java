
public class RiceBug {
	int number;
	int startRow;   
	int startColumn; //position
	int startTime;
	int strength;
	String direction;
	boolean dead;

	public RiceBug(int startR, int startC, int startT, String d, int st)
	{
		startRow = startR;
		startColumn = startC;
		startTime = startT;
		direction = d;
		strength=st;


	}

	public void move()
	{
		

		if(this.direction.equals("A"))
		{
			this.startColumn--;
			this.startRow--;

		}
		else if(this.direction.equals("B"))
		{
			this.startColumn--;
		}
		else if(this.direction.equals("C"))
		{
			this.startColumn--;
			this.startRow++;
		}
		else if(this.direction.equals("D"))
		{
			this.startRow--;
		}
		else if(this.direction.equals("E"))
		{
			this.startColumn++;
		}
		else if(this.direction.equals("F"))
		{
			this.startRow--;
			this.startColumn++;
		}
		else if(this.direction.equals("G"))
		{
			this.startColumn++;
		}
		else if(this.direction.equals("H"))
		{
			this.startColumn++;
			this.startRow++;
		}



	}

	public void tryEat(plant p)
	{

		int lowest = 0;
		for(int i=0; i<p.bugs.size() && p.bugs.get(i)!=null;i++)
		{
			if(this.strength<p.bugs.get(i).strength)
			{
				this.dead=true;
			}
			
		}
		if(this.dead==false)
		{
			eat(p);
		}


	}

	public void eat(plant p)
	{
		if(p.infected==false)
		{
			this.strength++;
			p.infected=true;
		}


	}





}
