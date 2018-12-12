package defaultpackage;

class Sample{
	private int a;
	public void SetA(final int a) {this.a = a;}
	public int GetA() {return this.a;}
}

public class Test4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Sample aClass = new Sample();
		aClass.SetA(10);
		System.out.println(aClass.GetA());
	}
}