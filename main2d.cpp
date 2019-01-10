/* This is the main file of Generic Crowd Simulation 2D
   Copyright (c) 2018  Alejandro Aguilar Sierra (asierra@unam.mx)
*/
#include <GLFW/glfw3.h>
#include <iostream>
#include "crowds.h"

// Simulaciones
void setupScenarioBlocks(CrowdSim *sim);

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

float const scale = 0.01;
bool pause = true;

void draw_obstacles(CrowdSim *sim) {
  glColor3f(0.5, 0.5, 0.5);
  glBegin(GL_QUADS);
  for (int i=0; i < sim->obstacle_vertices.size(); i += 4) {
    glVertex2f(sim->obstacle_vertices[i  ].x*scale, sim->obstacle_vertices[i  ].y*scale);
    glVertex2f(sim->obstacle_vertices[i+1].x*scale, sim->obstacle_vertices[i+1].y*scale);
    glVertex2f(sim->obstacle_vertices[i+2].x*scale, sim->obstacle_vertices[i+2].y*scale);
    glVertex2f(sim->obstacle_vertices[i+3].x*scale, sim->obstacle_vertices[i+3].y*scale);
  }
  glEnd ();    
}


int main(void)
{
  GLFWwindow* window;

  if (!glfwInit())
    return -1;

  window = glfwCreateWindow(640, 480, "Simulación Multitudes 2D", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }
  
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
  glfwSetKeyCallback(window, key_callback);
  
  CrowdSim *sim = new CrowdSim();
  setupScenarioBlocks(sim);

  glPointSize(6.0);
  while (!glfwWindowShouldClose(window)) { 
    glClear(GL_COLOR_BUFFER_BIT);

    draw_obstacles(sim);

    // Draw agents
    glBegin (GL_POINTS);

    int n = sim->getNumAgents();
    for (size_t i = 0; i < n; ++i) {
      glm::vec2 pos = sim->getAgentPosition(i);
      float x = pos.x*scale;
      float y = pos.y*scale;
      if (i == 0)
	glColor3f(1.0, 0.0, 0.5);
      else if (i == 25)
	glColor3f(0.5, 0.0, 1.0);
      else if (i == 50)
	glColor3f(0.0, 0.5, 1.0);
      else if (i >= 75)
	glColor3f(0.0, 1.0, 0.5);
      glVertex2f(x, y);	     
    }

    glEnd ();

    if (!pause) {
      sim->setPreferredVelocities();
      sim->doStep();
    }
		
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  
  glfwTerminate();
  return 0;
}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
  
  if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
    pause = !pause;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}
