#include "GameScene.h"
#include "GameView.h"
#include <float.h> // Константа FLT_EPSILON
#include <math.h>
#include <SFML/Audio.hpp>

// Добавим часто используемые идентификаторы в глобальное пространство имён.
using sf::Keyboard;
using sf::Vector2f;
using sf::Vector2i;

// Абсолютная скорость движения игрока.
static const float PLAYER_SPEED = 200;

static sf::Music backgroundMusic;
static sf::SoundBuffer coinSoundBuffer;
static sf::Sound coinSound;

// Выполняет нормализацию вектора (приведение к единичной длине).
static Vector2f Normalize(const Vector2f &value)
{
    const float length = std::hypotf(value.x, value.y);
    if (length < FLT_EPSILON)
    {
        return Vector2f(0, 0);
    }

    return value / length;
}

// Округляет компоненты вектора до ближайших целых чисел.
static Vector2f Round(const Vector2f &value)
{
    return Vector2f(roundf(value.x), roundf(value.y));
}

// Определяет состояние клавиатуры и выбирает направление движения.
// Возвращает нормализованный вектор направления игрока.
static Vector2f GetPlayerDirection()
{
    Vector2f direction;
    if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
    {
        direction.y = -1;
    }
    else if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
    {
        direction.y = +1;
    }
    if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
    {
        direction.x = -1;
    }
    else if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
    {
        direction.x = +1;
    }

    return Normalize(direction);
}

GameScene *NewGameScene()//инициализация сцены
{
    GameScene *pLogic = new GameScene;//Создается новый объект игровой сцены в динамической памяти
    TmxLevel &level = pLogic->level;
    // Загружаем музыку и звуки
    if (!backgroundMusic.openFromFile("res/Soliloquy.mp3"))
    {
        // Обработка ошибки загрузки музыки
        // Можно использовать альтернативный файл или продолжить без музыки
    }
    else
    {
        backgroundMusic.setLoop(true); // Зацикливаем музыку
        backgroundMusic.setVolume(50); // Громкость от 0 до 100
        backgroundMusic.play(); // Запускаем музыку
    }
    // Загружаем звук сбора монет
    if (!coinSoundBuffer.loadFromFile("res/Coins_Few_00.mp3"))//загружаем звук монет
    {
        // Обработка ошибки
    }
    else
    {
        coinSound.setBuffer(coinSoundBuffer);
    }                                        //Инициализация игровых объектов:
    level.LoadFromFile("res/platformer.tmx");//загружаем карту
    pLogic->player = level.GetFirstObject("player");//Игрок: присваивается первый объект с типом "player"
    pLogic->coins = level.GetAllObjects("coin");//Монеты: присваиваются все объекты с типом "coin"
    pLogic->enemies = level.GetAllObjects("enemy");//Враги: присваиваются все объекты с типом "enemy"
    pLogic->blocks = level.GetAllObjects("block");//Блоки: присваиваются все объекты с типом "block"
    
    pLogic->startPosition = sf::Vector2f(4611.f, 1695.f); // Задается стартовая позиция игрока(ваши координаты)
    pLogic->player.sprite.setPosition(pLogic->startPosition); //Позиция применяется к спрайту игрока

    return pLogic;//возвращаем указатель
}

void UpdateGameScene(void *pData, GameView &view, float deltaSec)
{
    // Извлекаем указатель на GameLogic, ранее переданный в игровой цикл.
    GameScene *pLogic = reinterpret_cast<GameScene *>(pData);
    (void)deltaSec;

    sf::Vector2f oldPosition = (pLogic->player.sprite.getPosition());

    TmxObject &player = pLogic->player;
    const Vector2f movement = Round(GetPlayerDirection() * PLAYER_SPEED * deltaSec);
    player.MoveBy(movement);

    const Vector2i windowSize = view.windowSize;
    SetCameraCenter(view, player.sprite.getPosition() + Vector2f(windowSize.x / 4, windowSize.y / 4));

    for (auto it = pLogic->coins.begin(); it != pLogic->coins.end();) {
        if (pLogic->player.sprite.getGlobalBounds().intersects(it->sprite.getGlobalBounds())) {
            // Игрок собирает монету
            coinSound.play();
            it = pLogic->coins.erase(it);
        }
        else {
            ++it;
        }
    }
    sf::Vector2f startPosition = (pLogic->player.sprite.getPosition());
    for (auto it = pLogic->enemies.begin(); it != pLogic->enemies.end();) {
        if (pLogic->player.sprite.getGlobalBounds().intersects(it->sprite.getGlobalBounds())) {
            // Игрока убивает противник
            pLogic->player.sprite.setPosition(pLogic->startPosition);
        }
        else {
            ++it;
        }
    }
    int collision = false;
    for (auto it = pLogic->blocks.begin(); it != pLogic->blocks.end(); ++it) {
        sf::FloatRect playerRect = pLogic->player.sprite.getGlobalBounds();
        sf::FloatRect blockRect = it->rect;
        sf::FloatRect newPlayerRect = playerRect;
        newPlayerRect.left += movement.x;
        newPlayerRect.top += movement.y;
        if (newPlayerRect.intersects(blockRect)) {
            collision = true;
            break;
        }
    }

    if (!collision) {
        pLogic->player.sprite.move(movement);
    }
    else {
        pLogic->player.sprite.setPosition(oldPosition);
    }
}

void DrawGameScene(void *pData, GameView &view)
{
    // Извлекаем указатель на GameLogic, ранее переданный в игровой цикл.
    GameScene *pLogic = reinterpret_cast<GameScene *>(pData);
    sf::RenderTarget &target = view.window;

    pLogic->level.Draw(target);
    for (const TmxObject &coin : pLogic->coins)
    {
        target.draw(coin.sprite);
    }
    for (const TmxObject &enemy : pLogic->enemies)
    {
        target.draw(enemy.sprite);
    }
    target.draw(pLogic->player.sprite);
}

void DestroyGameScene(GameScene *&pScene)
{

    backgroundMusic.stop();

    delete pScene;
    pScene = nullptr;
}
