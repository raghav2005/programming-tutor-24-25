package 21_22_paper;

public class Company {
    
    private String name;
    private List<Employee> employees;
    private ExecutiveTeam executiveTeam;

    public Company(String name) {
        this.name = name;
        this.employees = new ArrayList<>();
        this.executiveTeam = new ExecutiveTeam();
    }

    public void addWorker(String name, String department, int pay) {
        this.employees.add(new Worker(name, department, pay));
    }

    public void addManager(String name, String department, int pay, int bonus) {
        this.employees.add(new Manager(name, department, pay, bonus));
    }

    public void addToExecutiveTeam(Manager manager) {
        this.executiveTeam.add(manager);
    }

    public int getTotalPayPerMonth() {
        int total = 0;

        for (Employee employee : this.employees) {
            total += employee.getMonthlyPay();
        }

        return total;
    }
}
