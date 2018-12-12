
import java.util.Scanner;
public class openChallenge1 {

	public static void main(String[] args) {
		var scanner = new Scanner(System.in);
		System.out.println("가위바위보를 내시오");
		
		System.out.print("철수>>");
		var chulsu = scanner.next();
		System.out.print("영희>>");
		var youngheu = scanner.next();
		
		if(chulsu.equals("바위"))
		{
			if(youngheu.equals("바위"))
			{
				System.out.print("비겼습니다.");
			}
			else if(youngheu.equals("가위"))
			{
				System.out.print("철수가 이겼습니다.");
			}
			else
			{
				System.out.print("영희가 이겼습니다.");
			}
		}
		if(chulsu.equals("가위"))
		{
			if(youngheu.equals("가위"))
			{
				System.out.print("비겼습니다.");
			}
			else if(youngheu.equals("보"))
			{
				System.out.print("철수가 이겼습니다.");
			}
			else
			{
				System.out.print("영희가 이겼습니다.");
			}
		}
		if(chulsu.equals("보"))
		{
			if(youngheu.equals("보"))
			{
				System.out.print("비겼습니다.");
			}
			else if(youngheu.equals("바위"))
			{
				System.out.print("철수가 이겼습니다.");
			}
			else
			{
				System.out.print("영희가 이겼습니다.");
			}
		}
	}
}
