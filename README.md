# turba2
Turba2D:  Generic Multitude Simulation with OpenGL

Rendering a multi-agent simulation in real time using OpenGL.

## Compile

A Makefile for Unix like operative systems is included. With minimal
changes can work for other platforms.

## Usage

Run the executable and press SPACE to start or pause the
simulation. To exit, just press ESCAPE.

## Dependencies

C++ compiler, OpenGL headers and libraries, GLFW3, glad (compile it
for your own platform), RVO2 library: Reciprocal Collision Avoidance
for Real-Time Multi-Agent Simulation http://gamma.cs.unc.edu/RVO2/ .

Original code, with the only exception of RVO2 headers in the include
directory.

Copyright (c) 2018 Alejandro Aguilar Sierra (asierra@unam.mx)
