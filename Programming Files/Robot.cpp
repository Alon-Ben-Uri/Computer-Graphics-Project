#include "Robot.h"

/* draws the robot's head. */
void drawRobotHead(GLUquadricObj* head) {
	head = gluNewQuadric();
	glColor3f(0.0f, 1.0f, 0.0f);
	gluQuadricNormals(head, GLU_SMOOTH);
	gluQuadricTexture(head, GL_FALSE);

	gluSphere(head, 7.5, 30, 30);

	gluDeleteQuadric(head);
}

/* draws the robot's body. */
void drawRobotBody(GLUquadricObj* body) {
	body = gluNewQuadric();
	glColor3f(0.5f, 0.5f, 0.0f);
	gluQuadricNormals(body, GLU_SMOOTH);
	gluQuadricTexture(body, GL_FALSE);

	gluCylinder(body, 10.0, 10.0, 20, 30, 30);

	gluDeleteQuadric(body);
}

/* draws the robot's right upper arm. */
void drawRobotRightUpperArm(GLUquadricObj* rightUpperArm) {
	rightUpperArm = gluNewQuadric();

	glColor3f(0.5f, 0.5f, 0.5f);

	gluQuadricNormals(rightUpperArm, GLU_SMOOTH);
	gluQuadricTexture(rightUpperArm, GL_FALSE);

	gluCylinder(rightUpperArm, 2.5, 2.5, 10, 30, 30);
	gluDeleteQuadric(rightUpperArm);
}

/* draws the robot's right forearm. */
void drawRobotRightLowerArm(GLUquadricObj* rightLowerArm) {
	rightLowerArm = gluNewQuadric();
	glColor3f(0.5f, 0.5f, 0.5f);

	gluQuadricNormals(rightLowerArm, GLU_SMOOTH);
	gluQuadricTexture(rightLowerArm, GL_FALSE);

	gluCylinder(rightLowerArm, 2.5, 2.5, 10, 30, 30);
	gluDeleteQuadric(rightLowerArm);
}

/* draws the robot's right hand palm. */
void drawRobotRightPalm(GLUquadricObj* rightPalm) {
	rightPalm = gluNewQuadric();
	glColor3f(0.5f, 0.5f, 0.5f);

	gluQuadricNormals(rightPalm, GLU_SMOOTH);
	gluQuadricTexture(rightPalm, GL_FALSE);

	gluCylinder(rightPalm, 2.5, 2.5, 5, 30, 30);
	gluDeleteQuadric(rightPalm);
}

/* draws the robot in it's entirety, calling all components drawing functions. */
void drawRobot(void* r) {
	Robot* robot = static_cast<Robot*>(r);
    glPushMatrix();

    // body position and direction
    glPushMatrix();
    glTranslatef(robot->getRobotCenterPointX(), robot->getRobotCenterPointY(), robot->getRobotCenterPointZ());
    glRotatef(robot->getBodyDirectionX(), 1.0f, 0.0f, 0.0f);
    glRotatef(robot->getBodyDirectionY(), 0.0f, 1.0f, 0.0f);
    glRotatef(robot->getBodyDirectionZ(), 0.0f, 0.0f, 1.0f);
    drawRobotBody(robot->getBody());
    glPopMatrix();

    // head position and direction
    glPushMatrix();
    glTranslatef(robot->getRobotCenterPointX(), robot->getRobotCenterPointY() + 10.0f, robot->getRobotCenterPointZ());
    glRotatef(robot->getViewDirectionX(), 1.0f, 0.0f, 0.0f);
    glRotatef(robot->getViewDirectionY(), 0.0f, 1.0f, 0.0f);
    glRotatef(robot->getViewDirectionZ(), 0.0f, 0.0f, 1.0f);
    drawRobotHead(robot->getHead());
    glPopMatrix();

    // shoulder joint
    glPushMatrix();
    glTranslatef(robot->getRobotCenterPointX() - 15.0f, robot->getRobotCenterPointY(), robot->getRobotCenterPointZ());
    glRotatef(robot->getShoulderDirectionX(), 1.0f, 0.0f, 0.0f);
    glRotatef(robot->getShoulderDirectionY(), 0.0f, 1.0f, 0.0f);
    glRotatef(robot->getShoulderDirectionZ(), 0.0f, 0.0f, 1.0f);
    drawRobotRightUpperArm(robot->getRightUpperArm());

    // draw lower arm
    glTranslatef(0.0f, 0.0f, 10.0f);
    glRotatef(robot->getElbowDirectionX(), 1.0f, 0.0f, 0.0f);
    glRotatef(robot->getElbowDirectionY(), 0.0f, 1.0f, 0.0f);
    glRotatef(robot->getElbowDirectionZ(), 0.0f, 0.0f, 1.0f);
    glPushMatrix();
    drawRobotRightLowerArm(robot->getRightLowerArm());

    // draw palm
    glTranslatef(0.0f, 0.0f, 10.0f);
    glRotatef(robot->getPalmDirectionX(), 1.0f, 0.0f, 0.0f);
    glRotatef(robot->getPalmDirectionY(), 0.0f, 1.0f, 0.0f);
    glRotatef(robot->getPalmDirectionZ(), 0.0f, 0.0f, 1.0f);
    glPushMatrix();
    drawRobotRightPalm(robot->getRightPalm());
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
}
