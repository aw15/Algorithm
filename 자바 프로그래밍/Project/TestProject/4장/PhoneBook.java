import java.util.Scanner;

class Phone//8번문제
{
	private String name;
	private String number;
	public String getName() {return name;}
	public String getNumber() {return number;}
	public void setName(String name) {this.name = name;}
	public void setNumber(String number) {this.number = number;}
}
public class PhoneBook {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		var sc = new Scanner(System.in);
		System.out.print("인원수 ");
		int count = sc.nextInt();
		Phone phoneBook[] = new Phone[count];
		
		for(int i=0;i<phoneBook.length;i++)
		{
			System.out.print("이름과 전화번호(이름과 번호는 빈 칸없이 입력)");
			String name = sc.next();
			String number = sc.next();
			
			 phoneBook[i] = new Phone();
			 
			phoneBook[i].setName(name);
			phoneBook[i].setNumber(number);
		}
		String findName = "";
		while(!findName.equals("그만"))
		{
			System.out.print("이름 입력 : ");
			findName = sc.next();
			boolean isFind = false;
			for(int i=0;i<phoneBook.length;i++)
			{
				if(phoneBook[i].getName().equals(findName))
				{
					isFind = true;
					System.out.println(findName+"의 번호는 "+phoneBook[i].getNumber());
				}
			}
			if(!isFind&&!findName.equals("그만"))
			{
				System.out.println(findName+"이 없습니다.");
			}
		}
	}
}
