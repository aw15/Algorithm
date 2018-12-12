package default3;
import java.util.Scanner;

public class Practice16 {
	public static void main(String[] args)
	{
		var scanner = new Scanner(System.in);
		System.out.println("컴퓨터와 가위바위보게임을 합니다.");
		

		while(true)
		{
			System.out.print("가위 바위 보!>>");
			var chulsu = scanner.next();
			if(chulsu.equals("그만"))
			{
				System.out.println("게임을 종료합니다.");
				break;
			}
			
			String youngheu = "";
			int computer = (int)(Math.random()*3);
			switch(computer)
			{
			case 0:
				youngheu = "바위";
				break;
			case 1:
				youngheu = "가위";
				break;
			case 2:
				youngheu = "보";
				break;
			}
			
			
			if(chulsu.equals("바위"))
			{
				if(youngheu.equals("바위"))
				{
					System.out.printf("사용자 =  %s 컴퓨터 = %s 비겼습니다.\n",chulsu,youngheu);
				}
				else if(youngheu.equals("가위"))
				{
					System.out.printf("사용자 =  %s 컴퓨터 = %s 사용자가 이겼습니다.\n",chulsu,youngheu);
				}
				else
				{
					System.out.printf("사용자 =  %s 컴퓨터 = %s 컴퓨터가 이겼습니다.\n",chulsu,youngheu);
				}
			}
			if(chulsu.equals("가위"))
			{
				if(youngheu.equals("가위"))
				{
					System.out.printf("사용자 =  %s 컴퓨터 = %s 비겼습니다.\n",chulsu,youngheu);
				}
				else if(youngheu.equals("보"))
				{
					System.out.printf("사용자 =  %s 컴퓨터 = %s 사용자가 이겼습니다.\n",chulsu,youngheu);
				}
				else
				{
					System.out.printf("사용자 =  %s 컴퓨터 = %s 컴퓨터가 이겼습니다.\n",chulsu,youngheu);
				}
			}
			if(chulsu.equals("보"))
			{
				if(youngheu.equals("보"))
				{
					System.out.printf("사용자 =  %s 컴퓨터 = %s 비겼습니다.\n",chulsu,youngheu);
				}
				else if(youngheu.equals("바위"))
				{
					System.out.printf("사용자 =  %s 컴퓨터 = %s 사용자가 이겼습니다.\n",chulsu,youngheu);
				}
				else
				{
					System.out.printf("사용자 =  %s 컴퓨터 = %s 컴퓨터가 이겼습니다.\n",chulsu,youngheu);
				}
			}
		}
	}
}
