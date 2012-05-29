/*
 * Balloon.cpp
 *
 *  Created on: 1-mei-2012
 *      Author: stefan
 */
#include <stddef.h>
#include <assert.h>
#include "Balloon.hpp"
namespace capselchi {

	Balloon::Balloon(World* world, string colorName, float32 x, float32 y, float32 r, b2BodyDef bodyDef){
		position = new b2Vec2(x,y);
		this->r = r;
		this->colorName = colorName;
		bodyDef.userData = this;
		bodyDef.type = b2_dynamicBody;
		this->world = world;
		this->body = world->createBody(bodyDef);
		this->world->createBall(this);
	}

	Balloon::~Balloon(){
		body->SetUserData(NULL);
		world->removeBall(this);
		world->destroyBody(body);
	}

	b2Vec2 Balloon::getPösition(){
		return position;
	}

	float32 Balloon::getRadius(){
		return r;
	}

	b2Body* Balloon::getBody(){
		return body;
	}

	string Balloon::getColor(){
		return colorName;
	}

	int Balloon::isColor(string colorName){
		return this->colorName.compare(colorName);
	}

}  // namespace capselchi


