# RayTracer Technical Documentation

## Architecture Overview

The RayTracer project is built with a modular architecture that separates concerns into distinct components while maintaining high cohesion and loose coupling through interfaces.

### Core Components

#### 1. Scene Management (`Scene/`)

The Scene class acts as the main orchestrator, managing:
- Scene composition
- Rendering pipeline
- Object and light management
- Ray-object intersection calculations

Key classes:
- `Scene`: Main scene controller
- `SceneLoader`: Configuration file parser and scene builder

#### 2. Camera System (`Camera/`)

Handles view calculation and ray generation:
- Field of view calculation
- Ray generation for each pixel
- View transformation

Key components:
```cpp
class Camera {
    double _width, _height;
    Math::Point3D _position;
    Math::Point3D _rotation;
    double fov;
    double ratio;
};
```

#### 3. Primitive System (`Primitives/`)

Implements geometric primitives with the `IPrimitive` interface:

```cpp
class IPrimitive {
    virtual bool hits(Ray ray, double min, double max, Hit_info &hit_point) = 0;
    virtual Color getColor() const = 0;
    virtual void setPosition(Math::Point3D) = 0;
    virtual Math::Point3D getPosition() const = 0;
};
```

Supported primitives:
- Sphere
- Plane
- Cylinder

#### 4. Lighting System (`Light/`)

Implements lighting calculations through the `ILight` interface:

```cpp
class ILight {
    virtual double getAmbient() const = 0;
    virtual double getDiffuse() const = 0;
    virtual Math::Point3D getPosition() const = 0;
    virtual std::string getType() const = 0;
};
```

Supported light types:
- Point lights
- Directional lights

#### 5. Builder System (`Builder/`)

Implements the Builder pattern for scene construction:

```cpp
class IBuilder {
    virtual void buildCamera() = 0;
    virtual void buildPrimitives() = 0;
    virtual void buildLights() = 0;
    virtual void buildTransformations() = 0;
    virtual Scene build() const = 0;
};
```

### Ray Tracing Implementation

The ray tracing process follows these steps:

1. **Ray Generation**
   ```cpp
   Ray Camera::emitRay(double u, double v) {
       // Calculate ray direction based on camera parameters
       return Ray(origin, direction);
   }
   ```

2. **Intersection Testing**
   ```cpp
   bool Primitive::hits(Ray ray, double min, double max, Hit_info &hit_info) {
       // Calculate intersection with primitive
       // Update hit_info if intersection found
   }
   ```

3. **Lighting Calculation**
   ```cpp
   void Scene::processLight(Hit_info& hit_info) {
       // Calculate lighting contribution from each light source
       // Update color based on material properties
   }
   ```

### Configuration System

Scene configuration uses libconfig++ format:

```cfg
camera: {
    resolution: { width = 1920.0; height = 1080.0; };
    position: { x = 0.0; y = -100.0; z = 20.0; };
    rotation: { x = 0.0; y = 0.0; z = 0.0; };
    fieldOfView = 72.0;
};
```

The `SceneLoader` class parses this configuration and constructs the scene using the Builder pattern.

### Mathematics

The project uses custom mathematical classes for 3D operations:

- `Vector3D`: 3D vector operations
- `Point3D`: 3D point representation
- `Ray`: Ray representation for tracing
- `Color`: RGB color representation

### Performance Considerations

1. **Memory Management**
   - Use of smart pointers for automatic resource management
   - Efficient copying through clone patterns
   - Stack allocation where possible

2. **Optimization Techniques**
   - Early ray termination
   - Bounding volume optimization
   - Efficient intersection algorithms

### Error Handling

The project implements robust error handling:

```cpp
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
```

### Future Improvements

Potential areas for enhancement:

1. **Performance**
   - Implement multi-threading for parallel ray tracing
   - Add spatial partitioning (BVH, k-d trees)
   - GPU acceleration support

2. **Features**
   - Additional primitive types
   - More material properties
   - Texture mapping support
   - Anti-aliasing implementation

3. **Architecture**
   - Plugin system for custom primitives
   - Material system abstraction
   - Scene graph implementation 