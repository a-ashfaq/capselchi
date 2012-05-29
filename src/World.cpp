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

	World::World(){
		//TODO initialize seesaw and base
		b2Vec2 gravity;
		gravity.Set(0.0f, -10.0f);
		world = new b2World(gravity);
		b2BodyDef baseDef;
		baseDef.position.Set(0,0);
		base = world->CreateBody(&baseDef);
		b2BodyDef seesawDef;
		seesawDef.position.Set(0,1);
		seesawDef.type = b2_dynamicBody;
		seesaw = world->CreateBody(&seesawDef);
		//TODO create fixtures with shapes;
		b2Fixture* baseFixture = base->GetFixtureList();
		b2PolygonShape* baseShape = (b2PolygonShape*) &baseFixture->GetShape();
		float32 yCoord= 0;
		b2Vec2 baseContact;
		for(int32 index; index<baseShape->GetChildCount(); ++index){
			b2Vec2 vertex = baseShape->GetVertex(index);
			if(vertex.y>yCoord){
				yCoord = vertex.y;
				baseContact = vertex;
			}
		}
		b2Fixture* seesawFixture = seesaw->GetFixtureList();
		b2EdgeShape* seesawShape = (b2EdgeShape*) & seesawFixture->GetShape();
		//TODO joints

	}

	World::~World(){
		//TODO reset and destroy remaining artefacts
		delete world;
	}

	void World::createBall(Balloon* balloon){
		ballBodys.push_back(balloon->getBody());
		balloons.push_back(balloon);
	}

	void World::removeBall(Balloon* balloon){
		balloons.remove(balloon);
		ballBodys.remove(balloon->getBody());
	}

	void World::createWeight(Weight* weight){
		weights.push_back(weight->getBody());
		//TODO fixture & joint
	}

	b2Body* World::getBall(int index){
		//TODO get the ball at index location;
		return NULL;
	}

	b2Body* World::getWeight(int index){
		//TODO get weight at index location
		return NULL;
	}

	void World::reset(){
		//TODO reset world cleanup old world

	}

	b2Body* World::createBody(b2BodyDef def){
		return world->CreateBody(&def);
	}

	void World::destroyBody(b2Body* body){
		world->DestroyBody(body);
	}
}  // namespace capselchi



