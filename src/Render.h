/*
 * Render.h
 *
 *  Created on: May 30, 2012
 *      Author: koen
 */

#ifndef RENDER_H_
#define RENDER_H_

#include "main.h"
#include "Body.h"
#include "Fixture.h"

#include <cstdio>
#include <cstdarg>
#include <cstring>

namespace capselchi {

	class Render {
		public:
			Render();
			virtual ~Render();

			void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);

			void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);

			void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);

			void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);

			void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);

			void DrawTransform(const b2Transform& xf);

			void DrawPoint(const b2Vec2& p, float32 size, const b2Color& color);

			void DrawString(int x, int y, const char* string, ...);

			void DrawShape(b2Fixture* fixture, const b2Transform& xf, const b2Color& color);

			void DrawDebugData(list<Body*> bodies);
	};

}

#endif /* RENDER_H_ */
