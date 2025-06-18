/*一个游戏中有多种怪物(Monster)，怪物之间可能要发生战斗(fight)，每场战斗都是一个怪物与另一怪物之间的一对一战斗。
每个怪物都有自己的生命值(hitpoint)、攻击力值(damage)和防御力值(defense)，每种怪物都有各自特有的攻击(attack)方式，产生相应的攻击效果；
战斗时，两个怪物依次攻击对方，即怪物a首先攻击怪物b, 然后轮到怪物b攻击怪物a, 之后，怪物a再次攻击怪物b，…, 直到一方生命值为0。
1．请根据你对上述描述的理解，定义并实现怪物类Monster，成员的设计可以任意，但要求该类至少有一个不带virtual修饰的成员函数fight，
用来描述与另外一个怪物进行战斗的过程，该函数的实现可为Monster类的任意派生类所复用（派生类不需重新定义及实现）。不必考虑怪物的生命值减少至0后如何处理。
2．作为怪物的特例，猫和狗的攻击效果如下表所示。在Monster的基础上，以继承手段定义并实现这两个类。
猫进攻导致对方的生命值减少量：	
（猫的攻击力值 * 2 — 对方的防御力值） 
 若上式小于1，则取1	(狗的攻击力值 — 对方的防御力值 ＋5 )*2
若上式小于2，则取2
*/ 

#include<iostream>
using namespace std;
class Monster{
    protected:
    int hitpoint;
    int damage;
    int defense;
    public:
    Monster(int hi,int da,int de):hitpoint(hi),damage(da),defense(de){}
    virtual ~Monster(){}
    virtual void attack(Monster&B) = 0;
    int getHP() const{return hitpoint;};
    int getDA() const{return damage;};
    int getDF() const{return defense;};
    void reduceHP(int hit){
        this->hitpoint -= hit;
        if(hitpoint < 0) hitpoint = 0;
    }
    bool fight(Monster& B){//二分情况用bool 另外这里修改B，绝对不能加const
        while(true){//无限循环直到return
            this->attack(B);
            if(B.getHP() == 0) return true;
            B.attack(*this);
            if(hitpoint == 0) return false;
        }
    }
};
class cat:public Monster{
    public:
    cat(int hi,int da,int de):Monster(hi,da,de){}
    void attack(Monster& B){
        int hit = 2*damage - B.getDF();
        if(hit < 1) hit = 1;
        B.reduceHP(hit);
    }
};
class dog:public Monster{
    public:
    dog(int hi,int da,int de):Monster(hi,da,de){}
    void attack(Monster& B){
        int hit = damage - 2*(B.getDF() + 5);
        if(hit < 2) hit = 2;
        B.reduceHP(hit);
    }
};
int main()
{
    dog d(100,10,7);
    cat c(120,8,9);
    if(d.fight(c))
        cout<<"Win"<<endl;
    else 
        cout<<"Lost"<<endl;
}
