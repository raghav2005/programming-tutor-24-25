package vehicles;

// abstract class - cannot create an object of this type
public abstract class Vehicle {

    // attributes
    protected String brand; // protected - accessible within own class and subclasses
    private int numberOfWheels; // private - only accessible within own class

    // constructor
    public Vehicle(String brand, int numberOfWheels) {
        this.brand = brand;
        this.numberOfWheels = numberOfWheels;
    }

    // overloaded constructor - matched by number and type of arguments
    public Vehicle(String brand) {
        this.brand = brand;
        this.numberOfWheels = numberOfWheels;
    }

    // setter
    public void setBrand(String brand) {
        this.brand = brand;
    }

    // getter
    public String getBrand() {
        return brand;
    }

    // abstract method - must be implemented by subclasses
    public abstract void move();

    public void stop() {
        System.out.println("The vehicle has stopped.");
    }

}