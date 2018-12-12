import java.util.Scanner;

class Circle
{
	private double x,y;
	private int radius;
	public Circle(double x, double y, int radius)
	{
		this.x = x;
		this.y = y;
		this.radius = radius;
	}
	public void Show()
	{
		System.out.printf("(%f,%f)%d\n",x,y,radius);
	}
}

public class CircleManager {//5¹ø ¹®Á¦
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		Circle c[] = new Circle[3];
		
		double x,y;
		int radius;
		for(int i=0;i<c.length;i++)
		{
			System.out.println("x, y, radius>>");
			x = sc.nextDouble();
			y = sc.nextDouble();
			radius = sc.nextInt();
			c[i] = new Circle(x,y,radius);
		}
		for(int i=0;i<c.length;i++)
		{
			c[i].Show();
		}
		sc.close(); 
	}

}
