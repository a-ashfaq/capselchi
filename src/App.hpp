/*
 * App.hpp
 *
 *  Created on: 1-mei-2012
 *      Author: stefan
 */

#ifndef APP_HPP_
#define APP_HPP_

#include "balltracking/balltracker.h"
#include <Box2D.h>
#include <GL/freeglut.h>
#include <GL/glui.h>
#include <Box2D/Box2D.h>

namespace capselchi {/// Test settings. Some can be controlled in the GUI.
	struct Settings
	{
		Settings() :
			viewCenter(0.0f, 20.0f),
			hz(60.0f),
			velocityIterations(8),
			positionIterations(3),
			enableWarmStarting(1),
			enableContinuous(1),
			enableSubStepping(0),
			pause(0),
			singleStep(0)
			{}

		b2Vec2 viewCenter;
		float hz;
		int velocityIterations;
		int positionIterations;
		int enableWarmStarting;
		int enableContinuous;
		int enableSubStepping;
		int pause;
		int singleStep;
	};

	class App {
		public:
			App();
			int run(void);
/*
 * @author Bart Bottu, Stefan Diels, Koen Van den Dries
 * A class that contains the game loop and game initialization. It also
 * processes user input in the form of a BallTracker.
 */
		protected:
			void init(void);
			void loop(void);
			void cleanup(void);
			static void Resize(int w, int h);
			static void render();
			static b2Vec2 ConvertScreenToWorld(int32 x, int32 y);
			static void Timer(int);
			static void Keyboard(unsigned char key, int x, int y);
			static void KeyboardUp(unsigned char key, int x, int y);
			static void KeyboardSpecial(int key, int x, int y);
			static void Mouse(int button, int state, int x, int y);
			static void MouseMotion(int x, int y);
			static void MouseWheel(int wheel, int direction, int x, int y);
			static void Restart(int);
			static void Pause(int);
			static void Exit(int code);
			static void SingleStep(int);
protected:
	/*
	 * Initialize game
	 */
	void init(void);
	/*
	 * run game until end conditions are met
	 * process input, generate output
	 */
	void loop(void);
	/*
	 * cleanup after game ends
	 */
	void cleanup(void);

private:
	BallTracker* ballTracker;
	b2World* world;
	State* state;
	Settings settings;
	int width;
	int height;
	int framePeriod;
	int mainWindow;
	float settingsHz;
	GLUI *glui;
	int tx, ty, tw, th;
	bool rMouseDown;
	b2Vec2 lastp;
};



} // namespace capselchi

#endif /* APP_HPP_ */
