#pragma once
#include "acllib.h"

class Point {
private:
	int x, y;
public:
	//���캯��
	Point();
	Point(int x, int y);
	Point(const Point &position);
	//���úͻ�ȡX����ֵ
	int GetX() const;
	void SetX(int x);
	//���úͻ�ȡY����ֵ
	int GetY() const;
	void SetY(int y);
	//��������
	void SetPoint(const Point &position);
	void SetPoint(int x, int y);
	//���� + �����
	Point operator + (const Point &b);
	Point operator - (const Point &b);
};

class Rect {
private:
	int leftBoundary;
	int rightBoundary;
	int topBoundary;
	int bottomBoundary;
public:
	//Rect�๹�캯��
	Rect();
	Rect(int left, int right, int top, int bottom);
	Rect(const Rect &rect);
	//���úͻ�ȡ�߽����ֵ
	int GetLeft() const;
	void SetLeft(int left);
	int GetRight() const;
	void SetRight(int right);
	int GetTop() const;
	void SetTop(int top);
	int GetBottom() const;
	void SetBottom(int bottom);
	//���þ���
	void SetRect(const Rect &rect);
	void SetRect(int left, int right, int top, int bottom);
};

typedef Point Speed;
class Actor {
private:
	int width;
	int height;
	int healthPoint;
	int attack;
	Point position;
	Speed speed;
	Rect rect;
	ACL_Image &image;
public:
	//���캯��
	Actor();
	Actor(int width, int height, ACL_Image &image);
	//���úͻ�ȡActor������
	int GetWidth() const;
	void SetWidth(int width);
	int GetHeight() const;
	void SetHeight(int height);
	int GetHealthPoint() const;
	void SetHealthPoint(int healthPoint);
	int GetAttack() const;
	void SetAttack(int attack);
	const Point &GetPosition() const;
	void SetPosition(const Point &position);
	const Speed &GetSpeed() const;
	void SetSpeed(const Speed &speed);
	const Rect &GetRect() const;
	const ACL_Image &GetImage() const;
	ACL_Image *GetImagePointer();
	void SetImage(ACL_Image &image);
	//�ƶ�����
	void MoveSelf();
};

extern ACL_Image Default;