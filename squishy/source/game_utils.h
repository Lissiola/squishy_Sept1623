// game_utils.h
// Helper routines for managing game state.
// This file was automatically generated by Spritely 

#ifndef _GAME_UTILS_H_
#define _GAME_UTILS_H_

#include <gba_input.h>

// Setting video mode.
void SetBitmapVideoMode();
void SetSpriteVideoMode();

// Loading sprites.
void ClearSprites();
void LoadSpriteset(int id);

// Loading backgrounds.
void ClearBackgrounds();
void LoadBgTileset(int id);
void LoadBgMap(int id);
void LoadBgImage(int id);

// Current key/button state.
extern u16 g_keyPress, g_keyHeld;

// GetKeyState
// Get the stata of all of the keys/buttons.
// This must be called before CheckKeyHeld or CheckKeyPress
inline void GetKeyState() {
	// Get the current state of all of the buttons.
	scanKeys();
	
	// Get the buttons that have been newly pressed since the last
	// time we called scanKeys().
	g_keyPress = keysDown();
	
	// Get the buttons that are currently being pressed (regardless
	// of whether or not we've already handled the button press).
	g_keyHeld = keysHeld();
}

// CheckKeyHeld
// Is the specified key currently being held?
// This returns true even if we've already handled this particular key press.
// This is useful for actions that should repeat for as long as a key is held
// (for example arrow keys for movement).
inline bool CheckKeyHeld(u16 key) {
	return g_keyHeld & key;
}

// CheckKeyPress
// Has the player pressed the specified key?
// This returns true only if the key is newly pressed. The key will not repeat
// (like CheckKeyHeld) - the player needed to release and press the key again.
// This is useful for actions where the player needs to control how many times
// the action should occur (for example, throwing projectiles when the player
// has a limited number of objects to throw).
inline bool CheckKeyPress(u16 key) {
	return g_keyPress & key;
}

#endif	// _GAME_UTILS_H_
