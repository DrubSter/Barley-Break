#include <SFML/Graphics.hpp>
#include "LiderBoard.h"
#include "GameMenu.h"
#include "Game.h"
using namespace sf;
RenderWindow window;
void GamеStart();
void LiderWindows();
int main()
{
    
    // Создаём окно windows
    // Параметры: размер окна установить согласно текущему разрешению экрана
    // название моя игра, развернуть графическое окно на весь размер экрана
    window.create(VideoMode(600,600), L"Моя игра",Style::Close);
    
    // Создаём прямоугольник
    RectangleShape background(Vector2f(600, 600));
    // Загружаем в прямоугольник текстуру с изображением menu9.jpg
    Texture texture_window;
    if (!texture_window.loadFromFile("image/menu.png")) return 4;
    background.setTexture(&texture_window);

        
    // Название пунктов меню
    String name_menu[]{ L"Старт",L"Лидеры",L"Выход" };

    // Объект игровое меню
    game::GameMenu mymenu(window, 300, 300, 3, name_menu, 50, 50);
    // Установка цвета элементов пунктов меню
    mymenu.setColorTextMenu(Color(237, 147, 0), Color::Red, Color::Black);
    // выравнивание по центру пунктов меню 
    mymenu.AlignMenu(2);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) window.close();
            if (event.type == Event::KeyReleased)
            {
                // События выбра пунктов меню
                // нажати на клавиатуре стрелки вверх
                if (event.key.code == Keyboard::Up) { mymenu.MoveUp(); }
                // нажати на клавиатуре стрелки вниз
                if (event.key.code == Keyboard::Down) { mymenu.MoveDown(); }
                // нажати на клавиатуре клавиши Enter
                if (event.key.code == Keyboard::Return)
                {
                    // Переходим на выбранный пункт меню
                    switch (mymenu.getSelectedMenuNumber())
                    {
                    case 0:window.setVisible(false); GamеStart();  break;
                    case 1:window.setVisible(false); LiderWindows(); break;
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

    RenderWindow Lwindow(VideoMode(600,600),"Leaders", Style::Titlebar);

    RectangleShape background(Vector2f(600, 600));
    Texture texture_window;
    texture_window.loadFromFile("image/game.png");
    background.setTexture(&texture_window);

    Font font;
    font.loadFromFile("font/troika.otf");

    // Текст с обозначением клавиш
    Text text("Leader-board", font, 40);
    text.setFillColor(Color::Cyan);
    text.setPosition(200, 5);

    Text LeaderText(leaderBoard.TextRetunr() , font, 30);
    LeaderText.setFillColor(sf::Color(237, 147, 0));
    LeaderText.setOutlineThickness(2.f);
    LeaderText.setOutlineColor(sf::Color(205, 87, 0));
    LeaderText.setPosition(60, 40);

    Event event;
    while (Lwindow.isOpen())
    {
        while (Lwindow.pollEvent(event))
        {
            if (event.type == Event::Closed) { Lwindow.close(); window.setVisible(true); }
            if (event.type == Event::KeyPressed)
            {                
                if (event.key.code == Keyboard::Escape) { Lwindow.close(); window.setVisible(true); }
            }
        }
                
        Lwindow.clear();
        Lwindow.draw(background);
        Lwindow.draw(text);
        Lwindow.draw(LeaderText);
        Lwindow.display();
    }
}
void GamеStart()
{
    // Создаем окно размером 600 на 600 и частотой обновления 60 кадров в секунду
    RenderWindow gwindow(VideoMode(600, 600), "15", Style::Titlebar);
    gwindow.setFramerateLimit(60);

    RectangleShape background(Vector2f(600, 600));
    // Загружаем в прямоугольник текстуру с изображением menu9.jpg
    Texture texture_window;
    texture_window.loadFromFile("image/game.png");
    background.setTexture(&texture_window);

    Font font;
    font.loadFromFile("font/troika.otf");

    // Текст с обозначением клавиш
    Text text("Esc - Exit / Arrow Keys - Move Tile", font, 40);
    text.setFillColor(Color::Cyan);
    text.setPosition(5.f, 5.f);

    // Создаем объект игры
    Game game;
    game.setPosition(50.f, 50.f);

    Event event;
    int move_counter = 0;	// Счетчик случайных ходов для перемешивания головоломки
    
    game.Init();
    move_counter = 100;

    while (gwindow.isOpen())
    {
        while (gwindow.pollEvent(event))
        {
            if (event.type == Event::Closed) { gwindow.close(); window.setVisible(true); }
            if (event.type == Event::KeyPressed)
            {
                // Получаем нажатую клавишу - выполняем соответствующее действие
                if (event.key.code == Keyboard::Escape) {gwindow.close(); window.setVisible(true);}
                if (event.key.code == Keyboard::Left) game.Move(Direction::Left);
                if (event.key.code == Keyboard::Right) game.Move(Direction::Right);
                if (event.key.code == Keyboard::Up) game.Move(Direction::Up);
                if (event.key.code == Keyboard::Down) game.Move(Direction::Down);                
            }
        }

        // Если счетчик ходов больше нуля, продолжаем перемешивать головоломку
        if (move_counter-- > 0) game.Move((Direction)(rand() % 4));

        // Выполняем необходимые действия по отрисовке
        gwindow.clear();
        gwindow.draw(background);
        gwindow.draw(game);
        gwindow.draw(text);
        gwindow.display();
    }
}