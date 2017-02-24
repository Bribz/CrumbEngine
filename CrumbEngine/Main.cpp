// Main.cpp
// Entry point of program
// Bribz - 2/22/2017

#include "CrumbMain.h"
//#include "btBulletDynamicsCommon.h"

int main(int argc, char ** argv)
{
	/*
	btBroadphaseInterface * broadphase = new btDbvtBroadphase();
	btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();
	btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfiguration);

	btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver;

	btDiscreteDynamicsWorld* dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration);
	dynamicsWorld->setGravity(btVector3(0, -10, 0));
	*/
	
	CrumbMain *game = new CrumbMain();
	delete game;

	/*
	delete dynamicsWorld;
	delete solver;
	delete dispatcher;
	delete collisionConfiguration;
	delete broadphase;
	*/

	return 0;
}
