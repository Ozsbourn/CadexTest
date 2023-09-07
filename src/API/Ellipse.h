#ifndef ELLIPSE_H_
#define ELLIPSE_H_

namespace API {

	class Ellipse : public CurveBase {
	    double xrad{};
	    double yrad{};
	 
	public:
	    Ellipse(void) = default;
	    Ellipse(const API::Point& center, double radius_x, double radius_y)
	    : CurveBase(center), 
	      xrad{ radius_x }, 
	      yrad{ radius_y } {}
	 


	    inline virtual API::Point GetPoint(double t) const override {
	        return API::Point {
	            xrad * std::cos(t) + origin.x,
	            yrad * std::sin(t) + origin.y,
	            origin.z
	        };
	    }

	    inline virtual API::Vector3 GetVector(double t) const override {
	        return API::Vector3 {
	            -1.0 * xrad * std::sin(t),
	            yrad * std::cos(t)
	        };
	    }



	    virtual ~Ellipse(void) {}
	};

};

#endif // ELLIPSE_H_