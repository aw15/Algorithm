import java.util.Scanner;
//11��
class Add{
	private int a;
	private int b;
	public void SetValue(int a,int b) {this.a = a; this.b = b;}
	public void calculate() {System.out.println(a+b);}
}
class Sub{
	private int a;
	private int b;
	public void SetValue(int a,int b) {this.a = a; this.b = b;}
	public void calculate() {System.out.println(a-b);}
}
class Mul{
	private int a;
	private int b;
	public void SetValue(int a,int b) {this.a = a; this.b = b;}
	public void calculate() {System.out.println(a*b);}
}
class Div{
	private int a;
	private int b;
	public void SetValue(int a,int b) {this.a = a; this.b = b;}
	public void calculate() {
		if(b!=0)
			System.out.println(a+b);
		else
			System.out.println("can't divide by zero");
		}
}


public class Calculator {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		var sc = new Scanner(System.in);
		System.out.println("�� ������ �����ڸ� �Է��Ͻÿ� :");
		int a = sc.nextInt();
		int b = sc.nextInt();
		String op = sc.next();
		
		switch(op)
		{
		case "+":
			Add add =new Add();
			add.SetValue(a, b);
			add.calculate();
			break;
		case "-":
			Sub sub =new Sub();
			sub.SetValue(a, b);
			sub.calculate();
			break;
		case "*":
			var mul =new Mul();
			mul.SetValue(a, b);
			mul.calculate();
			break;
		case "/":
			var div =new Div();
			div.SetValue(a, b);
			div.calculate();
			break;
		}
	}

}
