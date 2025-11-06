#pragma once
#include "TmxLevel.h" //подключаем хэдер

/// Предварительное объявление (pre-declaration) структуры
///  позволит передавать и хранить указатели и ссылки на неё,
///  но не позволит пользоваться или создавать,
///  поскольку мы ещё не знаем ни размер в байтах, ни свойства структуры.
struct GameView;//прописываем пустую структуру GameView(поскольку заранее не знаем, что в ней будет)

/// Структура, абстрагирующая игровую сцену.
///  Код ниже намеренно написан в процедурном стиле:
///  - используются структуры
///  - используется явный вызов new и delete.
struct GameScene
{
    TmxLevel level;
    TmxObject player;
    std::vector<TmxObject> enemies;//прописывавем protected объекты структуры GameScene
    std::vector<TmxObject> coins;
    std::vector<TmxObject> blocks;
    sf::Vector2f startPosition;
};

GameScene* NewGameScene();
void UpdateGameScene(void* pData, GameView& view, float deltaSec); //инициализируем функции GameScene.cpp
void DrawGameScene(void* pData, GameView& view);
void DestroyGameScene(GameScene*& pScene);
