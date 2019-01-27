#pragma once

#include <iostream>
#include <glm.hpp>
using namespace std;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject() = 0;

	virtual void Update() = 0;
	virtual void Render() = 0;

	// Setters
	void SetPosition(glm::vec2 Pos) { position = Pos; }
	void SetSize(glm::vec2 Size) { size = Size; }
	void SetAngle(float Angle) { angle = Angle; }

	void SetIsActive(bool Active) { isActive = Active; }
	void SetIsAlive(bool Alive) { isAlive = Alive; }
	void SetIsVisible(bool Visible) { isVisible = Visible; }

	void SetTag(string Tag) { tag = Tag; }

	// Getters
	glm::vec2 GetPosition() { return position; }
	string GetTag() { return tag; }
	bool IsActive() { return isActive; }
	bool IsAlive() { return isAlive; }
	bool IsVisible() { return isVisible; }


protected:
	glm::vec2 position;
	glm::vec2 size;
	float angle;

	string tag;

	bool isActive;
	bool isAlive;
	bool isVisible;

};

