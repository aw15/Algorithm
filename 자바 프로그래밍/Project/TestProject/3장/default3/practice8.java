package default3;
import java.util.Scanner;

public class practice8 {
	
	
	public static void main(String[] Args)
	{
		var sc = new Scanner(System.in);
		
		System.out.println("정수 몇 개?");
		int count =  sc.nextInt();
		int[] arr = new int[count];
		
		for(int i = 0;i<count;i++)
		{
			int input = (int)(Math.random()*100)+1;
			System.out.println(input);
			arr[i] = input;
			for(int j=0;j<i;j++)
			{
				if(arr[j]==input)
				{
					i--;
					break;
				}
			}
		}
		
		for(int data:arr)
		{
			System.out.print(data+" ");
		}
		
	}
}
