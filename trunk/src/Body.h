/*
 * Body.h
 *
 *  Created on: May 30, 2012
 *      Author: koen
 */

#ifndef BODY_H_
#define BODY_H_

#include <Box2D/Box2D.h>
#include <list>
#include "Fixture.h"
#include "main.h"

using namespace std;

namespace capselchi {

class Fixture;

class Body {
	public:
		Body(b2Body* body);
		virtual ~Body();
		b2Body* getBody();
		list<Fixture*> getFixtureList();
		Fixture* CreateFixture(b2FixtureDef* fixDef, b2Color color);
		Fixture* CreateFixture(b2Shape* fixDef, float32 density, b2Color color);
		void DestroyFixture(Fixture* fixture);


	private:
		b2Body* body;
		list<Fixture*> fixtures;


};

}

#endif /* BODY_H_ */
