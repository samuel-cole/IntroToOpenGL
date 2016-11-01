#ifndef PHYSICS_GAME_H
#define PHYSICS_GAME_H

#include "FleXBase.h"

//=======================================================
//FleX project addition
//=======================================================
//Class that handles all of the logic specific to the physics puzzle game.
class PhysicsGame : public FleXBase
{
public:
	//Enum for specifying the types of properties that the player is able to modify.
	enum PropertyTypes
	{
		GRAVITY,
		RESTITUTION,
		FRICTION,
	};

private:
	//Called when the game is started, handles setting up the first level.
	int Init() override;

	//Called every frame. Used for gameplay tasks that happen every frame- this primarily involves updating the physics properties for the scene based upon the player's input.
	void Update(float a_deltaTime) override;

	//Checks whether the goal object has reached the target area, or has touched a hazard object, and either resets the game (on contact with a hazard object) or goes to the next level (on contact with the target area).
	void CheckWin();

	//Loads the level specified as an argument. Starting game argument is for whether this is the first level loaded in, or if another level already exists.
	void LoadLevel(const int a_level, const bool a_startingGame = false);
	//The index of the currently loaded level.
	int m_loadedLevel;

	//Index of the goal object within the vectors of objects in the scene.
	//The goal object is the object that the player must attempt to move to the target shape as the goal of the game.
	unsigned int m_goalObjectIndex;
	//Index of the target area shape within FleX.
	//The target shape is the area that the player must move the goal object to in order to win the game.
	unsigned int m_targetShapeIndex;
	//Indices of each hazard object within the scene.
	//Hazard shapes are areas that the player must ensure that the goal object does not touch, and causes the player to lose the game on contact with the goal object.
	std::vector<unsigned int> m_hazardShapeIndices;

	//Render handle to the point light used with the goal object.
	unsigned int m_goalObjectLightIndex;

	FlexParams g_params;

	vec3 m_gravityDir;
	float m_gravityStrength;

	vec3 m_oldGravityDir;
	float m_oldGravityStrength;

	float m_restitution;
	float m_oldRestitution;

	float m_currentLevelTime;

	char m_modifiablePropertiesMask;
};

#endif