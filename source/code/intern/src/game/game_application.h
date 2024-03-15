
#pragma once

#include "game_phase.h"

#include <array>

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

	private:

		// Old School: CPhase* m_pPhases[CPhase::NumberOfMembers];

		std::array<CPhase*, CPhase::NumberOfMembers> m_pPhases;
		CPhase::EPhase                               m_CurrentPhase;

	private:
		CApplication();

	private:
		void RunPhases();
	};
}
