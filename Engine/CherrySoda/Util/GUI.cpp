#include <CherrySoda/Util/GUI.h>

#include <CherrySoda/Engine.h>
#include <CherrySoda/Graphics/Graphics.h>
#include <CherrySoda/Input/MInput.h>
#include <CherrySoda/Util/Commands.h>
#include <CherrySoda/Util/Math.h>
#include <CherrySoda/Util/NumType.h>
#include <CherrySoda/Util/String.h>
#include <CherrySoda/Graphics/Texture.h>

#include <imgui.h>
#include <SDL.h>

#include <cstring>

using cherrysoda::GUI;

using cherrysoda::ButtonState;
using cherrysoda::Commands;
using cherrysoda::Effect;
using cherrysoda::Engine;
using cherrysoda::Graphics;
using cherrysoda::Keys;
using cherrysoda::Math;
using cherrysoda::MInput;
using cherrysoda::String;
using cherrysoda::StringUtil;
using cherrysoda::Texture2D;

namespace type = cherrysoda::type;

Effect GUI::ms_guiEffect;
Texture2D GUI::ms_fontTexture;
type::UInt16 GUI::ms_guiRenderPass = 0;
bool GUI::ms_disable = false;
bool GUI::ms_frameStarted = false;
bool GUI::ms_consoleFocused = false;
bool GUI::ms_sliderFocused = false;

static SDL_Cursor* g_MouseCursors[ImGuiMouseCursor_COUNT] = {};

const char* GetClipboardText_SDL2ImplForImGui(void*)
{
	return SDL_GetClipboardText();
}

void SetClipboardText_SDL2ImplForImGui(void*, const char* text)
{
	SDL_SetClipboardText(text);
}

