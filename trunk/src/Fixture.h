/*
 * Fixture.h
 *
 *  Created on: May 30, 2012
 *      Author: koen
 */

#ifndef FIXTURE_H_
#define FIXTURE_H_

#include <Box2D/Box2D.h>
#include "Body.h"

namespace capselchi {

class Body;

class Fixture {
	public:
		Fixture();
		virtual ~Fixture();


	private:
		b2Body* parentBody;
		b2Color color;
};

}

#endif /* FIXTURE_H_ */
