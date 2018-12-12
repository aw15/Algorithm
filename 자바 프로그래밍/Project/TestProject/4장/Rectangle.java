//���簢���� ǥ���ϴ� Ŭ������ �ۼ��϶�.
//�Ű������� ����  ���簢���� �� �ȿ� �ִ���
public class Rectangle {//�ǽ� 4��
	public int width, height, x, y;
	public float minx, miny, maxx,maxy;
	public Rectangle(int x, int y, int width, int height)
	{
		this.x=x;
		this.y=y;
		this.width = width;
		this.height = height;
		minx = x - width/2.0f;
		maxx = x + width/2.0f;
		miny = y - height/2.0f;
		maxy = y + height/2.0f;
	}
	public void Show() {
		System.out.printf("��ǥ = (%d, %d) ũ�Ⱑ %d x %d �� �簢��\n",x,y,width,height);
	}
	public int Square() {
		return width*height;
	}
    public static boolean inRect(float x, float y,float rectx1, float recty1, float rectx2,float recty2)
    {
    	if((x>=rectx1&&x<=rectx2)&&(y>=recty1&&y<=recty2))
    		return true;
    	else
    		return false;
    }
	public boolean contains(Rectangle compare){
		
		if(inRect(compare.minx,compare.miny,minx,miny,maxx,maxy))
		{
			return true;
		}
		if(inRect(compare.maxx,compare.maxy,minx,miny,maxx,maxy))
		{
			return true;
		}
		return false;
	}
	
	public static void main(String[] args)
	{
		Rectangle r1 = new Rectangle(2,2,8,7);
		Rectangle r2 = new Rectangle(5,5,6,6);
		Rectangle r3 = new Rectangle(1,1,10,10);
		
		r1.Show();
		System.out.println("r2�� ������ "+r2.Square());
		
		if(r3.contains(r1))
			System.out.println("r3�� r1�� �����մϴ�.");
		if(r3.contains(r2))
			System.out.println("r3�� r2�� �����մϴ�.");
	}
	
	
}
