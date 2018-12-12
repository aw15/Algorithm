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
					System.out.println(name+"�� ��ȣ�� "+phoneBook[i].getNumber());
				}
			}
			if(!isFind)
				System.out.printf("%s ��/��  �����ϴ�.\n",name);
	}
	public void Read()
	{
		System.out.print("�ο��� ");
		int count = sc.nextInt();
		phoneBook = new Phone[count];
		
		for(int i=0;i<phoneBook.length;i++)
		{
			System.out.print("�̸��� ��ȭ��ȣ(�̸��� ��ȣ�� �� ĭ���� �Է�)");
			String name = sc.next();
			String number = sc.next();
			
			 phoneBook[i] = new Phone();
			 
			phoneBook[i].setName(name);
			phoneBook[i].setNumber(number);
		}
		System.out.println("����Ǿ����ϴ�.");
	}
	public void run()
	{
		Read();
		String findName = "";
		while(!findName.equals("�׸�"))
		{
			System.out.print("�̸� �Է� : ");
			findName = sc.next();
			if(findName.equals("�׸�"))
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