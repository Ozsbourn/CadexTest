#ifndef HELIX_H_
#define HELIX_H_

namespace API {

	class Helix : public CurveBase {
	    double rad{};
	    double step{};
	 
	public:
	    Helix(void) = default;
	    Helix(const API::Point& center, double radius, double step_z)
	    : CurveBase(center), 
	      rad{ radius }, 
	      step{ step_z } {}
	 
	    
	 
	    inline virtual API::Point GetPoint(double t) const override {
	        return API::Point {
	            rad * t * std::cos(t) + origin.x,
	            rad * t * std::sin(t) + origin.y,
	            step * t + origin.z
	        };
	    }

	    inline virtual API::Vector3 GetVector(double t) const override {
	        return API::Vector3 {
	            rad * (std::cos(t) - t * std::sin(t)),
	            rad * (std::sin(t) + t * std::cos(t)),
	            step
	        };
	    }



	    virtual ~Helix(void) {}
	};

};

#endif // HELIX_H_