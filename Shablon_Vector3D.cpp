#include <iostream>
using namespace std;

template<typename T>
class Vector3D
{

public:
    Vector3D(){
        T x, y, z;
    }
	Vector3D(T x, T y, T z){
		x_x=x;
		y_y=y;
    z_z=z;
		}
	T getX() const
	{
		return x_x;
	}
	T getY() const
	{
		return y_y;
	}
  T getZ() const
  {
    return z_z;
  }
	void setX(T x){
	    this->x_x = x;
	}
  void setY(T y){
      this->y_y = y;
  }
  void setZ(T z){
      this->z_z = z;
  }
//сумма двух векторов
	Vector3D operator+ (const Vector3D& v2){
	    T a, b, c;
      a = this->getX() + v2.x_x;
	    b = this->getY() + v2.y_y;
      c = this->getZ() + v2.z_z;
	    return Vector3D(a, b, c);
	}
  
//разница двух векторов
  Vector3D operator- (const Vector3D& v2){
	    T a, b, c;
      a = this->getX() - v2.x_x;
	    b = this->getY() - v2.y_y;
      c = this->getZ() - v2.z_z;
	    return Vector3D(a, b, c);
	}
  
  //умножение на константу vector*a
	Vector3D operator* (const T a){
	    T x = (this->getX()) * a;
	    T y = (this->getY()) * a;
      T z = (this->getZ()) * a;
	    return Vector3D(x, y, z);
	}

//произведение векторов
  T operator* (const Vector3D& v2){
	    T x = (this->getX()) * v2.x_x;
	    T y = (this->getY()) * v2.y_y;
      T z = (this->getZ()) * v2.z_z;
	    return (x + y + z);
	}
  template<typename X>
	friend ostream& operator<<(ostream& os, const Vector3D<T>& v);

private:
	T x_x, y_y, z_z;


};
//вывод вектора в формате (1;1;1)
template<typename T>
ostream& operator<<(ostream& os, const Vector3D<T>& v){
	os<<"(" << v.getX() <<"; "<< v.getY()<<"; "<< v.getZ()<<")";
	return os;
}

//чтение вектора
template<typename T>
istream& operator>>(istream &is, Vector3D<T> &v){
    T a, b, c;
    is>> a >> b>>c;
    v.setX(a);
    v.setY(b);
    v.setZ(c);
    return is;
}

//умножение на константу a*vector
template<typename T>
Vector3D operator* (int a, Vector3D<T>& v){
    T x = a * v.getX();
    T y = a * v.getY();
    T z = a * v.getZ();
    return Vector3D(x, y, z);
}
