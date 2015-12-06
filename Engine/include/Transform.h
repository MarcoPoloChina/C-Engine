#ifndef TRANSFORM_H
#define TRANSFORM_H
struct Vector2d{
	Vector2d(): x(0), y(0){}
	Vector2d(int x, int y): x(x), y(y){}
	int x, y;
};
class Transform{
	public:
		Transform(): pos(Vector2d()), rotation(0){}
		Transform(Vector2d pos, double rotation): pos(pos), rotation(rotation){}
		Vector2d pos;
		double rotation;
};
#endif
