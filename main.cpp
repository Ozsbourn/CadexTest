#include <cmath>
#include <memory>
#include <typeinfo>
#include <iostream>
#include <algorithm>

#include ".\src\API\Util.h"

#include ".\src\API\CurveBase.h"

#include ".\src\API\Circle.h"
#include ".\src\API\Ellipse.h"
#include ".\src\API\Helix.h"

#include ".\src\Generator.h"



/* Type aliases definitions */
using point_t   = API::Point;
using vec3_t    = API::Vector3;

using curve_t   = API::CurveBase;

using crcl_t    = API::Circle;
using ellipse_t = API::Ellipse;

using helix_t   = API::Helix;



int main(int argc, char* argv[]) {
    constexpr size_t SIZE = 10uL;          // Size of first vector
    const double PI       = std::acos(-1); // PI number


    std::vector<GEN::WCurveBase> vec;
 
    
    GEN::Generator gen;  
    gen.SetDiapason(-20.0, 20.0); 
    for (auto i = 0uL; i < SIZE; ++i){
        vec.emplace_back(gen.Generate());  
    }
    
    using WCircle = std::shared_ptr<API::Circle>;  // Wrapper for shared pointer on `Circle` type
    std::vector<WCircle> vec2;
 
    double sum{}; // Sum of radius of circles
 
    for (auto& shape : vec) {
        const std::type_info& typeinfo{ typeid(*shape) };
 
        std::cout << typeinfo.name()          << ' '         // Type name
                  << shape->GetPoint(PI / 4)  << ' '         // Point of curve
                  << shape->GetVector(PI / 4) << std::endl;  // And derivative
 
        if (typeinfo.hash_code() == typeid(API::Circle).hash_code())  {
            //vec2.emplace_back(std::static_pointer_cast<API::Circle>(shape));
            vec2.emplace_back(std::dynamic_pointer_cast<API::Circle>(shape));
            sum += vec2.back()->GetRadius();
        }

        std::cout << std::endl;
    }

    std::sort(vec2.begin(), vec2.end(), [](const auto& lhs, const auto& rhs) {
        return lhs->GetRadius() < rhs->GetRadius(); // sort by radius
    });
 
    for (auto& i : vec2) {
        std::cout << i->GetRadius() << std::endl;
    }
    std::cout << "Sum = " << sum << std::endl;   

    return 0;
}