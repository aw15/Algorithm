import java.util.Scanner;

public class practice4 {
	public static void main(String arg[])
	{
	    var sc = new Scanner(System.in);
	    
	    System.out.println("���� 3�� �Է�>>>");
	    int a = sc.nextInt();
	    int b = sc.nextInt();
	    int c = sc.nextInt();
	    int mid =0;
	    
	    if(a>b&&a>c)
	    {
	    	if(b<c)
	    	{
	    		mid = c;
	    	}
	    	else
	    	{
	    		mid = b;
	    	}
	    }
	    else if(b>a&&b>c)
	    {
	    	if(a<c)
	    	{
	    		mid = c;
	    	}
	    	else
	    	{
	    		mid = a;
	    	}
	    }
	    else if(c>b&&c>a)
	    {
	    	if(b<a)
	    	{
	    		mid = a;
	    	}
	    	else
	    	{
	    		mid = b;
	    	}
	    }
	    
	    
	    
	    System.out.println("�߰� ���� "+mid);
	    
	    
	}
}
