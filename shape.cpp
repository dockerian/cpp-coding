#include<iostream>
using namespace std;

class point{
	public: 
		point(int x=0,int y=0){X=x;Y=y;}
	
		setx(int x){X=x;}
        sety(int y){Y=y;}

	private:
        int X,Y;
};

class shape{
	public:
		shape(int x=0,int y=0):center(point(x,y)){}

		virtual int draw()=0;
		void set_center(int x,int y){
			center.setx(x);
            center.sety(y);}
	
	private:
		point center;
};

class circle :public shape{
	public:
		circle(int x, int y, int rad):shape(x,y){radus=rad;}
		
		virtual int draw(){
			cout<<"draw a circle"<<endl;
			return 1;}
                
	private:
		int radus;
};

class triangle :public shape{
	public:
		triangle(int x,int y):shape(x,y){};

		virtual int draw(){
			cout<<"draw a triangle"<<endl;
			return 2;}
};

class rectangle :public shape {
	public:
		rectangle(int x,int y):shape(x,y){};

		virtual int draw(){
			cout<<"draw a rectangle"<<endl;
			return 3;}
};
     

class solid_rectangle :public rectangle{
	public:
		solid_rectangle(int x,int y):rectangle(x,y){};   
};


int	main()
{
	shape *p;
	triangle t1(1,2);
	rectangle r1(3,4);
	circle c1(1,2,3);
	solid_rectangle s1(5,6);

	p=&t1;
	p->draw();
	p=&r1;
	p->draw();
	p=&c1;
	p->draw();
	p=&s1;
	p->draw();

	return 0;
}
