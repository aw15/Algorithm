import java.util.Scanner;

public class practice3 {
	public static void main(String arg[])
	{
	    var sc = new Scanner(System.in);
	    System.out.println("금액을 입력하세요>>>>");
	    int money = sc.nextInt();
	    System.out.printf("오만원권 %d매\n",money/50000);
	    money = money%50000;
	    System.out.printf("만원권 %d매\n",money/10000);
	    money = money%10000;
	    System.out.printf("천원권 %d매\n",money/1000);
	    money = money%1000;
	    System.out.printf("백원  %d개\n",money/100);
	    money = money%100;
	    System.out.printf("오십원  %d개\n",money/50);
	    money = money%50;
	    System.out.printf("십원  %d개\n",money/10);
	    money = money%10;
	    System.out.printf("일원  %d개\n",money);
	}
}
