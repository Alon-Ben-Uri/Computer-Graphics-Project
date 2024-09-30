#include "OpenGL Project.h"

using namespace std;

Robot* r = new Robot(50.0f,  25.0f, 50.0f,   // robot center position
                     50.0f,  50.0f, 100.0f,  // robot face view direction
                     90.0f,  0.0f,  0.0f,   // body direction
                     90.0f,  0.0f,  0.0f,    // shoulder direction
                     0.0f,  0.0f,  0.0f,    // elbow direction
                     0.0f,  0.0f,  0.0f);   // palm direction

Camera* c = new Camera(50.0f, 50.0f, -150.0f,   // camera position
                       50.0f, 50.0f, 50.0f);    // camera direction

GLboolean robotPerspective = false;
GLboolean cameraPerspective = false;

GLfloat windowWidth = 800.0f, windowHeight = 600.0f;

GLfloat ambient[] = { 0.3f, 0.3f, 0.3f, 1.0 };      // Ambient light intensity
GLfloat specular[] = { 0.3f, 0.3f, 0.3f, 1.0f };    // Specular light intensity
GLfloat diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };     // Diffuse light intensity

/* initializes 3d, lighting and perspective. */
void init(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glViewport(0, 0, (GLsizei)windowWidth, (GLsizei)windowHeight);

    glShadeModel(GL_SMOOTH);   // Enable smooth shading
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

    //glColorMaterial(GL_FRONT, GL_EMISSION);
    GLfloat light_position[] = { 100.0, 100.0, 100.0, 0.0 }; // Light position (xyzw)
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, windowWidth / windowHeight, 1, 1001);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(50.0, 50.0, -150.0,
        50.0, 50.0, 50.0,
        0.0, 1.0, 0.0);
}

/* reshapes all objects when the user changes the window size. */
void reshape(int width, int height) {
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, windowWidth / windowHeight, 1, 1001);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(50.0, 50.0, -150.0,
        50.0, 50.0, 50.0,
        0.0, 1.0, 0.0);
}

/* draws a paved and polished floor. */
void drawFloor(void) {
    GLfloat maxStructuralBorder = 200.0f;

    int gridSize = 10;          // Size of the grid (10x10 tiles)
    float tileSize = 10.0f;      // Size of each tile

    for (int i = -gridSize; i < gridSize; i++) {
        for (int j = -gridSize; j < gridSize; j++) {
            glBegin(GL_QUADS); // Draw a quad for each tile
            // Alternate color for a checkerboard pattern
            if ((i + j) % 2 == 0) {
                glColor3f(0.7f, 0.7f, 0.7f); // Light gray
            }
            else {
                glColor3f(0.3f, 0.3f, 0.3f); // Dark gray
            }

            glNormal3f(0.0f, 1.0f, 0.0f); // Normal pointing up
            glVertex3f(i * tileSize + maxStructuralBorder / 2, 0.0f, j * tileSize + maxStructuralBorder / 2);
            glVertex3f((i + 1) * tileSize + maxStructuralBorder / 2, 0.0f, j * tileSize + maxStructuralBorder / 2);
            glVertex3f((i + 1) * tileSize + maxStructuralBorder / 2, 0.0f, (j + 1) * tileSize + maxStructuralBorder / 2);
            glVertex3f(i * tileSize + maxStructuralBorder / 2, 0.0f, (j + 1) * tileSize + maxStructuralBorder / 2);
            glEnd();
        }
    }
}

/* draws the room in which all objects are stored. */
void drawRoom(void) {
    GLfloat maxStructuralBorder = 200.0f;
    // start of drawing the room
    glBegin(GL_QUADS);

    // right wall
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, maxStructuralBorder);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, maxStructuralBorder, maxStructuralBorder);
    glVertex3f(0.0f, maxStructuralBorder, 0.0f);

    //back wall
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, maxStructuralBorder);
    glVertex3f(maxStructuralBorder, 0.0f, maxStructuralBorder);

    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(maxStructuralBorder, maxStructuralBorder, maxStructuralBorder);
    glVertex3f(0.0f, maxStructuralBorder, maxStructuralBorder);

    // left wall
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(maxStructuralBorder, 0.0f, maxStructuralBorder);
    glVertex3f(maxStructuralBorder, 0.0f, 0.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(maxStructuralBorder, maxStructuralBorder, 0.0f);
    glVertex3f(maxStructuralBorder, maxStructuralBorder, maxStructuralBorder);

    // ceiling
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.0f, maxStructuralBorder, 0.0f);
    glVertex3f(0.0f, maxStructuralBorder, maxStructuralBorder);
    glVertex3f(maxStructuralBorder, maxStructuralBorder, maxStructuralBorder);
    glVertex3f(maxStructuralBorder, maxStructuralBorder, 0.0f);

    drawFloor();

    glEnd();  // End of drawing the room.
}

