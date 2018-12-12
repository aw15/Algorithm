import java.util.Scanner;

class Day//7번문제
{
	private String work;
	public void set(String work) {this.work = work;}
	public String get() {return work;}
	public void show()
	{
		if(work == null) System.out.println("없습니다.");
		else System.out.println(work+"입니다.");
	}
}

public class MonthSchedule {
	Day[] schedule;
	public Scanner scanner;
	int daySelect = 0;
	
	public MonthSchedule(int count)
	{
		schedule = new Day[count];
		scanner = new Scanner(System.in);
		for(int i=0;i<schedule.length;i++)
		{
			schedule[i] = new Day();
		}

	}
	public void input()
	{
		System.out.println("할일?");
		String work = scanner.next();
		schedule[--daySelect].set(work);
	}
	public void run()
	{
		int select = 0;
		System.out.println("이번달 스케줄 관리 프로그램");	
		while(select!=3)
		{
			System.out.println("입려:1 보기:2 끝내기:3>>");
			select = scanner.nextInt();
			if(select == 3)
			{
				finish();
				break;
			}
			System.out.println("날짜(1~30)?>>");
			daySelect = scanner.nextInt();
			
			switch(select)
			{
			case 1:
				input();
				break;
			case 2:
				view();
				break;
			}
		}
	}
	public void finish()
	{
		System.out.println("프로그램을 종료합니다.");
	}
	public void view()
	{
		System.out.print(daySelect+"일의 할 일은");
		schedule[--daySelect].show();
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MonthSchedule monthSchedule = new MonthSchedule(30);
		monthSchedule.run();
	}

}
