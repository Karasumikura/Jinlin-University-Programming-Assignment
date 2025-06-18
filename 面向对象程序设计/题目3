/*题目描述
某同学为某公司开发一个部门员工年度奖金计算程序。每个部门有多名雇员 (Employee)，雇员又分为经理 (Manager)、普通员工 (Stuff) 等，每个雇员有各自不同的月工资；各部门有年度总利润，部门人均奖金基数为该部门年度总利润的30%再除以部门人数；将来雇员的种类可能会增加，具体的奖金计算规则也可能有变化，但雇员的年度奖金肯定与部门人均奖金基数相关。目前，奖金计算规则为：

经理的年度奖金额 = 本人月工资 * 2 + 部门人均奖金基数 * 2；
普通员工的年度奖金额 = 本人月工资 + 部门人均奖金基数 * 0.8。
为了测试设计的合理性，在假定每个部门有且只有3人的情况下，该同学编写了下面一段代码。

已给代码
C++

class Department {
public:
    Department(long totalprofit) : profit(totalprofit) {
        emps[0] = emps[1] = emps[2] = 0;
    }

    void SetEmployee(Employee * aEmp, int index) {
        emps[index] = aEmp;
    }

    void ShowEveryAward() {
        for(int i=0; i<3; i++) {
            // 注意：下面这行代码在图片中被部分遮挡，根据上下文推断其内容
            cout << emps[i]->Award(profit * 0.3 / 3) << endl;
        }
    }

private:
    Employee* emps[3];
    long      profit;
};
问题与要求
请根据上面代码，增加必要的类，给出类的具体实现，以帮助该同学完成设计工作。

在如下假定下，写出测试用的 main 函数代码：

某部门共有三人：一个经理，月工资为8000元；两个普通员工，月工资分别为5000元、4000元。该部门的年度总利润为300000元。*/
#include<iostream>
using namespace std;
//基类
class Employee {
    public:
    Employee(int s):salary(s){}
    virtual ~Employee(){}
    virtual float Award(float base) = 0;
    protected:
    int salary;
};
//派生类
class Stuff:public Employee{//普通员工
    public:
    Stuff(int s):Employee(s){}
    float Award(float base){
        return salary + base * 0.8;
    }
};
class Manager:public Employee{//经理
    public:
    Manager(int s):Employee(s){}
    float Award(float base){
        return salary * 2 + base * 2;
    }
};
class Department {
public:
    Department(long totalprofit) : profit(totalprofit) {
        emps[0] = emps[1] = emps[2] = 0;//这里0的意思是初始化，nullptr会更好
    }

    void SetEmployee(Employee * aEmp, int index) {
        emps[index] = aEmp;
    }

    void ShowEveryAward() {
        for(int i=0; i<3; i++) {
            cout << emps[i]->Award(profit * 0.3 / 3) << endl;
        }
    }

private:
    Employee* emps[3];
    long      profit;
};

int main(){
    long total = 300000;
    int s0 = 8000;
    int s1 = 4000;
    int s2 = 5000;
    Department d(total);
    Employee* i0 = new Manager(s0);
    Employee* i1 = new Stuff(s1);
    Employee* i2 = new Stuff(s2);
    d.SetEmployee(i0,0);
    d.SetEmployee(i1,1);
    d.SetEmployee(i2,2);
    d.ShowEveryAward();
    delete i0; // 释放动态分配的内存
    delete i1; 
    delete i2; 
    i0 = i1 = i2 = nullptr; // 避免悬空指针
    return 0;
}
