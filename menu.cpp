#include "menu.h"

Menu::Menu(GameEngine* game)
{
}

void Menu::Update(RenderWindow& window)
{

}

void Menu::HandleEvents(GameEngine* game)
{	
	if (Keyboard::isKeyPressed(Keyboard::Left)) { herosprite.move(-0.5, 0); } //первая координата Х отрицательна =>идём влево
	if (Keyboard::isKeyPressed(Keyboard::Right)) { herosprite.move(0.5, 0); } //первая координата Х положительна =>идём вправо
	if (Keyboard::isKeyPressed(Keyboard::Up)) { herosprite.move(0, -0.5); } //вторая координата (У) отрицательна =>идём вверх (вспоминаем из предыдущих уроков почему именно вверх, а не вниз)
	if (Keyboard::isKeyPressed(Keyboard::Down)) { herosprite.move(0, 0.5); } //вторая координата (У) положительна =>идём вниз (если не понятно почему именно вниз - смотрим предыдущие уроки
}

void Menu::Draw(RenderWindow& window)
{
		window.draw(text);
		window.draw(herosprite);
}
