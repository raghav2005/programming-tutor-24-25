import vehicles.*;

public class Main {

    public static void main(String[] args) {
        Car car = new Car("Toyota", "Corolla");

        car.move();
        car.drive();
        car.stop("it crashed");
        car.stop();
    }

}
