package defaultpackage;

import java.util.Scanner;

class Phone
{
	private String name;
	private String number;
	public String getName() {return name;}
	public String getNumber() {return number;}
	public void setName(String name) {this.name = name;}
	public void setNumber(String number) {this.number = number;}
}
public class PhoneBook {

	Scanner sc;
	Phone phoneBook[] ;
	public PhoneBook()
	{
		sc = new Scanner(System.in);
	}
	public void search(String name)
	{
		boolean isFind = false;
			for(int i=0;i<phoneBook.length;i++)
			{
				if(phoneBook[i].getName().equals(name))
				{
					isFind = true;
					System.out.println(name+"의 번호는 "+phoneBook[i].getNumber());
				}
			}
			if(!isFind)
				System.out.printf("%s 이/가  없습니다.\n",name);
	}
	public void Read()
	{
		System.out.print("인원수 ");
		int count = sc.nextInt();
		phoneBook = new Phone[count];
		
		for(int i=0;i<phoneBook.length;i++)
		{
			System.out.print("이름과 전화번호(이름과 번호는 빈 칸없이 입력)");
			String name = sc.next();
			String number = sc.next();
			
			 phoneBook[i] = new Phone();
			 
			phoneBook[i].setName(name);
			phoneBook[i].setNumber(number);
		}
		System.out.println("저장되없습니다.");
	}
	public void run()
	{
		Read();
		String findName = "";
		while(!findName.equals("그만"))
		{
			System.out.print("이름 입력 : ");
			findName = sc.next();
			if(findName.equals("그만"))
			{
				break;
			}
			search(findName);
		}
		sc.close();
		return;
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		PhoneBook book = new PhoneBook();
		book.run();
	}
}