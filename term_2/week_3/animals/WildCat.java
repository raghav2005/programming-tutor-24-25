package animals;

public class WildCat implements Animal {
    private String name; // Instance attribute
    private static int wildCatCount = 0; // Class attribute

    // Constructor
    public WildCat(String name) {
        this.name = name;
        wildCatCount++;
    }

    // Implement methods from Animal interface
    @Override
    public void eat() {
        System.out.println(name + " is hunting and eating.");
    }

    @Override
    public void sleep() {
        System.out.println(name + " is sleeping in the jungle.");
    }

    // Additional method specific to WildCat
    public void roar() {
        System.out.println(name + " is roaring!");
    }

    // Class method to get the total number of wild cats
    public static int getWildCatCount() {
        return wildCatCount;
    }
}
