import java.util.Scanner;

class Day//7������
{
	private String work;
	public void set(String work) {this.work = work;}
	public String get() {return work;}
	public void show()
	{
		if(work == null) System.out.println("�����ϴ�.");
		else System.out.println(work+"�Դϴ�.");
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
		System.out.println("����?");
		String work = scanner.next();
		schedule[--daySelect].set(work);
	}
	public void run()
	{
		int select = 0;
		System.out.println("�̹��� ������ ���� ���α׷�");	
		while(select!=3)
		{
			System.out.println("�Է�:1 ����:2 ������:3>>");
			select = scanner.nextInt();
			if(select == 3)
			{
				finish();
				break;
			}
			System.out.println("��¥(1~30)?>>");
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
		System.out.println("���α׷��� �����մϴ�.");
	}
	public void view()
	{
		System.out.print(daySelect+"���� �� ����");
		schedule[--daySelect].show();
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MonthSchedule monthSchedule = new MonthSchedule(30);
		monthSchedule.run();
	}

}
