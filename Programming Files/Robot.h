#pragma once

#include <GL/glut.h>
#include <iostream>
#include <math.h>

#define ROBOT_MOVEMENT_SPEED 2.0f

void drawRobotHead(GLUquadricObj*);
void drawRobotBody(GLUquadricObj*);
void drawRobotRightUpperArm(GLUquadricObj*);
void drawRobotRightLowerArm(GLUquadricObj*);
void drawRobotRightPalm(GLUquadricObj*);
void drawRobot(void*);

class Robot {
private:
	// robot components
	GLUquadricObj* head, * body, * leftArm, * rightUpperArm, * rightLowerArm, *rightPalm;

	// center point for all robot components (hierarchical)
	GLfloat robotCenterPointX, robotCenterPointY, robotCenterPointZ;
	// head direction
	GLfloat viewDirectionX, viewDirectionY, viewDirectionZ;
	// body direction
	GLfloat bodyDirectionX, bodyDirectionY, bodyDirectionZ;
	// shoulder direction
	GLfloat shoulderDirectionX, shoulderDirectionY, shoulderDirectionZ;
	// elbow direction
	GLfloat elbowDirectionX, elbowDirectionY, elbowDirectionZ;
	// palm direction
	GLfloat palmDirectionX, palmDirectionY, palmDirectionZ;

public:
	/* represents the center point for the robot, as well as a direction for each one of it's components. */
	Robot(	GLfloat robotCenterPointX,  GLfloat robotCenterPointY,  GLfloat robotCenterPointZ, 
			GLfloat viewDirectionX,		GLfloat viewDirectionY,		GLfloat viewDirectionZ,
			GLfloat bodyDirectionX,		GLfloat bodyDirectionY,		GLfloat bodyDirectionZ,
			GLfloat shoulderDirectionX, GLfloat shoulderDirectionY, GLfloat shoulderDirectionZ,
			GLfloat elbowDirectionX,	GLfloat elbowDirectionY,	GLfloat elbowDirectionZ,
			GLfloat palmDirectionX,		GLfloat palmDirectionY,		GLfloat palmDirectionZ		) {

		this->robotCenterPointX = robotCenterPointX;
		this->robotCenterPointY = robotCenterPointY;
		this->robotCenterPointZ = robotCenterPointZ;
		
		this->viewDirectionX = viewDirectionX;
		this->viewDirectionY = viewDirectionY;
		this->viewDirectionZ = viewDirectionZ;

		this->bodyDirectionX = bodyDirectionX;
		this->bodyDirectionY = bodyDirectionY;
		this->bodyDirectionZ = bodyDirectionZ;
		
		this->shoulderDirectionX = shoulderDirectionX;
		this->shoulderDirectionY = shoulderDirectionY;
		this->shoulderDirectionZ = shoulderDirectionZ;
		
		this->elbowDirectionX = elbowDirectionX;
		this->elbowDirectionY = elbowDirectionY;
		this->elbowDirectionZ = elbowDirectionZ;

		this->palmDirectionX = palmDirectionX;
		this->palmDirectionY = palmDirectionY;
		this->palmDirectionZ = palmDirectionZ;
	}

	/* getters and setters for the center point and for each component's direction. */
	
	GLfloat getRobotCenterPointX() {
		return robotCenterPointX;
	}

	GLfloat getRobotCenterPointY() {
		return robotCenterPointY;
	}

	GLfloat getRobotCenterPointZ() {
		return robotCenterPointZ;
	}

	void setRobotCenterPointX(GLfloat val) {
		this->robotCenterPointX = val;
	}

	void setRobotCenterPointY(GLfloat val) {
		this->robotCenterPointY = val;
	}

	void setRobotCenterPointZ(GLfloat val) {
		this->robotCenterPointZ = val;
	}

	GLfloat getViewDirectionX() {
		return this->viewDirectionX;
	}

	GLfloat getViewDirectionY() {
		return this->viewDirectionY;
	}

	GLfloat getViewDirectionZ() {
		return this->viewDirectionZ;
	}

	void setViewDirectionX(GLfloat val) {
		this->viewDirectionX = val;
	}

	void setViewDirectionY(GLfloat val) {
		this->viewDirectionY = val;
	}

	void setViewDirectionZ(GLfloat val) {
		this->viewDirectionZ = val;
	}

	GLfloat getBodyDirectionX() {
		return this->bodyDirectionX;
	}

	GLfloat getBodyDirectionY() {
		return this->bodyDirectionY;
	}

	GLfloat getBodyDirectionZ() {
		return this->bodyDirectionZ;
	}

	void setBodyDirectionX(GLfloat val) {
		this->bodyDirectionX = val;
	}

	void setBodyDirectionY(GLfloat val) {
		this->bodyDirectionY = val;
	}

	void setBodyDirectionZ(GLfloat val) {
		this->bodyDirectionZ = val;
	}

	GLfloat getShoulderDirectionX() {
		return this->shoulderDirectionX;
	}

	GLfloat getShoulderDirectionY() {
		return this->shoulderDirectionY;
	}

	GLfloat getShoulderDirectionZ() {
		return this->shoulderDirectionZ;
	}

	void setShoulderDirectionX(GLfloat val) {
		this->shoulderDirectionX = val;
	}

	void setShoulderDirectionY(GLfloat val) {
		this->shoulderDirectionY = val;
	}

	void setShoulderDirectionZ(GLfloat val) {
		this->shoulderDirectionZ = val;
	}

	GLfloat getElbowDirectionX() {
		return this->elbowDirectionX;
	}

	GLfloat getElbowDirectionY() {
		return this->elbowDirectionY;
	}

	GLfloat getElbowDirectionZ() {
		return this->elbowDirectionZ;
	}

	void setElbowDirectionX(GLfloat val) {
		this->elbowDirectionX = val;
	}

	void setElbowDirectionY(GLfloat val) {
		this->elbowDirectionY = val;
	}

	void setElbowDirectionZ(GLfloat val) {
		this->elbowDirectionZ = val;
	}

	GLfloat getPalmDirectionX() {
		return this->palmDirectionX;
	}

	GLfloat getPalmDirectionY() {
		return this->palmDirectionY;
	}

	GLfloat getPalmDirectionZ() {
		return this->palmDirectionZ;
	}

	void setPalmDirectionX(GLfloat val) {
		this->palmDirectionX = val;
	}

	void setPalmDirectionY(GLfloat val) {
		this->palmDirectionY = val;
	}

	void setPalmDirectionZ(GLfloat val) {
		this->palmDirectionZ = val;
	}

	GLUquadricObj* getHead() {
		return this->head;
	}

	GLUquadricObj* getBody() {
		return this->body;
	}

	GLUquadricObj* getRightUpperArm() {
		return this->rightUpperArm;
	}

	GLUquadricObj* getRightLowerArm() {
		return this->rightLowerArm;
	}

	GLUquadricObj* getRightPalm() {
		return this->rightPalm;
	}

	GLUquadricObj* getLeftArm() {
		return this->leftArm;
	}

};
