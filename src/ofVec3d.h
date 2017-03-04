#pragma once

#include "ofVec2d.h"
#include "ofVec4d.h"
#include "ofConstants.h"

#include <cmath>
#include <iostream>

/// \brief  ofVec3d is a class for storing a three dimensional vector.
/// 
/// Moving through space requires knowledge of where things are and where they are
/// going. Vector Maths is the class of mathematics that gives us control over
/// these things in space, allowing for elegant and intuitive descriptions of
/// complex structures and movement. Vectors are at the heart of animations,
/// particle systems, and 2D and 3D graphics.
/// 
/// Vectors in mathematics in general are entities with magnitude (also called
/// length) and direction. A vector whose magnitude is 1 (ie a vector that is
/// *normalized*) is called a *unit vector*. Unit vectors are very handy for
/// storing directions as they can be easily scaled up (or down) to represent
/// motion in a particular direction with a particular length.
/// 
/// *You will also see the term 'vector' used to describe an array of objects in
/// C++ (such as text strings). Don't let this confuse you, they are quite
/// different: one of them is a mathematical term for a fixed-length list of
/// numbers that you can do mathematical operations on, the other is a
/// C++-specific term that means 'dynamically sizeable array'.*
/// 
/// 'ofVec3d has three member variables, x, y, and z, which allow to conveniently
/// 'store 3D properties of an object such as its position, velocity, or
/// 'acceleration.
/// 
/// ~~~~{.cpp}
/// ofVec3d v1; // v1.x is 0, v1.y is 0, v1.z is 0
/// v1.set(10, 50, 80); // now v1.x is 10, v1.y is 50, v1.z is 80
/// ~~~~
/// 
/// Using 'ofVec3d' greatly simplifies arithmetic operations in three dimensions.
/// For example if you have two vectors 'v1' and 'v2', both of which represent a
/// 3D change in position, you can find the total change of position of both of
/// them just by doing an addition 'v1 + v2':
/// 
/// ~~~~{.cpp}
/// ofVec3d v1(5, 2, 1); 
/// // so now v1 represents walking 5 steps forward then 2 steps 
/// // sideways then 1 step upwards
/// ofVec3d v2;
/// v2.set(1, 1, 1); 
/// // so now v2 represents walking 1 step forward then 1 step 
/// // sideways then 1 step upwards
/// 
/// // what happens if you do v1 followed by v2?
/// // to find out just add v1 and v2 together:
/// ofVec3d result = v1 + v2; 
/// // result is (6, 3, 1), or 6 steps forward then 3 steps sideways
/// // then 2 steps upwards
/// ~~~~
/// 
/// You can scale an 'ofVec3d' by multiplying it with a double:
/// 
/// ~~~~{.cpp}
/// // walk 5 steps forward then 2 steps sideways then 1 step upwards
/// ofVec3d v1(5, 2, 1); 
/// // what happens if we do v1 three times?
/// ofVec3d result = v1 * 3; // result is (15, 6, 3), or 
/// // 15 steps forward, 6 steps sideways and 3 steps upwards
/// ~~~~
/// 
/// This also works for subtraction and division.
/// 
/// As you can see this really makes dealing with vectors as easy as dealing with
/// single 'double's or 'int's, and can reduce the number of lines of code you have
/// to write by half, at the same time making your code much easier to read and
/// understand!
/// \sa ofVec2d for 2D vectors
/// \sa ofVec4d for 4D vectors
class ofVec3d {
public:
   	/// \cond INTERNAL
	static const int DIM = 3;
	/// \endcond
	
	/// \brief Stores the `X` component of this vector.
	double x;
	
	/// \brief Stores the `Y` component of this vector.
	double y;
	
	/// \brief Stores the `Z` component of this vector.
	double z;
    
	//---------------------
	/// \name Construct a 3D vector
	/// \{
    
	/// \brief Construct a 3D vector. Defaults to (0,0,0).
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1; 
	/// // default: v1.x is 0, v1.y is 0, v1.z is 0
	///
	/// ofVec3d v2 = ofVec3d(40, 20, 10); 
	/// // v2.x is 40, v2.y is 20, v2.z is 10
	///
	/// ofVec3d v3(0.1, 0.3, -1.5); 
	/// // v3.x is 0.1, v3.y is 0.3, v3.z is -1.5
	/// ~~~~
	ofVec3d();

	/// \brief Construt a 3D vector with `x`, `y` and `z` specified
	ofVec3d( double x, double y, double z=0 );
	
	/// \brief Construct a 3D vector with `x`, `y` and `z` set to `scalar`
	explicit ofVec3d( double scalar );
	
    ofVec3d( const ofVec2d& vec );

	/// \brief Construct a new 3D vector from a 4D vector by 
	/// throwing away the 'w' component.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d mom = ofVec4d(40, 20, 10, 100);
	/// ofVec3d v(mom); // v is (40, 20, 10)
	/// ~~~~
    ofVec3d( const ofVec4d& vec );
	
	/// \}

	//---------------------
	/// \name Access components
	/// \{


	/// \brief Returns a pointer to the memory position of the first element of the vector
	/// ('x'); the other elements ('y' and 'z') immediately follow it in memory.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1 = ofVec3d(40, 20, 10);
	/// double * v1Ptr = v1.getPtr();
	/// double x = *(v1Ptr); // x is 40
	/// double y = *(v1Ptr+1); // y is 20
	/// double z = *(v1Ptr+2); // z is 10
	/// ~~~~
	/// 
	/// This is very useful when using arrays of 'ofVec3d's to store geometry
	/// information, as it allows the vector to be treated as a simple C array of
	/// 'double's that can be passed verbatim to OpenGL.
	/// 
	double * getPtr() {
		return (double*)&x;
	}
	const double * getPtr() const {
		return (const double *)&x;
	}
	

	/// \brief Allows to access the individual components of an 'ofVec3d' as though it is an
	/// array
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1 = ofVec3d(40, 20, 10);
	/// double x = v1[0]; // x is 40
	/// double y = v1[1]; // y is 20
	/// double z = v1[2]; // z is 10
	/// ~~~~
	/// 
	/// This function can be handy if you want to do the same operation to all 'x',
	/// 'y' and 'z' components, as it means you can just make a 'for' loop that
	/// repeats 3 times.
	double& operator[]( int n ){
		return getPtr()[n];
	}
	
	double operator[]( int n ) const {
		return getPtr()[n];
	}
	
    
	/// \brief Set 'x', 'y' and 'z' components of this vector with just one function call.
	/// 'z' is optional, it defaults to 0.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1;
	/// v1.set(40, 20, 70);
	/// ~~~~
    void set( double x, double y, double z = 0 );


	/// \brief Setting the values by using other 3 dimension vector ofVec3d.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1;
	/// ofVec3d v2;
	/// v1.set(40, 20, 70);
	/// v2.set(v1);
	/// ~~~~
    void set( const ofVec3d& vec );
	void set( double _scalar );

	/// \}

    //---------------------
	/// \name Comparison 
	/// \{

    /// \brief Check for equality between two ofVec3d
    ///
	/// Returns 'true' if each component is the same as the corresponding component in
	/// 'vec', ie if 'x == vec.x' and 'y == vec.y' and 'z == vec.z'; otherwise returns
	/// 'false'. But you should probably be using ['match'](#match) instead.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1(40, 20, 10); 
	/// ofVec3d v2(50, 30, 10); 
	/// ofVec3d v3(40, 20, 10); 
	/// // ( v1 == v2 ) is false
	/// // ( v1 == v3 ) is true
	/// ~~~~
    bool operator==( const ofVec3d& vec ) const;
    
	/// \brief Returns 'true' if any component is different to its corresponding component in
	/// 'vec', ie if 'x != vec.x' or 'y != vec.y' or 'z != vec.z'; otherwise returns
	/// 'false'.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1(40, 20, 10); 
	/// ofVec3d v2(50, 20, 40); 
	/// ofVec3d v3(40, 20, 10); 
	/// // ( v1 != v2 ) is true
	/// // ( v1 != v3 ) is false
	/// ~~~~
    bool operator!=( const ofVec3d& vec ) const;

	/// \brief Let you check if two vectors are similar given a tolerance threshold
	/// 'tolerance' (default = 0.0001).	
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1 = ofVec3d(40, 20, 70);
	/// ofVec3d v2 = ofVec3d(40.01, 19.999, 70.05);
	/// // v1.match(v2, 0.1) is true
	/// // v1.match(v2, 0.01) is false (because (70.5-70) > 0.01)
	/// ~~~~
	/// 
    bool match( const ofVec3d& vec, double tolerance = 0.0001 ) const;
    /**
	 * Checks if vectors look in the same direction.
	 */
    bool isAligned( const ofVec3d& vec, double tolerance = 0.0001 ) const;
    bool isAlignedRad( const ofVec3d& vec, double tolerance = 0.0001 ) const;
    
