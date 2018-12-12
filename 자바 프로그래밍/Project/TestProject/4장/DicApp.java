import java.util.Scanner;


class Dictionary//10번 문제
{		
	private static String[] kor = {"사랑","아기","돈","미래","희망"};
	private static String[] eng = {"love","baby","money","future","hope"};
	public static String kor2Eng(String word)
	{
		String ret = "없음";
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
		System.out.println("한영 단어 검색 프로그램입니다.");
		String input,  ret;
		do
		{
			System.out.println("한글단어? ");
			input = sc.next();
			ret = dictionary.kor2Eng(input);
			if(ret.equals("없음")) {
				System.out.printf("그런 단어는 없습니다.\n");
				continue;
			}
		    System.out.printf("%s (는/은) %s\n",input ,ret);
		}while(!input.equals("그만"));
		
		sc.close();
	}
}
