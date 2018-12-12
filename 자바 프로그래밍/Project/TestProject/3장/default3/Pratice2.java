package default3;

public class Pratice2 {
	public static void main(String[] args)
	{
		int n[][] = {{1},{1,2,3},{1},{1,2,3,4},{1,2}};
		
		for(int i=0;i<n.length;i++){
			System.out.print(i+"За їшјТ : ");
			for(int j=0;j<n[i].length;j++)
				System.out.print(n[i][j]+" ");
			System.out.println();
		}
	}
}
