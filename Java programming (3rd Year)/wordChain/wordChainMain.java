package wordChain;
import java.util.Scanner;
import java.util.ArrayList;
public class wordChainMain {


	static ArrayList<String> alreadyChecked = new ArrayList<String>();
	static ArrayList<String> wordAlist =  new ArrayList<String>();

	public static void main(String [] args)
	{

		Scanner s = new Scanner(System.in);
		int numberOfWords= s.nextInt();
		int i=0;

		while(i<numberOfWords)
		{
			String word = s.next();
			wordAlist.add(word);
			i++;
		}

		boolean SF = makeChain(wordAlist.get(0));

		if(SF==true)
		{
			System.out.println(" ");
			printArrayL(alreadyChecked);
			System.out.println(" ");
		}
		else if(SF==false)
		{
			System.out.println("Failure");
			System.out.println(" ");
		}
		
		
	}




	public static boolean canChain(String word1, String word2, int number)
	{
		boolean tf=false;
		//int l=word1.length();
		
		for(int i=3; i<word1.length() && i<word2.length();i++)
		{
			String w1 = word1.substring(word1.length()-i, word1.length());
			String w2  =word2.substring(0, i);
			
			if(word1.substring(word1.length()-i, word1.length()).equals(word2.substring(0, i)))
			{
				return true;
			}
		}

		return tf;
	}


	public static boolean makeChain(String word)
	{
		
		alreadyChecked.add(word);
		for(int i=0; i<wordAlist.size(); i++)
		{
			
			if(isInAList(wordAlist.get(i), alreadyChecked)==false)
			{
				if(canChain(word, wordAlist.get(i), 3))
				{
					makeChain(wordAlist.get(i));
				}

			}

		}

		if(alreadyChecked.size()==wordAlist.size())
		{
			return true;
		}
		else
		{
			alreadyChecked.remove(word);
			return false;
			
		}
	}

	public static boolean isInAList(String word, ArrayList<String> s)
	{
		boolean isIn=false;
		for(int i=0; i<s.size(); i++)
		{
			if(word == s.get(i))
			{
				isIn=true;
			}
		}
		return isIn;
	}
	
	public static void printArrayL(ArrayList<String> a)
	{
		for(int i=0; i<a.size(); i++)
		{
			System.out.println(a.get(i));
			
		}
		System.out.println(" ");
	}
}












