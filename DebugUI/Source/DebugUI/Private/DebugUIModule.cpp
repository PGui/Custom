#include "DebugUIModule.h"
#include <Interfaces/IPluginManager.h>

#include "ImGuiDelegates.h"

#define LOCTEXT_NAMESPACE "FDebugUIModule"

void FDebugUIModule::StartupModule()
{
	ImGuiTickHandle = FImGuiDelegates::OnMultiContextDebug().AddRaw(this, &FDebugUIModule::OnDraw);
}

void FDebugUIModule::ShutdownModule()
{
	if (ImGuiTickHandle.IsValid())
	{
		FImGuiDelegates::OnMultiContextDebug().Remove(ImGuiTickHandle);
		ImGuiTickHandle.Reset();
	}
}

void FDebugUIModule::OnDraw()
{
#if WITH_IMGUI
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			//ShowExampleMenuFile();
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Edit"))
		{
			if (ImGui::MenuItem("Undo", "CTRL+Z")) {}
			if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {}  // Disabled item
			ImGui::Separator();
			if (ImGui::MenuItem("Cut", "CTRL+X")) {}
			if (ImGui::MenuItem("Copy", "CTRL+C")) {}
			if (ImGui::MenuItem("Paste", "CTRL+V")) {}
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
}
#endif
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FDebugUIModule, DebugUI)