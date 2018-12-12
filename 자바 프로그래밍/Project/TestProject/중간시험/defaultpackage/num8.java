package defaultpackage;
class Car{
	private String color;
	private static int numberOfCars = 0;
	public Car(String color)
	{
		this.color = color;
		numberOfCars += 1;
	}
	public static int getNumberOfCars()
	{
		return numberOfCars;
	}
}

public class num8 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Car c1 = new Car("blue");
		Car c2 = new Car("white");
		int n = Car.getNumberOfCars();
		System.out.println("지금까지 생성된 자동차 수 = "+ n);
	}
}
