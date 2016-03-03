#include "Physics.h"

Physics::Physics() {
}

Physics::~Physics() {
}

float Physics::getAccelerationFM(float F, float M) {

	return F/M;

}

float Physics::getAccelerationVUT(float v, float u, float t) {

	return (v - u)/t;

}


float Physics::getVelocityUTA(float u, float t, float a) {

	return u + a*t;

}

float Physics::getVelocityUAS(float u, float a, float s) {

	return sqrt(u*u + 2*a*s);

}

float Physics::getDisplacementUVT(float u, float v, float t) {

	return 0.5 * (v + u) * t;

}

float Physics::getDisplacementUTA(float u, float t, float a) {

	return u*t + 0.5*a*t*t;

}

float Physics::getMomentum(float v, float m) {

	return v * m;

}

float Physics::getImpulse(float F, float t) {

	return F * t;

}

float Physics::getDistance(Vector3 a, Vector3 b) {

	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z));

}