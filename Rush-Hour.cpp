#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

struct Position{
int x=0,y=0;
void setValues(int xPos,int yPos){
x=xPos;
y=yPos;
}
bool operator==(const Position& other) const{
return x==other.x && y==other.y;
}
};

class GameObject{
protected:
Position position;
public:
virtual void display()=0;
virtual bool isCollidable() const {return true;}
Position getPosition() const {return position;}
virtual ~GameObject(){}
};

class C:public GameObject{
public:
C(Position p){position=p;}
void display(){cout<<"C ";}
bool isCollidable() const{return false;}
};

class B:public GameObject{
public:
B(Position p){position=p;}
void display(){cout<<"B ";}
};

class T:public GameObject{
public:
T(Position p){position=p;}
void display(){cout<<"T ";}
};

class F:public GameObject{
public:
F(Position p){position=p;}
void display(){cout<<"F ";}
bool isCollidable() const{return false;}
};

class O:public GameObject{
public:
O(Position p){position=p;}
void display(){cout<<"O ";}
};

class Game{
int numRows,numCols;
GameObject*** grid;
Position buildings[5][21];
Position trees[8];
Position otherCars[4];
Position fuelStations[4];
Position playerCarPosition;

public:
Game(int r,int c):numRows(r),numCols(c){
grid=new GameObject**[numRows];
for(int i=0;i<numRows;i++){
grid[i]=new GameObject*[numCols];
for(int j=0;j<numCols;j++){
grid[i][j]=nullptr;
}
}
setBuildingIndexes();
setTreeIndexes();
setOtherCarsIndexes();
setFuelStationIndexes();
playerCarPosition.setValues(1,1);
placeObjects();
}

void displayGrid(){
for(int i=0;i<numRows;i++){
for(int j=0;j<numCols;j++){
if(grid[i][j]) grid[i][j]->display();
else cout<<". ";
}
cout<<endl;
}
}

void placeObjects(){
for(int i=0;i<5;i++){
for(int j=0;j<21;j++){
Position& p=buildings[i][j];
grid[p.x][p.y]=new B(p);
}
}
for(int i=0;i<8;i++){
Position& p=trees[i];
grid[p.x][p.y]=new T(p);
}
for(int i=0;i<4;i++){
Position& p=otherCars[i];
grid[p.x][p.y]=new O(p);
}
for(int i=0;i<4;i++){
Position& p=fuelStations[i];
grid[p.x][p.y]=new F(p);
}
grid[playerCarPosition.x][playerCarPosition.y]=new C(playerCarPosition);
}

void movePlayer(char input){
int dx=0,dy=0;
if(input=='w'||input=='W') dx=-1;
else if(input=='s'||input=='S') dx=1;
else if(input=='a'||input=='A') dy=-1;
else if(input=='d'||input=='D') dy=1;
else return;

int newX=playerCarPosition.x+dx;
int newY=playerCarPosition.y+dy;

if(newX<0||newX>=numRows||newY<0||newY>=numCols) return;

GameObject* target=grid[newX][newY];
if(target&&target->isCollidable()) return;

delete grid[playerCarPosition.x][playerCarPosition.y];
grid[playerCarPosition.x][playerCarPosition.y]=nullptr;

playerCarPosition.setValues(newX,newY);
grid[newX][newY]=new C(playerCarPosition);
}

~Game(){
for(int i=0;i<numRows;i++){
for(int j=0;j<numCols;j++){
delete grid[i][j];
}
delete[] grid[i];
}
delete[] grid;
}

void setBuildingIndexes(){
int startX=5;
int startY=5;
for(int i=0;i<5;i++){
int x=startX,y=startY;
for(int j=0;j<21;j++){
buildings[i][j].setValues(x,y);
y++;
if((j+1)%7==0){y=startY;x++;}
}
startX+=5;
startY+=8;
if(i==2) startY=1;
}
}

void setTreeIndexes(){
trees[0].setValues(2,20);
trees[1].setValues(25,20);
trees[2].setValues(15,2);
trees[3].setValues(18,17);
trees[4].setValues(3,3);
trees[5].setValues(8,18);
trees[6].setValues(28,2);
trees[7].setValues(28,1);
}

void setOtherCarsIndexes(){
otherCars[0].setValues(12,27);
otherCars[1].setValues(25,27);
otherCars[2].setValues(15,10);
otherCars[3].setValues(20,13);
}

void setFuelStationIndexes(){
fuelStations[0].setValues(2,27);
fuelStations[1].setValues(20,15);
fuelStations[2].setValues(28,19);
fuelStations[3].setValues(25,6);
}
};

int main(){
Game game(30,30);
char input;
while(true){
system("cls");
game.displayGrid();
cout<<"\nUse W A S D to move, Q to quit: ";
input=_getch();
if(input=='q'||input=='Q') break;
game.movePlayer(input);
}
return 0;
}
