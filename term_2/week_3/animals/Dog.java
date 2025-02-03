package animals;

public class Dog implements Animal, Pet {
    private String name; // Instance attribute
    private static int dogCount = 0; // Class attribute

    // Constructor
    public Dog(String name) {
        this.name = name;
        dogCount++;
    }

    // Implement methods from Animal interface
    @Override
    public void eat() {
        System.out.println(name + " is eating dog food.");
    }

    @Override
    public void sleep() {
        System.out.println(name + " is sleeping in its kennel.");
    }

    // Implement method from Pet interface
    @Override
    public void play() {
        System.out.println(name + " is playing fetch.");
    }

    // Class method to get the total number of dogs
    public static int getDogCount() {
        return dogCount;
    }
}
