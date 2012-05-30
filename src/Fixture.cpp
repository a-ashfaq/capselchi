/*
 * Fixture.cpp
 *
 *  Created on: May 30, 2012
 *      Author: koen
 */

#include "Fixture.h"

namespace capselchi {

Fixture::Fixture() {
	// TODO Auto-generated constructor stub

}

Fixture::~Fixture() {
	// TODO Auto-generated destructor stub
}

b2Body *Fixture::getParent() {
	return parentBody;
}

b2Fixture *Fixture::getFixture() {
	return fixture;
}

b2Color Fixture::getColor() {
	return color;
}

}
