#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

class Talkable{
    public:
    virtual void talk() = 0;
};

class NormalTalk : public Talkable{
    public:
    void talk() override{
        cout<<"robot can talk normally"<<endl;
    }
};

class NoTalk : public Talkable{
    public:
    void talk() override{
        cout<<"robot can not talk"<<endl;
    }
};

class Walkable{
    public:
    virtual void walk() = 0;
};

class NormalWalk : public Walkable{
    public:
    void walk() override{
        cout<<"robot can walk normally"<<endl;
    }
};

class NoWalk : public Walkable{
    public:
    void walk() override{
        cout<<"robot can not walk"<<endl;
    }
};

class Flyable{
    public:
    virtual void fly() = 0;
};

class NormalFly : public Flyable{
    public:
    void fly() override{
        cout<<"robot can fly normally"<<endl;
    }
};

class NoWFly : public Flyable{
    public:
    void fly() override{
        cout<<"robot can not fly"<<endl;
    }
};

class Robot{
    private:
    Talkable* t;
    Walkable* w;
    Flyable* f;
    
    public:
    
    Robot(Talkable* t, Walkable* w,Flyable* f){
        this->t =  t;
        this->w = w;
        this->f =f;
    }
    
    void talk(){
        t->talk();
    }
    void walk(){
        w->walk();
    }
    void fly(){
        f->fly();
    }
    
    virtual void projection() = 0;
    
};

class Drone : public Robot{
    
    public:
    Drone(Talkable* t, Walkable* w,Flyable* f) : Robot(t,w,f){};
    
    void projection() override{
        cout<<"Hello i am Drone"<<endl;
    }
    
};

class Worker : public Robot {
    public:
    Worker(Talkable* t, Walkable* w,Flyable* f) : Robot(t,w,f){};
    
    void projection() override{
        cout<<"Hello i am Worker"<<endl;
    }
};

int main() 
{
    
    Robot* rb1 =  new Drone(new NoTalk(),new NoWalk(),new NormalFly());
    rb1->projection();
    rb1->walk();
    rb1->talk();
    rb1->fly();

    
    
    Robot* rb2 =  new Worker(new NormalTalk,new NormalWalk(),new NoWFly());
    rb2->projection();
    rb2->walk();
    rb2->talk();
    rb2->fly();


   
	return 0;
}
