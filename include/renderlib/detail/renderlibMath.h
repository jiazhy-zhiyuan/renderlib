#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#undef RGB

#include <stdint.h>
#include <string>

/*
 * Vector2
 */
namespace _detail
{
	template <typename T>
	struct Vector2
	{
		T x;
		T y;

		Vector2() :
			x((T)0), y((T)0)
		{}

		Vector2(const T& _x, const T& _y) :
			x(_x), y(_y)
		{}

		Vector2(const Vector2<T>& other) :
			x(other.x), y(other.y)
		{}

		template <typename TOther>
		Vector2(const Vector2<TOther>& other) :
			x(static_cast<T>(other.x)), y(static_cast<T>(other.y))
		{}

		Vector2& operator=(const Vector2<T>& other)
		{
			x = other.x;
			y = other.y;
			return *this;
		}

		Vector2<T> operator+(const Vector2<T>& other) const
		{
			return Vector2(x + other.x, y + other.y);
		}
		Vector2<T>& operator+=(const Vector2<T>& other)
		{
			x += other.x;
			y += other.y;
			return *this;
		}

		Vector2<T> operator-(const Vector2<T>& other) const
		{
			return Vector2<T>(x - other.x, y - other.y);
		}
		Vector2<T>& operator-=(const Vector2<T>& other)
		{
			x -= other.x;
			y -= other.y;

			return *this;
		}

		Vector2<T> operator*(const T v) const
		{
			return Vector2<T>(x * v, y * v);
		}
		Vector2<T>& operator*=(const T v)
		{
			x *= v;
			y *= v;
			return *this;
		}

		Vector2<T> operator*(const Vector2<T>& other) const
		{
			return Vector4<T>(x * other.x, y * other.y);
		}
		Vector2<T>& operator*=(const Vector2<T>& other)
		{
			x *= other.x;
			y *= other.y;
			return *this;
		}

		bool operator==(const Vector2<T>& other)
		{
			return x == other.x && y == other.y;
		}
	};
}

namespace math
{
	using Vector2 = ::_detail::Vector2<int32_t>;
	using Vector2f = ::_detail::Vector2<float>;
}

/*
 * Vector3
 */
namespace _detail
{
	template <typename T>
	struct Vector3
	{
		T x;
		T y;
		T z;

		Vector3() :
			x((T)0), y((T)0), z((T)0)
		{}

		Vector3(const T& _x, const T& _y, const T& _z) :
			x(_x), y(_y), z(_z)
		{}

		Vector3(const Vector3<T>& other) :
			x(other.x), y(other.y), z(other.z)
		{}

		template <typename TOther>
		Vector3(const Vector3<TOther>& other) :
			x(static_cast<T>(other.x)), y(static_cast<T>(other.y)), z(static_cast<T>(other.z))
		{}

		Vector3& operator=(const Vector3<T>& other)
		{
			x = other.x;
			y = other.y;
			z = other.z;
			return *this;
		}

		Vector3<T> operator+(const Vector3<T>& other) const
		{
			return Vector3(x + other.x, y + other.y, z + other.z);
		}
		Vector3<T>& operator+=(const Vector3<T>& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}

		Vector3<T> operator-(const Vector3<T>& other) const
		{
			return Vector3<T>(x - other.x, y - other.y, z - other.z);
		}
		Vector3<T>& operator-=(const Vector3<T>& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;

			return *this;
		}

		Vector3<T> operator*(const T v) const
		{
			return Vector3<T>(x * v, y * v, z * v);
		}
		Vector3<T>& operator*=(const T v)
		{
			x *= v;
			y *= v;
			z *= v;
			return *this;
		}

		Vector3<T> operator*(const Vector3<T>& other) const
		{
			return Vector4<T>(x * other.x, y * other.y, z * other.z);
		}
		Vector3<T>& operator*=(const Vector3<T>& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			return *this;
		}

		bool operator==(const Vector3<T>& other)
		{
			return x == other.x && y == other.y && z == other.z;
		}

		inline Vector3<T>& normalize()
		{
			T xxyyzz = x * x + y * y + z * z;
			float invLength = 1.0f / sqrtf(xxyyzz);
			x *= invLength;
			y *= invLength;
			z *= invLength;
			return *this;
		}

