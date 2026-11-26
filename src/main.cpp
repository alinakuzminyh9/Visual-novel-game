#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>

int main()
{
    sf::RenderWindow window(sf::VideoMode({1280u, 720u}), "Визуальная новелла");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.openFromFile("assets/fonts/arial.ttf"))
    {
        std::cout << "Ошибка: не найден шрифт!\n";
        std::cout << "Положи файл .ttf в папку assets/fonts/\n";
        return 1;
    }

    sf::Text text(font, "Привет! Это начало новеллы.\nНажми ПРОБЕЛ, чтобы продолжить.", 28);
    text.setFillColor(sf::Color::White);
    text.setPosition({50.f, 550.f});

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (const auto* key = event->getIf<sf::Event::KeyPressed>())
            {
                if (key->code == sf::Keyboard::Key::Space)
                {
                    text.setString("Отлично! Теперь можно делать выборы.");
                }
            }
        }

        window.clear(sf::Color(25, 25, 45));
        window.draw(text);
        window.display();
    }

    return 0;
}

