package default3;
import java.util.Scanner;

public class OpenChallenge {
	public static int reverse(int num)
	{
		int answer =0;
		if(num == 0)
		{
			System.out.println("�߸��� �Է�");
			return -1;
		}
		while(num != 0)
		{
			answer += (num%10);
			num /= 10;
			answer *=10;

		}
		answer /=10;
		return answer;
	}
	public static boolean isPalindrome(int num)
	{
		if(reverse(num) == num)
			return true;
		return false;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		var sc = new Scanner(System.in);
		while(true)
		{
			System.out.println("�ڿ��� �Է�");
			if(isPalindrome(sc.nextInt()))
			{
				System.out.println("Palindrome�Դϴ�.");
			}
			else
				System.out.println("Palindrome�� �ƴմϴ�.");
		}
	}
}
