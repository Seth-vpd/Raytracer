/*
** EPITECH PROJECT, 2024
** Plane
** File description:
** SceneLoader.cpp
*/

#include "../includes/SceneLoader.hpp"

namespace RayTracer
{
    SceneLoader::SceneLoader(std::string filename)
    {
        if (read_config_file(filename) < 0) return;
        try {
            buildCamera();
            buildPrimitives();
            buildLights();
            buildTransformations();
        } catch(libconfig::SettingTypeException &stex) {
            std::cerr << "Error: " << stex.what() << std::endl;
            exit(84);
        } catch(libconfig::SettingNotFoundException &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            exit(84);
        }
    }

    int SceneLoader::read_config_file(std::string filename)
    {
        try {
            config.readFile(filename.c_str());
        }
        catch(libconfig::FileIOException &fioe) {
            std::cerr << "I/O error while reading file." << std::endl;
            exit(84);
        }
        catch(libconfig::ParseException &pex) {
            std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                      << " - " << pex.getError() << std::endl;
            exit(84);
        }
        return 0;
    }


    void SceneLoader::buildCamera()
    {
        double width, height, fov;
        Math::Point3D position, rotation;

        libconfig::Setting& cameraSetting = config.lookup("camera");
        width = cameraSetting["resolution"]["width"];
        height = cameraSetting["resolution"]["height"];
        position.x = cameraSetting["position"]["x"];
        position.y = cameraSetting["position"]["y"];
        position.z = cameraSetting["position"]["z"];
        rotation.x = cameraSetting["rotation"]["x"];
        rotation.y = cameraSetting["rotation"]["y"];
        rotation.z = cameraSetting["rotation"]["z"];
        fov = cameraSetting["fieldOfView"];
        scene.setCamera(Camera(width, height, position, rotation, fov));
    }

    void SceneLoader::buildPrimitives()
    {
        if (!config.exists("primitives")) {
            return;
        }
        load_spheres();
        load_planes();
        load_cynlinders();
    }

    void SceneLoader::load_spheres()
    {
        libconfig::Setting& primitivesSetting = config.lookup("primitives");
        if (!primitivesSetting.exists("spheres")) {
            return;
        }
        libconfig::Setting& spheresSetting = primitivesSetting["spheres"];

        for (int i = 0; i < spheresSetting.getLength(); i++) {
            scene.addPrimitive(factory.createPrimitive("sphere", spheresSetting[i]));
        }
    }

    void SceneLoader::load_planes()
    {
        libconfig::Setting& primitivesSetting = config.lookup("primitives");
        if (!primitivesSetting.exists("planes")) {
            return;
        }
        libconfig::Setting& planesSetting = primitivesSetting["planes"];

        for (int i = 0; i < planesSetting.getLength(); i++) {
            scene.addPrimitive(factory.createPrimitive("plane", planesSetting[i]));
        }
    }

    void SceneLoader::load_cynlinders()
    {
        libconfig::Setting& primitivesSetting = config.lookup("primitives");
        if (!primitivesSetting.exists("cylinders")) {
            return;
        }
        libconfig::Setting& cynlindersSetting = primitivesSetting["cylinders"];

        for (int i = 0; i < cynlindersSetting.getLength(); i++) {
            scene.addPrimitive(factory.createPrimitive("cylinder", cynlindersSetting[i]));
        }
    }

    void SceneLoader::load_translation()
    {
        libconfig::Setting& transformationsSetting = config.lookup("transformations");
        double x, y, z;
        x = transformationsSetting["translation"]["x"];
        y = transformationsSetting["translation"]["y"];
        z = transformationsSetting["translation"]["z"];
        scene.addTransformation(std::make_unique<Translation>(Math::Vector3D(x, y, z)));
    }

    void SceneLoader::buildTransformations()
    {
        load_translation();
    }

    void SceneLoader::buildLights()
    {
        load_points_light();
        load_directionals_light();
    }

    void SceneLoader::load_directionals_light()
    {
        libconfig::Setting& lightSetting = config.lookup("lights");
        libconfig::Setting& directionalsSettings = lightSetting["directional"];

        for (int i = 0; i < directionalsSettings.getLength(); i++) {
            try
            {
                scene.addLight(factory.createLight("directional", lightSetting, directionalsSettings[i]));
            }
            catch(const Error& e)
            {
                std::cerr << e.what() << std::endl;
            }
            
        }
    }

    void SceneLoader::load_points_light()
    {
        libconfig::Setting& lightSetting = config.lookup("lights");
        libconfig::Setting& pointsSettings = lightSetting["point"];

        for (int i = 0; i < pointsSettings.getLength(); i++) {
            try {
                scene.addLight(factory.createLight("point", lightSetting, pointsSettings[i]));
            } catch (const Error& err) {
                std::cerr << err.what() << std::endl;
            }
        }
    }

    Scene SceneLoader::build() const
    {
        return scene;
    }
}
