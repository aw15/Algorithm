//직사각형을 표현하는 클래스를 작성하라.
//매개변수로 받은  직사각형이 내 안에 있는지
public class Rectangle {//실습 4번
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
		System.out.printf("좌표 = (%d, %d) 크기가 %d x %d 인 사각형\n",x,y,width,height);
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
		System.out.println("r2의 면적은 "+r2.Square());
		
		if(r3.contains(r1))
			System.out.println("r3는 r1을 포함합니다.");
		if(r3.contains(r2))
			System.out.println("r3는 r2을 포함합니다.");
	}
	
	
}
