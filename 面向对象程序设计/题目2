/*每个品种的果树都有各自的结果期，果树的结果期是指果树从种植到结果经历的年数树龄相关。
某果农从2007年1月开始承包果园。目前，果园中有苹果树和桃树，可以根据下表中公式进行年产值预算。
为帮助果农估算每年年末果园总年产值，请按要求编写程序：

1. 编写描述苹果树、桃树，设计时必须考虑未来可能增种新的品种，可以添加你认为必要的类，不必考虑果树的死亡情况。

苹果树的预计年产值 (结果期=5年) 计算规则如下：

如果 树龄 < 结果期，年产值为 0。
如果 结果期 <= 树龄 <= 结果期+10，年产值为 1200 + (树龄 - 结果期) x 50。
如果 结果期+10 < 树龄 <= 结果期+15，年产值为 2000 - 树龄 x 60。
如果 树龄 > 结果期+15，年产值为 200。
桃树的预计年产值 (结果期=3年) 计算规则如下：

如果 树龄 < 结果期，年产值为 0。
如果 结果期 <= 树龄 <= 结果期+20，年产值为 1500 - (树龄 - 结果期) x 10。
(注：此公式在图中印刷较为模糊，根据上下文推断为 x 10)
如果 树龄 > 结果期+20，年产值为 400。
2. 作为一个示例，假设果园中只有一棵已生长6年的苹果树、一棵已经生长5年的桃树、
一棵已经生长2年的桃树。请利用上一问的结果，编写完整程序，分别输出果园今年的年总产值和明年的年总产值。*/

#include<iostream>
using namespace std;
//抽象基类
class tree{
    public:
    tree(int a):age(a){}
    virtual ~tree(){}
    virtual int final() = 0;
    tree& operator+=(const int& b){
        this->age += b;
        return *this;
    }
    protected:
    int age;
    int need;
};
//派生实现
class apple:public tree{
    public:
    apple(int a):tree(a){
        need = 5;
    }
    int final(){
        if(age > need + 15) return 200;
        else if(age > need + 10) return 2000 - age * 60;
        else if(age >= need) return 1200 +(age - need)* 50;
        else return 0;
    }
};
class tao:public tree{//桃树
    public:
    tao(int a):tree(a){
        need = 5;
    }
    int final(){
        if(age > need + 20) return 400;
        else if(age >= need) return 1500 -(age - need)* 10;
        else return 0;
    }
};
class yuan{//果园类
    public:
    yuan(){
        tr[0] = tr[1] = tr[2] = nullptr;
    }
    void result(int year){
        int sum = 0;
        for(int i = 0;i < 3;i++){
            *tr[i] += year;//模拟任意年份
            sum += tr[i]->final();
            *tr[i] += (year - year*2);//恢复默认
        }
        cout << sum << endl;
    }
    void add(tree* t,int index){//加树入果园
        tr[index] = t;
    }
    private:
    tree* tr[3];
};
int main(){
    tree* a1 = new apple(6);
    tree* a2 = new tao(5);
    tree* a3 = new tao(2);
    yuan y;
    y.add(a1,0);
    y.add(a2,1);
    y.add(a3,2);
    y.result(0);
    y.result(1);
    delete a1; // 释放动态分配的内存
    delete a2; 
    delete a3; 
    a1 = a2 = a3 = nullptr; // 避免悬空指针
    return 0;
}
