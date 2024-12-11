#include <SFML/Graphics.hpp>
#include "LiderBoard.h"
#include "GameMenu.h"
#include "Game.h"
using namespace sf;
RenderWindow window(VideoMode(600, 600), L"��� ����", Style::Close);
void Gam�Start();
void LiderWindows();
int main()
{
     
    // ������ �������������
    RectangleShape background(Vector2f(600, 600));
    // ��������� � ������������� �������� � ������������ menu9.jpg
    Texture texture_window;
    if (!texture_window.loadFromFile("image/menu.png")) return 4;
    background.setTexture(&texture_window);

        
    // �������� ������� ����
    String name_menu[]{ L"�����",L"������",L"�����" };

    // ������ ������� ����
    game::GameMenu mymenu(window, 300, 300, 3, name_menu, 50, 50);
    // ��������� ����� ��������� ������� ����
    mymenu.setColorTextMenu(Color(237, 147, 0), Color::Red, Color::Black);
    // ������������ �� ������ ������� ���� 
    mymenu.AlignMenu(2);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) window.close();
            if (event.type == Event::KeyReleased)
            {
                // ������� ����� ������� ����
                // ������ �� ���������� ������� �����
                if (event.key.code == Keyboard::Up) { mymenu.MoveUp(); }
                // ������ �� ���������� ������� ����
                if (event.key.code == Keyboard::Down) { mymenu.MoveDown(); }
                // ������ �� ���������� ������� Enter
                if (event.key.code == Keyboard::Return)
                {
                    // ��������� �� ��������� ����� ����
                    switch (mymenu.getSelectedMenuNumber())
                    {
                    case 0:/*window.setVisible(false)*/; Gam�Start();  break;
                    case 1:/*window.setVisible(false)*/; LiderWindows(); break;
                    case 2:window.close(); break;
                    }

                }
            }
        }

        window.clear();
        window.draw(background);        
        mymenu.draw();
        window.display();
    }


	return 0;
}
void LiderWindows()
{
    LiderBoard leaderBoard;
    leaderBoard.GetFile();

    window.setTitle("Leaders");

    RectangleShape background(Vector2f(600, 600));
    Texture texture_window;
    texture_window.loadFromFile("image/game.png");
    background.setTexture(&texture_window);

    Font font;
    font.loadFromFile("font/troika.otf");

    // ����� � ������������ ������
    Text text("Leader-board", font, 40);
    text.setFillColor(Color::Cyan);
    text.setPosition(200, 5);

    Text LeaderText(leaderBoard.TextRetunr() , font, 30);
    LeaderText.setFillColor(sf::Color(237, 147, 0));
    LeaderText.setOutlineThickness(2.f);
    LeaderText.setOutlineColor(sf::Color(205, 87, 0));
    LeaderText.setPosition(60, 40);

    Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) { window.close(); }
            if (event.type == Event::KeyPressed)
            {                
                if (event.key.code == Keyboard::Escape) { main();}
            }
        }
                
        window.clear();
        window.draw(background);
        window.draw(text);
        window.draw(LeaderText);
        window.display();
    }
}
void Gam�Start()
{
    // ������� ���� �������� 600 �� 600 � �������� ���������� 60 ������ � �������
    window.setTitle("15");
    window.setFramerateLimit(60);

    RectangleShape background(Vector2f(600, 600));
    // ��������� � ������������� �������� � ������������ menu9.jpg
    Texture texture_window;
    texture_window.loadFromFile("image/game.png");
    background.setTexture(&texture_window);

    Font font;
    font.loadFromFile("font/troika.otf");

    // ����� � ������������ ������
    Text text("Esc - Exit / Arrow Keys - Move Tile", font, 40);
    text.setFillColor(Color::Cyan);
    text.setPosition(5.f, 5.f);

    // ������� ������ ����
    Game game;
    game.setPosition(50.f, 50.f);

    Event event;
    int move_counter = 0;	// ������� ��������� ����� ��� ������������� �����������
    
    game.Init();
    move_counter = 100;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) { window.close();}
            if (event.type == Event::KeyPressed)
            {
                // �������� ������� ������� - ��������� ��������������� ��������
                if (event.key.code == Keyboard::Escape) {main();}
                if (event.key.code == Keyboard::Left) game.Move(Direction::Left);
                if (event.key.code == Keyboard::Right) game.Move(Direction::Right);
                if (event.key.code == Keyboard::Up) game.Move(Direction::Up);
                if (event.key.code == Keyboard::Down) game.Move(Direction::Down);                
            }
        }

        // ���� ������� ����� ������ ����, ���������� ������������ �����������
        if (move_counter-- > 0) game.Move((Direction)(rand() % 4));

        // ��������� ����������� �������� �� ���������
        window.clear();
        window.draw(background);
        window.draw(game);
        window.draw(text);
        window.display();
    }
}