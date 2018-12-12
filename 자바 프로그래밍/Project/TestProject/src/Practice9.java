import java.util.Scanner;

public class Practice9 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

       System.out.println("원의 중심과 반지름 입력 : ");
       var sc = new Scanner(System.in);
       
       float centerx = sc.nextFloat();
       float centery = sc.nextFloat();
       float radius = sc.nextFloat();
   	while(true)
   	{
       System.out.println("점 입력: ");
       float x = sc.nextFloat();
       float y = sc.nextFloat();
       
       if(Math.sqrt(Math.pow(x-centerx,2)+Math.pow(y-centery,2))<=radius)
       {
    	   System.out.printf("점 (%f, %f)는 원 안에 있다\n.",x,y);   
       }
       else
       {
    	   System.out.println("원안에 없습니다.");   
       }
	}
	}

}