ImGuiKey CherrySodaKeyToImGuiKey(Keys key)
{
	switch (key) {
		case Keys::Tab: return ImGuiKey_Tab;
		case Keys::Left: return ImGuiKey_LeftArrow;
		case Keys::Right: return ImGuiKey_RightArrow;
		case Keys::Up: return ImGuiKey_UpArrow;
		case Keys::Down: return ImGuiKey_DownArrow;
		case Keys::PageUp: return ImGuiKey_PageUp;
		case Keys::PageDown: return ImGuiKey_PageDown;
		case Keys::Home: return ImGuiKey_Home;
		case Keys::End: return ImGuiKey_End;
		case Keys::Insert: return ImGuiKey_Insert;
		case Keys::Delete: return ImGuiKey_Delete;
		case Keys::Back: return ImGuiKey_Backspace;
		case Keys::Space: return ImGuiKey_Space;
		case Keys::Enter: return ImGuiKey_Enter;
		case Keys::Escape: return ImGuiKey_Escape;
		case Keys::OemQuotes: return ImGuiKey_Apostrophe;
		case Keys::OemComma: return ImGuiKey_Comma;
		case Keys::OemMinus: return ImGuiKey_Minus;
		case Keys::OemPeriod: return ImGuiKey_Period;
		case Keys::OemQuestion: return ImGuiKey_Slash;
		case Keys::OemSemicolon: return ImGuiKey_Semicolon;
		case Keys::OemPlus: return ImGuiKey_Equal;
		case Keys::OemOpenBrackets: return ImGuiKey_LeftBracket;
		case Keys::OemBackslash: return ImGuiKey_Backslash;
		case Keys::OemCloseBrackets: return ImGuiKey_RightBracket;
		case Keys::OemTilde: return ImGuiKey_GraveAccent;
		case Keys::CapsLock: return ImGuiKey_CapsLock;
		case Keys::Scroll: return ImGuiKey_ScrollLock;
		case Keys::NumLock: return ImGuiKey_NumLock;
		case Keys::PrintScreen: return ImGuiKey_PrintScreen;
		case Keys::Pause: return ImGuiKey_Pause;
		case Keys::NumPad0: return ImGuiKey_Keypad0;
		case Keys::NumPad1: return ImGuiKey_Keypad1;
		case Keys::NumPad2: return ImGuiKey_Keypad2;
		case Keys::NumPad3: return ImGuiKey_Keypad3;
		case Keys::NumPad4: return ImGuiKey_Keypad4;
		case Keys::NumPad5: return ImGuiKey_Keypad5;
		case Keys::NumPad6: return ImGuiKey_Keypad6;
		case Keys::NumPad7: return ImGuiKey_Keypad7;
		case Keys::NumPad8: return ImGuiKey_Keypad8;
		case Keys::NumPad9: return ImGuiKey_Keypad9;
		case Keys::LeftControl: return ImGuiKey_LeftCtrl;
		case Keys::LeftShift: return ImGuiKey_LeftShift;
		case Keys::LeftAlt: return ImGuiKey_LeftAlt;
		case Keys::LeftSuper: return ImGuiKey_LeftSuper;
		case Keys::RightControl: return ImGuiKey_RightCtrl;
		case Keys::RightShift: return ImGuiKey_RightShift;
		case Keys::RightAlt: return ImGuiKey_RightAlt;
		case Keys::RightSuper: return ImGuiKey_RightSuper;
		case Keys::D0: return ImGuiKey_0;
		case Keys::D1: return ImGuiKey_1;
		case Keys::D2: return ImGuiKey_2;
		case Keys::D3: return ImGuiKey_3;
		case Keys::D4: return ImGuiKey_4;
		case Keys::D5: return ImGuiKey_5;
		case Keys::D6: return ImGuiKey_6;
		case Keys::D7: return ImGuiKey_7;
		case Keys::D8: return ImGuiKey_8;
		case Keys::D9: return ImGuiKey_9;
		case Keys::A: return ImGuiKey_A;
		case Keys::B: return ImGuiKey_B;
		case Keys::C: return ImGuiKey_C;
		case Keys::D: return ImGuiKey_D;
		case Keys::E: return ImGuiKey_E;
		case Keys::F: return ImGuiKey_F;
		case Keys::G: return ImGuiKey_G;
		case Keys::H: return ImGuiKey_H;
		case Keys::I: return ImGuiKey_I;
		case Keys::J: return ImGuiKey_J;
		case Keys::K: return ImGuiKey_K;
		case Keys::L: return ImGuiKey_L;
		case Keys::M: return ImGuiKey_M;
		case Keys::N: return ImGuiKey_N;
		case Keys::O: return ImGuiKey_O;
		case Keys::P: return ImGuiKey_P;
		case Keys::Q: return ImGuiKey_Q;
		case Keys::R: return ImGuiKey_R;
		case Keys::S: return ImGuiKey_S;
		case Keys::T: return ImGuiKey_T;
		case Keys::U: return ImGuiKey_U;
		case Keys::V: return ImGuiKey_V;
		case Keys::W: return ImGuiKey_W;
		case Keys::X: return ImGuiKey_X;
		case Keys::Y: return ImGuiKey_Y;
		case Keys::Z: return ImGuiKey_Z;
		case Keys::F1: return ImGuiKey_F1;
		case Keys::F2: return ImGuiKey_F2;
		case Keys::F3: return ImGuiKey_F3;
		case Keys::F4: return ImGuiKey_F4;
		case Keys::F5: return ImGuiKey_F5;
		case Keys::F6: return ImGuiKey_F6;
		case Keys::F7: return ImGuiKey_F7;
		case Keys::F8: return ImGuiKey_F8;
		case Keys::F9: return ImGuiKey_F9;
		case Keys::F10: return ImGuiKey_F10;
		case Keys::F11: return ImGuiKey_F11;
		case Keys::F12: return ImGuiKey_F12;
		default: return ImGuiKey_None;
	}
}

