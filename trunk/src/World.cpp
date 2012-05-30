/*
 * World.cpp
 *
 *  Created on: 21-mei-2012
 *      Author: stefan
 */
#include <assert.h>
#include <stddef.h>
#include "World.hpp"

namespace capselchi {

	World::World() {
		//TODO initialize seesaw and base
		b2Vec2 gravity;
		gravity.Set(0.0f, -settings.gravity);
		world = new b2World(gravity);
		b2BodyDef baseDef;
		baseDef.position.Set(0, 0);
		base = this->createBody(&baseDef);
		b2BodyDef seesawDef;
		seesawDef.position.Set(0, 1);
		seesawDef.type = b2_dynamicBody;
		seesaw = this->createBody(&seesawDef);
		//TODO create fixtures with shapes;
		Fixture* baseFixture = base->getFixtureList().front();
		b2PolygonShape* baseShape = (b2PolygonShape*) baseFixture->getFixture()->GetShape();
		float32 yCoord = 0;
		b2Vec2 baseContact;
		for (int32 index; index < baseShape->GetChildCount(); ++index) {
			b2Vec2 vertex = baseShape->GetVertex(index);
			if (vertex.y > yCoord) {
				yCoord = vertex.y;
				baseContact = vertex;
			}
		}
		Fixture* seesawFixture = seesaw->getFixtureList().front();
		b2EdgeShape* seesawShape = (b2EdgeShape*) seesawFixture->getFixture()->GetShape();
		//TODO joints

	}

	World::~World() {
		//TODO reset and destroy remaining artefacts
		delete world;
	}

	void World::createBall(Balloon* balloon) {
		balloons.push_back(balloon);
	}

	void World::removeBall(Balloon* balloon) {
		balloons.remove(balloon);
	}

	void World::createWeight(Weight* weight) {
		weights.push_back(weight->getBody());
		bodies.push_back(weight->getBody());
		//TODO fixture & joint
	}

	Body* World::getBall(int index) {
		//TODO get the ball at index location;
		return NULL;
	}

	Body* World::getWeight(int index) {
		//TODO get weight at index location
		return NULL;
	}

	void World::reset() {
		//TODO reset world cleanup old world

	}

	Body* World::createBody(b2BodyDef* def) {
		Body* body = new Body(world->CreateBody(def));
		bodies.push_back(body);
		return body;
	}

	void World::destroyBody(Body* body) {
		bodies.remove(body);
		delete body;
		world->DestroyBody(body->getBody());
	}
} // namespace capselchi