	/// \brief Returns 'true' if this vector is pointing in the same direction as
	/// 'vec', with an angle error threshold 'tolerance' in degrees (default
	/// 0.0001 degrees).	
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1 = ofVec3d(40, 20, 70);
	/// ofVec3d v2 = ofVec3d(4, 2, 7);
	/// // v1.align(v2, 0.0) is true
	/// ~~~~
    bool align( const ofVec3d& vec, double tolerance = 0.0001 ) const;
    
	/// \brief Returns 'true' if this vector is pointing in the same direction
	/// as 'vec', with an angle error threshold 'tolerance' in radians
	/// (default 0.0001).
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1 = ofVec3d(40, 20, 70);
	/// ofVec3d v2 = ofVec3d(4, 2, 7);
	/// // v1.align(v2, 0.0) is true
	/// ~~~~
    bool alignRad( const ofVec3d& vec, double tolerance = 0.0001 ) const;
	
	
    /// \}

	//---------------------
	/// \name Operators
	/// \{

	/// Super easy vector addition. Returns a new vector
	/// ('x'+'vec.x','y'+'vec.y','z'+'vec.z').
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1 = ofVec3d(40, 20, 10); 
	/// ofVec3d v2 = ofVec3d(25, 50, 10);
	/// ofVec3d v3 = v1 + v2; // v3 is (65, 70, 20)
	/// ~~~~
    ofVec3d  operator+( const ofVec3d& pnt ) const;

	/// Returns a new vector with a double value 'f' added to 'x', 'y' and 'z'
	/// members.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1(2, 5, 1);
	/// ofVec3d v2 = v1 + 10; // (12, 15, 11)
	/// ~~~~

    ofVec3d  operator+( const double f ) const;
    
	/// Super easy addition assignment. Adds 'vec.x' to 'x', adds 'vec.y' to 'y' and
	/// adds 'vec.z' to 'z'.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1 = ofVec3d(40, 20, 10); 
	/// ofVec3d v2 = ofVec3d(25, 50, 10);
	/// v1 += v2; // v1 is (65, 70, 20)
	/// ~~~~
	ofVec3d& operator+=( const ofVec3d& pnt );
    
	/// Adds a double value 'f' to 'x', 'y' and 'z' members.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1(2, 5, 1);
	/// v1 += 10; // (12, 15, 11)
	/// ~~~~
    ofVec3d& operator+=( const double f );
    
	/// Super easy vector subtraction. Returns a new vector
	/// ('x'-'vec.x','y'-'vec.y','z'-'vec.z').	
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1 = ofVec3d(40, 20, 10); 
	/// ofVec3d v2 = ofVec3d(25, 50, 10);
	/// ofVec3d v3 = v1 - v2; // v3 is (15, -30, 0)
	/// ~~~~
    ofVec3d  operator-( const ofVec3d& vec ) const;



	/// Returns a new vector with a double value 'f' subtracted from 'x', 'y' and 'z'
	/// members.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1(2, 5, 1);
	/// ofVec3d v2 = v1 - 10; // (-8, -5, -9)
	/// ~~~~
 	ofVec3d  operator-( const double f ) const;

	/// Returns a new 'ofVec3d' that is the inverted version (mirrored in X, Y and Z)
	/// of this vector.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1(2, 5, 1);
	/// ofVec3d v2 = -v1; // (-2, -5, -1)
	/// ~~~~
	/// 
    ofVec3d  operator-() const;

	/// Super easy subtraction assignment. Subtracts 'vec.x' from 'x', subtracts
	/// 'vec.y' from 'y' and subtracts 'vec.z' from 'z'.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1 = ofVec3d(40, 20, 10); 
	/// ofVec3d v2 = ofVec3d(25, 50, 10);
	/// v1 -= v2; // v1 is (15, -30, 0)
	/// ~~~~    
    ofVec3d& operator-=( const ofVec3d& vec );

	/// Subtract a double value 'f' from 'x', 'y', and 'z' members.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1(2, 5, 1);
	/// v1 -= 10; // (-8, -5, -9)
	/// ~~~~
	ofVec3d& operator-=( const double f );

	/// Returns a new vector ('x'*'vec.x','y'*'vec.y','z'*'vec.z').
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1 = ofVec3d(40, 20, 10); 
	/// ofVec3d v2 = ofVec3d(2, 4, 10);
	/// ofVec3d v3 = v1 * v2; // (80, 80, 100)
	/// ~~~~
	/// 
	/// Useful for scaling a 3D point by a non-uniform scale.
	/// 
    ofVec3d  operator*( const ofVec3d& vec ) const;

	/// Return a new 'ofVec3d' that is this vector scaled by multiplying 'x', 'y', 'z'
	/// members by 'f'.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1(2, 5, 1);
	/// ofVec3d v2 = v1 * 4; // (8, 20, 4)
	/// ~~~~
    ofVec3d  operator*( const double f ) const;
    
	/// Multiplies 'x' by 'vec.x', and multiplies 'y' by 'vec.y', and multiplies 'z'
	/// by 'vec.z'.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1 = ofVec3d(40, 20, 10); 
	/// ofVec3d v2 = ofVec3d(2, 4, 10);
	/// v1 *= v2; // v1 is now (80, 80, 100)
	/// ~~~~
	/// 
	/// Useful for scaling a 3D point by a non-uniform scale.
    ofVec3d& operator*=( const ofVec3d& vec );

	/// Scale this vector by multiplying 'x', 'y' and 'z' members by 'f'.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1(2, 5, 1);
	/// v1 *= 4; // (8, 20, 4)
	/// ~~~~
    ofVec3d& operator*=( const double f );
    
	/// Returns a new vector ('x'/'vec.x','y'/'vec.y','z'/'vec.z').
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1 = ofVec3d(40, 20, 10); 
	/// ofVec3d v2 = ofVec3d(2, 4, 10);
	/// ofVec3d v3 = v1 / v2; // (20, 5, 1)
	/// ~~~~
	/// 
	/// Useful for scaling a 3D point by a non-uniform scale.
    ofVec3d  operator/( const ofVec3d& vec ) const;
    
	/// Return a new 'ofVec3d' that is this vector scaled by dividing 'x', 'y'
	/// and 'z' members by 'f'.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1(2, 5, 1);
	/// ofVec3d v2 = v1 / 4; // (0.5, 1.25, 0.25)
	/// ~~~~
    ofVec3d  operator/( const double f ) const;
    
	/// Divides 'x' by 'vec.x', divides 'y' by 'vec.y', and divides 'z' by 'vec.z'.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1 = ofVec3d(40, 20, 10); 
	/// ofVec3d v2 = ofVec3d(2, 4, 10);
	/// v1 *= v2; // v1 is now (20, 5, 1)
	/// ~~~~
	/// 
	/// Useful for scaling a 3D point by a non-uniform scale.
    ofVec3d& operator/=( const ofVec3d& vec );

	/// Scale this vector by dividing 'x', 'y' and 'z' members by 'f'.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1(2, 5, 1);
	/// v1 /= 4; // (0.5, 1.25, 0.25)
	/// ~~~~
    ofVec3d& operator/=( const double f );
	
    /// \cond INTERNAL
	friend ostream& operator<<(ostream& os, const ofVec3d& vec);
	friend istream& operator>>(istream& is, ofVec3d& vec);
	/// \endcond

    /// \}
	
	//---------------------
	/// \name Simple manipulations
	/// \{

	/// \brief Return a new 'ofVec3d' that is the result of scaling this vector up or down so that it has
	/// the requested length.	
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1(3, 4); // length is 5
	/// ofVec3d v2 = v1.getScaled(15); // v2 is (9, 12), which has length of 15
	/// ~~~~
	/// 
    ofVec3d  getScaled( const double length ) const;


	/// \brief Scales this vector up or down so that it has the requested length.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1(3, 4); // length is 5
	/// v1.scale(15); // v1 is now (9, 12), which has length of 15
	/// ~~~~
    ofVec3d& scale( const double length );
    
	
	/// \brief Return a new 'ofVec3d' that is the result of rotating this vector by 'angle'
	/// degrees around the given axis.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1(1, 0, 0);
	/// // rotate v1 around the z axis
	/// ofVec3d v2 = v1.getRotated(45, ofVec3d(0, 0, 1)); // v2 is (√2, √2, 0)
	/// // rotate v1 around the y axis
	/// ofVec3d v3 = v1.getRotated(45, ofVec3d(0, 1, 0)); // v3 is (√2, 0, √2)
	/// ~~~~
	/// 
    ofVec3d  getRotated( double angle, const ofVec3d& axis ) const;
    
