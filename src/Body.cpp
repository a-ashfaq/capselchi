/*
 * Body.cpp
 *
 *  Created on: May 30, 2012
 *      Author: koen
 */

#include "Body.h"

namespace capselchi {

Body::Body(b2Body* body) {
	this->body = body;
}

Body::~Body() {
	list<Fixture*> fixtures = this->getFixtureList();
	list<Fixture*>::iterator fIter;
	for (fIter = fixtures.begin(); fIter != fixtures.end(); ++fIter) {
		Fixture* f = *fIter;
		delete f;
	}
}

b2Body *Body::getBody() {
	return body;
}

list<Fixture*> Body::getFixtureList() {
	return fixtures;
}

    Fixture *Body::CreateFixture(b2FixtureDef *fixDef, b2Color color)
    {
    }

    void Body::DestroyFixture(Fixture *fixture)
    {
    }

    Fixture *Body::CreateFixture(b2Shape *fixDef, float32 density, b2Color color)
    {
    }

}
