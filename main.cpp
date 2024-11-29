#include <SFML/Graphics.hpp>
#include "GameMenu.h"
#include "Game.h"
using namespace sf;
RenderWindow window;
void Gam�Start();

int main()
{
    // ������ ���� windows
    // ���������: ������ ���� ���������� �������� �������� ���������� ������
    // �������� ��� ����, ���������� ����������� ���� �� ���� ������ ������
    window.create(VideoMode(600,600), L"��� ����");
    
    // ������ �������������
    RectangleShape background(Vector2f(600, 600));
    // ��������� � ������������� �������� � ������������ menu9.jpg
    Texture texture_window;
    if (!texture_window.loadFromFile("image/menu.png")) return 4;/////////////////////////////////////////////////////
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
                    case 0:window.setVisible(false); Gam�Start();  break;
                    //case 1:About_Game();  break;
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

void Gam�Start()
{
    // ������� ���� �������� 600 �� 600 � �������� ���������� 60 ������ � �������
    RenderWindow gwindow(VideoMode(600, 600), "15");
    gwindow.setFramerateLimit(60);

    RectangleShape background(Vector2f(600, 600));
    // ��������� � ������������� �������� � ������������ menu9.jpg
    Texture texture_window;
    texture_window.loadFromFile("image/game.png");
    background.setTexture(&texture_window);

    Font font;
    font.loadFromFile("calibri.ttf");

    // ����� � ������������ ������
    Text text("F2 - New Game / Esc - Exit / Arrow Keys - Move Tile", font, 20);
    text.setFillColor(Color::Cyan);
    text.setPosition(5.f, 5.f);

    // ������� ������ ����
    Game game;
    game.setPosition(50.f, 50.f);

    Event event;
    int move_counter = 0;	// ������� ��������� ����� ��� ������������� �����������

    while (gwindow.isOpen())
    {
        while (gwindow.pollEvent(event))
        {
            if (event.type == Event::Closed) { gwindow.close(); window.setVisible(true); }
            if (event.type == Event::KeyPressed)
            {
                // �������� ������� ������� - ��������� ��������������� ��������
                if (event.key.code == Keyboard::Escape) {gwindow.close(); window.setVisible(true);}
                if (event.key.code == Keyboard::Left) game.Move(Direction::Left);
                if (event.key.code == Keyboard::Right) game.Move(Direction::Right);
                if (event.key.code == Keyboard::Up) game.Move(Direction::Up);
                if (event.key.code == Keyboard::Down) game.Move(Direction::Down);
                // ����� ����
                if (event.key.code == Keyboard::F2)
                {
                    game.Init();
                    move_counter = 100;
                }
            }
        }

        // ���� ������� ����� ������ ����, ���������� ������������ �����������
        if (move_counter-- > 0) game.Move((Direction)(rand() % 4));

        // ��������� ����������� �������� �� ���������
        gwindow.clear();
        gwindow.draw(background);
        gwindow.draw(game);
        gwindow.draw(text);
        gwindow.display();
    }
}