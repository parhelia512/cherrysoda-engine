#ifndef _CHERRYSODA_INPUT_MINPUT_H_
#define _CHERRYSODA_INPUT_MINPUT_H_

#include <CherrySoda/Util/Log.h>
#include <CherrySoda/Util/Math.h>
#include <CherrySoda/Util/NumType.h>

namespace cherrysoda {

enum class PlayerIndex
{
	One = 0,
	Two = 1,
	Three = 2,
	Four = 3
};

enum class Buttons : type::UInt32
{
	None = 0,
	DPadUp = 1,
	DPadDown = 2,
	DPadLeft = 4,
	DPadRight = 8,
	Start = 16,
	Back = 32,
	LeftStick = 64,
	RightStick = 128,
	LeftShoulder = 256,
	RightShoulder = 512,
	BigButton = 2048,
	A = 4096,
	B = 8192,
	X = 16384,
	Y = 32768,
	LeftThumbstickLeft = 2097152,
	RightTrigger = 4194304,
	LeftTrigger = 8388608,
	RightThumbstickUp = 16777216,
	RightThumbstickDown = 33554432,
	RightThumbstickRight = 67108864,
	RightThumbstickLeft = 134217728,
	LeftThumbstickUp = 268435456,
	LeftThumbstickDown = 536870912,
	LeftThumbstickRight = 1073741824
};

DECLARE_ENUM_FLAG(Buttons);

class MInput
{
public:
	friend class Engine;

	struct GamePadThumbSticks
	{
		inline GamePadThumbSticks(const Math::Vec2& leftThumbstick, const Math::Vec2& rightThumbStick)
		: m_left(leftThumbstick)
		, m_right(rightThumbStick)
		{
		}

		Math::Vec2 m_left;
		Math::Vec2 m_right;
	};

	struct GamePadTriggers
	{
		inline GamePadTriggers(float left, float right)
		: m_left(left)
		, m_right(right)
		{
		}

		float m_left;
		float m_right;
	};

	struct GamePadButtons
	{
		inline GamePadButtons(Buttons buttons)
		: m_buttons(buttons)
		{
		}

		Buttons m_buttons;
	};

	struct GamePadState
	{
		inline bool IsButtonDown(Buttons buttons) const
		{
			return (m_buttons.m_buttons & buttons) == buttons;
		}

		inline bool IsButtonUp(Buttons buttons) const
		{
			return (m_buttons.m_buttons & buttons) != buttons;
		}

		GamePadThumbSticks m_thumbSticks = GamePadThumbSticks(Vec2_Zero, Vec2_Zero);
		GamePadTriggers m_triggers = GamePadTriggers(0.f, 0.f);
		GamePadButtons m_buttons = GamePadButtons(Buttons::None);
		bool m_connected = false;
	};

	class GamePadData
	{
	public:
		friend class MInput;

		void Update();
		void UpdateNull();

		void Rumble(float strength, float time);
		void StopRumble();

		// Buttons
		// TODO: Implement gamepad button stuff
		inline bool Check(Buttons button) const { return m_currentState.IsButtonDown(button); }
		inline bool Pressed(Buttons button) const { return m_currentState.IsButtonDown(button) && m_previousState.IsButtonUp(button); }
		inline bool Released(Buttons button) const { return m_currentState.IsButtonUp(button) && m_previousState.IsButtonDown(button); }

		inline bool Check(Buttons buttonA, Buttons buttonB) const
		{
			return Check(buttonA) || Check(buttonB);
		}

		inline bool Pressed(Buttons buttonA, Buttons buttonB) const
		{
			return Pressed(buttonA) || Pressed(buttonB);
		}

		inline bool Released(Buttons buttonA, Buttons buttonB) const
		{
			return Released(buttonA) || Released(buttonB);
		}

		inline bool Check(Buttons buttonA, Buttons buttonB, Buttons buttonC) const
		{
			return Check(buttonA) || Check(buttonB) || Check(buttonC);
		}

		inline bool Pressed(Buttons buttonA, Buttons buttonB, Buttons buttonC) const
		{
			return Pressed(buttonA) || Pressed(buttonB) || Pressed(buttonC);
		}

		inline bool Released(Buttons buttonA, Buttons buttonB, Buttons buttonC) const
		{
			return Released(buttonA) || Released(buttonB) || Released(buttonC);
		}

		// Sticks
		inline const Math::Vec2 GetLeftStick() const
		{
			return m_currentState.m_thumbSticks.m_left;
		}

		inline const Math::Vec2 GetLeftStick(float deadZone) const
		{
			Math::Vec2 ret = m_currentState.m_thumbSticks.m_left;
			if (Math_Dot(ret, ret) < deadZone * deadZone) {
				ret = Vec2_Zero;
			}
			return ret;
		}

		inline const Math::Vec2 GetRightStick() const
		{
			return m_currentState.m_thumbSticks.m_right;
		}

		inline const Math::Vec2 GetRightStick(float deadZone) const
		{
			Math::Vec2 ret = m_currentState.m_thumbSticks.m_right;
			if (Math_Dot(ret, ret) < deadZone * deadZone) {
				ret = Vec2_Zero;
			}
			return ret;
		}

		inline float GetLeftTrigger() const
		{
			return m_currentState.m_triggers.m_left;
		}

		inline float GetRightTrigger() const
		{
			return m_currentState.m_triggers.m_right;
		}

		inline bool LeftTriggerCheck(float threshold) const
		{
			return m_currentState.m_triggers.m_left >= threshold;
		}

		inline bool LeftTriggerPressed(float threshold) const
		{
			return m_currentState.m_triggers.m_left >= threshold && m_previousState.m_triggers.m_left < threshold;
		}

		inline bool LeftTriggerReleased(float threshold) const
		{
			return m_currentState.m_triggers.m_left < threshold && m_previousState.m_triggers.m_left >= threshold;
		}

		inline bool RightTriggerCheck(float threshold) const
		{
			return m_currentState.m_triggers.m_right >= threshold;
		}

		inline bool RightTriggerPressed(float threshold) const
		{
			return m_currentState.m_triggers.m_right >= threshold && m_previousState.m_triggers.m_right < threshold;
		}

		inline bool RightTriggerReleased(float threshold) const
		{
			return m_currentState.m_triggers.m_right < threshold && m_previousState.m_triggers.m_right >= threshold;
		}

	private:
		inline GamePadData(PlayerIndex playerIndex)
		: m_playerIndex(playerIndex)
		{
		}

		PlayerIndex m_playerIndex;
		GamePadState m_currentState;
		GamePadState m_previousState;
		bool m_attached = false;

		float m_rumbleStrength = 0.f;
		float m_rumbleTime = 0.f;
	};

	static GamePadData* GamePads(int index)
	{
		CHERRYSODA_ASSERT(index < 4, "GamePad index out of range!\n");
		return ms_gamePads[index];
	}

	static void Initialize();

private:
	static void Shutdown();
	static void Update();
	static void UpdateNull();

	static const GamePadState GetGamePadState(int index);
	static bool SetGamePadVibration(int index, float leftMotor, float rightMotor);

	static GamePadData* ms_gamePads[4];
	static void* ms_internalDevices[4];
};

} // namespace cherrysoda

#endif // _CHERRYSODA_INPUT_MINPUT_H_
