import java.util.Scanner;


public class Grade {//2��

	private int math, science, english;
	public Grade(int a, int b, int c)
	{
		math = a;
		science = b;
		english = c;
	}
	public float Average()
	{
		return (math+science+english)/3.0f;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		var sc = new Scanner(System.in);
		System.out.println("����, ����, ���� ������ 3���� ���� �Է�>>");
		int math = sc.nextInt();
		int science = sc.nextInt();
		int english = sc.nextInt();
		
		Grade grade = new Grade(math, science, english);
		System.out.println("����� "+grade.Average());
		
		sc.close();
	}
}