/* 1st object - draws a lantern that is also an adjustable light source. */
void drawLantern() {

    GLfloat lightPos[] = { 100.0f, 150.0f, 100.0f, 1.0f };
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glMaterialfv(GL_FRONT, GL_SPECULAR, lightPos);
    glMaterialf(GL_FRONT, GL_SHININESS, 64.0f);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

    glPushMatrix();
    // Scale the lantern by 10x and move it to (100, 100, 100)
    glTranslatef(100.0f, 100.0f, 100.0f);
    glScalef(10.0f, 10.0f, 10.0f);

    // Base of the lantern
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glColor3f(0.8f, 0.8f, 0.8f); // Gray color
    GLUquadric* base = gluNewQuadric();
    gluCylinder(base, 1.5, 1.5, 3.0, 32, 32); // Draw the lantern's cylindrical body
    glPopMatrix();

    // Top cover of the lantern
    glPushMatrix();
    glTranslatef(0.0f, 3.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.5f); // Darker gray for the top
    glutSolidSphere(1.5, 32, 32); // Top cover
    glPopMatrix();

    // Bottom cover of the lantern
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.5f); // Darker gray for the bottom
    glutSolidSphere(1.5, 32, 32); // Bottom cover
    glPopMatrix();

    glPopMatrix();

}

/* 2nd object - draws a tree. */
void drawTree() {
    glPushMatrix();
    glColor3f(0.55f, 0.27f, 0.07f); // Brown color for the trunk
    glTranslatef(150.0f, 50.0f, 150.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    GLUquadric* quadric = gluNewQuadric();
    gluCylinder(quadric, 10, 10, 50.0, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f, 0.8f, 0.0f); // Green color for the leaves
    glTranslatef(150.0f, 50.0f, 150.0f);
    glutSolidSphere(15.0, 32, 32); // Top sphere
    glTranslatef(0.0f, 10.0f, 0.0f);
    glutSolidSphere(12.0, 32, 32); // 1st-Middle sphere
    glTranslatef(0.0f, 10.0f, 0.0f);
    glutSolidSphere(9.0, 32, 32); // 2nd-Middle sphere
    glTranslatef(0.0f, 10.0f, 0.0f);
    glutSolidSphere(6.0, 32, 32); // Bottom sphere
    glPopMatrix();
}

/* 3rd object - draws a metalic, light reflecting sphere. */
void drawMetalicSphere(void) {
    GLfloat matSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat matShininess[] = { 50.0 };

    // Draw a metallic sphere
    glPushMatrix();
    glTranslatef(100.0f, 10.0f, 100.0f); // Position it above the floor
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);
    glColor3f(0.8f, 0.8f, 0.8f); // Slightly grayish color
    glutSolidSphere(10.0, 30, 30); // Radius 10
    glPopMatrix();

    // Reset to default material for non-metallic objects
    GLfloat noSpecular[] = { 0.0, 0.0, 0.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_SPECULAR, noSpecular);
}

/* displays all shapes, objects and spaces. */
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawRoom();
    drawRobot(r);           
    drawLantern();          // 1st object + direct light source
    drawTree();             // 2nd object
    drawMetalicSphere();    // 3rd object

    glutSwapBuffers();
}

/* changes perspective to the robot's perspective. */
void changeToRobotPerspective(void) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(r->getRobotCenterPointX(), r->getRobotCenterPointY() + 10.0f, r->getRobotCenterPointZ() + 10.0f,
        r->getViewDirectionX(), r->getViewDirectionY(), r->getViewDirectionZ(),
        0.0, 1.0, 0.0);
}

