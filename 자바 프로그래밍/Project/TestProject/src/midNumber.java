

public class midNumber {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a=5,b=6,c=1;
		int mid;
		if(a<=b)
		{
			if(b<=c)
			{
				mid =b;
			}
			else if(a<c)
			{
				mid =c;
			}
			else
			{
				mid=a;
			}
		}
		else
		{
			if(a<=c)
			{
				mid =a;
			}
			else if(b<c)
			{
				mid =c;
			}
			else
			{
				mid=b;
			}
		}
		System.out.println(mid);
	}

}
