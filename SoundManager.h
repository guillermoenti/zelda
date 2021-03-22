#pragma once

#include "includes.h"
#include <SFML/Audio.hpp>

#define MAX_SOUNDS 40

class SoundManager {
	public:
		SoundManager();
		~SoundManager();
		
		void playMusic(const char* filepath);
		int playSound(const char* filepath, bool loop = false);
		void loadSound(const char* filepath);

		void musicPause();
		void musicResume();
		void musicStop();
		bool musicIsPlaying();

		void soundPause(int soundID);
		void soundResume(int soundID);
		void soundStop(int soundID);
		bool soundIsPlaying(int soundID);

		static SoundManager* getInstance();

	private:
		sf::SoundBuffer* getBuffer(const char* file);
		void updateSoundFirstFreeSlot();

		static SoundManager* instance;

		std::map<std::string, sf::SoundBuffer*> mSndBufferMap; //Solo sonidos
		std::vector<sf::Sound*>					mSoundVector; //Para limitar los sondios
		sf::Music*								mCurrentBGM;  //Musica de fondo actual (solo una a la vez)

		int mCurrentSoundIndex;
};
