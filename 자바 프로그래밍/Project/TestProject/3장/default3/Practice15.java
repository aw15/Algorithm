package default3;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Practice15 {
	public static void main(String[] args)
	{
		var sc = new Scanner(System.in);
		
		int n =0;
		int m =0;
		while(true)
		{
			System.out.println("���ϰ��� �ϴ� �� ���� �Է��Ͻÿ�.");
			try
			{
				n = sc.nextInt();
				m = sc.nextInt();
				System.out.print(n+" X "+m+" = "+n*m);
				break;
			}
			catch(InputMismatchException e)
			{
				sc.nextLine();
				continue;
			}
		}

		
	}
}
