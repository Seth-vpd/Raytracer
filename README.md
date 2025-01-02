# RayTracer - 3D Rendering Engine

<p align="center">
  <img src="docs/raytracer_banner.png" alt="RayTracer Banner" width="800"/>
</p>

## Overview

RayTracer is a sophisticated 3D rendering engine developed in C++ that implements ray tracing techniques to generate photorealistic images. The engine simulates the inverse path of light to create stunning visual representations from scene configuration files.

## Features

- **Ray Tracing Implementation**: Accurate simulation of light behavior for realistic rendering
- **Configurable Scenes**: Scene description through configuration files
- **Multiple Primitives Support**: 
  - Spheres
  - Planes
  - Cylinders
- **Lighting System**:
  - Point lights
  - Directional lights
  - Ambient lighting
  - Diffuse lighting
- **Camera System**: Configurable camera with adjustable position, rotation, and field of view
- **Transformations**: Support for geometric transformations (Translation, etc.)

## Architecture

The project follows a modular architecture with several key components:

### Core Components

1. **Scene Management** (`Scene/`)
   - Scene composition and rendering
   - Object management
   - Lighting calculations

2. **Camera System** (`Camera/`)
   - View frustum calculation
   - Ray generation
   - Perspective projection

3. **Primitives** (`Primitives/`)
   - Abstract primitive interface
   - Implementations for:
     - Spheres
     - Planes
     - Cylinders

4. **Lighting** (`Light/`)
   - Light source abstractions
   - Point light implementation
   - Directional light implementation

5. **Transformations** (`Transformations/`)
   - Geometric transformation handling
   - Translation support

6. **Builder System** (`Builder/`)
   - Scene loading and construction
   - Configuration file parsing
   - Factory pattern implementation

### Design Patterns

The project implements several design patterns for maintainability and extensibility:

1. **Builder Pattern**: Used for scene construction
2. **Factory Pattern**: For creating primitives and lights
3. **Interface Segregation**: Through abstract interfaces (ILight, IPrimitive, etc.)

## Getting Started

### Prerequisites

- C++ compiler with C++20 support
- libconfig++ library
- Make build system

### Building the Project

```bash
# Clone the repository
git clone [repository-url]

# Build the project
make

# Clean build files
make clean

# Rebuild the project
make re
```

### Usage

```bash
./raytracer [scene_config_file]
```

### Scene Configuration

Scene configuration files use the libconfig format. Example:

```cfg
camera: {
    resolution: { width = 1920.0; height = 1080.0; };
    position: { x = 0.0; y = -100.0; z = 20.0; };
    rotation: { x = 0.0; y = 0.0; z = 0.0; };
    fieldOfView = 72.0;
};

primitives: {
    spheres = (
        {
            x = 60.0;
            y = 5.0;
            z = 40.0;
            r = 25.0;
            color = { r = 255.0; g = 64.0; b = 64.0; };
        }
    );
};

lights: {
    ambient = 0.4;
    diffuse = 0.6;
    point = (
        {
            x = 400.0;
            y = 100.0;
            z = 500.0;
        }
    );
};
```

## Project Structure

```
.
├── Builder/           # Scene construction and loading
├── Camera/           # Camera system implementation
├── Light/            # Lighting system
├── Primitives/       # 3D primitive objects
├── Scene/            # Scene management
├── Transformations/  # Geometric transformations
└── Utils/            # Utility functions and classes
```

## Contributors

This project was developed by:
- Jaures ADEHOSSI (jaures.adehossi@epitech.eu)
- Seth DJENONTIN (seth.djenontin@epitech.eu)
- Aquilas HOUNKANRIN (aquilas.hounkanrin@epitech.eu)
- Ronel HOUNKPATIN (ronel.hounpkatin@epitech.eu)

## License

This project is part of the EPITECH curriculum and follows EPITECH's project guidelines.
