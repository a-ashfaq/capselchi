/*
 * Render.cpp
 *
 *  Created on: May 30, 2012
 *      Author: koen
 */

#include "Render.h"

namespace capselchi {

Render::Render() {
	// TODO Auto-generated constructor stub

}

Render::~Render() {
	// TODO Auto-generated destructor stub
}

void Render::DrawShape(b2Fixture* fixture, const b2Transform& xf, const b2Color& color) {
	switch (fixture->GetType()) {
		case b2Shape::e_circle: {
			b2CircleShape* circle = (b2CircleShape*) fixture->GetShape();

			b2Vec2 center = b2Mul(xf, circle->m_p);
			float32 radius = circle->m_radius;
			b2Vec2 axis = b2Mul(xf.q, b2Vec2(1.0f, 0.0f));

			this->DrawSolidCircle(center, radius, axis, color);
		}
			break;

		case b2Shape::e_edge: {
			b2EdgeShape* edge = (b2EdgeShape*) fixture->GetShape();
			b2Vec2 v1 = b2Mul(xf, edge->m_vertex1);
			b2Vec2 v2 = b2Mul(xf, edge->m_vertex2);
			this->DrawSegment(v1, v2, color);
		}
			break;

		case b2Shape::e_chain: {
			b2ChainShape* chain = (b2ChainShape*) fixture->GetShape();
			int32 count = chain->m_count;
			const b2Vec2* vertices = chain->m_vertices;

			b2Vec2 v1 = b2Mul(xf, vertices[0]);
			for (int32 i = 1; i < count; ++i) {
				b2Vec2 v2 = b2Mul(xf, vertices[i]);
				this->DrawSegment(v1, v2, color);
				this->DrawCircle(v1, 0.05f, color);
				v1 = v2;
			}
		}
			break;

		case b2Shape::e_polygon: {
			b2PolygonShape* poly = (b2PolygonShape*) fixture->GetShape();
			int32 vertexCount = poly->m_vertexCount;
			b2Assert(vertexCount <= b2_maxPolygonVertices);
			b2Vec2 vertices[b2_maxPolygonVertices];

			for (int32 i = 0; i < vertexCount; ++i) {
				vertices[i] = b2Mul(xf, poly->m_vertices[i]);
			}

			this->DrawSolidPolygon(vertices, vertexCount, color);
		}
			break;

		default:
			break;
	}
}

void Render::DrawDebugData(list<Body*> bodies) {

	list<Body*>::iterator bIter;
	for (bIter = bodies.begin(); bIter != bodies.end(); ++bIter) {
		Body* b = *bIter;
		const b2Transform& xf = b->GetTransform();
		for (Fixture* f = b->GetFixtureList(); f; f = f->GetNext()) {
			if (b->IsActive() == false) {
				DrawShape(f, xf, b2Color(0.5f, 0.5f, 0.3f));
			} else if (b->GetType() == b2_staticBody) {
				DrawShape(f, xf, b2Color(0.5f, 0.9f, 0.5f));
			} else if (b->GetType() == b2_kinematicBody) {
				DrawShape(f, xf, b2Color(0.5f, 0.5f, 0.9f));
			} else if (b->IsAwake() == false) {
				DrawShape(f, xf, b2Color(0.6f, 0.6f, 0.6f));
			} else {
				DrawShape(f, xf, b2Color(0.9f, 0.7f, 0.7f));
			}
		}
	}

	if (flags & b2Draw::e_centerOfMassBit) {
		for (b2Body* b = m_bodyList; b; b = b->GetNext()) {
			b2Transform xf = b->GetTransform();
			xf.p = b->GetWorldCenter();
			this->DrawTransform(xf);
		}
	}
}

void Render::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
	glColor3f(color.r, color.g, color.b);
	glBegin( GL_LINE_LOOP);
		for (int32 i = 0; i < vertexCount; ++i) {
			glVertex2f(vertices[i].x, vertices[i].y);
		}
	glEnd();
}

void Render::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
	glEnable( GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0.5f * color.r, 0.5f * color.g, 0.5f * color.b, 0.5f);
	glBegin( GL_TRIANGLE_FAN);
		for (int32 i = 0; i < vertexCount; ++i) {
			glVertex2f(vertices[i].x, vertices[i].y);
		}
	glEnd();
	glDisable(GL_BLEND);

	glColor4f(color.r, color.g, color.b, 1.0f);
	glBegin( GL_LINE_LOOP);
		for (int32 i = 0; i < vertexCount; ++i) {
			glVertex2f(vertices[i].x, vertices[i].y);
		}
	glEnd();
}

void Render::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) {
	const float32 k_segments = 16.0f;
	const float32 k_increment = 2.0f * b2_pi / k_segments;
	float32 theta = 0.0f;
	glColor3f(color.r, color.g, color.b);
	glBegin( GL_LINE_LOOP);
		for (int32 i = 0; i < k_segments; ++i) {
			b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
			glVertex2f(v.x, v.y);
			theta += k_increment;
		}
	glEnd();
}

void Render::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) {
	const float32 k_segments = 16.0f;
	const float32 k_increment = 2.0f * b2_pi / k_segments;
	float32 theta = 0.0f;
	glEnable( GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0.5f * color.r, 0.5f * color.g, 0.5f * color.b, 0.5f);
	glBegin( GL_TRIANGLE_FAN);
		for (int32 i = 0; i < k_segments; ++i) {
			b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
			glVertex2f(v.x, v.y);
			theta += k_increment;
		}
	glEnd();
	glDisable(GL_BLEND);

	theta = 0.0f;
	glColor4f(color.r, color.g, color.b, 1.0f);
	glBegin( GL_LINE_LOOP);
		for (int32 i = 0; i < k_segments; ++i) {
			b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
			glVertex2f(v.x, v.y);
			theta += k_increment;
		}
	glEnd();

	b2Vec2 p = center + radius * axis;
	glBegin( GL_LINES);
		glVertex2f(center.x, center.y);
		glVertex2f(p.x, p.y);
	glEnd();
}

void Render::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) {
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_LINES);
		glVertex2f(p1.x, p1.y);
		glVertex2f(p2.x, p2.y);
	glEnd();
}

void Render::DrawTransform(const b2Transform& xf) {
	b2Vec2 p1 = xf.p, p2;
	const float32 k_axisScale = 0.4f;
	glBegin( GL_LINES);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(p1.x, p1.y);
		p2 = p1 + k_axisScale * xf.q.GetXAxis();
		glVertex2f(p2.x, p2.y);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(p1.x, p1.y);
		p2 = p1 + k_axisScale * xf.q.GetYAxis();
		glVertex2f(p2.x, p2.y);

	glEnd();
}

void Render::DrawPoint(const b2Vec2& p, float32 size, const b2Color& color) {
	glPointSize(size);
	glBegin(GL_POINTS);
		glColor3f(color.r, color.g, color.b);
		glVertex2f(p.x, p.y);
	glEnd();
	glPointSize(1.0f);
}

void Render::DrawString(int x, int y, const char *string, ...) {
	char buffer[128];

	va_list arg;
	va_start(arg, string);
	vsprintf(buffer, string, arg);
	va_end(arg);

	glMatrixMode( GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);
	gluOrtho2D(0, w, h, 0);
	glMatrixMode( GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glColor3f(0.9f, 0.6f, 0.6f);
	glRasterPos2i(x, y);
	int32 length = (int32) strlen(buffer);
	for (int32 i = 0; i < length; ++i) {
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, buffer[i]);
	}

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

}
