#pragma once

#include <Modules/ModuleManager.h>

#ifdef IMGUI_API
#define WITH_IMGUI 1
#else
#define WITH_IMGUI 0
#endif // IMGUI_API

#if WITH_IMGUI
#include <imgui.h>
#endif // WITH_IMGUI

class FDebugUIModule : public IModuleInterface
{
public:

	/**
	 * Singleton-like access to this module's interface. This is just for convenience!
	 * Beware of calling this during the shutdown phase, though. Your module might have been unloaded already.
	 *
	 * @return Returns singleton instance, loading the module on demand if needed
	 */
	static inline FDebugUIModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FDebugUIModule>("DebugUI");
	}

	/**
	 * Checks to see if this module is loaded and ready. It is only valid to call Get() if IsAvailable() returns true.
	 *
	 * @return True if the module is loaded and ready to use
	 */
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("DebugUI");
	}

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void OnDraw();

public:
	FDelegateHandle ImGuiTickHandle;
};
