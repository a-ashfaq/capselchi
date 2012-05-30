/*
 * World.hpp
 *
 *  Created on: 21-mei-2012
 *      Author: stefan
 */

#ifndef WORLD_HPP_
#define WORLD_HPP_

#include "main.h"
#include <list>
#include "Balloon.hpp"
#include "Weight.hpp"
#include "Body.h"
#include "Fixture.h"

namespace capselchi {
	class Balloon;
	class Weight;
	class World {
		public:
			World(void);
			~World(void);
			void createBall(Balloon* balloon);
			void createWeight(Weight* weight);
			Body* getBall(int index);
			Body* getWeight(int index);
			void reset(void);
			Body* createBody(b2BodyDef* def);
			void removeBall(Balloon* balloon);
			void destroyBody(Body* body);

		private:
			b2World* world;
			list<Body*> ballBodies;
			list<Balloon*> balloons;
			list<Body*> weights;
			Body* base;
			Body* seesaw;
			list<Body*> bodies;
	};

} // namespace capselchi


#endif /* WORLD_HPP_ */
