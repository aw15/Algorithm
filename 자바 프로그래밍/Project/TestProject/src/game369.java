
import java.util.Scanner;

public class game369 {
	public static void main(String[] args) { 
		int count =0;
		int num =0;
		System.out.print("1~99������ ������ �Է��ϼ���");
		Scanner scanner = new Scanner(System.in);
		
		num = scanner.nextInt();
		if((num/10)%3==0&&num!=0)
		{
			count++;
		}
		if((num%10)%3==0&&num!=0)
		{
			count++;
		}
		
		if(count==2)
		{
			System.out.print("�ڼ�¦¦");
		}
		if(count==1)
		{
			System.out.print("�ڼ�¦");
		}
		scanner.close();
	}
}
