
import java.util.Scanner;

public class practice12 {
	public static void main(String arg[])
	{
      var sc = new Scanner(System.in);
      while(true)
      {
    	  System.out.println("연산>>");
    	  float x = sc.nextFloat();
    	  String operation = sc.next();
    	  float y = sc.nextFloat();
    	  float result = 0;
    	  
    	  if(operation.equals("+"))
    		  result = x+y;
    	  if(operation.equals("*"))
    		  result = x*y;
    	  if(operation.equals("-"))
    		  result = x-y;
    	  if(operation.equals("/"))
    		  if(y==0)
    		  {
    			  System.out.println("0으로 나눌 수 없습니다.");
    			  break;
    		  }
    		  else
    			  result = x/y;
    	  
    	  System.out.printf("%f %s %f  결과는 %f\n",x,operation,y,result);
      }
	}
}
