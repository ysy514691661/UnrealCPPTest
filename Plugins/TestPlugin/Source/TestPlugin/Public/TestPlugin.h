// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorAssetLibrary.h"
#include "Blutility/Classes/EditorUtilityWidget.h"
#include "UMGEditor/Public/WidgetBlueprint.h"
#include "EditorUtilityWidgetBlueprint.h"
#include "EditorUtilitySubsystem.h"
#include "Modules/ModuleManager.h"

class FToolBarBuilder;
class FMenuBuilder;

class FTestPluginModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** This function will be bound to Command. */
	void PluginButtonClicked();
	void PluginButtonClicked2();
	void PluginButtonClicked3();
	
private:

	void RegisterMenus();
	void AddToolbarExtension(FToolBarBuilder& Builder);
	void AddMenuExtension(FMenuBuilder& Builder);
	void FillMenu(FMenuBuilder& Builder);
	void AddMenu(FMenuBarBuilder& Builder);



private:
	TSharedPtr<class FUICommandList> PluginCommands;
	TSharedPtr<class FUICommandList> PluginCommands2;
	TSharedPtr<class FUICommandList> PluginCommands3;

	
};
