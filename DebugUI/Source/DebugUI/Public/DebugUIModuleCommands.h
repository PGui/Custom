#pragma once

#include <HAL/IConsoleManager.h>

class FDebugUIModuleCommands
{
public:

	static const TCHAR* const ToggleInput;

	FDebugUIModuleCommands();

private:

	void ToggleInputImpl();

	FAutoConsoleCommand ToggleInputCommand;
};
