package logic;

public class User {
private String name;
private String surname;
private String salary;

public User(String name, String surname, String salary) {
	this.name=name;
	this.surname=surname;
	this.salary=salary;	
}
public void setName(String name) {
	this.name=name;
}
public String getName() {
	return name;
	}
public void setSurname(String surname) {
	this.surname=surname;
}
public String getSurname() {
	return surname;
	}
public void setSalary(String salary) {
	this.salary=salary;
}
public String getSalary() {
	return salary;
	}
}
