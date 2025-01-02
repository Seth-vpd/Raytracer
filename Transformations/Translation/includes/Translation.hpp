/*
** EPITECH PROJECT, 2024
** IPrimitives
** File description:
** Transformation
*/

#ifndef TRANSLATION_HPP_
#define TRANSLATION_HPP_

#include "../../ITransformation.hpp"
#include "../../../Primitives/IPrimitive.hpp"

namespace RayTracer
{
    class Translation : public ITransformation {
        public:
            Translation(Math::Vector3D);
            ~Translation();
            std::unique_ptr<ITransformation> clone() const;
            void translate(std::unique_ptr<IPrimitive> primitive);
            Math::Vector3D getVector();
            void applyTransformation(std::vector<std::unique_ptr<IPrimitive>> &primitives);
            void print_data();

        protected:
        private:
            Math::Vector3D vector;
    };
}

#endif
