import java.util.Scanner;

public class practice11 {
	public static void main(String arg[])
	{
      var sc = new Scanner(System.in);
      while(true)
      {
    	  System.out.println("���� �Է��ϼ���(1~12): ");
    	  int month = sc.nextInt();
    	  
    	  if(month<1||month>12)
    	  {
    		  System.out.println("�߸� �Է�!");
    	  }
    	  else
    	  {
    		  if(month>=3&&month<=5)
    			  System.out.println("��!");
    		  if(month>=6&&month<=8)
    			  System.out.println("����!");
    		  if(month>=9&&month<=11)
    			  System.out.println("����!");
    		  if((month>=1&&month<=2)||month==12)
    			  System.out.println("�ܿ�!");
    	  }
      }
	}
}
