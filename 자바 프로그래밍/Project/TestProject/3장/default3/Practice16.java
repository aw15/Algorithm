package default3;
import java.util.Scanner;

public class Practice16 {
	public static void main(String[] args)
	{
		var scanner = new Scanner(System.in);
		System.out.println("��ǻ�Ϳ� ���������������� �մϴ�.");
		

		while(true)
		{
			System.out.print("���� ���� ��!>>");
			var chulsu = scanner.next();
			if(chulsu.equals("�׸�"))
			{
				System.out.println("������ �����մϴ�.");
				break;
			}
			
			String youngheu = "";
			int computer = (int)(Math.random()*3);
			switch(computer)
			{
			case 0:
				youngheu = "����";
				break;
			case 1:
				youngheu = "����";
				break;
			case 2:
				youngheu = "��";
				break;
			}
			
			
			if(chulsu.equals("����"))
			{
				if(youngheu.equals("����"))
				{
					System.out.printf("����� =  %s ��ǻ�� = %s �����ϴ�.\n",chulsu,youngheu);
				}
				else if(youngheu.equals("����"))
				{
					System.out.printf("����� =  %s ��ǻ�� = %s ����ڰ� �̰���ϴ�.\n",chulsu,youngheu);
				}
				else
				{
					System.out.printf("����� =  %s ��ǻ�� = %s ��ǻ�Ͱ� �̰���ϴ�.\n",chulsu,youngheu);
				}
			}
			if(chulsu.equals("����"))
			{
				if(youngheu.equals("����"))
				{
					System.out.printf("����� =  %s ��ǻ�� = %s �����ϴ�.\n",chulsu,youngheu);
				}
				else if(youngheu.equals("��"))
				{
					System.out.printf("����� =  %s ��ǻ�� = %s ����ڰ� �̰���ϴ�.\n",chulsu,youngheu);
				}
				else
				{
					System.out.printf("����� =  %s ��ǻ�� = %s ��ǻ�Ͱ� �̰���ϴ�.\n",chulsu,youngheu);
				}
			}
			if(chulsu.equals("��"))
			{
				if(youngheu.equals("��"))
				{
					System.out.printf("����� =  %s ��ǻ�� = %s �����ϴ�.\n",chulsu,youngheu);
				}
				else if(youngheu.equals("����"))
				{
					System.out.printf("����� =  %s ��ǻ�� = %s ����ڰ� �̰���ϴ�.\n",chulsu,youngheu);
				}
				else
				{
					System.out.printf("����� =  %s ��ǻ�� = %s ��ǻ�Ͱ� �̰���ϴ�.\n",chulsu,youngheu);
				}
			}
		}
	}
}
