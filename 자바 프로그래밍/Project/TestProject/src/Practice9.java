import java.util.Scanner;

public class Practice9 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

       System.out.println("���� �߽ɰ� ������ �Է� : ");
       var sc = new Scanner(System.in);
       
       float centerx = sc.nextFloat();
       float centery = sc.nextFloat();
       float radius = sc.nextFloat();
   	while(true)
   	{
       System.out.println("�� �Է�: ");
       float x = sc.nextFloat();
       float y = sc.nextFloat();
       
       if(Math.sqrt(Math.pow(x-centerx,2)+Math.pow(y-centery,2))<=radius)
       {
    	   System.out.printf("�� (%f, %f)�� �� �ȿ� �ִ�\n.",x,y);   
       }
       else
       {
    	   System.out.println("���ȿ� �����ϴ�.");   
       }
	}
	}

}
