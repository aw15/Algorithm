package default3;
import java.util.Scanner;


public class Practice3 {
	public static void main(String[] args)
	{
		System.out.println("������ �Է��ϼ��� : ");
		Scanner sc = new Scanner(System.in);
		
		int num = sc.nextInt();
		
		for(int i=num;i>0;i--)
		{
			for(int j=0;j<i;j++)
			{
				System.out.print("*");
			}
			System.out.print("\n");
		}
	}
}
