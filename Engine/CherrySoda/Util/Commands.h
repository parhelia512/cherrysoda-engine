#ifndef _CHERRYSODA_UTIL_COMMANDS_H_
#define _CHERRYSODA_UTIL_COMMANDS_H_

#include <CherrySoda/Util/Color.h>
#include <CherrySoda/Util/STL.h>
#include <CherrySoda/Util/String.h>

#define CHERRYSODA_CONSOLE_VARIABLE(VAR,TYPE,VALUE,HELP) \
static TYPE VAR=VALUE; \
static cherrysoda::CommandRegisterHelper CHERRYSODA_COMMAND_REGISTER_HELPER_##VAR(#VAR, \
[](const cherrysoda::STL::Vector<cherrysoda::String>& args) \
{ \
	if (cherrysoda::STL::Count(args) == 0) \
		cherrysoda::Commands::Log(cherrysoda::StringUtil::ToString(VAR)); \
	else \
		cherrysoda::StringUtil::SafeTo<TYPE>(args[0],VAR); \
	return 0; \
},HELP);

#define CHERRYSODA_REGISTER_COMMAND(COMMAND,FUNC,HELP) \
static cherrysoda::CommandRegisterHelper CHERRYSODA_COMMAND_REGISTER_HELPER_##COMMAND(#COMMAND,FUNC,HELP);

#define CHERRYSODA_COMMAND(COMMAND,HELP) \
int CherrySodaCommand_##COMMAND(const cherrysoda::STL::Vector<cherrysoda::String>& args); \
CHERRYSODA_REGISTER_COMMAND(COMMAND,CherrySodaCommand_##COMMAND,HELP); \
int CherrySodaCommand_##COMMAND(const cherrysoda::STL::Vector<cherrysoda::String>& args)

namespace cherrysoda {

class Commands
{
public:
	friend class GUI;

	static inline void Register(const StringID& command, STL::Func<int, const STL::Vector<String>&> func, const String& help)
	{
		INTERNAL_GetCommands()[command] = { func, help };
	}

	static int ExecuteCommand();
	static void Log(const String& str, const Color& color = Color::White);

	static void ClearLog();

	static void ShowHelp();
	static void ShowHelp(const String& command);

private:
	struct CommandInfo
	{
		STL::Func<int, STL::Vector<String>> func;
		String help;
	};

	static STL::HashMap<StringID, CommandInfo>& INTERNAL_GetCommands();

	static char ms_currentText[512];
	static STL::Vector<STL::Pair<Color,String>> ms_drawCommands;
	static bool ms_consoleTextScrollNeeded;
};

class CommandRegisterHelper
{
public:
	CommandRegisterHelper(const StringID& command, STL::Func<int, const STL::Vector<String>&> func, const String& help)
	{
		Commands::Register(command, func, help);
	}
};

} // namespace cherrysoda

#endif // _CHERRYSODA_UTIL_COMMANDS_H_