		inline Vector3<T> cross(const Vector3& rhs) const {
			return Vector3<T>(y*rhs.z - z * rhs.y, z*rhs.x - x * rhs.z, x*rhs.y - y * rhs.x);
		}

		inline float length() const {
			return sqrtf(x*x + y * y + z * z);
		}

		inline float dot(const Vector3& rhs) const {
			return (x*rhs.x + y * rhs.y + z * rhs.z);
		}
	};
}

namespace math
{
	using Vector3 = ::_detail::Vector3<int32_t>;
	using Vector3f = ::_detail::Vector3<float>;
}

/* 
 * Vector4
 */
namespace _detail
{
	template <typename T>
	struct Vector4
	{
		T x;
		T y;
		T z;
		T w;

		Vector4() :
			x((T)0), y((T)0), z((T)0), w((T)0)
		{}

		Vector4(const T& _x, const T& _y, const T& _z, const T& _w) :
			x(_x), y(_y), z(_z), w(_w)
		{}

		Vector4(const Vector4<T>& other) :
			x(other.x), y(other.y), z(other.z), w(other.w)
		{}

		template <typename TOther>
		Vector4(const Vector4<TOther>& other) :
			x(static_cast<T>(other.x)), y(static_cast<T>(other.y)), z(static_cast<T>(other.z)), w(static_cast<T>(other.w))
		{}

		Vector4& operator=(const Vector4<T>& other)
		{
			x = other.x;
			y = other.y;
			z = other.z;
			w = other.w;
			return *this;
		}

		Vector4<T> operator+(const Vector4<T>& other) const
		{
			return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
		}
		Vector4<T>& operator+=(const Vector4<T>& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;
			return *this;
		}

		Vector4<T> operator-(const Vector4<T>& other) const
		{
			return Vector4<T>(x - other.x, y - other.y, z - other.z, w - other.w);
		}
		Vector4<T>& operator-=(const Vector4<T>& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;

			return *this;
		}

		Vector4<T> operator*(const T v) const
		{
			return Vector4<T>(x * v, y * v, z * v, w * v);
		}
		Vector4<T>& operator*=(const T v)
		{
			x *= v;
			y *= v;
			z *= v;
			w *= v;
			return *this;
		}

		Vector4<T> operator*(const Vector4<T>& other) const
		{
			return Vector4<T>(x * other.x, y * other.y, z * other.z, w * other.w);
		}
		Vector4<T>& operator*=(const Vector4<T>& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;
			return *this;
		}

		bool operator==(const Vector4<T>& other)
		{
			return x == other.x && y == other.y && z == other.z && w == other.w;
		}
	};
}

namespace math
{
	using Vector4 = ::_detail::Vector4<uint32_t>;
	using Vector4f = ::_detail::Vector4<float>;
}

/*
 * Rect
 */
namespace _detail
{
	template <typename T>
	struct Rect
	{
		T x;
		T y;
		T w;
		T h;

		Rect() :
			x((T)0), y((T)0),
			w((T)0), h((T)0)
		{}

		Rect(T _x, T _y, T _w, T _h) :
			x(_x), y(_y),
			w(_w), h(_h)
		{}

		Rect(const Rect<T>& other) :
			x(other.x), y(other.y),
			w(other.w), h(other.h)
		{}

		template <typename TOther>
		Rect(const Rect<TOther>& other) :
			x(static_cast<T>(other.x)), y(static_cast<T>(other.y)),
			w(static_cast<T>(other.w)), h(static_cast<T>(other.h))
		{}

		Rect(const _detail::Vector2<T>& position, const _detail::Vector2<T>& size) :
			x(position.x), y(position.y),
			w(size.x), h(size.y)
		{}

		inline bool Contains(const Rect& r) const
		{
			return
				r.x >= x && r.y >= y &&
				(r.x + r.w) <= (x + w) && (r.y + r.h) <= (y + h);
		}

		inline bool Contains(const _detail::Vector2<T>& pos, const _detail::Vector2<T>& size) const
		{
			return
				pos.x >= x && pos.y >= y &&
				(pos.x + size.x) <= (x + w) && (pos.y + size.y) <= (y + h);
		}

		inline bool IsIn(const Rect& r) const
		{
			return r.Contains(*this);
		}

