
import java.util.ArrayList;

public class plant {
	boolean infected;
	ArrayList<RiceBug> bugs = new ArrayList<RiceBug>();
	
	public plant (boolean i)
	{
		infected=i;
	}
	
	public void add(RiceBug bug)
	{
		bugs.add(bug);
	}
	
	public void leave(RiceBug bug)
	{
		bugs.remove(bug);
	}

}
