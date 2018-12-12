package defaultpackage;

public class Test2 {
	public static void main(String[] args)
	{
		for(int i=1;i<20;i++)
		{
			if(i%2==0)
				continue;
			else
				System.out.println(i);
			if(i == 19)
				break;
		}
	}
}
