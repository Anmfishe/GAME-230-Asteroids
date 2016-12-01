#include "Bullet.h"
#include "Ship.h"
#include "Asteroid.h"

using namespace sf;

void update_state(float dt);
void render_frame();
void load();
void loadAsteroids();
void make_bullet();
const int SCREENWIDTH = 800;
const int SCREENHEIGHT = 800;
int curr_asteroids;
int num_asteroids = 2;

Ship *ship;
RenderWindow window;

vector<GameObject*> SceneGraph;

int main()
{
	window.create(VideoMode(SCREENWIDTH, SCREENHEIGHT), "Asteroids");
	Clock clock;
	load();
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					make_bullet();
				}
			}
		}

		float dt = clock.restart().asSeconds();

		update_state(dt);
		render_frame();
		window.display();
	}

	return 0;
}

void update_state(float dt)
{
	for (auto i = SceneGraph.begin(); i != SceneGraph.end(); ++i) {
		if ((*i)->dead()) {
			delete (*i);
			SceneGraph.erase(i);
			break;
		}
		(*i)->update(dt, window);
	}
	ship->update(dt, window);
}

void render_frame()
{
	window.clear(Color(0, 0, 0));
	for (auto i = SceneGraph.begin(); i != SceneGraph.end(); ++i) {
		(*i)->render(window);
	}
	ship->render(window);
}
void load() {
	ship = new Ship(SCREENWIDTH, SCREENHEIGHT);
	curr_asteroids = num_asteroids;
	loadAsteroids();
}
void loadAsteroids() {
	for (int i = 0; i < num_asteroids; i++) {
		Asteroid *ast = new Asteroid();
		SceneGraph.push_back(ast);
	}
}
void make_bullet() {
	Bullet *b = ship->get_bullet();
	SceneGraph.push_back(b);
}