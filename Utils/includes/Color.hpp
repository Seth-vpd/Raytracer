/*
** EPITECH PROJECT, 2024
** Color
** File description:
** Color
*/

#ifndef COLOR_HPP_
#define COLOR_HPP_

#include <iostream>
#include <cmath>

namespace RayTracer
{
    class Color {
        public:
            Color();
            Color(double l);
            Color(double r, double g, double b);
            void clamp(double min = 0.0f, double max = 1.0f);
            void applyGamma(double, double);
            ~Color();

            Color& operator=(const Color& c);
            Color& operator+=(const Color& c);
            Color& operator*=(const Color& c);
            Color& operator*=(double f);
            Color& operator*(double f);

            double r = 0.0, g = 0.0, b = 0.0;
        protected:
        private:
    };
    std::ostream& operator<<(std::ostream &line, Color);
}

#endif /* !COLOR_HPP_ */