void GUI::Initialize()
{
	ImGui::CreateContext();

	ms_guiRenderPass = Graphics::MaxRenderPassCount() - 1;

	// Setup back-end capabilities flags
	ImGuiIO& io = ImGui::GetIO();
	io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
	io.BackendPlatformName = "imgui_impl_cherrysoda";

	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable | ImGuiConfigFlags_NavEnableGamepad | ImGuiConfigFlags_NavEnableKeyboard;

	// TODO: Hide SDL2 from ImGui, provide engine interface
	// Load mouse cursors
	g_MouseCursors[ImGuiMouseCursor_Arrow] = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
	g_MouseCursors[ImGuiMouseCursor_TextInput] = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_IBEAM);
	g_MouseCursors[ImGuiMouseCursor_ResizeAll] = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZEALL);
	g_MouseCursors[ImGuiMouseCursor_ResizeNS] = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENS);
	g_MouseCursors[ImGuiMouseCursor_ResizeEW] = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZEWE);
	g_MouseCursors[ImGuiMouseCursor_ResizeNESW] = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENESW);
	g_MouseCursors[ImGuiMouseCursor_ResizeNWSE] = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENWSE);
	g_MouseCursors[ImGuiMouseCursor_Hand] = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
	g_MouseCursors[ImGuiMouseCursor_NotAllowed] = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_NO);

	// Clipboard
	io.GetClipboardTextFn = GetClipboardText_SDL2ImplForImGui;
	io.SetClipboardTextFn = SetClipboardText_SDL2ImplForImGui;
	io.ClipboardUserData = nullptr;

	// Font texture 
	BuildFontTexture();

	// Style
	// auto& style = ImGui::GetStyle();
	// style.WindowBorderSize = 2.0f;
	// style.FrameBorderSize = 2.0f;
	// style.ScaleAllSizes(2.0f);

	// Shader
	ms_guiEffect = Graphics::GetEmbeddedEffect("sprite");
}

void GUI::Terminate()
{
	SDL_FreeCursor(g_MouseCursors[ImGuiMouseCursor_Arrow]);
	SDL_FreeCursor(g_MouseCursors[ImGuiMouseCursor_TextInput]);
	SDL_FreeCursor(g_MouseCursors[ImGuiMouseCursor_ResizeAll]);
	SDL_FreeCursor(g_MouseCursors[ImGuiMouseCursor_ResizeNS]);
	SDL_FreeCursor(g_MouseCursors[ImGuiMouseCursor_ResizeEW]);
	SDL_FreeCursor(g_MouseCursors[ImGuiMouseCursor_ResizeNESW]);
	SDL_FreeCursor(g_MouseCursors[ImGuiMouseCursor_ResizeNWSE]);
	SDL_FreeCursor(g_MouseCursors[ImGuiMouseCursor_Hand]);
	SDL_FreeCursor(g_MouseCursors[ImGuiMouseCursor_NotAllowed]);

	ms_fontTexture.Dispose();
	ImGui::DestroyContext();
}

