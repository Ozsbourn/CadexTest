#include <cmath>
#include <random>
#include <memory>

#ifndef GENERATOR_H_
#define GENERATOR_H_

namespace GEN {

    using WCurveBase = std::shared_ptr<API::CurveBase>; // Wrapper for shared pointer on a `CurveBase` type
     
    class Generator {
    private:
        static constexpr double EPS = 1E-6;

        /* Possible generated types */
        enum Shapes { 
            circle, 
            ellipse, 
            helix 
        };
     
        static std::random_device rd;
     
        std::uniform_real_distribution<double> NumbersGen{ -1, 1 };         // Generator for random double numbers (PRNG)
        std::uniform_int_distribution<>          TypesGen{ circle, helix }; // Genearator for random types
     
    public:
     
        void SetDiapason(const double min, const double max) {
            if ((std::abs(max) + std::abs(min)) < 2 * EPS) {
                return; 
            }

            NumbersGen = decltype(NumbersGen){ min, max };
        }
     
        WCurveBase GenerateCircle(void) {
            double radius{};
            while (radius < EPS) {
                radius = std::abs(NumbersGen(rd)); 
            }
     
            return std::make_shared<API::Circle>(API::Point{ NumbersGen(rd), NumbersGen(rd) }, radius);
        }
     
        WCurveBase GenerateEllipse(void) {
            double radius_x{};
            while (radius_x < EPS) {
                radius_x = std::abs(NumbersGen(rd));
            }
     
            double radius_y{};
            while (radius_y < EPS) {
                radius_y = std::abs(NumbersGen(rd));
            }
     
            return std::make_shared<API::Ellipse>(API::Point{ NumbersGen(rd), NumbersGen(rd) }, radius_x, radius_y);
        }
     
        WCurveBase GenerateHelix(void) {
            double radius{};
            while (radius < EPS) {
                radius = std::abs(NumbersGen(rd));
            }
     
            double step{};
            while (std::abs(step) < EPS) {
                step = NumbersGen(rd);
            }
     
            return std::make_shared<API::Helix>(API::Point{ NumbersGen(rd), NumbersGen(rd), NumbersGen(rd) }, radius, step);
        }
     
        WCurveBase Generate(void) {
            switch (TypesGen(rd)) {
                case circle:
                    return GenerateCircle();
                case ellipse:
                    return GenerateEllipse();
                case helix:
                    return GenerateHelix();
                default:
                    return GenerateCircle();
            }
        }
    };


    std::random_device GEN::Generator::rd;
};

#endif // GENERATOR_H_