package default3;
import java.util.Scanner;

public class Practice4 {
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("�ҹ��� ���ĺ��� �Է�");
		String alphabet = sc.next();
		char ch = alphabet.charAt(0);
		
		
		for(int i=0;i<='e'-'a';i++)
		{
			for(char j = 'a';j<=ch-i;j++)
			{
				System.out.print(j);
			}
			System.out.println();
		}
	}
}