	/// \brief Make a copy of this vector and perform an Euler rotation of the copy around
	/// three axes: 'ax' degrees about the x axis, 'ay' about the y axis and 'az'
	/// about the z axis. Return the copy.
	/// 
	/// ~~~~~{.cpp}
	/// ofVec3d v1( 1, 0, 0 );
	/// ofVec3d v2 = v1.getRotated( 0, 0, 90 ); // v is now (0, 1, 0)
	/// ofVec3d v3 = v1.getRotated( 45, 0, 0 ); // v is now (0, √2, √2)
	/// ~~~~~
	/// 
	/// Watch out for gimbal lock when specifying multiple rotations in the same call.
	/// 
    ofVec3d  getRotated(double ax, double ay, double az) const;
    
	/// \brief Return a new 'ofVec3d' that is the result of rotating this vector by
	/// 'angle' degrees around the axis specified by 'axis', using 'pivot' as
	/// the origin of rotation.
    ofVec3d  getRotated( double angle, const ofVec3d& pivot, const ofVec3d& axis ) const;
    
    
    /// \brief Return a new 'ofVec3d' that is the result of rotating this 
    /// vector by 'angle' radians around the given axis.
    ///
    /// ~~~~{.cpp}
    /// ofVec3d v1(1, 0, 0);
    /// // rotate v1 around the z axis
    /// ofVec3d v2 = v1.getRotated(PI/4, ofVec3d(0, 0, 1)); // v2 is (√2, √2, 0)
    /// // rotate v1 around the y axis
    /// ofVec3d v3 = v1.getRotated(PI/4, ofVec3d(0, 1, 0)); // v3 is (√2, 0, √2)
    /// ~~~~
    ofVec3d  getRotatedRad( double angle, const ofVec3d& axis ) const;

	/// \brief Make a copy of this vector and perform an Euler rotation of the copy around
	/// three axes: 'ax' radians about the x axis, 'ay' about the y axis and 'az'
	/// about the z axis. Return the copy.
	///
	/// ~~~~~{.cpp}
	/// ofVec3d v1( 1, 0, 0 );
	/// ofVec3d v2 = v1.getRotatedRad( 0, 0, HALF_PI ); // v is now (0, 1, 0)
	/// ofVec3d v3 = v1.getRotatedRad( PI/4, 0, 0 ); // v is now (0, √2, √2)
	/// ~~~~~
	/// 
	/// Watch out for gimbal lock when specifying multiple rotations in the same call.
    /// 
	ofVec3d  getRotatedRad(double ax, double ay, double az) const;
  	
  	/// \brief Return a new 'ofVec3d' that is the result of rotating this vector by 'angle' radians
    /// around the axis specified by 'axis', using 'pivot' as the origin of rotation.
    ofVec3d   getRotatedRad( double angle, const ofVec3d& pivot, const ofVec3d& axis ) const;
    	
 	/// \brief Return a new 'ofVec3d' that is the result of rotating this vector by
	/// 'angle' degrees around the given axis.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1(1, 0, 0);
	/// // rotate v1 around the z axis
	/// v1.rotate(45, ofVec3d(0, 0, 1)); // v2 is (√2, √2, 0)
	/// 
	/// v1.set(1, 0, 0);
	/// // then rotate around the y axis
	/// v1.rotate(45, ofVec3d(0, 1, 0)); // v3 is (√2, 0, √2)
	/// ~~~~
	ofVec3d& rotate( double angle, const ofVec3d& axis );

	/// \brief Perform an Euler rotation of this vector around three axes: 'ax' degrees about
	/// the x axis, 'ay' about the y axis and 'az' about the z axis.
	/// 
	/// ~~~~~{.cpp}
	/// ofVec3d v( 1, 0, 0 );
	/// v.rotate( 0, 0, 90 ); // v is now (0, 1, 0)
	/// v.rotate( 45, 0, 0 ); // v is now (0, √2, √2)
	/// ~~~~~
	/// 
	/// Watch out for gimbal lock when specifying multiple rotations in the same call.
	/// 
    ofVec3d& rotate(double ax, double ay, double az);

	/// \brief Rotate this vector by 'angle' degrees around the axis specified by 'axis',
	/// using 'pivot' as the origin of rotation.
	ofVec3d& rotate( double angle, const ofVec3d& pivot, const ofVec3d& axis );
    

	/// \brief Return a new 'ofVec3d' that is the result of rotating this vector by 'angle'
	/// degrees around the given axis.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1(1, 0, 0);
	/// // rotate v1 around the z axis
	/// v1.rotate(45, ofVec3d(0, 0, 1)); // v2 is (√2, √2, 0)
	/// 
	/// v1.set(1, 0, 0);
	/// // then rotate around the y axis
	/// v1.rotate(45, ofVec3d(0, 1, 0)); // v3 is (√2, 0, √2)
	/// ~~~~
    ofVec3d& rotateRad( double angle, const ofVec3d& axis );
    
	/// \brief Perform an Euler rotation of this vector around three axes: 'ax' radians about
	/// the x axis, 'ay' about the y axis and 'az' about the z axis.
	/// 
	/// ~~~~~{.cpp}
	/// ofVec3d v( 1, 0, 0 );
	/// v.rotateRad( 0, 0, HALF_PI ); // v is now (0, 1, 0)
	/// v.rotateRad( PI/4, 0, 0 ); // v is now (0, √2, √2)
	/// ~~~~~
	/// 
	/// Watch out for gimbal lock when specifying multiple rotations in the same call.
    ofVec3d& rotateRad(double ax, double ay, double az);
    
	/// \brief Rotate this vector by 'angle' radians around the axis specified by 'axis',
	/// using 'pivot' as the origin of rotation.
    ofVec3d& rotateRad( double angle, const ofVec3d& pivot, const ofVec3d& axis );    
    
    	
	
	/// \brief Return a new 'ofVec3d' calculated by copying this vector and then mapping from
	/// its default coordinate system -- origin (0,0,0), X direction (1,0,0), Y
	/// direction (0,1,0), Z direction (0,0,1) -- to a new coordinate system defined
	/// with origin at 'origin', X direction 'vx', and Y direction 'vy', and Z
	/// direction 'vz'.
	/// 
	/// *In most cases you want 'vx', 'vy', and 'vz' to be perpendicular and of unit
	/// length; if they are not perpendicular you will have shearing as part of the
	/// mapping, and if they are not of unit length you will have scaling as part of
	/// the mapping.*
	/// 
	ofVec3d getMapped( const ofVec3d& origin,
					  const ofVec3d& vx,
					  const ofVec3d& vy,
					  const ofVec3d& vz ) const;

	/// \brief Map this vector from its default coordinate system -- origin (0,0,0), X
	/// direction (1,0,0), Y direction (0,1,0), Z direction (0,0,1) -- to a new
	/// coordinate system defined with origin at 'origin', X direction 'vx', and Y
	/// direction 'vy', and Z direction 'vz'.
	///
	/// *In most cases you want 'vx', 'vy', and 'vz' to be perpendicular and of
	/// unit length; if they are not perpendicular you will have shearing as part
	/// of the mapping, and if they are not of unit length you will have scaling
	/// as part of the mapping.*
	/// 
    ofVec3d& map( const ofVec3d& origin,
				 const ofVec3d& vx,
				 const ofVec3d& vy,
				 const ofVec3d& vz );
	
	

    /// \}
	
	
	//---------------------
	/// \name Distance
	/// \{


	/// \brief Treats both this vector and 'pnt' as points in 3D space, and
	/// calculates and returns the distance between them.	
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d p1(3, 4, 2);
	/// ofVec3d p2(6, 8, 5);
	/// double distance = p1.distance( p2 ); // distance is 5.8310
	/// ~~~~
	/// 	
	/// 'distance' involves a square root calculation, which is one of the
	/// slowest things you can do in programming. If you don't need an exact
	/// number but rather just a rough idea of distance (for example when
	/// finding the shortest distance of a bunch of points to a reference
	/// point, where it doesn't matter exactly what the distances are, you
	/// just want the shortest), you can use squareDistance() instead.
	double distance( const ofVec3d& pnt) const;
    
