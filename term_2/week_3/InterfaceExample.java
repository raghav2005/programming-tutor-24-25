import animals.Dog;
import animals.WildCat;
import animals.Animal;
import animals.Pet;

public class InterfaceExample {
    public static void main(String[] args) {
        // Create Dog objects
        Dog myDog1 = new Dog("Buddy");
        Dog myDog2 = new Dog("Charlie");

        // Create WildCat objects
        WildCat jungleCat1 = new WildCat("Leo");
        WildCat jungleCat2 = new WildCat("Simba");

        // Demonstrate interface fields
        System.out.println("Kingdom of all animals: " + Animal.KINGDOM);
        System.out.println("Type of pet animals: " + Pet.PET_TYPE);

        // Using default methods
        System.out.println("\nDog behaviors:");
        myDog1.eat();
        myDog1.sleep();
        myDog1.play();
        myDog1.showKingdom(); // Default method from Animal
        myDog1.showPetType(); // Default method from Pet

        System.out.println("\nWildCat behaviors:");
        jungleCat1.eat();
        jungleCat1.sleep();
        jungleCat1.roar();
        jungleCat1.showKingdom(); // Default method from Animal

        // Using class methods to get counts
        System.out.println("\nClass-level information:");
        System.out.println("Total Dogs created: " + Dog.getDogCount());
        System.out.println("Total WildCats created: " + WildCat.getWildCatCount());
    }
}
