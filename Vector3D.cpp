#include <iostream>
using namespace std;

class Vector2D
{

public:
    Vector2D(){
        float x, y, z;
    }
	Vector2D(float x, float y, float z){
		x_x=x;
		y_y=y;
    z_z=z;
		}
	float getX() const
	{
		return x_x;
	}
	float getY() const
	{
		return y_y;
	}
  float getZ() const
  {
    return z_z;
  }
	void setX(float x){
	    this->x_x = x;
	}
  void setY(float y){
      this->y_y = y;
  }
  void setZ(float z){
      this->z_z = z;
  }
//сумма двух векторов
	Vector2D operator+ (const Vector2D& v2){
	    float a, b, c;
      a = this->getX() + v2.x_x;
	    b = this->getY() + v2.y_y;
      c = this->getZ() + v2.z_z;
	    return Vector2D(a, b, c);
	}
  
//разница двух векторов
  Vector2D operator- (const Vector2D& v2){
	    float a, b, c;
      a = this->getX() - v2.x_x;
	    b = this->getY() - v2.y_y;
      c = this->getZ() - v2.z_z;
	    return Vector2D(a, b, c);
	}
  
  //умножение на константу vector*a
	Vector2D operator* (const int a){
	    float x = (this->getX()) * a;
	    float y = (this->getY()) * a;
      float z = (this->getZ()) * a;
	    return Vector2D(x, y, z);
	}

//произведение векторов
  float operator* (const Vector2D& v2){
	    float x = (this->getX()) * v2.x_x;
	    float y = (this->getY()) * v2.y_y;
      float z = (this->getZ()) * v2.z_z;
	    return (x + y + z);
	}
	friend ostream& operator<<(ostream& os, const Vector2D& v);

private:
	float x_x, y_y, z_z;


};
//вывод вектора в формате (1;1;1)
ostream& operator<<(ostream& os, const Vector2D& v){
	os<<"(" << v.getX() <<"; "<< v.getY()<<"; "<< v.getZ()<<")";
	return os;
}

//чтение вектора
istream& operator>>(istream &is, Vector2D &v){
    int a, b, c;
    is>> a >> b>>c;
    v.setX(a);
    v.setY(b);
    v.setZ(c);
    return is;
}

//умножение на константу a*vector
Vector2D operator* (int a, Vector2D& v){
    float x = a * v.getX();
    float y = a * v.getY();
    float z = a * v.getZ();
    return Vector2D(x, y, z);
}