	/// \brief Treats both this vector and 'pnt' as points in 3D space, and calculates and
	/// returns the squared distance between them.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d p1(3, 4, 2);
	/// ofVec3d p2(6, 8, 5);
	/// double distance = p1.distance( p2 ); // distance is 5.8310
	/// ~~~~
	/// 
	/// Use as a much faster alternative to distance() if you don't need
	/// to know an exact number but rather just a rough idea of distance (for example
	/// when finding the shortest distance of a bunch of points to a reference point,
	/// where it doesn't matter exactly what the distances are, you just want the
	/// shortest). It avoids the square root calculation that is ordinarily required
	/// to calculate a length.
	/// 
    double squareDistance( const ofVec3d& pnt ) const;
	
		
	/// \}

	//---------------------
	/// \name Interpolation
	/// \{

	/// \brief Perform a linear interpolation of this vector's position towards 'pnt'
	/// and return the interpolated vector without altering the original. 'p'
	/// controls the amount to move towards 'pnt'. 'p' is normally between 0
	/// and 1 and where 0 means stay the original position and 1 means move
	/// all the way to 'pnt', but you can also have 'p' greater than 1
	/// overshoot 'pnt', or less than 0 to move backwards away from 'pnt'.	
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1(0, 5, 0);
	/// ofVec3d v2(10, 10, 20);
	/// ofVec3d v3 = v1.getInterpolated(p2, 0.5); // v3 is (5, 7.5, 10)
	/// ofVec3d v4 = v1.getInterpolated(p2, 0.8); // v4 is (8, 9, 16)
	/// ~~~~
	/// 
    ofVec3d   getInterpolated( const ofVec3d& pnt, double p ) const;

	/// \brief Perform a linear interpolation of this vector's position towards
	/// 'pnt'. 'p' controls the amount to move towards 'pnt'. 'p' is normally
	/// between 0 and 1 and where 0 means stay the original position and 1
	/// means move all the way to 'pnt', but you can also have 'p' greater
	/// than 1 overshoot 'pnt', or less than 0 to move backwards away from
	/// 'pnt'.	
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1( 0, 5, 0 );
	/// ofVec3d v2( 10, 10, 20 );
	/// // go go gadget zeno
	/// v1.interpolate( v2, 0.5 ); // v1 is now (5, 7.5, 10)
	/// v1.interpolate( v2, 0.5 ); // v1 is now (7.5, 8.75, 15)
	/// v1.interpolate( v2, 0.5 ); // v1 is now (8.75, 9.375, 17.5)
	/// v1.interpolate( v2, 0.5 ); // v1 is now (9.375, 9.6875, 18.75)
	/// ~~~~
    ofVec3d&  interpolate( const ofVec3d& pnt, double p );
    
	/// \brief Calculate and return the midpoint between this vector and 'pnt'.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1(5, 0, 0);
	/// ofVec3d v2(10, 10, 20);
	/// ofVec3d mid = v1.getMiddle(v2); // mid gets (7.5, 5, 10)
	/// ~~~~
    ofVec3d   getMiddle( const ofVec3d& pnt ) const;

	/// Set this vector to the midpoint between itself and 'pnt'.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1( 0, 5, 0 );
	/// ofVec3d v2( 10, 10, 20);
	/// // go go gadget zeno
	/// v1.middle( v2 ); // v1 is now (5, 7.5, 10)
	/// v1.middle( v2 ); // v1 is now (7.5, 8.75, 15)
	/// v1.middle( v2 ); // v1 is now (8.75, 9.375, 17.5)
	/// v1.middle( v2 ); // v1 is now (9.375, 9.6875, 18.75)
	/// ~~~~
    ofVec3d&  middle( const ofVec3d& pnt );
    
	/// \brief Sets this vector to be the average (*centre of gravity* or
	/// *centroid*) of a given array of 'ofVec3d's. 'points' is the array of
	/// 'ofVec3d's and 'num' specifies the number of 'ofVec3d's in the array.	
	/// 
	/// ~~~~{.cpp}
	/// int numPoints = 10;
	/// ofVec3d points[numPoints];
	/// for ( int i=0; i<numPoints; i++ ) {
	/// 	points[i].set( ofRandom(0,100), ofRandom(0,100), ofRandom(0,100) );
	/// }
	/// ofVec3d centroid;
	/// centroid.average( points, numPoints ); 
	/// // centroid now is the centre of gravity/average of all the random points
	/// ~~~~
	ofVec3d&  average( const ofVec3d* points, int num );
    
    /// \}

    //---------------------
	/// \name Limit
	/// \{
	
	/// \brief Return a normalized copy of this vector. 
	/// 
	/// *Normalization* means to scale the vector so that its length
	/// (magnitude) is exactly 1, at which stage all that is left is the
	/// direction. A normalized vector is usually called a *unit vector*, and
	/// can be used to represent a pure direction (heading).	
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1(5, 0, 0);
	/// ofVec3d v1Normalized = v1.getNormalized(); // (1, 0, 0)
	/// ofVec3d v2(5, 0, 5);
	/// ofVec3d v2Normalized = v2.getNormalized(); // (√2, 0, √2)
	/// ~~~~
	ofVec3d  getNormalized() const;
   
	/// \brief Normalize the vector.
	/// 
	/// *Normalizing* means to scale the vector so that its length (magnitude)
	/// is exactly 1, at which stage all that is left is the direction. A
	/// normalized vector is usually called a *unit vector*, and can be used
	/// to represent a pure direction (heading).	
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1(5, 0, 0);
	/// v1.normalize(); // v2 is now (1, 0, 0)
	/// ofVec3d v2(5, 0, 5);
	/// v2.normalize(); // v2 is now (√2, 0, √2)
	/// ~~~~
	/// 
  	ofVec3d& normalize();
	
	
	/// \brief Return a copy of this vector with its length (magnitude) restricted to a
	/// maximum of 'max' units by scaling down if necessary.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1(5, 0, 1); // length is about 5.1
	/// ofVec3d v2(2, 0, 1); // length is about 2.2
	/// ofVec3d v1Limited = v1.getLimited(3); 
	/// // v1Limited is (2.9417, 0, 0.58835) which has length of 3 in the same direction as v1
	/// ofVec3d v2Limited = v2.getLimited(3);
	/// // v2Limited is (2, 0, 1) (same as v2)
	/// ~~~~
	ofVec3d  getLimited(double max) const;

	/// \brief Restrict the length (magnitude) of this vector to a maximum of 'max'
	/// units by scaling down if necessary.	
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1(5, 0, 1); // length is about 5.1
	/// ofVec3d v2(2, 0, 1); // length is about 2.2
	/// v1.limit(3); 
	/// // v1 is now (2.9417, 0, 0.58835) which has length of 3 in the same direction as at initialization
	/// v2.limit(3);
	/// // v2 is unchanged
	/// ~~~~
    ofVec3d& limit(double max);

	
	/// \}

	//---------------------
	/// \name Measurement
	/// \{


	/// Return the length (magnitude) of this vector.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v(3, 4, 1);
	/// double len = v.length(); // len is 5.0990
	/// ~~~~
	/// 
	/// `length' involves a square root calculation, which is one of the
	/// slowest things you can do in programming. If you don't need an exact
	/// number but rather just a rough idea of a length (for example when
	/// finding the shortest distance of a bunch of points to a reference
	/// point, where it doesn't matter exactly what the lengths are, you just
	/// want the shortest), you can use lengthSquared() instead.
	///    
    double length() const;

    /// \brief Return the squared length (squared magnitude) of this vector.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v(3, 4, 1);
	/// double len = v.length(); // len is 5.0990
	/// ~~~~
	/// 
	/// Use as a much faster alternative to length() if you don't need
	/// to know an accurate length but rather just a rough idea of a length (for
	/// example when finding the shortest distance of a bunch of points to a
	/// reference point, where it doesn't matter exactly what the lengths are, you
	/// just want the shortest). It avoids the square root calculation that is
	/// ordinarily required to calculate a length.
    double lengthSquared() const;

	/// \brief Calculate and return the coplanar angle in degrees between this vector
	/// and 'vec'.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1(1,0,0);
	/// ofVec3d v2(0,1,0);
	/// double angle = v1.angle(v2); // angle is 90
	/// ~~~~    
	double angle( const ofVec3d& vec ) const;
    
	/// \brief Calculate and return the coplanar angle in radians between this 
	/// vector and 'vec'.
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d v1(1,0,0);
	/// ofVec3d v2(0,1,0);
	/// double angle = v1.angle(v2); // angle is 90
	/// ~~~~
	/// 
    double angleRad( const ofVec3d& vec ) const;
	

	/// \}

