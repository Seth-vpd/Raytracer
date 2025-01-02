/*
** EPITECH PROJECT, 2024
** IPrimitives
** File description:
** Primitives' Interface
*/

#ifndef ITRANSFORMATION_HPP_
#define ITRANSFORMATION_HPP_

#include "../Utils/includes/Ray.hpp"
#include "../Primitives/IPrimitive.hpp"
#include <vector>
#include <memory>

namespace RayTracer
{
    class ITransformation {
        public:
            virtual ~ITransformation() {};
            virtual void print_data() = 0;
            virtual std::unique_ptr<ITransformation> clone() const = 0;
            virtual void applyTransformation(std::vector<std::unique_ptr<IPrimitive>> &primitives) = 0;

        protected:
        private:
    };    
}


#endif