/*
 * main.h
 *
 *  Created on: May 30, 2012
 *      Author: koen
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <Box2D/Box2D.h>
#include <GL/freeglut.h>
#include <GL/glui.h>

using namespace std;

namespace {

	struct Settings {
			Settings() :
				viewCenter(0.0f, 20.0f), hz(60.0f), velocityIterations(8), positionIterations(3), enableWarmStarting(1),
						enableContinuous(0), enableSubStepping(0), pause(0), singleStep(0), gravity(9.81f) {
			}

			b2Vec2 viewCenter;
			float hz;
			int velocityIterations;
			int positionIterations;
			int enableWarmStarting;
			int enableContinuous;
			int enableSubStepping;
			int pause;
			int singleStep;
			float gravity;

	};

	Settings settings;
	int32 width = 640;
	int32 height = 480;
	int32 framePeriod = 16;
	int32 mainWindow;
	float settingsHz = 60.0;
	GLUI *glui;
	float32 viewZoom = 1.0f;
	int tx, ty, tw, th;
	bool rMouseDown;
}

#endif /* MAIN_H_ */
