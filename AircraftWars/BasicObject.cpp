#include "BasicObject.h"
#include "acllib.h"
//Point类的构造函数
Point::Point() {
	this->x = 0;
	this->y = 0;
}
Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}
Point::Point(const Point &position) {
	this->SetPoint(position);
}
//设置和获取X的数值
int Point::GetX() const {
	return this->x;
}
void Point::SetX(int x) {
	this->x = x;
}
//设置和获取Y的数值
int Point::GetY() const {
	return this->y;
}
void Point::SetY(int y) {
	this->y = y;
}
//设置坐标
void Point::SetPoint(const Point &position) {
	this->x = position.GetX();
	this->y = position.GetY();
}
void Point::SetPoint(int x, int y) {
	this->x = x;
	this->y = y;
}
//重载 + 运算符
Point Point::operator + (const Point &b) {
	Point temp(this->x + b.GetX(), this->y + b.GetY());
	return temp;
}
Point Point::operator - (const Point &b) {
	Point temp(this->x - b.GetX(), this->y - b.GetY());
	return temp;
}

//Rect类的构造函数
Rect::Rect() {
	this->leftBoundary = 0;
	this->rightBoundary = 0;
	this->topBoundary = 0;
	this->bottomBoundary = 0;
}
Rect::Rect(int left, int right, int top, int bottom) {
	this->leftBoundary = left;
	this->rightBoundary = right;
	this->topBoundary = top;
	this->bottomBoundary = bottom;
}
Rect::Rect(const Rect &rect) {
	this->SetRect(rect);
}
//设置和获取边界的数值
int Rect::GetLeft() const {
	return this->leftBoundary;
}
void Rect::SetLeft(int left) {
	this->leftBoundary = left;
}
int Rect::GetRight() const {
	return this->rightBoundary;
}
void Rect::SetRight(int right) {
	this->rightBoundary = right;
}
int Rect::GetTop() const {
	return this->topBoundary;
}
void Rect::SetTop(int top) {
	this->topBoundary = top;
}
int Rect::GetBottom() const {
	return this->bottomBoundary;
}
void Rect::SetBottom(int bottom) {
	this->bottomBoundary = bottom;
}
//设置矩形数值
void Rect::SetRect(const Rect &rect) {
	this->leftBoundary = rect.GetLeft();
	this->rightBoundary = rect.GetRight();
	this->topBoundary = rect.GetTop();
	this->bottomBoundary = rect.GetBottom();
}
void Rect::SetRect(int left, int right, int top, int bottom) {
	this->leftBoundary = left;
	this->rightBoundary = right;
	this->topBoundary = left;
	this->bottomBoundary = bottom;
}


ACL_Image Default;
Actor::Actor() :image(Default) {
	this->width = 0;
	this->height = 0;
	this->healthPoint = 100;
	this->attack = 50;
	this->SetPosition(Point(0, 0));
	this->SetSpeed(Point(0, 0));
	this->SetRect(Rect(0, 0, 0, 0));
}
Actor::Actor(int width, int height, ACL_Image &image) :image(image) {
	this->width = width;
	this->height = height;
	this->healthPoint = 100;
	this->attack = 50;
	this->SetPosition(Point(0, 0));
	this->SetSpeed(Point(0, 0));
	this->SetRect(Rect(0, 0, 0, 0));
}
int Actor::GetWidth() const {
	return this->width;
}
void Actor::SetWidth(int width) {
	this->width = width;
}
int Actor::GetHeight() const {
	return this->height;
}
void Actor::SetHeight(const int height) {
	this->height = height;
}
int Actor::GetHealthPoint() const {
	return this->healthPoint;
}
void Actor::SetHealthPoint(int healthPoint) {
	this->healthPoint = healthPoint;
}
int Actor::GetAttack() const {
	return this->attack;
}
void Actor::SetAttack(int attack) {
	this->attack = attack;

}
const Point &Actor::GetPosition() const {
	return this->position;
}
void Actor::SetPosition(const Point &position) {
	this->position.SetPoint(position);
}
const Speed &Actor::GetSpeed() const {
	return this->speed;
}
void Actor::SetSpeed(const Speed &speed) {
	this->speed.SetPoint(speed);
}
const Rect &Actor::GetRect() const {
	return this->rect;
}
void Actor::SetRect(const Rect &rect) {
	this->rect.SetRect(rect);
}
const ACL_Image &Actor::GetImage() const {
	return this->image;
}
ACL_Image *Actor::GetImagePointer() {
	return &this->image;
}
void Actor::SetImage(ACL_Image &image) {
	this->image = image;
}
//
void Actor::MoveSelf() {
	position.SetPoint(position + speed);
}

