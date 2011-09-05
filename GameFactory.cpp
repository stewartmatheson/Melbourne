/*
 *  GameFactory.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 5/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "GameFactory.h"
#include "PlayerView.h"
#include "BulletView.h"
#include "EnemyView.h"
#include "DebugDraw.h"
#include "Box2D.h"
#include "ContactListener.h"
#include "ExplosionView.h"
#include "StarFieldView.h"
#include "ScoreView.h"
#include "PowerUpView.h"
#include "EnergyView.h"
#include "HighScoreView.h"

GameFactory::GameFactory(sf::RenderWindow* a) : app(a), die_sound("die.ogg", 1.00f, 10.0f)
{
	b2AABB worldAABB;
	worldAABB.lowerBound.Set(-1500.0f, -1500.0f);
	worldAABB.upperBound.Set(1500.0f, 1500.0f);
	b2Vec2 gravity(0.0f, 0.0f);
	bool doSleep = true;
    world = new b2World(worldAABB, gravity, doSleep);
    
    ContactListener* listener = new ContactListener();
    world->SetContactListener(listener);
    
    
    b2DebugDraw* dd = new DebugDraw();
    dd->SetFlags(b2DebugDraw::e_shapeBit || b2DebugDraw::e_jointBit || b2DebugDraw::e_coreShapeBit || b2DebugDraw::e_aabbBit || b2DebugDraw::e_obbBit || b2DebugDraw::e_pairBit || b2DebugDraw::e_centerOfMassBit);
    world->SetDebugDraw(dd);
    
}

b2Body* GameFactory::create_box2d_body(float const x, float const y, float const xpos, float const ypos, bool is_static)
{
    //set up the body for the player
    b2BodyDef player_body_def;
	player_body_def.position.Set(xpos, ypos);
	player_body_def.angularDamping = 2.00f;
	player_body_def.linearDamping = 0.1f;
	b2Body* body = world->CreateBody(&player_body_def);
	
    //add the poly
	b2PolygonDef ship_poly;
	ship_poly.SetAsBox(x, y);
    if(!is_static)
    {
        ship_poly.density = .005f;
        ship_poly.friction = 0.3f;    
    }

	
	body->CreateShape(&ship_poly);
	body->SetMassFromShapes();
    
    return body;
}

Player* GameFactory::create_player()
{
    int scale = 15; 
    
    b2XForm xf1;
    xf1.R.Set(0.3524f * b2_pi);
    xf1.position = b2Mul(xf1.R, b2Vec2(1.0f * scale, 0.0f * scale));
    
    b2PolygonDef sd1;
    sd1.vertexCount = 3;
    sd1.vertices[0] = b2Mul(xf1, b2Vec2(-1.0f * scale, 0.0f * scale));
    sd1.vertices[1] = b2Mul(xf1, b2Vec2(1.0f * scale, 0.0f * scale));
    sd1.vertices[2] = b2Mul(xf1, b2Vec2(0.0f * scale, 0.5f * scale));
    sd1.density = .002f;
    
    b2XForm xf2;
    xf2.R.Set(-0.3524f * b2_pi);
    xf2.position = b2Mul(xf2.R, b2Vec2(-1.0f * scale, 0.0f * scale));
    
    b2PolygonDef sd2;
    sd2.vertexCount = 3;
    sd2.vertices[0] = b2Mul(xf2, b2Vec2(-1.0f * scale, 0.0f * scale));
    sd2.vertices[1] = b2Mul(xf2, b2Vec2(1.0f * scale, 0.0f * scale));
    sd2.vertices[2] = b2Mul(xf2, b2Vec2(0.0f * scale, 0.5f * scale));
    sd2.density = .002f;
    
    b2BodyDef bd;
    bd.angularDamping = 6.6f;
    bd.linearDamping = .10f;
    
    bd.position.Set(1000.0f, 1000.00f);
    bd.angle = b2_pi;
    b2Body* body = world->CreateBody(&bd);
    body->CreateShape(&sd1);
    body->CreateShape(&sd2);
    body->SetMassFromShapes();
    body->AllowSleeping(false);
    
	Player* p = new Player(body);
	PlayerView* pv = new PlayerView(app);
    ScoreView* sv = new ScoreView(app);
    EnergyView* ev = new EnergyView(app);
    HighScoreView* hsv = new HighScoreView(app);
    p->register_observer(pv);
    p->register_observer(sv);
    p->register_observer(ev);
    p->register_observer(hsv);
    body->SetUserData(p);
    return p;
}

Enemy* GameFactory::create_enemy()
{
    int scale = 10; 
    
    b2XForm xf1;
    xf1.R.Set(0.3524f * b2_pi);
    xf1.position = b2Mul(xf1.R, b2Vec2(1.0f * scale, 0.0f * scale));
    
    b2PolygonDef sd1;
    sd1.vertexCount = 3;
    sd1.vertices[0] = b2Mul(xf1, b2Vec2(-1.0f * scale, 0.0f * scale));
    sd1.vertices[1] = b2Mul(xf1, b2Vec2(1.0f * scale, 0.0f * scale));
    sd1.vertices[2] = b2Mul(xf1, b2Vec2(0.0f * scale, 0.5f * scale));
    sd1.density = .002f;
    
    b2XForm xf2;
    xf2.R.Set(-0.3524f * b2_pi);
    xf2.position = b2Mul(xf2.R, b2Vec2(-1.0f * scale, 0.0f * scale));
    
    b2PolygonDef sd2;
    sd2.vertexCount = 3;
    sd2.vertices[0] = b2Mul(xf2, b2Vec2(-1.0f * scale, 0.0f * scale));
    sd2.vertices[1] = b2Mul(xf2, b2Vec2(1.0f * scale, 0.0f * scale));
    sd2.vertices[2] = b2Mul(xf2, b2Vec2(0.0f * scale, 0.5f * scale));
    sd2.density = .002f;
    
    b2BodyDef bd;
    bd.angularDamping = 6.6f;
    bd.linearDamping = .10f;
    
    bd.position.Set(0.0f, 1.05f);
    bd.angle = b2_pi;
    b2Body* body = world->CreateBody(&bd);
    body->CreateShape(&sd1);
    body->CreateShape(&sd2);
    body->SetMassFromShapes();
   
    
    //b2Body* body = create_box2d_body(7.0f, 7.0f, xpos, ypos);
    
    
    int xpos = sf::Randomizer::Random(-1500, 1500);
    int ypos = sf::Randomizer::Random(-1500, 1500);
    
	Enemy* e = new Enemy(body);
    e->set_die_sound(&die_sound);
	EnemyView* ev = new EnemyView(app);
    ExplosionView* ex = new ExplosionView(app);
    e->set_explosion_view(ex);
    e->register_observer(ev);
    e->register_observer(ex);
    body->SetUserData(e);
    return e;
}

b2World* GameFactory::get_world()
{
    return world;
}

Bullet* GameFactory::create_bullet(Player* p)
{
    b2BodyDef bullet_body_def;
	bullet_body_def.position.Set(p->get_x_position(), p->get_y_position());
	
    //bullet_body_def.position.Set(10, 10);
    
    b2Body* body = world->CreateBody(&bullet_body_def);
	
	b2CircleDef bullet_circle;
	bullet_circle.radius = 3.5f;
	bullet_circle.density = .05f;
	bullet_circle.friction = 0.3f;
	
	body->CreateShape(&bullet_circle);
	body->SetMassFromShapes();
    body->SetBullet(true);
    
    b2Vec2 fv = p->get_body()->GetWorldVector(b2Vec2(0.0f, -2000.0f));
    b2Vec2 pv = p->get_body()->GetWorldPoint(b2Vec2(0.0f, 0.0f));
    body->ApplyImpulse(fv, pv);
    
    BulletView* bv = new BulletView(app);
    Bullet* b = new Bullet(body, p);
    b->register_observer(bv);
    body->SetUserData(b);
    return b;
}

MusicTrack* GameFactory::create_music_track()
{
    MusicTrack* m = new MusicTrack("sound\time-to-go.mp3");
    return m;
}

World* GameFactory::create_world()
{
    StarFieldView* s = new StarFieldView(app);
    World* w = new World();
    w->register_observer(s);
    return w;
}

Wall* GameFactory::create_wall(int const x_pos, int const y_pos, int const length, int const wall_thickness)
{
    //set up the body for the player
    b2BodyDef wall_body_def ;
	wall_body_def.position.Set(x_pos , y_pos);
	wall_body_def.angularDamping = 2.00f;
	wall_body_def.linearDamping = 0.1f;
	b2Body* body = world->CreateBody(&wall_body_def);
	
    //add the poly
	b2PolygonDef wall_poly;
	wall_poly.SetAsBox(x_pos + wall_thickness, y_pos + length);
	body->CreateShape(&wall_poly);
	body->SetMassFromShapes();
    
    Wall* w = new Wall(body);
    body->SetUserData(w);
    return w;
}

PowerUp* GameFactory::create_powerup()
{   
    int xpos = sf::Randomizer::Random(-200, 200);
    int ypos = sf::Randomizer::Random(-200, 200);
    b2BodyDef powerup_body_def;
	powerup_body_def.position.Set(xpos, ypos);
    
    b2Body* body = world->CreateBody(&powerup_body_def);
	b2CircleDef powerup_circle;
	powerup_circle.radius = 15.0f;
	body->CreateShape(&powerup_circle);
	body->SetMassFromShapes();
    
    PowerUpView* pv = new PowerUpView(app);
    PowerUp* p = new PowerUp(body);
    p->register_observer(pv);
    body->SetUserData(p);
    return p;
}