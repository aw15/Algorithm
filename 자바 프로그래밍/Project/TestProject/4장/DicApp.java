import java.util.Scanner;


class Dictionary//10�� ����
{		
	private static String[] kor = {"���","�Ʊ�","��","�̷�","���"};
	private static String[] eng = {"love","baby","money","future","hope"};
	public static String kor2Eng(String word)
	{
		String ret = "����";
		for(int i=0;i<kor.length;i++)
		{
			if(kor[i].equals(word))
				return eng[i];
		}
		return ret;
	}
}

public class DicApp {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		var dictionary = new Dictionary();
		System.out.println("�ѿ� �ܾ� �˻� ���α׷��Դϴ�.");
		String input,  ret;
		do
		{
			System.out.println("�ѱ۴ܾ�? ");
			input = sc.next();
			ret = dictionary.kor2Eng(input);
			if(ret.equals("����")) {
				System.out.printf("�׷� �ܾ�� �����ϴ�.\n");
				continue;
			}
		    System.out.printf("%s (��/��) %s\n",input ,ret);
		}while(!input.equals("�׸�"));
		
		sc.close();
	}
}