	//---------------------
	/// \name Perpendicular
	/// \{

    
	/// \brief Construct a plane using this vector and 'vec' (by finding the plane that both
	/// lectors lie on), and return the vector that is perpendicular to that plane
	/// (the normal to that plane).
	/// 
	/// ~~~~{.cpp}
	/// ofSetLogLevel(OF_LOG_NOTICE);
	/// ofVec3d v1(1,0,0);
	/// ofVec3d v2(0,1,0);
	/// ofVec3d p = v1.getPerpendicular(v2);
	/// ofLog(OF_LOG_NOTICE, "%1.1f, %1.1f, %1.1f\n", p.x, p.y, p.z);
	/// // prints "0.0, 0.0, 1.0"
	/// ~~~~
	/// 
	/// This method is usually used to calculate a normal vector to a surface, which
	/// can then be used to calculate lighting, collisions, and other 3D effects.
	/// 
	ofVec3d  getPerpendicular( const ofVec3d& vec ) const;


	/// \brief Construct a plane using this vector and 'vec' (by finding the plane that both
	/// lie on), and set our 'x', 'y' and 'z' to be the vector that is perpendicular
	/// to the constructed plane (the normal to the plane).
	/// 
	/// ~~~~{.cpp}
	/// ofSetLogLevel(OF_LOG_NOTICE);
	/// ofVec3d v1(1,0,0);
	/// ofVec3d v2(0,1,0); 
	/// v1.perpendicular(v2); 
	/// ofLog(OF_LOG_NOTICE, "%1.1f, %1.1f, %1.1f\n", v1.x, v1.y, v1.z);
	/// // prints "0.0, 0.0, 1.0'
	/// ~~~~
	/// 
	/// This method is usually used to calculate a normal vector to a surface, which
	/// can then be used to calculate lighting, collisions, and other 3D effects.
	/// 
    ofVec3d& perpendicular( const ofVec3d& vec );
	
	

	/// \brief Returns the cross product (vector product) of this vector and 'vec'. This is a
	/// binary operation on two vectors in three-dimensional space, which results in a
	/// vector that is perpendicular to both of the vectors being multiplied, and
	/// normal to the plane containing them. The name *cross product* is derived from
	/// the cross symbol X that is often used to designate this operation; the
	/// alternative name *vector product* emphasizes the vector (rather than scalar)
	/// nature of the result.
	/// 
	/// ![CROSS](math/crossproduct.png)
	/// Image courtesy of Wikipedia
    ofVec3d  getCrossed( const ofVec3d& vec ) const;
    
	/// Set this vector to the cross product (vector product) of itself and
	/// 'vec'. This is a binary operation on two vectors in three-dimensional
	/// space, which results in a vector that is perpendicular to both of the
	/// vectors being multiplied, and normal to the plane containing them. The
	/// name *cross product* is derived from the cross symbol X that is often
	/// used to designate this operation; the alternative name *vector
	/// product* emphasizes the vector (rather than scalar) nature of the
	/// result.
    ofVec3d& cross( const ofVec3d& vec );

	
	/// \brief Calculate and return the dot product of this vector with 'vec'.
	/// 
	/// *Dot product* (less commonly known as *Euclidean inner product*)
	/// expresses the angular relationship between two vectors. In other
	/// words it is a measure of how *parallel* two vectors are. If they are
	/// completely perpendicular the dot product is 0; if they are completely
	/// parallel their dot product is either 1 if they are pointing in the
	/// same direction, or -1 if they are pointing in opposite directions.	
	/// 
	/// ![DOT](math/dotproduct.png)
	/// Image courtesy of Wikipedia
	/// 
	/// ~~~~{.cpp}
	/// ofVec3d a1(1, 0, 0);
	/// ofVec3d b1(0, 0, 1); // 90 degree angle to a1
	/// dot = a1.dot(b1); // dot is 0, ie cos(90)
	/// 
	/// ofVec3d a2(1, 0, 0); 
	/// ofVec3d b2(1, 1, 0); // 45 degree angle to a2
	/// b2.normalize(); // vectors should to be unit vectors (normalized)
	/// double dot = a2.dot(b2); // dot is 0.707, ie cos(45)
	/// 
	/// ofVec3d a3(0, 1, 0);
	/// ofVec3d b3(0, -1, 0); // 180 degree angle to a3
	/// dot = a3.dot(b3); // dot is -1, ie cos(180)
	/// ~~~~
	/// 
    double dot( const ofVec3d& vec ) const;
	
	/// \}


	
    //-----------------------------------------------
    // this methods are deprecated in 006 please use:
	/// \cond INTERNAL

    // getScaled
    OF_DEPRECATED_MSG("Use member method getScaled() instead.", ofVec3d rescaled( const double length ) const);
	
    // scale
    OF_DEPRECATED_MSG("Use member method scale() instead.", ofVec3d& rescale( const double length ));
	
    // getRotated
    OF_DEPRECATED_MSG("Use member method getRotated() instead.", ofVec3d rotated( double angle, const ofVec3d& axis ) const);
	
    // getRotated should this be const???
    OF_DEPRECATED_MSG("Use member method getRotated() instead.", ofVec3d rotated(double ax, double ay, double az));
	
    // getNormalized
    OF_DEPRECATED_MSG("Use member method getNormalized() instead.", ofVec3d normalized() const);
	
    // getLimited
    OF_DEPRECATED_MSG("Use member method getLimited() instead.", ofVec3d limited(double max) const);
	
    // getCrossed
    OF_DEPRECATED_MSG("Use member method getCrossed() instead.", ofVec3d crossed( const ofVec3d& vec ) const);
	
    // getPerpendicular
    OF_DEPRECATED_MSG("Use member method getPerpendicular() instead.", ofVec3d perpendiculared( const ofVec3d& vec ) const);
    
    // use getMapped
    OF_DEPRECATED_MSG("Use member method getMapped() instead.", ofVec3d mapped( const ofVec3d& origin,
					const ofVec3d& vx,
					const ofVec3d& vy,
					const ofVec3d& vz ) const);
	
    // use squareDistance
    OF_DEPRECATED_MSG("Use member method squareDistance() instead.", double  distanceSquared( const ofVec3d& pnt ) const);
	
    // use getInterpolated
    OF_DEPRECATED_MSG("Use member method getInterpolated() instead.", ofVec3d interpolated( const ofVec3d& pnt, double p ) const);
	
    // use getMiddle
    OF_DEPRECATED_MSG("Use member method getMiddle() instead.", ofVec3d middled( const ofVec3d& pnt ) const);
    
    // use getRotated
    OF_DEPRECATED_MSG("Use member method getRotated() instead.", ofVec3d rotated( double angle,
						const ofVec3d& pivot,
						const ofVec3d& axis ) const);    

    // return all zero vector
    static ofVec3d zero() { return ofVec3d(0, 0, 0); }
    
    // return all one vector
    static ofVec3d one() { return ofVec3d(1, 1, 1); }

    /// \endcond

};


/// \cond INTERNAL


// Non-Member operators
//
//
ofVec3d operator+( double f, const ofVec3d& vec );
ofVec3d operator-( double f, const ofVec3d& vec );
ofVec3d operator*( double f, const ofVec3d& vec );
ofVec3d operator/( double f, const ofVec3d& vec );


/////////////////
// Implementation
/////////////////


inline ofVec3d::ofVec3d( const ofVec2d& vec ):x(vec.x), y(vec.y), z(0) {}
inline ofVec3d::ofVec3d( const ofVec4d& vec ):x(vec.x), y(vec.y), z(vec.z) {}
inline ofVec3d::ofVec3d(): x(0), y(0), z(0) {}
inline ofVec3d::ofVec3d( double _all ): x(_all), y(_all), z(_all) {}
inline ofVec3d::ofVec3d( double _x, double _y, double _z ):x(_x), y(_y), z(_z) {}


// Getters and Setters.
//
//
inline void ofVec3d::set( double _scalar ) {
	x = _scalar;
	y = _scalar;
	z = _scalar;
}

inline void ofVec3d::set( double _x, double _y, double _z ) {
	x = _x;
	y = _y;
	z = _z;
}

inline void ofVec3d::set( const ofVec3d& vec ) {
	x = vec.x;
	y = vec.y;
	z = vec.z;
}


// Check similarity/equality.
//
//
inline bool ofVec3d::operator==( const ofVec3d& vec ) const {
	return (x == vec.x) && (y == vec.y) && (z == vec.z);
}

inline bool ofVec3d::operator!=( const ofVec3d& vec ) const {
	return (x != vec.x) || (y != vec.y) || (z != vec.z);
}

