/*
** EPITECH PROJECT, 2024
** Scene
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include "../../Primitives/IPrimitive.hpp"
#include "../../Utils/includes/Ray.hpp"
#include "../../Utils/includes/c++libs.hpp"
#include "../../Camera/includes/Camera.hpp"
#include "../../Light/Point/includes/PointLight.hpp"
#include "../../Transformations/Translation/includes/Translation.hpp"
#include "../../Light/Directional/includes/Directional.hpp"

namespace RayTracer
{
    class Scene {
        public:
            Scene() {};
            Scene(const Scene &);
            void setCamera(Camera _camera);
            void addTransformation(std::unique_ptr<ITransformation> transformation);
            void addPrimitive(std::unique_ptr<IPrimitive> primitive);
            void addLight(std::unique_ptr<ILight> light);
            void loop();
            void processLight(RayTracer::Hit_info& hit_info);
            void processTransformations();
            void render(std::vector<std::unique_ptr<IPrimitive>> &primitives, RayTracer::Ray ray);
            const std::unique_ptr<Camera>& getCamera() const { return camera; };
            const std::vector<std::unique_ptr<IPrimitive>>& getPrimitives() const { return primitives; };
            const std::vector<std::unique_ptr<ILight>>& getLights() const { return lights; };
            const std::vector<std::unique_ptr<ITransformation>>& getTransformations() const { return transformations; };
            ~Scene() {};

        protected:
        private:
            std::unique_ptr<Camera> camera;
            std::vector<std::unique_ptr<ILight>> lights;
            std::vector<std::unique_ptr<IPrimitive>> primitives;
            std::vector<std::unique_ptr<ITransformation>> transformations;
    };
} // namespace RayTracer

#endif /* !SCENE_HPP_ */