		inline bool IsIn(const _detail::Vector2<T>& pos, const _detail::Vector2<T>& size) const
		{
			return
				x >= pos.x && y >= pos.y &&
				(x + w) <= (pos.x + size.x) && (y + h) <= (pos.y + size.y);
		}
	};
}

namespace math
{
	using Rect = ::_detail::Rect<int32_t>;
	using Rectf = ::_detail::Rect<float>;
}

/*
 * Matrix
 */
namespace math
{
	struct Matrix4
	{
		float m[16];

		Matrix4();  // init with identity
		Matrix4(const float src[16]);
		Matrix4(float m00, float m01, float m02, float m03, // 1st column
			float m04, float m05, float m06, float m07, // 2nd column
			float m08, float m09, float m10, float m11, // 3rd column
			float m12, float m13, float m14, float m15);// 4th column

		void        set(const float src[16]);
		void        set(float m00, float m01, float m02, float m03, // 1st column
			float m04, float m05, float m06, float m07, // 2nd column
			float m08, float m09, float m10, float m11, // 3rd column
			float m12, float m13, float m14, float m15);// 4th column
		void        setRow(int index, const float row[4]);
		void        setRow(int index, const Vector4& v);
		void        setRow(int index, const Vector3& v);
		void        setColumn(int index, const float col[4]);
		void        setColumn(int index, const Vector4& v);
		void        setColumn(int index, const Vector3& v);

		const float* get() const;
		float       getDeterminant() const;
		Vector3     getAngle() const;                       // return (pitch, yaw, roll)

		Matrix4&    identity();
		Matrix4&    transpose();                            // transpose itself and return reference
		Matrix4&    invert();                               // check best inverse method before inverse
		Matrix4&    invertEuclidean();                      // inverse of Euclidean transform matrix
		Matrix4&    invertGeneral();                        // inverse of generic matrix

															// transform matrix
		Matrix4&    translate(float x, float y, float z);   // translation by (x,y,z)
		Matrix4&    translate(const Vector3& v);            //
		Matrix4&    rotate(float angle, const Vector3& axis); // rotate angle(degree) along the given axix
		Matrix4&    rotate(float angle, float x, float y, float z);
		Matrix4&    rotateX(float angle);                   // rotate on X-axis with degree
		Matrix4&    rotateY(float angle);                   // rotate on Y-axis with degree
		Matrix4&    rotateZ(float angle);                   // rotate on Z-axis with degree
		Matrix4&    scale(float scale);                     // uniform scale
		Matrix4&    scale(float sx, float sy, float sz);    // scale by (sx, sy, sz) on each axis
		Matrix4&    lookAt(float tx, float ty, float tz);   // face object to the target direction
		Matrix4&    lookAt(float tx, float ty, float tz, float ux, float uy, float uz);
		Matrix4&    lookAt(const Vector3& target);
		Matrix4&    lookAt(const Vector3& target, const Vector3& up);
		//@@Matrix4&    skew(float angle, const Vector3& axis); //

		// operators
		Matrix4     operator+(const Matrix4& rhs) const;    // add rhs
		Matrix4     operator-(const Matrix4& rhs) const;    // subtract rhs
		Matrix4&    operator+=(const Matrix4& rhs);         // add rhs and update this object
		Matrix4&    operator-=(const Matrix4& rhs);         // subtract rhs and update this object
		Vector4     operator*(const Vector4& rhs) const;    // multiplication: v' = M * v
		Vector3     operator*(const Vector3& rhs) const;    // multiplication: v' = M * v
		Matrix4     operator*(const Matrix4& rhs) const;    // multiplication: M3 = M1 * M2
		Matrix4&    operator*=(const Matrix4& rhs);         // multiplication: M1' = M1 * M2
		bool        operator==(const Matrix4& rhs) const;   // exact compare, no epsilon
		bool        operator!=(const Matrix4& rhs) const;   // exact compare, no epsilon
		float       operator[](int index) const;            // subscript operator v[0], v[1]
		float&      operator[](int index);                  // subscript operator v[0], v[1]

		float       getCofactor(float m0, float m1, float m2,
			float m3, float m4, float m5,
			float m6, float m7, float m8) const;
	};
}