inline bool ofVec3d::match( const ofVec3d& vec, double tolerance ) const{
	return (fabs(x - vec.x) < tolerance)
	&& (fabs(y - vec.y) < tolerance)
	&& (fabs(z - vec.z) < tolerance);
}

/**
 * Checks if vectors look in the same direction.
 */
inline bool ofVec3d::isAligned( const ofVec3d& vec, double tolerance ) const {
	double angle = this->angle( vec );
	return  angle < tolerance;
}
inline bool ofVec3d::align( const ofVec3d& vec, double tolerance ) const {
    return isAligned( vec, tolerance );
}

inline bool ofVec3d::isAlignedRad( const ofVec3d& vec, double tolerance ) const {
	double angle = this->angleRad( vec );
	return  angle < tolerance;
}
inline bool ofVec3d::alignRad( const ofVec3d& vec, double tolerance ) const {
    return isAlignedRad( vec, tolerance );
}


// Operator overloading for ofVec3d
//
//

inline ostream& operator<<(ostream& os, const ofVec3d& vec) {
	os << vec.x << ", " << vec.y << ", " << vec.z;
	return os;
}

inline istream& operator>>(istream& is, ofVec3d& vec) {
	is >> vec.x;
	is.ignore(2);
	is >> vec.y;
	is.ignore(2);
	is >> vec.z;
	return is;
}

inline ofVec3d ofVec3d::operator+( const ofVec3d& pnt ) const {
	return ofVec3d( x+pnt.x, y+pnt.y, z+pnt.z );
}

inline ofVec3d& ofVec3d::operator+=( const ofVec3d& pnt ) {
	x+=pnt.x;
	y+=pnt.y;
	z+=pnt.z;
	return *this;
}

inline ofVec3d ofVec3d::operator-( const ofVec3d& vec ) const {
	return ofVec3d( x-vec.x, y-vec.y, z-vec.z );
}

inline ofVec3d& ofVec3d::operator-=( const ofVec3d& vec ) {
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	return *this;
}

inline ofVec3d ofVec3d::operator*( const ofVec3d& vec ) const {
	return ofVec3d( x*vec.x, y*vec.y, z*vec.z );
}

inline ofVec3d& ofVec3d::operator*=( const ofVec3d& vec ) {
	x*=vec.x;
	y*=vec.y;
	z*=vec.z;
	return *this;
}

inline ofVec3d ofVec3d::operator/( const ofVec3d& vec ) const {
	return ofVec3d( vec.x!=0 ? x/vec.x : x , vec.y!=0 ? y/vec.y : y, vec.z!=0 ? z/vec.z : z );
}

inline ofVec3d& ofVec3d::operator/=( const ofVec3d& vec ) {
	vec.x!=0 ? x/=vec.x : x;
	vec.y!=0 ? y/=vec.y : y;
	vec.z!=0 ? z/=vec.z : z;
	return *this;
}

inline ofVec3d ofVec3d::operator-() const {
	return ofVec3d( -x, -y, -z );
}


//operator overloading for double
//
//
//inline void ofVec3d::operator=( const double f){
//	x = f;
//	y = f;
//	z = f;
//}

inline ofVec3d ofVec3d::operator+( const double f ) const {
	return ofVec3d( x+f, y+f, z+f);
}

inline ofVec3d& ofVec3d::operator+=( const double f ) {
	x += f;
	y += f;
	z += f;
	return *this;
}

inline ofVec3d ofVec3d::operator-( const double f ) const {
	return ofVec3d( x-f, y-f, z-f);
}

inline ofVec3d& ofVec3d::operator-=( const double f ) {
	x -= f;
	y -= f;
	z -= f;
	return *this;
}

inline ofVec3d ofVec3d::operator*( const double f ) const {
	return ofVec3d( x*f, y*f, z*f );
}

inline ofVec3d& ofVec3d::operator*=( const double f ) {
	x*=f;
	y*=f;
	z*=f;
	return *this;
}

inline ofVec3d ofVec3d::operator/( const double f ) const {
	if(f == 0) return ofVec3d( x, y, z);
	
	return ofVec3d( x/f, y/f, z/f );
}

inline ofVec3d& ofVec3d::operator/=( const double f ) {
	if(f == 0) return *this;
	
	x/=f;
	y/=f;
	z/=f;
	return *this;
}


//Scale
//
//
inline ofVec3d ofVec3d::rescaled( const double length ) const {
	return getScaled(length);
}
inline ofVec3d ofVec3d::getScaled( const double length ) const {
	double l = (double)sqrt(x*x + y*y + z*z);
	if( l > 0 )
		return ofVec3d( (x/l)*length, (y/l)*length, (z/l)*length );
	else
		return ofVec3d();
}
inline ofVec3d& ofVec3d::rescale( const double length ) {
	return scale(length);
}
inline ofVec3d& ofVec3d::scale( const double length ) {
	double l = (double)sqrt(x*x + y*y + z*z);
	if (l > 0) {
		x = (x/l)*length;
		y = (y/l)*length;
		z = (z/l)*length;
	}
	return *this;
}



// Rotation
//
//
inline ofVec3d ofVec3d::rotated( double angle, const ofVec3d& axis ) const {
	return getRotated(angle, axis);
}
inline ofVec3d ofVec3d::getRotated( double angle, const ofVec3d& axis ) const {
	ofVec3d ax = axis.getNormalized();
	double a = (double)(angle*DEG_TO_RAD);
	double sina = sin( a );
	double cosa = cos( a );
	double cosb = 1.0 - cosa;
	
	return ofVec3d( x*(ax.x*ax.x*cosb + cosa)
				   + y*(ax.x*ax.y*cosb - ax.z*sina)
				   + z*(ax.x*ax.z*cosb + ax.y*sina),
				   x*(ax.y*ax.x*cosb + ax.z*sina)
				   + y*(ax.y*ax.y*cosb + cosa)
				   + z*(ax.y*ax.z*cosb - ax.x*sina),
				   x*(ax.z*ax.x*cosb - ax.y*sina)
				   + y*(ax.z*ax.y*cosb + ax.x*sina)
				   + z*(ax.z*ax.z*cosb + cosa) );
}

inline ofVec3d ofVec3d::getRotatedRad( double angle, const ofVec3d& axis ) const {
	ofVec3d ax = axis.getNormalized();
	double a = angle;
	double sina = sin( a );
	double cosa = cos( a );
	double cosb = 1.0 - cosa;
	
	return ofVec3d( x*(ax.x*ax.x*cosb + cosa)
				   + y*(ax.x*ax.y*cosb - ax.z*sina)
				   + z*(ax.x*ax.z*cosb + ax.y*sina),
				   x*(ax.y*ax.x*cosb + ax.z*sina)
				   + y*(ax.y*ax.y*cosb + cosa)
				   + z*(ax.y*ax.z*cosb - ax.x*sina),
				   x*(ax.z*ax.x*cosb - ax.y*sina)
				   + y*(ax.z*ax.y*cosb + ax.x*sina)
				   + z*(ax.z*ax.z*cosb + cosa) );
}

inline ofVec3d& ofVec3d::rotate( double angle, const ofVec3d& axis ) {
	ofVec3d ax = axis.getNormalized();
	double a = (double)(angle*DEG_TO_RAD);
	double sina = sin( a );
	double cosa = cos( a );
	double cosb = 1.0 - cosa;
	
	double nx = x*(ax.x*ax.x*cosb + cosa)
	+ y*(ax.x*ax.y*cosb - ax.z*sina)
	+ z*(ax.x*ax.z*cosb + ax.y*sina);
	double ny = x*(ax.y*ax.x*cosb + ax.z*sina)
	+ y*(ax.y*ax.y*cosb + cosa)
	+ z*(ax.y*ax.z*cosb - ax.x*sina);
	double nz = x*(ax.z*ax.x*cosb - ax.y*sina)
	+ y*(ax.z*ax.y*cosb + ax.x*sina)
	+ z*(ax.z*ax.z*cosb + cosa);
	x = nx; y = ny; z = nz;
	return *this;
}


inline ofVec3d& ofVec3d::rotateRad(double angle, const ofVec3d& axis ) {
	ofVec3d ax = axis.getNormalized();
	double a = angle;
	double sina = sin( a );
	double cosa = cos( a );
	double cosb = 1.0 - cosa;
	
	double nx = x*(ax.x*ax.x*cosb + cosa)
	+ y*(ax.x*ax.y*cosb - ax.z*sina)
	+ z*(ax.x*ax.z*cosb + ax.y*sina);
	double ny = x*(ax.y*ax.x*cosb + ax.z*sina)
	+ y*(ax.y*ax.y*cosb + cosa)
	+ z*(ax.y*ax.z*cosb - ax.x*sina);
	double nz = x*(ax.z*ax.x*cosb - ax.y*sina)
	+ y*(ax.z*ax.y*cosb + ax.x*sina)
	+ z*(ax.z*ax.z*cosb + cosa);
	x = nx; y = ny; z = nz;
	return *this;
}

