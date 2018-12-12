import java.util.Scanner;

public class Practice3to16 {

	public static void main(String[] args)
	{
		var sc = new Scanner(System.in);
		String str[] = {"가위","바위","보"};
		while(true)
		{
			int n = (int)(Math.random()*3);
			var select = sc.next();
			if(select.equals("그만"))
			{
				System.out.println("게임을 종료합니다.");
				break;
			}
			switch(select)
			{
			case "바위":
				
			}
		}
		
	}
}
