package default3;
import java.util.Scanner;

public class Practice14 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String course[] = {"Java", "C++", "HTML","��ǻ�ͱ���","�ȵ���̵�"};
		int score[] = {95,88,76,62,55};
		String select = "���";
		Scanner sc = new Scanner(System.in);
		do
		{
			System.out.println("�����̸�>>");
            select = sc.next();
            boolean isFind = false;
            for(int i=0;i<course.length;i++)
            {
            	if(course[i].equals(select))
            	{
            		isFind = true;
            		System.out.println(course[i]+"�� ������ "+ score[i]+"�� �Դϴ�.");
            		break;
            	}
            }
            if(!isFind&&!select.equals("�׸�"))
            {
            	System.out.println("���� �����Դϴ�.");
            }
		}while(!select.equals("�׸�"));
	}

}
