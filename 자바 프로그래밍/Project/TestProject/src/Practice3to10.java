


public class Practice3to10 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[][] num = new int[4][4];
		for(int i=0;i<10;)
		{
			int index = (int)(Math.random()*4);
			int index2 = (int)(Math.random()*4);
			if(num[index][index2]==0)
			{
				num[index][index2] = (int)(Math.random()*10+1);
				i++;
			}
		}
		
		for(int i=0;i<num.length;i++)
		{
			for(int j=0;j<num[i].length;j++)
			{
				System.out.print(num[i][j]+" ");
			}
			System.out.println();
		}
	}

}
