package animals;

public interface Pet {
    // Fields in interfaces
    String PET_TYPE = "Domesticated";

    // Abstract methods
    void play();

    // Default method with an implementation
    default void showPetType() {
        System.out.println("This is a " + PET_TYPE + " animal.");
    }
}
