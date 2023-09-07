#ifndef CIRCLE_H_
#define CIRCLE_H_

namespace API {

	class Circle : public CurveBase {
	private:
	    double rad{};

	public:
	    Circle(void) = default;
	    Circle(const API::Point& center, double radius)
	    : CurveBase(center), 
	      rad{ radius } {}
	 


	    inline double GetRadius(void) const { 
	        return rad; 
	    }



	    inline virtual API::Point GetPoint(double t)    const override {
	        return API::Point {
	            rad * std::cos(t) + origin.x,
	            rad * std::sin(t) + origin.y,
	            origin.z
	        };
	    }

	    inline virtual API::Vector3 GetVector(double t) const override {
	        return API::Vector3 {
	            -1.0f * rad * std::sin(t),
	            rad * std::cos(t)
	        };
	    }



	    virtual ~Circle(void) {}
	};

};

#endif // CIRCLE_H_