package default3;
import java.util.Scanner;

public class Practice14 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String course[] = {"Java", "C++", "HTML","컴퓨터구조","안드로이드"};
		int score[] = {95,88,76,62,55};
		String select = "계속";
		Scanner sc = new Scanner(System.in);
		do
		{
			System.out.println("과목이름>>");
            select = sc.next();
            boolean isFind = false;
            for(int i=0;i<course.length;i++)
            {
            	if(course[i].equals(select))
            	{
            		isFind = true;
            		System.out.println(course[i]+"의 점수는 "+ score[i]+"점 입니다.");
            		break;
            	}
            }
            if(!isFind&&!select.equals("그만"))
            {
            	System.out.println("없는 과목입니다.");
            }
		}while(!select.equals("그만"));
	}

}
