#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <list>
#include <math.h>
#include <cstdlib>
#include"SFML\System.hpp"
#include<stdio.h>
#include<utility>
#include<algorithm>
#include<string>
#include<vector>
#include<windows.h>
#include<time.h>
using namespace std;
using namespace sf;
void Showtexet(int x, int y, string word, int size, sf::RenderWindow& window, sf::Font* font);
void updatascore(string a, int b);
void Showscoreboard(sf::RenderWindow& window);
int main()
{
	srand(time(NULL));


	sf::VideoMode desktop = sf::VideoMode().getDesktopMode();
	sf::RenderWindow window(desktop, "GaiiA", sf::Style::None);
	sf::Texture items;
	sf::Texture HP_items;
	sf::Texture players;
	sf::Texture projectiles;
	sf::Texture enemies;
	sf::Texture Sin_enemies;
	sf::Texture Notshoot_enemies;
	sf::Texture backgrounds;
	sf::SoundBuffer Whendeath;
	sf::SoundBuffer Whenshoot;
	sf::SoundBuffer Whenclick;
	sf::SoundBuffer Whenmove;
	sf::Clock clock;
	items.loadFromFile("wship1.png");
	HP_items.loadFromFile("wship-3.png");
	players.loadFromFile("WB_baseu3_d0.png");
	projectiles.loadFromFile("Shots.png");
	enemies.loadFromFile("Spacestation-by-MillionthVector.png");
	Sin_enemies.loadFromFile("greenship3.png");
	Notshoot_enemies.loadFromFile("RD1.png");
	backgrounds.loadFromFile("simple-starry-space-background.png");
	Whendeath.loadFromFile("Space Explosion - Sound effect.ogg");
	Whenshoot.loadFromFile("Laser Gun Sound Effect 2.ogg");
	Whenclick.loadFromFile("Mouse Click - Sound Effect (HD).ogg");
	Whenmove.loadFromFile("Slide Sound Effect.ogg");
	sf::Sound Whendeaths;
	Whendeaths.setBuffer(Whendeath);
	sf::Sound Whenmoves;
	Whenmoves.setBuffer(Whenmove);
	sf::Sound Whenclicks;
	Whenclicks.setBuffer(Whenclick);
	sf::Sound Whenshoots;
	Whenshoots.setBuffer(Whenshoot);
	Sprite background;
	background.setTexture(backgrounds);

	CircleShape Background_IN;
	Background_IN.setFillColor(Color::White);
	Background_IN.setRadius(2.0f);
	//BALLS
	Sprite projectile;
	projectile.setTexture(projectiles);
	projectile.setScale(0.5f, 0.5f);

	Sprite item;
	item.setTexture(items);
	item.setScale(0.3f, 0.3f);

	Sprite HP_item;
	HP_item.setTexture(HP_items);
	HP_item.setScale(0.3f, 0.3f);


	Sprite enemy;
	enemy.setTexture(enemies);
	enemy.setScale(0.3f, 0.3f);

	Sprite Sin_enemy;
	Sin_enemy.setTexture(Sin_enemies);
	Sin_enemy.setScale(1.0f, 1.0f);

	Sprite Notshoot_enemy;
	Notshoot_enemy.setTexture(Notshoot_enemies);
	Notshoot_enemy.setScale(0.6f, 0.6f);

	Sprite player;
	player.setTexture(players);
	player.setPosition(960, 900);
	player.setScale(0.2f, 0.2f);
	Vector2f playerCenter;
	int shootTimer = 0;

	std::vector<CircleShape> Background_INss;
	Background_INss.push_back(CircleShape(Background_IN));

	std::vector<Sprite> projectiless;
	projectiless.push_back(Sprite(projectile));

	std::vector<Sprite> enemiess;
	enemiess.push_back(Sprite(enemy));

	std::vector<Sprite> Sin_enemiess;
	Sin_enemiess.push_back(Sprite(Sin_enemy));

	std::vector<Sprite> Notshoot_enemiess;
	Notshoot_enemiess.push_back(Sprite(Notshoot_enemy));

	std::vector<Sprite> itemss;
	itemss.push_back(Sprite(item));

	std::vector<Sprite> HP_itemss;
	HP_itemss.push_back(Sprite(HP_item));


	int Notshoot_enemySpawnTimer = 0;
	int Sin_enemySpawnTimer = 0;
	int enemySpawnTimer = 0;
	int Background_INsSpawnTimer = 0;
	int itemSpawnTimer = 0;
	int HP_itemSpawnTimer = 0;
	float deltaTime;
	Font font;
	if (!font.loadFromFile("font/space punk Bold Italic.ttf"))
		throw("COULD NOT LOAD FONT!");
	Text Maiclickss;
	Maiclickss.setFont(font);
	Maiclickss.setCharacterSize(120);
	Maiclickss.setFillColor(Color::Red);
	Maiclickss.setStyle(Text::Bold);
	Maiclickss.setString("GAIIA");
	Maiclickss.setPosition(850, 100);

	Text Maiclicks;
	Maiclicks.setFont(font);
	Maiclicks.setCharacterSize(60);
	Maiclicks.setFillColor(Color::Red);
	Maiclicks.setStyle(Text::Bold);
	Maiclicks.setString("64010591");
	Maiclicks.setPosition(1000, 800);

	Text Maiclick;
	Maiclick.setFont(font);
	Maiclick.setCharacterSize(60);
	Maiclick.setFillColor(Color::Red);
	Maiclick.setStyle(Text::Bold);
	Maiclick.setString("Pitpiibul Phongphotjanatham");
	Maiclick.setPosition(1000, 750);

	Text clickplay;
	clickplay.setFont(font);
	clickplay.setCharacterSize(60);
	clickplay.setFillColor(Color::Red);
	clickplay.setStyle(Text::Bold);
	clickplay.setString("Play");
	clickplay.setPosition(250, 250);

	Text ClickExit;
	ClickExit.setFont(font);
	ClickExit.setCharacterSize(60);
	ClickExit.setFillColor(Color::Red);
	ClickExit.setStyle(Text::Bold);
	ClickExit.setString("Exit");
	ClickExit.setPosition(250, 500);

	Text ClickRank;
	ClickRank.setFont(font);
	ClickRank.setCharacterSize(60);
	ClickRank.setFillColor(Color::Red);
	ClickRank.setStyle(Text::Bold);
	ClickRank.setString("Top Score");
	ClickRank.setPosition(250, 750);

	Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(40);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(1500.f, 960.f);
	int page = 0;
	int score = 0;   
	int HP= 0 ;
	RectangleShape Bar;
	Bar.setFillColor(Color::Red);
	Bar.setSize(Vector2f((float)HP * 100.f, 100.f));

	std::string playerInput;
	sf::Text playerText("", font, 70);
	playerText.setPosition(940, 270);
	playerText.setFillColor(sf::Color::White);

	sf::Texture textureBlueZone;
	textureBlueZone.loadFromFile("space-background-with-abstract-shape-stars_189033-30.png");
	sf::Sprite spriteBG;
	spriteBG.setTexture(textureBlueZone);
	spriteBG.setPosition(0, 0);
	spriteBG.setScale(10.0f, 10.0f);

	sf::Text finish("Click", font, 80);
	finish.setPosition(945, 425);


	sf::Text click("Click Here", font, 80);
	click.setPosition(945, 805);
	while (window.isOpen())
	{
		// Event processing
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode < 128 && HP == 0)
				{
					playerInput.push_back(event.text.unicode);

				}
				if (event.text.unicode == '\b')
				{
					playerInput.pop_back();
					playerInput.pop_back();

				}
			}
			if (event.type == event.KeyPressed)
			{
				if (Keyboard::isKeyPressed(Keyboard::Escape))
					window.close();
			}

		}

		// Activate the window for OpenGL rendering
		if (clickplay.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
		{
			Whenclicks.play();
			clickplay.setFillColor(sf::Color::Green);

		}
		else
		{
			clickplay.setFillColor(sf::Color::Red);
			clickplay.setStyle(0);
		}
		if (ClickRank.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
		{
			Whenclicks.play();
			ClickRank.setFillColor(sf::Color::Green);

		}
		else
		{
			ClickRank.setFillColor(sf::Color::Red);
			ClickRank.setStyle(0);
		}

		if (ClickExit.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
		{
			Whenclicks.play();
			ClickExit.setFillColor(sf::Color::Green);

		}
		else
		{
			ClickExit.setFillColor(sf::Color::Red);
			ClickExit.setStyle(0);
		}

		//Main State Change

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (ClickExit.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
				window.close();
		}
		//State Play
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (clickplay.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
				page = 1;

		}
		//State Score
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (ClickRank.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
				page = 3;
		}

		//menu
		if (page == 0) {
			HP = 30;
			score = 0;
			window.clear();
			window.draw(background);
			window.draw(clickplay);
			window.draw(Maiclick);
			window.draw(Maiclicks);
			window.draw(Maiclickss);
			clickplay.setPosition(250, 250);
			ClickRank.setPosition(250, 500);
			ClickExit.setPosition(250, 750);

			window.draw(ClickRank);
			window.draw(ClickExit);
			window.display();
		}
		//game play
		if (page == 1)
		{
			deltaTime = clock.restart().asSeconds();
			if (deltaTime > 1.0f / 20.0f)
				deltaTime = 1.0f / 20.0f;
		
			playerCenter = Vector2f(player.getPosition().x + 90, player.getPosition().y);

			if (player.getPosition().y > window.getSize().y - player.getGlobalBounds().height)
				player.setPosition(player.getPosition().x, window.getSize().y - player.getGlobalBounds().height);

			if (player.getPosition().y < 0)
				player.setPosition(player.getPosition().x, 0);

			if (player.getPosition().x > window.getSize().x - player.getGlobalBounds().width)
				player.setPosition(window.getSize().x - player.getGlobalBounds().width,player.getPosition().y);

			if (player.getPosition().x < 0)
				player.setPosition(0, player.getPosition().y);


			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				player.move(800.0f* deltaTime, 0.f);

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{

				
				player.move(-800.0f * deltaTime, 0.f);

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{

				
				player.move(0.f, -800.0f * deltaTime);

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{

				
				player.move(0.f, 800.0f * deltaTime);

			}
			//background
			if (Background_INsSpawnTimer < 1)
				Background_INsSpawnTimer++;

			if (Background_INsSpawnTimer >= 1)
			{
				Background_IN.setPosition((rand() % int(window.getSize().x - Background_IN.getScale().x)), 0.f);
				Background_INss.push_back(CircleShape(Background_IN));

				Background_INsSpawnTimer = 0;
			}

			for (size_t i = 0; i < Background_INss.size(); i++)
			{
				Background_INss[i].move(0.f,500.f * deltaTime);

				if (Background_INss[i].getPosition().y > window.getSize().y)
					Background_INss.erase(Background_INss.begin() + i);
			}
			//items
			if (itemSpawnTimer < 120)
				itemSpawnTimer++;

			if (itemSpawnTimer >= 120)
			{
				item.setPosition((rand() % int(window.getSize().x - item.getScale().x)), 0.f);
				itemss.push_back(Sprite(item));

				itemSpawnTimer = 0;
			}

			for (size_t i = 0; i < itemss.size(); i++)
			{
				itemss[i].move(200.f * deltaTime, 1500.f * deltaTime);

				if (itemss[i].getPosition().y > window.getSize().y)
					itemss.erase(itemss.begin() + i);
			}
			//HP_items
			if (HP < 15) {
				if (HP_itemSpawnTimer < 120)
					HP_itemSpawnTimer++;

				if (HP_itemSpawnTimer >= 120)
				{
					HP_item.setPosition((rand() % int(window.getSize().x - HP_item.getScale().x)), 0.f);
					HP_itemss.push_back(Sprite(HP_item));

					HP_itemSpawnTimer = 0;
				}

				for (size_t i = 0; i < HP_itemss.size(); i++)
				{
					HP_itemss[i].move(-150.f * deltaTime, 1200.f * deltaTime);

					if (HP_itemss[i].getPosition().y > window.getSize().y)
						HP_itemss.erase(HP_itemss.begin() + i);
				}
			}
			//Notshoot_enemy
			if (score >= 300) {
				if (Notshoot_enemySpawnTimer < 120)
					Notshoot_enemySpawnTimer++;

				if (Notshoot_enemySpawnTimer >= 120)
				{
					Notshoot_enemy.setPosition((rand() % int(window.getSize().x - Notshoot_enemy.getScale().x)), 0.f);
					Notshoot_enemiess.push_back(Sprite(Notshoot_enemy));

					Notshoot_enemySpawnTimer = 0;
				}

				for (size_t i = 0; i < Notshoot_enemiess.size(); i++)
				{
					Notshoot_enemiess[i].move(0.0f, 1300.f * deltaTime);

					if (Notshoot_enemiess[i].getPosition().y > window.getSize().y)
						Notshoot_enemiess.erase(Notshoot_enemiess.begin() + i);
				}
			}
			//PROJECTILES
			if (shootTimer < 30)
				shootTimer++;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shootTimer >= 30) //Shoot
			{
				projectile.setPosition(playerCenter);
				projectiless.push_back(projectile);
				Whenshoots.play();
				shootTimer = 0;
			}

			for (size_t i = 0; i < projectiless.size(); i++)
			{
				projectiless[i].move(0.f, -900.f * deltaTime);

				if (projectiless[i].getPosition().y <= 0)
					projectiless.erase(projectiless.begin() + i);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
			//ENEMIES
			if (enemySpawnTimer < 50)
				enemySpawnTimer++;

			if (enemySpawnTimer >= 50)
			{
				enemy.setPosition((rand() % int(window.getSize().x - enemy.getScale().x)), 0.f);
				enemiess.push_back(Sprite(enemy));

				enemySpawnTimer = 0;
			}

			for (size_t i = 0; i < enemiess.size(); i++)
			{
				enemiess[i].move(0.f, 1000.f * deltaTime);

				if (enemiess[i].getPosition().y > window.getSize().y)
					enemiess.erase(enemiess.begin() + i);
			}
			//Sin_ENEMIES
			if (score >= 100) {
				if (Sin_enemySpawnTimer < 150)
					Sin_enemySpawnTimer++;

				if (Sin_enemySpawnTimer >= 150)
				{
					Sin_enemy.setPosition((rand() % int(window.getSize().x - Sin_enemy.getScale().x)), 0.f);
					Sin_enemiess.push_back(Sprite(Sin_enemy));

					Sin_enemySpawnTimer = 0;
				}

				for (size_t i = 0; i < Sin_enemiess.size(); i++)
				{
					Sin_enemiess[i].move(0.0f, 1100.f * deltaTime);

					if (Sin_enemiess[i].getPosition().y > window.getSize().y)
						Sin_enemiess.erase(Sin_enemiess.begin() + i);
				}
			}
			//Collision Enemies
			if (!enemiess.empty() && !projectiless.empty())
			{
				for (size_t i = 0; i < projectiless.size(); i++)
				{
					for (size_t k = 0; k < enemiess.size(); k++)
					{
						if (projectiless[i].getGlobalBounds().intersects(enemiess[k].getGlobalBounds()))
						{
							projectiless.erase(projectiless.begin() + i);
							enemiess.erase(enemiess.begin() + k);
							score++;
							break;
						}
					}
				}
			}
			for (size_t i = 0; i < enemiess.size(); i++)
			{
				if (player.getGlobalBounds().intersects(enemiess[i].getGlobalBounds()))
				{
					HP--;
					enemiess.erase(enemiess.begin() + i);

				}
			}

			//Collision Sin_Enemies
			if (!Sin_enemiess.empty() && !projectiless.empty())
			{
				for (size_t i = 0; i < projectiless.size(); i++)
				{
					for (size_t k = 0; k < Sin_enemiess.size(); k++)
					{
						if (projectiless[i].getGlobalBounds().intersects(Sin_enemiess[k].getGlobalBounds()))
						{
							projectiless.erase(projectiless.begin() + i);
							Sin_enemiess.erase(Sin_enemiess.begin() + k);
							score++;
							break;
						}
					}
				}
			}
			for (size_t i = 0; i < Sin_enemiess.size(); i++)
			{
				if (player.getGlobalBounds().intersects(Sin_enemiess[i].getGlobalBounds()))
				{
					HP= HP-2;
					Sin_enemiess.erase(Sin_enemiess.begin() + i);

				}
			}
			//Collision items
			for (size_t i = 0; i < itemss.size(); i++)
			{
				if (player.getGlobalBounds().intersects(itemss[i].getGlobalBounds()))
				{
					score = score + 2;
					itemss.erase(itemss.begin() + i);

				}
			}
			//Collision Notshoot_enemies
			for (size_t i = 0; i < Notshoot_enemiess.size(); i++)
			{
				if (player.getGlobalBounds().intersects(Notshoot_enemiess[i].getGlobalBounds()))
				{
					HP = HP - 1;
					Notshoot_enemiess.erase(Notshoot_enemiess.begin() + i);

				}
			}
			//Collosion HP_items
			for (size_t i = 0; i < HP_itemss.size(); i++)
			{
				if (player.getGlobalBounds().intersects(HP_itemss[i].getGlobalBounds()))
				{
					HP ++;
					HP_itemss.erase(HP_itemss.begin() + i);

				}
			}
			Bar.setPosition(0, 0);
			Bar.setSize(Vector2f((float)HP * 15.f, 25.f));
			window.clear();

			scoreText.setString("Score: " + std::to_string(score));
			//DRAW
			window.clear();
			clickplay.setPosition(-0, 0);
			ClickRank.setPosition(-0, 0);
			ClickExit.setPosition(-0, 0);
			window.draw(player);
			for (size_t i = 0; i < Background_INss.size(); i++)
			{
				window.draw(Background_INss[i]);

			}

			for (size_t i = 0; i < enemiess.size(); i++)
			{
				window.draw(enemiess[i]);

			}
			if (score >= 100) {
				for (size_t i = 0; i < Sin_enemiess.size(); i++)
				{
					window.draw(Sin_enemiess[i]);

				}
			}
			if (score >= 300) {
				for (size_t i = 0; i < Notshoot_enemiess.size(); i++)
				{
					window.draw(Notshoot_enemiess[i]);

				}
			}
			for (size_t i = 0; i < projectiless.size(); i++)
			{
				window.draw(projectiless[i]);
			}

			for (size_t i = 0; i < itemss.size(); i++)
			{
				window.draw(itemss[i]);

			 }
			 if (HP < 15) {
				for (size_t i = 0; i < HP_itemss.size(); i++)
				{
					window.draw(HP_itemss[i]);
				}
			}
			window.draw(Bar);
			window.draw(scoreText);
			window.display();
			//SetGameOver
			if (HP <= 0)
			{
				page = 2;
				Whendeaths.play();
				window.display();
			}
		}
		//gameover
		if (page == 2) {
			if (finish.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
			{
				finish.setFillColor(sf::Color::Green);
				finish.setStyle(sf::Text::Underlined);
			}
			else
			{
				finish.setFillColor(sf::Color::Red);
				finish.setStyle(0);
			}
			window.clear();
			window.draw(finish);
			playerText.setString("Name here:  " + playerInput);
			window.draw(playerText);
			window.display();

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (finish.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
				{
					page = 0;
					updatascore(playerInput, score);

				}

			}

		}
		//scoreboard
		if (page == 3) {
			if (click.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
			{
				click.setFillColor(sf::Color::Green);
				click.setStyle(sf::Text::Underlined);
			}
			else
			{
				click.setFillColor(sf::Color::Red);
				click.setStyle(0);
			}
			window.clear();

			window.draw(spriteBG);
			Showscoreboard(window);
			window.draw(click);
			window.display();


			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (click.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
					page = 0;
			}
		}
	}
	return 0;
}
void Showtexet(int x, int y, string word, int size, sf::RenderWindow& window, sf::Font* font)
{
	sf::Text text;
	text.setFont(*font);
	text.setPosition(x, y);
	text.setString(word);
	text.setCharacterSize(size);
	window.draw(text);
}

void updatascore(string a, int b)
{
	FILE* fp;
	char temp[255];
	int score[6];
	string name[6];
	vector <pair<int, string>> userScore;
	fp = fopen("./Score.txt", "r");
	if (fp == NULL)
		printf("File not found\n");

	for (int i = 0; i < 5; i++)
	{
		fscanf(fp, "%s", &temp);
		name[i] = temp;
		fscanf(fp, "%d", &score[i]);
		userScore.push_back(make_pair(score[i], name[i]));
	}

	name[5] = a;
	score[5] = b;
	userScore.push_back(make_pair(score[5], name[5]));
	sort(userScore.begin(), userScore.end());
	fclose(fp);
	fopen("Score.txt", "w");
	for (int i = 5; i >= 1; i--)
	{
		strcpy(temp, userScore[i].second.c_str());
		fprintf(fp, "%s %d\n", temp, userScore[i].first);
	}
	fclose(fp);
}

void Showscoreboard(sf::RenderWindow& window)
{
	sf::Font font;
	font.loadFromFile("font/space punk Bold Italic.ttf");

	FILE* fp;
	char temp[255];
	int score[6];
	string name[6];
	fp = fopen("./Score.txt", "r");
	for (int i = 0; i < 5; i++)
	{
		char no[3] = { '1' + i };
		no[1] = '.';
		no[2] = '\0';
		Showtexet(700, 350 + 100 * i, no, 50, window, &font);
		fscanf(fp, "%s", &temp);
		Showtexet(750, 350 + 100 * i, temp, 50, window, &font);
		fscanf(fp, "%d", &score[i]);
		char sc[10];
		int k = 0, j;
		if (score[i] == 0)
			sc[k++] = 48;
		while (score[i] > 0)
		{
			sc[k++] = score[i] % 10 + 48;
			score[i] /= 10;
		}
		sc[k] = '\0';
		char show[10];
		for (j = 0; j < strlen(sc); j++)
		{
			show[j] = sc[strlen(sc) - 1 - j];
		}
		show[j] = '\0';
		Showtexet(1100, 350 + 100 * i, show, 50, window, &font);
	}
	fclose(fp);
	//Cout
}