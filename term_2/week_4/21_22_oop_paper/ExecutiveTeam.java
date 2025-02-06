package 21_22_paper;

public class ExecutiveTeam {
    private List<Manager> managers;

    public ExecutiveTeam() {
        this.managers = new ArrayList<>();
    }

    public void add(Manager manager) {
        this.managers.add(manager);
    }

    public void remove(String name) {
        for (Manager manager : this.managers) {
            if (manager.getName().equals(name)) {
                this.managers.remove(manager);
                return;
            }
        }
    }
}
