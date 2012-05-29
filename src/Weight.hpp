/*
 * Weight.hpp
 *
 *  Created on: 29-mei-2012
 *      Author: stefan
 */

#ifndef WEIGHT_HPP_
#define WEIGHT_HPP_

#include "World.hpp"
#include "Actor.hpp"
#include <Box2D.h>

using namespace std;
namespace capselchi {
class Weight :public Actor{
public:
	Weight(World* world, b2Vec2 position, float32 weight, b2BodyDef def);
	~Weight(void);
	b2Vec2 getPosition();
	float32 getWeight();
	b2Body* getBody();

private:
	World* world;
	b2Vec2 position;
	float32 weight;
	b2Body* body;
};

}  // namespace capselchi

#endif /* WEIGHT_HPP_ */
