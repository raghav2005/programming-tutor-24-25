package 21_22_paper;

public abstract class Employee {
    
    private String name;
    private String department;
    private int monthlyPay;

    public Employee(String name, String department, int pay) {
        this.name = name;
        this.department = department;
        this.monthlyPay = pay;
    }

    public String getName() {
        return this.name;
    }

    public String getDepartment() {
        return this.department;
    }

    public int getMonthlyPay() {
        return this.monthlyPay;
    }

}
