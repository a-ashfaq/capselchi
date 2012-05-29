/*
 * Balloon.hpp
 *
 *  Created on: 1-mei-2012
 *      Author: stefan
 */

#ifndef BALLOON_HPP_
#define BALLOON_HPP_

#include <string>
#include <Box2D/Box2D.h>
#include "World.hpp"
#include "Actor.hpp"

using namespace std;
namespace capselchi {

class World;

/**
 *
 */
class Balloon : public Actor{
public:
	Balloon(World* world, string colorName, float32 x, float32 y, float32 r, b2BodyDef bodyDef);
	~Balloon();
	b2Vec2 getPosition();
	float32 getRadius();
	b2Body* getBody();
	string getColor();
	int isColor(string colorName);
	//TODO modify body with modification of position and radius

private:
	World* world;
	string colorName;
	b2Vec2 position;
	float32 r;
	b2Body* body;
};

}  // namespace capselchi

#endif /* BALLOON_HPP_ */
