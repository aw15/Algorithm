import java.util.Scanner;

class Phone//8������
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
		System.out.print("�ο��� ");
		int count = sc.nextInt();
		Phone phoneBook[] = new Phone[count];
		
		for(int i=0;i<phoneBook.length;i++)
		{
			System.out.print("�̸��� ��ȭ��ȣ(�̸��� ��ȣ�� �� ĭ���� �Է�)");
			String name = sc.next();
			String number = sc.next();
			
			 phoneBook[i] = new Phone();
			 
			phoneBook[i].setName(name);
			phoneBook[i].setNumber(number);
		}
		String findName = "";
		while(!findName.equals("�׸�"))
		{
			System.out.print("�̸� �Է� : ");
			findName = sc.next();
			boolean isFind = false;
			for(int i=0;i<phoneBook.length;i++)
			{
				if(phoneBook[i].getName().equals(findName))
				{
					isFind = true;
					System.out.println(findName+"�� ��ȣ�� "+phoneBook[i].getNumber());
				}
			}
			if(!isFind&&!findName.equals("�׸�"))
			{
				System.out.println(findName+"�� �����ϴ�.");
			}
		}
	}
}
