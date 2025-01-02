/*
** EPITECH PROJECT, 2024
** Main
** File description:
** Main
*/

#include "../Builder/SceneLoader/includes/SceneLoader.hpp"

int main(int ac, char **av)
{
    if (ac == 2) {
        RayTracer::SceneLoader loader(av[1]);
        RayTracer::Scene scene = loader.build();
        scene.loop();
        return 0;
    }
    else
        return 84;
}