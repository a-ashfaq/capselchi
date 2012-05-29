/*
 * App.cpp
 *
 *  Created on: 1-mei-2012
 *      Author: stefan
 */

#include <assert.h>
#include <stddef.h>
#include "App.hpp"

namespace capselchi {

		//TODO game loop
	int App::run(void) {
		init();
		loop();
		cleanup();
		return 0;
	}

	void App::init(void) {
		glutInit(0, 0);
		glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_MULTISAMPLE);
		glutInitWindowSize(width, height);
		mainWindow = glutCreateWindow("Balance");
		glutDisplayFunc(render);
		GLUI_Master.set_glutReshapeFunc(Resize);
		GLUI_Master.set_glutKeyboardFunc(Keyboard);
		GLUI_Master.set_glutSpecialFunc(KeyboardSpecial);
		GLUI_Master.set_glutMouseFunc(Mouse);
		glutMouseWheelFunc(MouseWheel);
		glutMotionFunc(MouseMotion);
		glutKeyboardUpFunc(KeyboardUp);
		glui = GLUI_Master.create_glui_subwindow(mainWindow, GLUI_SUBWINDOW_RIGHT );
		glui->add_separator();
		GLUI_Spinner* velocityIterationSpinner = glui->add_spinner("Vel Iters", GLUI_SPINNER_INT, &settings.velocityIterations);
		velocityIterationSpinner->set_int_limits(1, 500);
		GLUI_Spinner* positionIterationSpinner = glui->add_spinner("Pos Iters", GLUI_SPINNER_INT, &settings.positionIterations);
		positionIterationSpinner->set_int_limits(0, 100);
		GLUI_Spinner* hertzSpinner = glui->add_spinner("Hertz", GLUI_SPINNER_FLOAT, &settingsHz);
		hertzSpinner->set_float_limits(5.0f, 200.0f);
		glui->add_checkbox("Warm Starting", &settings.enableWarmStarting);
		glui->add_checkbox("Time of Impact", &settings.enableContinuous);
		glui->add_checkbox("Sub-Stepping", &settings.enableSubStepping);
		glui->add_button("Pause", 0, Pause);
		glui->add_button("Single Step", 0, SingleStep);
		glui->add_button("Restart", 0, Restart);
		glui->add_button("Quit", 0, (GLUI_Update_CB) (Exit));
		glui->set_main_gfx_window(mainWindow);
		glEnable(GL_MULTISAMPLE);
		// Use a timer to control the frame rate.
		glutTimerFunc(framePeriod, Timer, 0);
		glutMainLoop();

	}

	void App::loop(void) {
		//TODO game loop
	}

	App::App() {
		width = 640;
		height = 480;
		framePeriod = 16;
		settingsHz = 60.0f;
	}

	void App::cleanup(void) {
	}

	void App::KeyboardSpecial(int key, int x, int y) {
	}

	void App::Resize(int w, int h) {
	}

	b2Vec2 App::ConvertScreenToWorld(int32 x, int32 y) {
	}

	void App::Keyboard(unsigned char key, int x, int y) {
	}

	void App::Mouse(int button, int state, int x, int y) {
	}

	void App::Timer(int value) {
	}

	void App::MouseMotion(int x, int y) {
	}

	void App::KeyboardUp(unsigned char key, int x, int y) {
	}

	void App::MouseWheel(int wheel, int direction, int x, int y) {
	}

	void App::render(){
	}



	void App::Restart(int){
	   // Resize(width, height);
	}

	void App::Pause(int){
		//settings.pause = !settings.pause;
	}

	void App::Exit(int code){
		// TODO: freeglut is not building on OSX
	#ifdef FREEGLUT
		glutLeaveMainLoop();
	#endif
		exit(code);
	}

	void App::SingleStep(int){
		//settings.pause = 1;
		//settings.singleStep = 1;
	}


}
