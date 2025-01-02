/*
** EPITECH PROJECT, 2024
** Color
** File description:
** Color
*/

#include "../includes/Color.hpp"

namespace RayTracer
{
    Color::Color() {}

    Color::Color(double l) { r = l; g = l; b = l; }

    Color::Color(double _r, double _g, double _b) : r(_r), g(_g), b(_b) {};

    Color::~Color() {}

    Color& Color::operator=(const Color &c)
    {
        r = c.r;
        g = c.g;
        b = c.b;
        return *this;
    }

    Color operator+(const Color& c1, const Color& c2)
    {
        return Color(c1.r + c2.r, c1.g + c2.g, c1.b + c2.b);
    }

    Color operator*(const Color& c1, const Color& c2)
    {
        return Color(c1.r * c2.r, c1.g * c2.g, c1.b * c2.b);
    }

    Color operator*(const Color& c, double f)
    {
        return Color(c.r * f, c.g * f, c.b * f);
    }

    Color operator*(double f, const Color& c)
    {
        return Color(f * c.r, f * c.g, f * c.b);
    }

    void Color::clamp(double min, double max)
    {
        r = std::max(min, std::min(max, r));
        g = std::max(min, std::min(max, g));
        b = std::max(min, std::min(max, b));
    }

    void Color::applyGamma(double exposure, double gamma)
    {
        r = std::pow(r * exposure, gamma);
        g = std::pow(g * exposure, gamma);
        b = std::pow(b * exposure, gamma);
    }

    Color& Color::operator+=(const Color& c)
    {
        r += c.r;
        g += c.g;
        b += c.b;
        return *this;
    }

    Color& Color::operator*=(const Color& c)
    {
        r *= c.r;
        g *= c.g;
        b *= c.b;
        return *this;
    }

    Color& Color::operator*=(double f)
    {
        r *= f;
        g *= f;
        b *= f;
        return *this;
    }

    std::ostream& operator<<(std::ostream &line, Color vector)
    {
        return line << vector.r << ' ' << vector.g << ' ' << vector.b << std::endl;
    }
}
