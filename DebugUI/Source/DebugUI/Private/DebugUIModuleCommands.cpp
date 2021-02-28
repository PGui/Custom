#include "DebugUIModuleCommands.h"

const TCHAR* const FDebugUIModuleCommands::ToggleInput = TEXT("ImGui.ToggleInput");

FDebugUIModuleCommands::FDebugUIModuleCommands()
	: ToggleInputCommand(ToggleInput,
		TEXT("Toggle ImGui input mode."),
		FConsoleCommandDelegate::CreateRaw(this, &FDebugUIModuleCommands::ToggleInputImpl))
{
}

void FDebugUIModuleCommands::ToggleInputImpl()
{
}