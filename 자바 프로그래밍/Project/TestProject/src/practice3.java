import java.util.Scanner;

public class practice3 {
	public static void main(String arg[])
	{
	    var sc = new Scanner(System.in);
	    System.out.println("�ݾ��� �Է��ϼ���>>>>");
	    int money = sc.nextInt();
	    System.out.printf("�������� %d��\n",money/50000);
	    money = money%50000;
	    System.out.printf("������ %d��\n",money/10000);
	    money = money%10000;
	    System.out.printf("õ���� %d��\n",money/1000);
	    money = money%1000;
	    System.out.printf("���  %d��\n",money/100);
	    money = money%100;
	    System.out.printf("���ʿ�  %d��\n",money/50);
	    money = money%50;
	    System.out.printf("�ʿ�  %d��\n",money/10);
	    money = money%10;
	    System.out.printf("�Ͽ�  %d��\n",money);
	}
}
