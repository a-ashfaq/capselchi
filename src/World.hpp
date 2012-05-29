/*
 * World.hpp
 *
 *  Created on: 21-mei-2012
 *      Author: stefan
 */

#ifndef WORLD_HPP_
#define WORLD_HPP_

#include <Box2D.h>
#include <list>
#include "Balloon.hpp"
#include "Weight.hpp"

using namespace std;
namespace capselchi {

class World {
public:
	World(void);
	~World(void);
	void createBall(Balloon* balloon);
	void createWeight(Weight* weight);
	b2Body* getBall(int index);
	b2Body* getWeight(int index);
	void reset(void);
	b2Body* createBody(b2BodyDef def);
	void removeBall(Balloon* balloon);
	void destroyBody(b2Body* body);

private:
	b2World* world;
	list<b2Body*> ballBodys;
	list<Balloon*> balloons;
	list<b2Body*> weights;
	b2Body* base;
	b2Body* seesaw;
};

}  // namespace capselchi



#endif /* WORLD_HPP_ */