void GUI::Update()
{
	if (ms_disable) return;

	ImGuiIO& io = ImGui::GetIO();


	// Window size update
	auto winSize = Engine::Instance()->GetWindowSize();	
	io.DisplaySize.x = winSize.x;
	io.DisplaySize.y = winSize.y;

	if (Engine::Instance()->IsActive()) {
		// Keyboard
		static STL::List<Keys> s_previousKeyboardKeys;
		auto keyboardKeys = MInput::GetCurrentKeyboardKeys();
		STL::Sort(keyboardKeys);

		if (keyboardKeys != s_previousKeyboardKeys) {
			auto it1 = s_previousKeyboardKeys.begin();
			auto it2 = keyboardKeys.begin();

			while (it1 != s_previousKeyboardKeys.end() && it2 != keyboardKeys.end()) {
				if (*it1 < *it2) { io.AddKeyEvent(CherrySodaKeyToImGuiKey(*it1), false); ++it1; }
				else if (*it1 > *it2) { io.AddKeyEvent(CherrySodaKeyToImGuiKey(*it2), true); ++it2; }
				else { ++it1; ++it2; }
			}
			for (; it1 != s_previousKeyboardKeys.end(); ++it1) {
				io.AddKeyEvent(CherrySodaKeyToImGuiKey(*it1), false);
			}
			for (; it2 != keyboardKeys.end(); ++it2) {
				io.AddKeyEvent(CherrySodaKeyToImGuiKey(*it2), true);
			}
			bool keyShift = false, keyCtrl = false, keyAlt = false, keySuper = false;
			MInput::KeyboardState keyboard = MInput::GetKeyboardState();
			keyCtrl  = keyboard.IsKeyDown(Keys::LeftControl) || keyboard.IsKeyDown(Keys::RightControl);
			keyShift = keyboard.IsKeyDown(Keys::LeftShift)   || keyboard.IsKeyDown(Keys::RightShift);
			keyAlt   = keyboard.IsKeyDown(Keys::LeftAlt)     || keyboard.IsKeyDown(Keys::RightAlt);
			keySuper = keyboard.IsKeyDown(Keys::LeftSuper)   || keyboard.IsKeyDown(Keys::RightSuper);
			ImGuiKeyModFlags keyMods =
				(keyCtrl  ? ImGuiKeyModFlags_Ctrl  : 0) |
				(keyShift ? ImGuiKeyModFlags_Shift : 0) |
				(keyAlt   ? ImGuiKeyModFlags_Alt   : 0) |
				(keySuper ? ImGuiKeyModFlags_Super : 0);
			io.AddKeyModsEvent(keyMods);
		}

		s_previousKeyboardKeys = keyboardKeys;

		// Mouse
		MInput::MouseState mouse = MInput::GetMouseState();
		static int s_previousWheel = mouse.m_scrollWheelValue;
		int mouseWheelDelta = (mouse.m_scrollWheelValue - s_previousWheel) / 120;
		io.AddMousePosEvent(static_cast<float>(mouse.m_x), static_cast<float>(mouse.m_y));
		io.AddMouseButtonEvent(0, mouse.m_leftButton == ButtonState::Pressed);
		io.AddMouseButtonEvent(1, mouse.m_rightButton == ButtonState::Pressed);
		io.AddMouseButtonEvent(2, mouse.m_middleButton == ButtonState::Pressed);
		io.AddMouseWheelEvent(0.f, static_cast<float>(mouseWheelDelta));
		s_previousWheel = mouse.m_scrollWheelValue;

		// Mouse cursor control
		if (!(io.ConfigFlags & ImGuiConfigFlags_NoMouseCursorChange)) {
			ImGuiMouseCursor imgui_cursor = ImGui::GetMouseCursor();
			if (io.MouseDrawCursor || imgui_cursor == ImGuiMouseCursor_None)
			{
				// Hide OS mouse cursor if imgui is drawing it or if it wants no cursor
				SDL_ShowCursor(SDL_DISABLE);
			}
			else
			{
				// Show OS mouse cursor
				SDL_SetCursor(g_MouseCursors[imgui_cursor] ? g_MouseCursors[imgui_cursor] : g_MouseCursors[ImGuiMouseCursor_Arrow]);
				if (Engine::Instance()->DoShowCursor()) {
					SDL_ShowCursor(SDL_ENABLE);
				}
				else if (!Engine::Instance()->ConsoleOpened()) {
					SDL_ShowCursor(SDL_DISABLE);
				}
			}
		}

		// GamePad
		if ((io.ConfigFlags & ImGuiConfigFlags_NavEnableGamepad) != 0) {
			auto gamepad = MInput::GamePads(0);
			if (gamepad->Attached()) {
				io.BackendFlags |= ImGuiBackendFlags_HasGamepad;

				io.AddKeyEvent(ImGuiKey_GamepadStart, gamepad->Check(Buttons::Start));
				io.AddKeyEvent(ImGuiKey_GamepadBack, gamepad->Check(Buttons::Back));
				io.AddKeyEvent(ImGuiKey_GamepadFaceDown, gamepad->Check(Buttons::A));
				io.AddKeyEvent(ImGuiKey_GamepadFaceRight, gamepad->Check(Buttons::B));
				io.AddKeyEvent(ImGuiKey_GamepadFaceLeft, gamepad->Check(Buttons::X));
				io.AddKeyEvent(ImGuiKey_GamepadFaceUp, gamepad->Check(Buttons::Y));
				io.AddKeyEvent(ImGuiKey_GamepadDpadLeft, gamepad->Check(Buttons::DPadLeft));
				io.AddKeyEvent(ImGuiKey_GamepadDpadRight, gamepad->Check(Buttons::DPadRight));
				io.AddKeyEvent(ImGuiKey_GamepadDpadUp, gamepad->Check(Buttons::DPadUp));
				io.AddKeyEvent(ImGuiKey_GamepadDpadDown, gamepad->Check(Buttons::DPadDown));
				io.AddKeyEvent(ImGuiKey_GamepadL1, gamepad->Check(Buttons::LeftShoulder));
				io.AddKeyEvent(ImGuiKey_GamepadR1, gamepad->Check(Buttons::RightShoulder));
				io.AddKeyEvent(ImGuiKey_GamepadL3, gamepad->Check(Buttons::LeftStick));
				io.AddKeyEvent(ImGuiKey_GamepadR3, gamepad->Check(Buttons::RightStick));

				float LT = gamepad->GetLeftTrigger();
				float RT = gamepad->GetRightTrigger();
				io.AddKeyAnalogEvent(ImGuiKey_GamepadL2, LT > 0.1f, LT);
				io.AddKeyAnalogEvent(ImGuiKey_GamepadR2, RT > 0.1f, RT);

				const float stickDeadZone = 0.1f;
				Math::Vec2 LS = gamepad->GetLeftStick(stickDeadZone);
				Math::Vec2 RS = gamepad->GetRightStick(stickDeadZone);
				io.AddKeyAnalogEvent(ImGuiKey_GamepadLStickLeft, LS.x < -stickDeadZone, Math_Clamp(LS.x, -1.f, 0.f) * -1.f);
				io.AddKeyAnalogEvent(ImGuiKey_GamepadLStickRight, LS.x > stickDeadZone, Math_Clamp(LS.x, 0.f, 1.f));
				io.AddKeyAnalogEvent(ImGuiKey_GamepadLStickUp, LS.y > stickDeadZone, Math_Clamp(LS.y, 0.f, 1.f));
				io.AddKeyAnalogEvent(ImGuiKey_GamepadLStickDown, LS.y < -stickDeadZone, Math_Clamp(LS.y, -1.f, 0.f) * -1.f);
				io.AddKeyAnalogEvent(ImGuiKey_GamepadRStickLeft, RS.x < -stickDeadZone, Math_Clamp(RS.x, -1.f, 0.f) * -1.f);
				io.AddKeyAnalogEvent(ImGuiKey_GamepadRStickRight, RS.x > stickDeadZone, Math_Clamp(RS.x, 0.f, 1.f));
				io.AddKeyAnalogEvent(ImGuiKey_GamepadRStickUp, RS.y > stickDeadZone, Math_Clamp(RS.y, 0.f, 1.f));
				io.AddKeyAnalogEvent(ImGuiKey_GamepadRStickDown, RS.y < -stickDeadZone, Math_Clamp(RS.y, -1.f, 0.f) * -1.f);
			}
			else {
				io.BackendFlags &= ~ImGuiBackendFlags_HasGamepad;
			}
		}
	}

	// Delta time
	io.DeltaTime = Engine::Instance()->RawDeltaTime();

	ImGui::NewFrame();

	ms_frameStarted = true;

	// Debug Console GUI
	ms_consoleFocused = false;
	ms_sliderFocused = false;
	if (Engine::Instance()->ConsoleOpened()) {
		if (!Engine::Instance()->DoShowCursor() && !io.MouseDrawCursor) {
			SDL_ShowCursor(SDL_ENABLE);
		}
		ImGui::SetNextWindowSizeConstraints(ImVec2(300.f, 180.f), ImVec2(FLT_MAX, FLT_MAX));
		ImGui::Begin("Console");
		{
			bool isLogOutputFocused = false;
			ImGui::BeginChild("LogOutput", ImVec2(0.f, -ImGui::GetTextLineHeight() - 13.f), true);
			{
				isLogOutputFocused = ImGui::IsWindowFocused();
				for (auto c : Commands::ms_drawCommands) {
					ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(c.first.R(), c.first.G(), c.first.B(), c.first.A()));
					ImGui::TextUnformatted(c.second.c_str());
					ImGui::PopStyleColor();
				}
				if (Commands::ms_consoleTextScrollNeeded) {
					ImGui::SetScrollHereY();
					Commands::ms_consoleTextScrollNeeded = false;
				}
			}
			ImGui::EndChild();
			if (ImGui::IsWindowFocused() || isLogOutputFocused) {
				ms_consoleFocused = true;
				if (!ImGui::IsAnyItemActive() && !ImGui::IsMouseClicked(0)) {
					ImGui::SetKeyboardFocusHere(0);
				}
			}
			struct Funcs
			{
				static int InputTextCallback(ImGuiInputTextCallbackData* data)
				{
					if (data->EventFlag == ImGuiInputTextFlags_CallbackCompletion) {
						String suffix = Commands::GetCompletionSuffix(String(data->Buf, data->BufTextLen));
						data->InsertChars(data->BufTextLen, suffix.c_str());
					}
					else if (data->EventFlag == ImGuiInputTextFlags_CallbackHistory) {
						if (data->EventKey == ImGuiKey_UpArrow) {
							String command = Commands::GetBackwardHistory();
							data->DeleteChars(0, data->BufTextLen);
							data->InsertChars(0, command.c_str());
							data->SelectAll();
						}
						else if (data->EventKey == ImGuiKey_DownArrow) {
							String command = Commands::GetForwardHistory();
							data->DeleteChars(0, data->BufTextLen);
							data->InsertChars(0, command.c_str());
							data->SelectAll();
						}
					}
					return 0;
				}
			};
			ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x - ImGui::GetTextLineHeight() * 2.f - 26.f);
			const ImGuiInputTextFlags inputTextFlag = ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_CallbackCompletion | ImGuiInputTextFlags_CallbackHistory;
			bool commandInput = ImGui::InputText("##Command", Commands::ms_currentText, IM_ARRAYSIZE(Commands::ms_currentText), inputTextFlag, Funcs::InputTextCallback);
			ImGui::PopItemWidth();
			ImGui::SameLine(); commandInput |= ImGui::Button("Enter");
			if (commandInput && Commands::ms_currentText[0] != '\0') {
				Commands::ExecuteCommand();
			}
		}
		ImGui::End();
		if (STL::IsNotEmpty(Commands::ms_sliderInfo)) {
			ImGui::SetNextWindowSizeConstraints(ImVec2(280.f, 170.f), ImVec2(FLT_MAX, FLT_MAX));
			ImGui::Begin("Sliders");
			{
				ms_sliderFocused = ImGui::IsWindowFocused();
				for (auto& slider : Commands::ms_sliderInfo) {
					if (ImGui::SliderFloat(slider.param.c_str(), &slider.value, slider.minValue, slider.maxValue)) {
						Commands::ExecuteCommand(slider.param + " " + StringUtil::ToString(slider.value));
					}
				}
			}
			ImGui::End();
		}
	}
}

