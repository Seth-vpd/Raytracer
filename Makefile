##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Make
##

SRC	=	Primitives/Sphere/src/Sphere.cpp	\
		Primitives/Plane/src/Plane.cpp	\
		Primitives/Cylinder/src/Cylinder.cpp	\
		Utils/src/Point3D.cpp	\
		Utils/src/Vector3D.cpp	\
		Utils/src/Color.cpp	\
		Camera/src/Camera.cpp	\
		Transformations/Translation/src/Translation.cpp	\
		Light/Point/src/PointLight.cpp	\
		Light/Directional/src/Directional.cpp	\
		Builder/SceneLoader/src/SceneLoader.cpp	\
		Builder/SceneLoader/Factory/src/Factory.cpp	\
		Scene/src/Scene.cpp	\
		Scene/main.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	raytracer

all:	$(NAME)

$(NAME):	$(OBJ)
		g++ -std=c++20 -Wall -Wextra -Werror $(OBJ) -g3 -o $(NAME) -lconfig++

clean:
	rm -rf $(NAME)
	rm -rf $(OBJ)

fclean: clean
	rm -rf *~
	rm -rf *#

re:	fclean all


