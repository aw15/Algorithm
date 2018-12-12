
import java.util.Scanner;

public class Practice3to14 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String course[] = {"Java", "C++", "HTML","컴퓨터구조","안드로이드"};
		int score[] = {95,88,76,62,55};
		var sc = new Scanner(System.in);
		
		while(true)
		{
			System.out.println("과목이름>>");
			var select = sc.next();
			if(select.equals("그만"))
			{
				break;
			}
			boolean isFind = false;
			for(int i=0;i<course.length;i++)
			{
				if(course[i].equals(select))
				{
					System.out.printf("%s의 점수는 %d\n",course[i],score[i]);
					isFind = true;
					break;
				}
			}
			if(!isFind)
			{
				System.out.printf("없는 과목입니다.\n");
			}
			
			
		}
	}

}
