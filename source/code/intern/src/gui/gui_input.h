#pragma once

#include <SFML/Window/Keyboard.hpp>

namespace Gui
{
	class CInput
	{
		public:
			struct SKeyInput
			{
				sf::Keyboard::Key Key;
			};

			enum EInputType
			{
				KeyPressed,
				KeyReleased,
				NumberOfInputTypes
			};

			EInputType m_InputType;
			SKeyInput m_KeyInput;
	};
}