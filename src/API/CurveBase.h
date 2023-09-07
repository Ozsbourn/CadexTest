#ifndef CURVEBASE_H_
#define CURVEBASE_H_

namespace API {

	class CurveBase {
	protected:
	    API::Point origin{}; 
	 
	    CurveBase(void) = default;
	    CurveBase(const API::Point& center) : origin{ center } {}
	public:
	    virtual ~CurveBase(void) {}
	 
	    inline virtual API::Point   GetPoint(double t)  const = 0;  // get a point of curve by a `t` parameter
	    inline virtual API::Vector3 GetVector(double t) const = 0;  // get the first derivative of curve by a `t` parameter
	};

};

#endif // CURVEBASE_H_