/* changes perspective to the camera's perspective. */
void changeCameraPerspective(void) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(c->getCameraCoordX(), c->getCameraCoordY(), c->getCameraCoordZ(),
        c->getCameraDirectionX(), c->getCameraDirectionY(), c->getCameraDirectionZ(),
        0.0, 1.0, 0.0);
}

/* determines how movement and perspective keys are enabled and used. */
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    /* CAMERA AND BODY MOVEMENT KEYS */
    case 'w':
        if (cameraPerspective)
            c->setCameraCoords(c->getCameraCoordX(), c->getCameraCoordY(), c->getCameraCoordZ() + CAMERA_SPEED);
        else
            r->setRobotCenterPointZ(r->getRobotCenterPointZ() + ROBOT_MOVEMENT_SPEED);
        break;
    case 's':
        if (cameraPerspective)
            c->setCameraCoords(c->getCameraCoordX(), c->getCameraCoordY(), c->getCameraCoordZ() - CAMERA_SPEED);
        else 
            r->setRobotCenterPointZ(r->getRobotCenterPointZ() - ROBOT_MOVEMENT_SPEED);
        break;
    case 'a':
        if (cameraPerspective)
            c->setCameraCoords(c->getCameraCoordX() + CAMERA_SPEED, c->getCameraCoordY(), c->getCameraCoordZ());
        else {
            r->setRobotCenterPointX(r->getRobotCenterPointX() + ROBOT_MOVEMENT_SPEED);
        }
        break;
    case 'd':
        if (cameraPerspective)
            c->setCameraCoords(c->getCameraCoordX() - CAMERA_SPEED, c->getCameraCoordY(), c->getCameraCoordZ());
        else {
            r->setRobotCenterPointX(r->getRobotCenterPointX() - ROBOT_MOVEMENT_SPEED);
        }
        break;


    /* CAMERA UP AND DOWN */
    case '-':
        if (cameraPerspective)
            c->setCameraCoords(c->getCameraCoordX(), c->getCameraCoordY() - CAMERA_SPEED, c->getCameraCoordZ());
        break;
    case '+':
        if (cameraPerspective)
            c->setCameraCoords(c->getCameraCoordX(), c->getCameraCoordY() + CAMERA_SPEED, c->getCameraCoordZ());
        break;


    /* SHOULDER MOVEMENT KEYS */
    case '5':
        r->setShoulderDirectionX(r->getShoulderDirectionX() - ROBOT_MOVEMENT_SPEED);
        break;
    case 'r':
        r->setShoulderDirectionY(r->getShoulderDirectionY() + ROBOT_MOVEMENT_SPEED);
        break;
    case 't':
        r->setShoulderDirectionX(r->getShoulderDirectionX() + ROBOT_MOVEMENT_SPEED);
        break;
    case 'y':
        r->setShoulderDirectionY(r->getShoulderDirectionY() - ROBOT_MOVEMENT_SPEED);
        break;


    /* ELBOW MOVEMENT KEYS */
    case '8':
        r->setElbowDirectionX(r->getElbowDirectionX() - ROBOT_MOVEMENT_SPEED);
        break;
    case 'u':
        r->setElbowDirectionY(r->getElbowDirectionY() + ROBOT_MOVEMENT_SPEED);
        break;
    case 'i':
        r->setElbowDirectionX(r->getElbowDirectionX() + ROBOT_MOVEMENT_SPEED);
        break;
    case 'o':
        r->setElbowDirectionY(r->getElbowDirectionY() - ROBOT_MOVEMENT_SPEED);
        break;


    /* PALM MOVEMENT KEYS */
    case 'h':
        r->setPalmDirectionX(r->getPalmDirectionX() - ROBOT_MOVEMENT_SPEED);
        break;
    case 'b':
        r->setPalmDirectionY(r->getPalmDirectionY() + ROBOT_MOVEMENT_SPEED);
        break;
    case 'n':
        r->setPalmDirectionX(r->getPalmDirectionX() + ROBOT_MOVEMENT_SPEED);
        break;
    case 'm':
        r->setPalmDirectionY(r->getPalmDirectionY() - ROBOT_MOVEMENT_SPEED);
        break;


    /* SPECIAL KEYS*/
    case 'p':
        if (robotPerspective == true) {
            robotPerspective = false;
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(c->getCameraCoordX(), c->getCameraCoordY(), c->getCameraCoordZ(),
                c->getCameraDirectionX(), c->getCameraDirectionY(), c->getCameraDirectionZ(),
                0.0, 1.0, 0.0);
        }
        else
            robotPerspective = true;        
        break;
    case 'c':
        if (cameraPerspective == true)
            cameraPerspective = false;
        else
            cameraPerspective = true;
        break;
    }

    if (robotPerspective == true)
        changeToRobotPerspective();
    else
        changeCameraPerspective();
  
    glutPostRedisplay();
}