// const???
inline ofVec3d ofVec3d::rotated(double ax, double ay, double az) {
	return getRotated(ax,ay,az);
}

inline ofVec3d ofVec3d::getRotated(double ax, double ay, double az) const {
	double a = (double)cos(DEG_TO_RAD*(ax));
	double b = (double)sin(DEG_TO_RAD*(ax));
	double c = (double)cos(DEG_TO_RAD*(ay));
	double d = (double)sin(DEG_TO_RAD*(ay));
	double e = (double)cos(DEG_TO_RAD*(az));
	double f = (double)sin(DEG_TO_RAD*(az));
	
	double nx = c * e * x - c * f * y + d * z;
	double ny = (a * f + b * d * e) * x + (a * e - b * d * f) * y - b * c * z;
	double nz = (b * f - a * d * e) * x + (a * d * f + b * e) * y + a * c * z;
	
	return ofVec3d( nx, ny, nz );
}

inline ofVec3d ofVec3d::getRotatedRad(double ax, double ay, double az) const {
	double a = cos(ax);
	double b = sin(ax);
	double c = cos(ay);
	double d = sin(ay);
	double e = cos(az);
	double f = sin(az);
	
	double nx = c * e * x - c * f * y + d * z;
	double ny = (a * f + b * d * e) * x + (a * e - b * d * f) * y - b * c * z;
	double nz = (b * f - a * d * e) * x + (a * d * f + b * e) * y + a * c * z;
	
	return ofVec3d( nx, ny, nz );
}


inline ofVec3d& ofVec3d::rotate(double ax, double ay, double az) {
	double a = (double)cos(DEG_TO_RAD*(ax));
	double b = (double)sin(DEG_TO_RAD*(ax));
	double c = (double)cos(DEG_TO_RAD*(ay));
	double d = (double)sin(DEG_TO_RAD*(ay));
	double e = (double)cos(DEG_TO_RAD*(az));
	double f = (double)sin(DEG_TO_RAD*(az));
	
	double nx = c * e * x - c * f * y + d * z;
	double ny = (a * f + b * d * e) * x + (a * e - b * d * f) * y - b * c * z;
	double nz = (b * f - a * d * e) * x + (a * d * f + b * e) * y + a * c * z;
	
	x = nx; y = ny; z = nz;
	return *this;
}


inline ofVec3d& ofVec3d::rotateRad(double ax, double ay, double az) {
	double a = cos(ax);
	double b = sin(ax);
	double c = cos(ay);
	double d = sin(ay);
	double e = cos(az);
	double f = sin(az);
	
	double nx = c * e * x - c * f * y + d * z;
	double ny = (a * f + b * d * e) * x + (a * e - b * d * f) * y - b * c * z;
	double nz = (b * f - a * d * e) * x + (a * d * f + b * e) * y + a * c * z;
	
	x = nx; y = ny; z = nz;
	return *this;
}


// Rotate point by angle (deg) around line defined by pivot and axis.
//
//
inline ofVec3d ofVec3d::rotated( double angle,
								const ofVec3d& pivot,
								const ofVec3d& axis ) const{
	return getRotated(angle, pivot, axis);
}

inline ofVec3d ofVec3d::getRotated( double angle,
								   const ofVec3d& pivot,
								   const ofVec3d& axis ) const
{
	ofVec3d ax = axis.getNormalized();
	double tx = x - pivot.x;
	double ty = y - pivot.y;
	double tz = z - pivot.z;
	
	double a = (double)(angle*DEG_TO_RAD);
	double sina = sin( a );
	double cosa = cos( a );
	double cosb = 1.0 - cosa;
	
	double xrot = tx*(ax.x*ax.x*cosb + cosa)
	+ ty*(ax.x*ax.y*cosb - ax.z*sina)
	+ tz*(ax.x*ax.z*cosb + ax.y*sina);
	double yrot = tx*(ax.y*ax.x*cosb + ax.z*sina)
	+ ty*(ax.y*ax.y*cosb + cosa)
	+ tz*(ax.y*ax.z*cosb - ax.x*sina);
	double zrot = tx*(ax.z*ax.x*cosb - ax.y*sina)
	+ ty*(ax.z*ax.y*cosb + ax.x*sina)
	+ tz*(ax.z*ax.z*cosb + cosa);
	
	
	return ofVec3d( xrot+pivot.x, yrot+pivot.y, zrot+pivot.z );
}


inline ofVec3d ofVec3d::getRotatedRad( double angle,
									  const ofVec3d& pivot,
									  const ofVec3d& axis ) const
{
	ofVec3d ax = axis.getNormalized();
	double tx = x - pivot.x;
	double ty = y - pivot.y;
	double tz = z - pivot.z;
	
	double a = angle;
	double sina = sin( a );
	double cosa = cos( a );
	double cosb = 1.0 - cosa;
	
	double xrot = tx*(ax.x*ax.x*cosb + cosa)
	+ ty*(ax.x*ax.y*cosb - ax.z*sina)
	+ tz*(ax.x*ax.z*cosb + ax.y*sina);
	double yrot = tx*(ax.y*ax.x*cosb + ax.z*sina)
	+ ty*(ax.y*ax.y*cosb + cosa)
	+ tz*(ax.y*ax.z*cosb - ax.x*sina);
	double zrot = tx*(ax.z*ax.x*cosb - ax.y*sina)
	+ ty*(ax.z*ax.y*cosb + ax.x*sina)
	+ tz*(ax.z*ax.z*cosb + cosa);
	
	
	return ofVec3d( xrot+pivot.x, yrot+pivot.y, zrot+pivot.z );
}


inline ofVec3d& ofVec3d::rotate( double angle,
								const ofVec3d& pivot,
								const ofVec3d& axis )
{
	ofVec3d ax = axis.getNormalized();
	x -= pivot.x;
	y -= pivot.y;
	z -= pivot.z;
	
	double a = (double)(angle*DEG_TO_RAD);
	double sina = sin( a );
	double cosa = cos( a );
	double cosb = 1.0 - cosa;
	
	double xrot = x*(ax.x*ax.x*cosb + cosa)
	+ y*(ax.x*ax.y*cosb - ax.z*sina)
	+ z*(ax.x*ax.z*cosb + ax.y*sina);
	double yrot = x*(ax.y*ax.x*cosb + ax.z*sina)
	+ y*(ax.y*ax.y*cosb + cosa)
	+ z*(ax.y*ax.z*cosb - ax.x*sina);
	double zrot = x*(ax.z*ax.x*cosb - ax.y*sina)
	+ y*(ax.z*ax.y*cosb + ax.x*sina)
	+ z*(ax.z*ax.z*cosb + cosa);
	
	x = xrot + pivot.x;
	y = yrot + pivot.y;
	z = zrot + pivot.z;
	
	return *this;
}


inline ofVec3d& ofVec3d::rotateRad( double angle,
								   const ofVec3d& pivot,
								   const ofVec3d& axis )
{
	ofVec3d ax = axis.getNormalized();
	x -= pivot.x;
	y -= pivot.y;
	z -= pivot.z;
	
	double a = angle;
	double sina = sin( a );
	double cosa = cos( a );
	double cosb = 1.0 - cosa;
	
	double xrot = x*(ax.x*ax.x*cosb + cosa)
	+ y*(ax.x*ax.y*cosb - ax.z*sina)
	+ z*(ax.x*ax.z*cosb + ax.y*sina);
	double yrot = x*(ax.y*ax.x*cosb + ax.z*sina)
	+ y*(ax.y*ax.y*cosb + cosa)
	+ z*(ax.y*ax.z*cosb - ax.x*sina);
	double zrot = x*(ax.z*ax.x*cosb - ax.y*sina)
	+ y*(ax.z*ax.y*cosb + ax.x*sina)
	+ z*(ax.z*ax.z*cosb + cosa);
	
	x = xrot + pivot.x;
	y = yrot + pivot.y;
	z = zrot + pivot.z;
	
	return *this;
}




// Map point to coordinate system defined by origin, vx, vy, and vz.
//
//
inline ofVec3d ofVec3d::mapped( const ofVec3d& origin,
							   const ofVec3d& vx,
							   const ofVec3d& vy,
							   const ofVec3d& vz ) const{
	return getMapped(origin, vx, vy, vz);
}

