
import java.util.Scanner;
public class openChallenge1 {

	public static void main(String[] args) {
		var scanner = new Scanner(System.in);
		System.out.println("������������ ���ÿ�");
		
		System.out.print("ö��>>");
		var chulsu = scanner.next();
		System.out.print("����>>");
		var youngheu = scanner.next();
		
		if(chulsu.equals("����"))
		{
			if(youngheu.equals("����"))
			{
				System.out.print("�����ϴ�.");
			}
			else if(youngheu.equals("����"))
			{
				System.out.print("ö���� �̰���ϴ�.");
			}
			else
			{
				System.out.print("���� �̰���ϴ�.");
			}
		}
		if(chulsu.equals("����"))
		{
			if(youngheu.equals("����"))
			{
				System.out.print("�����ϴ�.");
			}
			else if(youngheu.equals("��"))
			{
				System.out.print("ö���� �̰���ϴ�.");
			}
			else
			{
				System.out.print("���� �̰���ϴ�.");
			}
		}
		if(chulsu.equals("��"))
		{
			if(youngheu.equals("��"))
			{
				System.out.print("�����ϴ�.");
			}
			else if(youngheu.equals("����"))
			{
				System.out.print("ö���� �̰���ϴ�.");
			}
			else
			{
				System.out.print("���� �̰���ϴ�.");
			}
		}
	}
}