void GUI::Render()
{
	if (ms_frameStarted) {
		ms_frameStarted = false;
	}
	else return;

	ImGui::Render();

	ImGuiIO& io = ImGui::GetIO();
	auto drawData = ImGui::GetDrawData();

	int fbWidth = (int)(drawData->DisplaySize.x * drawData->FramebufferScale.x);
	int fbHeight = (int)(drawData->DisplaySize.y * drawData->FramebufferScale.y);
	if (fbWidth <= 0 || fbHeight <= 0)
		return;

	ImVec2 clipOff = drawData->DisplayPos;
	ImVec2 clipScale = drawData->FramebufferScale;

	CHERRYSODA_ASSERT(sizeof(ImDrawIdx) == 2, "ImGui graphics index type is not type::UInt16\n");

	Graphics::BeginRenderPass(ms_guiRenderPass);
	Graphics::UseCurrentRenderPass()->SetViewport(0, 0, fbWidth, fbHeight);
	Graphics::UseCurrentRenderPass()->SetViewProjectionMatrix(Math_Identity<Math::Mat4>(), Math_Ortho(Graphics::TexelHalf(), io.DisplaySize.x + Graphics::TexelHalf(), io.DisplaySize.y + Graphics::TexelHalf(), Graphics::TexelHalf(), -1000.f, 1000.f));
	for (int n = 0; n < drawData->CmdListsCount; ++n) {
		const ImDrawList* drawList = drawData->CmdLists[n];
		auto vb = Graphics::CreateTransientVertexBuffer(reinterpret_cast<Graphics::ImGuiVertex*>(drawList->VtxBuffer.Data), drawList->VtxBuffer.Size);
		auto ib = Graphics::CreateTransientIndexBuffer(drawList->IdxBuffer.Data, drawList->IdxBuffer.Size);
		for (const ImDrawCmd* cmd = drawList->CmdBuffer.begin(), *cmdEnd = drawList->CmdBuffer.end(); cmd != cmdEnd; ++cmd) {
			if (cmd->UserCallback) {
				cmd->UserCallback(drawList, cmd);
			}
			else if (0 != cmd->ElemCount) {
				ImVec4 clipRect;
				clipRect.x = (cmd->ClipRect.x - clipOff.x) * clipScale.x;
				clipRect.y = (cmd->ClipRect.y - clipOff.y) * clipScale.y;
				clipRect.z = (cmd->ClipRect.z - clipOff.x) * clipScale.x;
				clipRect.w = (cmd->ClipRect.w - clipOff.y) * clipScale.y;
				Graphics::SetScissor((int)clipRect.x, (int)(clipRect.y), (int)(clipRect.z - clipRect.x), (int)(clipRect.w - clipRect.y));
				Graphics::SetTexture((Texture*)cmd->TextureId);
				Graphics::SetTransientVertexBuffer(vb);
				Graphics::SetTransientIndexBuffer(ib, cmd->IdxOffset, cmd->ElemCount);
				Graphics::SetStateNoDepth(Graphics::BlendFunction::Alpha);
				Graphics::SubmitOnCurrentRenderPass(&ms_guiEffect);
			}
		}
	}
	Graphics::EndRenderPass(ms_guiRenderPass);
}

void GUI::BuildFontTexture()
{
	ImGuiIO& io = ImGui::GetIO();
	unsigned char* data;
	int width, height;
	io.Fonts->GetTexDataAsRGBA32(&data, &width, &height);
	ms_fontTexture.Dispose();
	ms_fontTexture = Texture2D::FromRGBA(data, width, height);
	io.Fonts->TexID = (ImTextureID)(&ms_fontTexture);
}

void GUI::TextInput(const char* text)
{
	ImGuiIO& io = ImGui::GetIO();
	io.AddInputCharactersUTF8(text);
}
