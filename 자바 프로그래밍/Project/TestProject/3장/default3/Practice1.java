package default3;


public class Practice1 {
  
	public static void main(String[] args)
	{
		int sum =0;
		int i=0;
		for(i =0;i<100;i+=2)
		{
			sum+=i;
		}
		System.out.println("for문으로 "+sum);
		
		
		sum =0;
		i=0;
		do
		{
			sum += i;
			i += 2;
		}while(i<100);
		System.out.println("do-while문으로 "+sum);
		
	}
}
