package default3;
import java.util.Scanner;

public class Practice4 {
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("소문자 알파벳을 입력");
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