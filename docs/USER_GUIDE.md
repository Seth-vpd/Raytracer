# RayTracer User Guide

## Table of Contents

1. [Installation](#installation)
2. [Basic Usage](#basic-usage)
3. [Scene Configuration](#scene-configuration)
4. [Examples](#examples)
5. [Troubleshooting](#troubleshooting)

## Installation

### Prerequisites

Before installing RayTracer, ensure you have the following:

- C++ compiler with C++20 support
- libconfig++ library
- Make build system

### Installation Steps

1. Install dependencies (Ubuntu/Debian):
   ```bash
   sudo apt-get update
   sudo apt-get install g++ make libconfig++-dev
   ```

2. Clone and build the project:
   ```bash
   git clone [repository-url]
   cd raytracer
   make
   ```

## Basic Usage

### Running the Program

Basic syntax:
```bash
./raytracer [scene_config_file]
```

Example:
```bash
./raytracer Config_files/base.cfg
```

### Output

The program outputs a PPM format image to stdout. To save the output:
```bash
./raytracer Config_files/base.cfg > output.ppm
```

## Scene Configuration

### File Format

Scene configuration files use the libconfig format with the following sections:

1. **Camera Configuration**
   ```cfg
   camera: {
       resolution: { 
           width = 1920.0; 
           height = 1080.0; 
       };
       position: { 
           x = 0.0; 
           y = -100.0; 
           z = 20.0; 
       };
       rotation: { 
           x = 0.0; 
           y = 0.0; 
           z = 0.0; 
       };
       fieldOfView = 72.0;
   };
   ```

2. **Primitives Configuration**
   ```cfg
   primitives: {
       # Spheres
       spheres = (
           {
               x = 60.0;
               y = 5.0;
               z = 40.0;
               r = 25.0;
               color = { 
                   r = 255.0; 
                   g = 64.0; 
                   b = 64.0; 
               };
           }
       );

       # Planes
       planes = (
           {
               axis = "Z";
               position = -20.0;
               color = { 
                   r = 64.0; 
                   g = 64.0; 
                   b = 255.0; 
               };
           }
       );

       # Cylinders
       cylinders = (
           {
               x = 0.0;
               y = 0.0;
               z = 0.0;
               r = 1.5;
               h = 5.0;
               color = { 
                   r = 64.0; 
                   g = 255.0; 
                   b = 64.0; 
               };
           }
       );
   };
   ```

3. **Lighting Configuration**
   ```cfg
   lights: {
       ambient = 0.4;  # Ambient light intensity
       diffuse = 0.6;  # Diffuse light intensity
       
       # Point lights
       point = (
           {
               x = 400.0;
               y = 100.0;
               z = 500.0;
           }
       );
       
       # Directional lights
       directional = (
           {
               x = 1.0;
               y = -1.0;
               z = -1.0;
           }
       );
   };
   ```

### Configuration Parameters

#### Camera Parameters
- `resolution`: Image dimensions in pixels
- `position`: Camera location in 3D space
- `rotation`: Camera orientation in degrees
- `fieldOfView`: Field of view angle in degrees

#### Primitive Parameters
- **Sphere**:
  - `x, y, z`: Center position
  - `r`: Radius
  - `color`: RGB color values (0-255)

- **Plane**:
  - `axis`: Normal axis ("X", "Y", or "Z")
  - `position`: Distance from origin
  - `color`: RGB color values

- **Cylinder**:
  - `x, y, z`: Base center position
  - `r`: Radius
  - `h`: Height
  - `color`: RGB color values

#### Light Parameters
- `ambient`: Global ambient light intensity (0-1)
- `diffuse`: Global diffuse light intensity (0-1)
- Point lights: Position in 3D space
- Directional lights: Direction vector

## Examples

### Basic Scene
```cfg
camera: {
    resolution: { width = 800.0; height = 600.0; };
    position: { x = 0.0; y = 0.0; z = 5.0; };
    rotation: { x = 0.0; y = 0.0; z = 0.0; };
    fieldOfView = 45.0;
};

primitives: {
    spheres = (
        {
            x = 0.0;
            y = 0.0;
            z = -5.0;
            r = 1.0;
            color = { r = 255.0; g = 0.0; b = 0.0; };
        }
    );
};

lights: {
    ambient = 0.2;
    diffuse = 0.8;
    point = (
        {
            x = 5.0;
            y = 5.0;
            z = 5.0;
        }
    );
};
```

## Troubleshooting

### Common Issues

1. **Black Output**
   - Check light positions and intensities
   - Verify camera is facing the scene
   - Ensure primitives are within view frustum

2. **Compilation Errors**
   - Verify C++20 compiler is installed
   - Check libconfig++ installation
   - Ensure all dependencies are met

3. **Runtime Errors**
   - Validate configuration file syntax
   - Check for missing required parameters
   - Verify file paths are correct

### Error Messages

- `Error: Setting not found`: Missing required configuration parameter
- `Error: Setting type mismatch`: Incorrect parameter type
- Exit code 84: General error (invalid configuration or runtime error)

### Getting Help

For additional help:
1. Check the technical documentation
2. Review example configuration files
3. Contact the development team 