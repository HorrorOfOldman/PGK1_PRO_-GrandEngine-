#pragma once
#include <allegro5/allegro.h>  
#include <vector>
#include <string>
using namespace std;

class AnimatedObject
{
private:
	vector<string> FPS;
	size_t ActFps;
 
public:
	AnimatedObject();
	AnimatedObject(const vector<string>& fps);
	void setFPS(const vector<string>& fps);
	const string& readActualFrame() const;
	void NextFrame();
};