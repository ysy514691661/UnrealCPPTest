// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestPluginCommands.h"

#define LOCTEXT_NAMESPACE "FTestPluginModule"

void FTestPluginCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "Plugin1", "Add to Menu", EUserInterfaceActionType::Button, FInputGesture());
	UI_COMMAND(PluginAction2, "Plugin2", "Add to tool bar", EUserInterfaceActionType::Button, FInputGesture());
	UI_COMMAND(PluginAction3, "Plugin3", "Add to tool bar drop down", EUserInterfaceActionType::Button, FInputGesture());
	
}

#undef LOCTEXT_NAMESPACE
