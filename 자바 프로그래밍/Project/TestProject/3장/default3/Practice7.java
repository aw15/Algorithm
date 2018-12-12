package default3;
import java.util.Scanner;



public class Practice7 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int score[] = new int[10];
		int sum =0;
		System.out.print("·£´ýÇÑ Á¤¼öµé : ");
		for(int i=0;i<score.length;i++)
		{
			score[i] = (int)(Math.random()*10+1);
			sum +=score[i];
			System.out.print(score[i]+" ");
		}
		System.out.println("\n Æò±ÕÀº : "+sum/10.0);
	}
}