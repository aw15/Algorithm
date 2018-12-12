package default3;

public class Pratice10 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[][] arr = new int[4][4];
		for(int i=0;i<arr.length;i++)
		{
			for(int j =0;j<arr[i].length;j++)
			{
				arr[i][j] = 0;
			}
		}
		
		
		for(int i=0;i<10;)
		{
			int index = (int)(Math.random()*4);
			int index2 = (int)(Math.random()*4);
			
			if(arr[index][index2]==0)
			{
				arr[index][index2] = (int)(Math.random()*10)+1;
				i++;
			}
		}
		
		for(int i=0;i<arr.length;i++)
		{
			for(int j =0;j<arr[i].length;j++)
			{
				System.out.print(arr[i][j]+" ");
			}
			System.out.println();
		}
		
	}

}
