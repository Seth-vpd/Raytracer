/*
** EPITECH PROJECT, 2024
** IBuilder
** File description:
** IBuilder
*/

#ifndef IBUILDER_HPP_
#define IBUILDER_HPP_

#include <iostream>
#include "../Scene/includes/Scene.hpp"

namespace RayTracer
{
    class IBuilder {
        public:
            virtual ~IBuilder() {};
            virtual void buildCamera() = 0;
            virtual void buildPrimitives() = 0;
            virtual void buildLights() = 0;
            virtual void buildTransformations() = 0;
            virtual Scene build() const = 0;

        protected:
        private:
    };    
}

#endif /* !IBUILDER_HPP_ */