/* arrow key usages */
void specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        if (cameraPerspective)
            c->setCameraDirection(c->getCameraDirectionX(), c->getCameraDirectionY() + CAMERA_SPEED, c->getCameraDirectionZ());
        else
            r->setViewDirectionY(r->getViewDirectionY() + ROBOT_MOVEMENT_SPEED);
        break;
    case GLUT_KEY_RIGHT:
        if (cameraPerspective)
            c->setCameraDirection(c->getCameraDirectionX() - CAMERA_SPEED, c->getCameraDirectionY(), c->getCameraDirectionZ());
        else
            r->setViewDirectionX(r->getViewDirectionX() - ROBOT_MOVEMENT_SPEED);
        break;
    case GLUT_KEY_LEFT:
        if (cameraPerspective)
            c->setCameraDirection(c->getCameraDirectionX() + CAMERA_SPEED, c->getCameraDirectionY(), c->getCameraDirectionZ());
        else
            r->setViewDirectionX(r->getViewDirectionX() + ROBOT_MOVEMENT_SPEED);
        break;
    case GLUT_KEY_DOWN:
        if (cameraPerspective)
            c->setCameraDirection(c->getCameraDirectionX(), c->getCameraDirectionY() - CAMERA_SPEED, c->getCameraDirectionZ());
        else 
            r->setViewDirectionY(r->getViewDirectionY() - ROBOT_MOVEMENT_SPEED);
        break;
    }
    
    //printf("x: %f, y: %f, c: %f\n", c->getCameraDirectionX(), c->getCameraDirectionY(), c->getCameraDirectionZ());

    if (robotPerspective == true)
        changeToRobotPerspective();
    else
        changeCameraPerspective();

    glutPostRedisplay();
}

/* executes menu functionalities */
void menu(int option) {
    switch (option) {
    case 1: // Adjust ambient light
        cout << "Please enter 3 numbers to change ambient light (x, y, z):\n" << endl;
        cin >> ambient[0];
        cin >> ambient[1];
        cin >> ambient[2];
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
        break;
    case 2: // Adjust specular light
        cout << "Please enter 3 numbers to change ambient light(x, y, z) : \n" << endl;
        cin >> specular[0];
        cin >> specular[1];
        cin >> specular[2];
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, specular);
        break;
    case 3: // Help
        cout << "IO Controls:\n\n" << endl;
        cout << "Keyboard - w, a, s, d, move the robot forwards, right, down and left respectively.\n" << endl;
        cout << "Toggling on camera control, using 'c' means that from now on we move the camera in opposed to moving the robot.\n" << endl;
        cout << "'+/-' are used to move the camera up and down respectively.\n" << endl;
        cout << "The arrow keys move the camera's loot-at direction.\n" << endl;
        cout << "Toggling on the robot's perspective, using 'p', enables us to move and look around from the robot's perspective.\n\n" << endl;
        cout << "Mouse - right-clicking on the mouse opens the menu, and left click is used to select an option.\n" << endl;
        cout << "Lighting - to change the ambient or direct/specular light, right click on the window,\n choose one of the options, and input the wanted values in the CMD.\n" << endl;
        break;
    case 4: // Exit
        exit(0);
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    void display(void);
    void resize(int, int);
    void keyboard(unsigned char, int, int);
    void animate(void);
    void init(void);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Window Name");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    glutCreateMenu(menu);
    glutAddMenuEntry("Adjust ambient light", 1);
    glutAddMenuEntry("Adjust specular light", 2);
    glutAddMenuEntry("Help", 3);
    glutAddMenuEntry("Exit", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}
