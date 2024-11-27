#include "AnimatedObject.h"

AnimatedObject::AnimatedObject() : ActFps(0) {}

AnimatedObject::AnimatedObject(const vector<string>& fps)
    : FPS(fps), ActFps(0) {}

void AnimatedObject::setFPS(const vector<string>& fps) {
    this->FPS = fps;
    ActFps = 0;
}

const string& AnimatedObject::readActualFrame() const {
    return FPS[ActFps];
}

void AnimatedObject::NextFrame() {
    if (!FPS.empty()) {
        ActFps = (ActFps + 1) % FPS.size();
    }
}