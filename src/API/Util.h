#ifndef API_UTIL_H_
#define API_UTIL_H_

namespace API {

    /**
     * @brief [ Struct Point represents point in 3D ]
     * @details [ Any coords in Point have a double precision ]
     * 
     * @param x [ X coord ]
     * @param y [ Y coord ]
     * @param z [ Z coord ]
     */
    struct Point {
        double x{};
        double y{}; 
        double z{};


        /*Point(const double x, const double y, const double z) 
        : this->x(x),
          this->y(y),
          this->z(z) {}

        constexpr double GetX(void) const noexcept { return x; };
        constexpr double GetY(void) const noexcept { return y; };
        constexpr double GetZ(void) const noexcept { return z; };

        void SetX(const double x) noexcept { this->x = x; };
        void SetY(const double y) noexcept { this->y = y; };
        void SetZ(const double z) noexcept { this->z = z; };*/
    };
     

    /**
     * @brief [ Struct Vector3 represents vector in 3D ]
     * @details [ Any coords in Vector3 have a double precision ]
     * 
     * @param x [ X coord ]
     * @param y [ Y coord ]
     * @param z [ Z coord ]
     */
    struct Vector3 { 
        double x{}; 
        double y{}; 
        double z{}; 


        /*Vector3(const double x, const double y, const double z) 
        : this->x(x),
          this->y(y),
          this->z(z) {}

        constexpr double GetX(void) const noexcept { return x; };
        constexpr double GetY(void) const noexcept { return y; };
        constexpr double GetZ(void) const noexcept { return z; };

        void SetX(const double x) noexcept { this->x = x; };
        void SetY(const double y) noexcept { this->y = y; };
        void SetZ(const double z) noexcept { this->z = z; };*/
    }; 



    
    std::ostream& operator<<(std::ostream& os, const Vector3& v) {
        os << "Vector is { " << v.x << ", " << v.y << ", " << v.z << " }";

        return os;
    }

    std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "Point is  { " << p.x << ", " << p.y << ", " << p.z << " }";

        return os;
    }

};

#endif // API_UTIL_H_