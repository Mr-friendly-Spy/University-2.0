#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>

// ������� ��� ��������� �������
void drawGraph(sf::RenderWindow& window, std::function<float(float)> func,
    float xMin, float xMax, float scaleX, float scaleY,
    sf::Color color) {
    sf::VertexArray graph(sf::LinesStrip);

    for (float x = xMin; x <= xMax; x += 0.1f) {
        float y = func(x); // ���������� �������� �������

        // �������������� ��������� � ��������
        float screenX = 400 + x * scaleX;
        float screenY = 300 - y * scaleY;

        // ���������� ����� � ������ ������
        graph.append(sf::Vertex(sf::Vector2f(screenX, screenY), color));
    }

    window.draw(graph);
}

int main() {
    setlocale(LC_ALL, "RU_ru");
    // �������� ����
    sf::RenderWindow window(sf::VideoMode(800, 600),
        "An application for displaying graphs");

    // ���������� ��� �������� ���������������� �����
    sf::CircleShape userPoint(5); // ������ 5 ��������
    userPoint.setFillColor(sf::Color::Red);
    bool userPointExists =
        false; // ���������� ��� �������� ������������� ���������������� �����

    // 1 _ �������� ������ (�������� ���)
    // ...
    // ...
    //
    //
    sf::Font font;
    font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");

    // 2 _ ����� ��� ����������� ��������� ����� (�������� ���)
    // ������ ������ 20, ��������� ������ (10,10), ���� �����. ����� ������� �
    // ���������� coordinatesText
    // ...
    // ...
    //
    sf::Text coordinatesText("", font, 20);
    coordinatesText.setPosition(10, 10);
    coordinatesText.setFillColor(sf::Color::White);

    // ��� X � Y
    sf::VertexArray xAxis(sf::Lines, 2);
    xAxis[0].position = sf::Vector2f(50, 300);  // ������ ��� X
    xAxis[0].color = sf::Color::White;          // ���� ���
    xAxis[1].position = sf::Vector2f(750, 300); // ����� ��� X
    xAxis[1].color = sf::Color::White;

    sf::VertexArray yAxis(sf::Lines, 2);
    yAxis[0].position = sf::Vector2f(400, 50);  // ������ ��� Y
    yAxis[0].color = sf::Color::White;          // ���� ���
    yAxis[1].position = sf::Vector2f(400, 550); // ����� ��� Y
    yAxis[1].color = sf::Color::White;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // �������� ����� �����
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // ��������� ������� �����
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    // �������������� �������� ��������� � "��������������"
                    float mathX = (mousePos.x - 400) / 10.0f;  // ������� 30 �� X
                    float mathY = -(mousePos.y - 300) / 10.0f; // ������� 100 �� Y

                    // ��������� ����� ���������������� �����
                    userPoint.setPosition(mousePos.x - userPoint.getRadius(),
                        mousePos.y - userPoint.getRadius());
                    userPointExists = true; // ��������, ��� ����� ����������

                    std::string zone;

                    if (mathY == mathX + 9 || mathY == mathX * mathX) {
                        zone = "on the curve";
                    }
                    else if (mathY > mathX*mathX && mathY > mathX + 9) {
                        zone = "5";
                    }
                    else if (mathY > mathX + 9 && mathX < 0 && mathY < mathX*mathX) {
                        zone = "1";
                    }
                    else if (mathY > mathX + 9 && mathX > 0 && mathY < mathX * mathX) {
                        zone = "4";
                    }
                    else if (mathY < mathX*mathX) {
                        zone = "2";
                    }
                    else {
                        zone = "3";
                    }

                    // ���������� ������ � ������������ �����
                    coordinatesText.setString("Coordinates: (" + std::to_string(mathX) +
                        ", " + std::to_string(mathY) +
                        ")\nZone: " + zone);
                }
            }
        }

        // 4 _ ������� ������ (�������� ���)
        window.clear(sf::Color::Black);

        //

        // ��������� ����
        window.draw(xAxis);
        window.draw(yAxis);



            // 5 _  ��������� ������� y1 = 0.5*x (�������� �� ��� ������)
            drawGraph(
                window, [](float x) { return x * x; }, -10, 10, 10, 10, sf::Color::Blue);

        // 5 _   ��������� ������� y2 = x * x - 5 (�������� �� ��� ������)
        drawGraph(
            window, [](float x) { return x + 9; }, -100, 100, 10, 10,
            sf::Color::Red);

        // ��������� ���������������� �����, ���� ��� ����������
        if (userPointExists) {
            window.draw(userPoint);
            window.draw(coordinatesText);
        }

        // ����������� ������ �����
        window.display();
    }

    return 0;
}