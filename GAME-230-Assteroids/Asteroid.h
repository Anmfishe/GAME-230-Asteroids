#pragma once
#include "GameObject.h"
class Asteroid :
	public GameObject
{
public:
	void update(float dt, RenderWindow &w) {

	};
	void render(RenderWindow &w) {
		w.draw(circle);
	};
	bool dead() {
		return false;
	};
	Asteroid();
	~Asteroid();
private:
	CircleShape circle;
	Vector2f vel;
};

