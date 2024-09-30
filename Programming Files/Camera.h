#pragma once

#include <GL/glut.h>
#include <iostream>

#define CAMERA_SPEED 20.0f

class Camera
{
private:
	// Camera world coordinates.
	GLfloat xCoord, yCoord, zCoord;

	// Camera view direction.
	GLfloat xDirection, yDirection, zDirection;

	GLfloat cameraSpeed = 2.0f;

public:
	Camera(GLfloat xCoord, GLfloat yCoord, GLfloat zCoord, GLfloat xDirection, GLfloat yDirection, GLfloat zDirection) {
		this->xCoord = xCoord;
		this->yCoord = yCoord;
		this->zCoord = zCoord;

		this->xDirection = xDirection;
		this->yDirection = yDirection;
		this->zDirection = zDirection;
	}

	/* getters and setters for the camera's coordinates and direction. */
	void setCameraCoords(GLfloat xCoord, GLfloat yCoord, GLfloat zCoord) {
		this->xCoord = xCoord;
		this->yCoord = yCoord;
		this->zCoord = zCoord;
	}

	GLfloat getCameraCoordX() {
		return this->xCoord;
	}

	GLfloat getCameraCoordY() {
		return this->yCoord;
	}

	GLfloat getCameraCoordZ() {
		return this->zCoord;
	}

	void setCameraDirection(GLfloat xDirection, GLfloat yDirection, GLfloat zDirection) {
		this->xDirection = xDirection;
		this->yDirection = yDirection;
		this->zDirection = zDirection;
	}

	GLfloat getCameraDirectionX() {
		return this->xDirection;
	}

	GLfloat getCameraDirectionY() {
		return this->yDirection;
	}

	GLfloat getCameraDirectionZ() {
		return this->zDirection;
	}

};

