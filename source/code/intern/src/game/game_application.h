
#pragma once

#include "game_phase.h"
#include <array>
#include <SFML/Graphics/RenderWindow.hpp>

namespace Game
{
	class CApplication
	{
	public:
		static CApplication& GetInstance()
		{
			static CApplication instance;
			return instance;
		};

		CApplication(const CApplication&) = delete;
		CApplication& operator = (const CApplication&) = delete;

	public:
		void Startup();
		void Run();
		void Shutdown();

	public:
		sf::RenderWindow m_Window;

	private:

		std::array<CPhase*, CPhase::NumberOfMembers> m_pPhases;
		CPhase::EPhase                               m_CurrentPhase;

	private:
		CApplication();

	private:
		void RunPhases();
	};
}
