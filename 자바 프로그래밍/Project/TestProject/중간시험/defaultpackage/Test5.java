package defaultpackage;

import java.util.Scanner;

public class Test5 {
	
	public static void stat(int[] arr)
	{
		for(int i =0;i<5;i++)
		{
			for(int j =i+1;j<5;j++)
			{
				if(arr[i]<arr[j])
				{
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
		
		for(var data:arr)
		{
			System.out.print(data+" ");
		}
		System.out.print("    중간값 = "+arr[2]);
	}
	
	public static void main(String[] args) {
		var sc = new Scanner(System.in);
		System.out.println("5명 학생 점수 입력>>");
		int grade[] = new int[5];
		for(int i=0;i<5;i++)
		{
			grade[i] = sc.nextInt();
		}
		stat(grade);

	}
}

