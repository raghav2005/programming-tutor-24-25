package animals;

public interface Animal {
    // Fields in interfaces are implicitly public, static, and final (constants)
    String KINGDOM = "Animalia";

    // Abstract methods
    void eat();

    void sleep();

    // Default method with an implementation
    default void showKingdom() {
        System.out.println("This animal belongs to the kingdom: " + KINGDOM);
    }
}
