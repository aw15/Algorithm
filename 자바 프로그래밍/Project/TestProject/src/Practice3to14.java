
import java.util.Scanner;

public class Practice3to14 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String course[] = {"Java", "C++", "HTML","��ǻ�ͱ���","�ȵ���̵�"};
		int score[] = {95,88,76,62,55};
		var sc = new Scanner(System.in);
		
		while(true)
		{
			System.out.println("�����̸�>>");
			var select = sc.next();
			if(select.equals("�׸�"))
			{
				break;
			}
			boolean isFind = false;
			for(int i=0;i<course.length;i++)
			{
				if(course[i].equals(select))
				{
					System.out.printf("%s�� ������ %d\n",course[i],score[i]);
					isFind = true;
					break;
				}
			}
			if(!isFind)
			{
				System.out.printf("���� �����Դϴ�.\n");
			}
			
			
		}
	}

}