inline ofVec3d ofVec3d::getMapped( const ofVec3d& origin,
								  const ofVec3d& vx,
								  const ofVec3d& vy,
								  const ofVec3d& vz ) const
{
	return ofVec3d( origin.x + x*vx.x + y*vy.x + z*vz.x,
				   origin.y + x*vx.y + y*vy.y + z*vz.y,
				   origin.z + x*vx.z + y*vy.z + z*vz.z );
}

inline ofVec3d& ofVec3d::map( const ofVec3d& origin,
							 const ofVec3d& vx,
							 const ofVec3d& vy,
							 const ofVec3d& vz )
{
	double xmap = origin.x + x*vx.x + y*vy.x + z*vz.x;
	double ymap =  origin.y + x*vx.y + y*vy.y + z*vz.y;
	z = origin.z + x*vx.z + y*vy.z + z*vz.z;
	x = xmap;
	y = ymap;
	return *this;
}


// Distance between two points.
//
//
inline double ofVec3d::distance( const ofVec3d& pnt) const {
	double vx = x-pnt.x;
	double vy = y-pnt.y;
	double vz = z-pnt.z;
	return (double)sqrt(vx*vx + vy*vy + vz*vz);
}

inline double  ofVec3d::distanceSquared( const ofVec3d& pnt ) const{
	return squareDistance(pnt);
}

inline double  ofVec3d::squareDistance( const ofVec3d& pnt ) const {
	double vx = x-pnt.x;
	double vy = y-pnt.y;
	double vz = z-pnt.z;
	return vx*vx + vy*vy + vz*vz;
}



// Linear interpolation.
//
//
/**
 * p==0.0 results in this point, p==0.5 results in the
 * midpoint, and p==1.0 results in pnt being returned.
 */

inline ofVec3d ofVec3d::interpolated( const ofVec3d& pnt, double p ) const {
	return getInterpolated(pnt,p);
}

inline ofVec3d ofVec3d::getInterpolated( const ofVec3d& pnt, double p ) const {
	return ofVec3d( x*(1-p) + pnt.x*p,
				   y*(1-p) + pnt.y*p,
				   z*(1-p) + pnt.z*p );
}

inline ofVec3d& ofVec3d::interpolate( const ofVec3d& pnt, double p ) {
	x = x*(1-p) + pnt.x*p;
	y = y*(1-p) + pnt.y*p;
	z = z*(1-p) + pnt.z*p;
	return *this;
}


inline ofVec3d ofVec3d::middled( const ofVec3d& pnt ) const {
	return getMiddle(pnt);
}

inline ofVec3d ofVec3d::getMiddle( const ofVec3d& pnt ) const {
	return ofVec3d( (x+pnt.x)/2.0, (y+pnt.y)/2.0, (z+pnt.z)/2.0 );
}

inline ofVec3d& ofVec3d::middle( const ofVec3d& pnt ) {
	x = (x+pnt.x)/2.0;
	y = (y+pnt.y)/2.0;
	z = (z+pnt.z)/2.0;
	return *this;
}


// Average (centroid) among points.
// Addition is sometimes useful for calculating averages too.
//
//
inline ofVec3d& ofVec3d::average( const ofVec3d* points, int num ) {
	x = 0.0;
	y = 0.0;
	z = 0.0;
	for( int i=0; i<num; i++) {
		x += points[i].x;
		y += points[i].y;
		z += points[i].z;
	}
	x /= num;
	y /= num;
	z /= num;
	return *this;
}



// Normalization
//
//
inline ofVec3d ofVec3d::normalized() const {
	return getNormalized();
}

inline ofVec3d ofVec3d::getNormalized() const {
	double length = (double)sqrt(x*x + y*y + z*z);
	if( length > 0 ) {
		return ofVec3d( x/length, y/length, z/length );
	} else {
		return ofVec3d();
	}
}

inline ofVec3d& ofVec3d::normalize() {
	double length = (double)sqrt(x*x + y*y + z*z);
	if( length > 0 ) {
		x /= length;
		y /= length;
		z /= length;
	}
	return *this;
}



// Limit length.
//
//

inline ofVec3d ofVec3d::limited(double max) const {
	return getLimited(max);
}

inline ofVec3d ofVec3d::getLimited(double max) const {
    ofVec3d limited;
    double lengthSquared = (x*x + y*y + z*z);
    if( lengthSquared > max*max && lengthSquared > 0 ) {
        double ratio = max/(double)sqrt(lengthSquared);
        limited.set( x*ratio, y*ratio, z*ratio);
    } else {
        limited.set(x,y,z);
    }
    return limited;
}

inline ofVec3d& ofVec3d::limit(double max) {
    double lengthSquared = (x*x + y*y + z*z);
    if( lengthSquared > max*max && lengthSquared > 0 ) {
        double ratio = max/(double)sqrt(lengthSquared);
        x *= ratio;
        y *= ratio;
        z *= ratio;
    }
    return *this;
}


// Perpendicular vector.
//
//
inline ofVec3d ofVec3d::crossed( const ofVec3d& vec ) const {
	return getCrossed(vec);
}
inline ofVec3d ofVec3d::getCrossed( const ofVec3d& vec ) const {
	return ofVec3d( y*vec.z - z*vec.y,
				   z*vec.x - x*vec.z,
				   x*vec.y - y*vec.x );
}

inline ofVec3d& ofVec3d::cross( const ofVec3d& vec ) {
	double _x = y*vec.z - z*vec.y;
	double _y = z*vec.x - x*vec.z;
	z = x*vec.y - y*vec.x;
	x = _x;
	y = _y;
	return *this;
}

/**
 * Normalized perpendicular.
 */
inline ofVec3d ofVec3d::perpendiculared( const ofVec3d& vec ) const {
	return getPerpendicular(vec);
}

inline ofVec3d ofVec3d::getPerpendicular( const ofVec3d& vec ) const {
	double crossX = y*vec.z - z*vec.y;
	double crossY = z*vec.x - x*vec.z;
	double crossZ = x*vec.y - y*vec.x;
	
	double length = (double)sqrt(crossX*crossX +
							   crossY*crossY +
							   crossZ*crossZ);
	
	if( length > 0 )
		return ofVec3d( crossX/length, crossY/length, crossZ/length );
	else
		return ofVec3d();
}

inline ofVec3d& ofVec3d::perpendicular( const ofVec3d& vec ) {
	double crossX = y*vec.z - z*vec.y;
	double crossY = z*vec.x - x*vec.z;
	double crossZ = x*vec.y - y*vec.x;
	
	double length = (double)sqrt(crossX*crossX +
							   crossY*crossY +
							   crossZ*crossZ);
	
	if( length > 0 ) {
		x = crossX/length;
		y = crossY/length;
		z = crossZ/length;
	} else {
		x = 0.0;
		y = 0.0;
		z = 0.0;
	}
	
	return *this;
}


// Length
//
//
inline double ofVec3d::length() const {
	return (double)sqrt( x*x + y*y + z*z );
}

inline double ofVec3d::lengthSquared() const {
	return (double)(x*x + y*y + z*z);
}



/**
 * Angle (deg) between two vectors.
 * This is an unsigned relative angle from 0 to 180.
 * http://www.euclideanspace.com/maths/algebra/vectors/angleBetween/index.htm
 */
inline double ofVec3d::angle( const ofVec3d& vec ) const {
	ofVec3d n1 = this->getNormalized();
	ofVec3d n2 = vec.getNormalized();
	return (double)(acos( n1.dot(n2) )*RAD_TO_DEG);
}

inline double ofVec3d::angleRad( const ofVec3d& vec ) const {
	ofVec3d n1 = this->getNormalized();
	ofVec3d n2 = vec.getNormalized();
	return (double)acos( n1.dot(n2) );
}



/**
 * Dot Product.
 */
inline double ofVec3d::dot( const ofVec3d& vec ) const {
	return x*vec.x + y*vec.y + z*vec.z;
}





// Non-Member operators
//
//
inline ofVec3d operator+( double f, const ofVec3d& vec ) {
    return ofVec3d( f+vec.x, f+vec.y, f+vec.z );
}

inline ofVec3d operator-( double f, const ofVec3d& vec ) {
    return ofVec3d( f-vec.x, f-vec.y, f-vec.z );
}

inline ofVec3d operator*( double f, const ofVec3d& vec ) {
    return ofVec3d( f*vec.x, f*vec.y, f*vec.z );
}

inline ofVec3d operator/( double f, const ofVec3d& vec ) {
    return ofVec3d( f/vec.x, f/vec.y, f/vec.z);
}

/// \endcond
