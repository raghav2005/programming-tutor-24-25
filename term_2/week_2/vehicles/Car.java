package vehicles;

// extends = inherits
public class Car extends Vehicle {

    private String model;

    public Car(String brand, String model) {
        super(brand); // how to call super class' constructor
        this.model = model;
    }

    public void setBrandCopy(String brand) {
        this.brand = brand; // works cuz brand is protected in Vehicle instead of private
    }

    @Override
    public void move() {
        System.out.println(brand + " " + model + " is starting!");
    }

    public void drive() {
        System.out.println("The car is driving.");
    }

    public void stop(String s) {
        super.stop();
        System.out.println("The vehicle has stopped because " + s + ".");
    }
}