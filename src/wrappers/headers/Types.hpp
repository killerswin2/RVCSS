#pragma once

namespace RV::Bindings 
{
    struct __declspec(dllexport) vector3
    {
    public:

        float x;
        float y;
        float z;

        constexpr vector3() : x{ 0 }, y{ 0 }, z{ 0 }
        {
        }

        constexpr vector3(const float x_, const float y_, const float z_) : x{ x_ }, y{ y_ }, z{ z_ }
        {
        }
    };
}