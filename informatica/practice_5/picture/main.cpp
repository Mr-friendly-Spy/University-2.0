#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


int main()
{
	sf::RenderWindow window(sf::VideoMode({ 800, 600}), "Ship in sea");

	window.clear();

	sf::RectangleShape shape3;
	shape3.setSize({ 800, 400 });
	shape3.setRotation(180);
	shape3.setPosition({ 800, 400 });
	shape3.setFillColor(sf::Color(0x0, 191, 255));
	window.draw(shape3);

	sf::RectangleShape shape4;
	shape4.setSize({ 800, 400 });
	shape4.setRotation(180);
	shape4.setPosition({ 800, 800 });
	shape4.setFillColor(sf::Color(0x0, 0x0, 255));
	window.draw(shape4);

	sf::ConvexShape trapeze;
	trapeze.setPosition({ 400, 415 });
	trapeze.setFillColor(sf::Color(101, 55, 0));
	trapeze.setRotation(180);
	trapeze.setPointCount(4);
	trapeze.setPoint(0, {-90, 0});
	trapeze.setPoint(1, {90, 0});
	trapeze.setPoint(2, {140, 60});
	trapeze.setPoint(3, {-140, 60});
	window.draw(trapeze);

	sf::RectangleShape shape1;
	shape1.setSize({ 10, 200 });
	shape1.setRotation(180);
	shape1.setPosition({ 400, 390 });
	shape1.setFillColor(sf::Color(101, 55, 0));
	window.draw(shape1);

	sf::CircleShape shape2(75);
	shape2.setPointCount(3);
	shape2.setPosition({ 336, 250 });
	shape2.setRotation(-30);
	shape2.setFillColor(sf::Color(255, 255, 255));
	window.draw(shape2);

	window.display();

	sf::sleep(sf::seconds(3600));
}
