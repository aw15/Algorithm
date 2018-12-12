import java.util.Scanner;

class Seat
{
	private String name = "---";
	public String GetName() {return name;}
	public void SetName(String name) {this.name = name;}
}


public class Reservation {
	public Seat theater[];
	int sCount =0;
	int aCount =0;
	int bCount =0;
	public Scanner sc;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Reservation system;
		
		
		
	}
	public Reservation()
	{
		theater = new Seat[30];
		sc = new Scanner(System.in);
	}
	public void Run()
	{
		System.out.println("명품콘서트홀 예약 시스템입니다.");
		
		while(true)
		{
			System.out.println("예약:1, 조회:2, 취소:3, 끝내기:4");
			int select = sc.nextInt();
			if(select==1)
				Reserve();
			else if(select==2)
				Search();
			else if(select==3)
				Cancel();
			else if(select == 4)
				break;
		}

		return;
	}
	public void Reserve()
	{
	}
	public void Search()
	{
		
	}
	public void Cancel()
	{
		
	}
}
