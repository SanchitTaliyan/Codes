// OOP

#include<iostream>

using namespace std;

// abstract class

class AbstractEmployee {
  virtual void askForPromotion() = 0;    //pure virtual function or abstract function this is obliglatory function
};

// everyting inside a class is private by default.
class Employee:AbstractEmployee {
  private:     // this is by default in class
    string company;
    int age;

  protected:   // can be accessed by derived classes.
    string name;

  public:
    void setName(string Name) {   //setter
        name = Name;
    }

    string getName() {            //getter
        return name;
    }

    void setCompany(string Company) {
        company = Company;
    }

    string getCompany() {
        return company;
    }

    void setAge(int Age) {
        if (Age >= 18) {
            age = Age;
        }
    }

    int getAge() {
        return age;
    }

    void introduceYourself() {
        cout << "Name - "<< name << endl;
        cout << "company - "<< company << endl;
        cout << "age - "<< age << endl;
    }

    Employee(string Name, string Company, int Age) { // we need to provide constructor of its sub class also.
        name = Name;
        company = Company;
        age = Age;
    }

    void askForPromotion() {
      if (age > 30)
       cout << name << " got promoted!" << endl;
      else
        cout << name << " sorry NO promotion for you!" << endl;
    }

    virtual void work(){
      cout << name << " is checking email, task backlog, performing tasks..." << endl;
    }

};

class Developer:public Employee {
  public:
    string favProgrammingLang;

    Developer(string Name, string Company, int Age, string FavProgrammingLang):Employee(Name, Company, Age) {
      favProgrammingLang = FavProgrammingLang;
    }
    
    void fixBug() {
      cout << name << " fixed bug using " << favProgrammingLang << endl;
    }

    //polymorphism
    void work() {
      cout << name << " is writing " << favProgrammingLang << " code." << endl;
    }
};

class Teacher:public Employee {
  public:
    string subject;
    void prepareLesson() {
      cout << name << " is preparing " << subject << " lesson." << endl;
    }

    Teacher(string Name, string Company, int Age, string Subject):Employee(Name, Company, Age) {
      subject = Subject;
    }

    //polymorphism
    void work() {
      cout << name << " is taking class every morning from Mon to Sat." << endl;
    }
};

int main()
{
  Employee emp1 = Employee("Ram", "Google", 27);      //object of class employee
  /*emp1.name = "Ram";
  emp1.company = "Google";
  emp1.age = 27;*/

  emp1.introduceYourself();

  Employee emp2 = Employee("Shyam", "Microsoft", 31);
  /*emp2.name = "Shyam";
  emp2.company = "Microsoft";
  emp2.age = 28;*/
  emp2.introduceYourself();

  emp1.setAge(15);
  cout << emp1.getName() << " is " << emp1.getAge() << " years old." << endl;
  emp1.askForPromotion();
  emp2.askForPromotion();

  Developer d1 = Developer("Ghanshyam", "Pwer", 27, "C++");

  d1.fixBug();
  d1.askForPromotion();

  Teacher t = Teacher("Geeta", "JVC", 52, "Hindi");
  //t.prepareLesson();
  //t.askForPromotion();

  //d1.work();
  //t.work();

  Employee *e1 = &d1;   //parent holding reference of child class.
  Employee *e2 = &t;

  e1->work();
  e2->work();
}