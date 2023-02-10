// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestPlugin.h"

#include "LevelEditor.h"
#include "TestPluginStyle.h"
#include "TestPluginCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"



static const FName TestPluginTabName("TestPlugin");

#define LOCTEXT_NAMESPACE "FTestPluginModule"

void FTestPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// FString TheFloatStr = FString::SanitizeFloat(desLocation.Z);
	// GEngine->AddOnScreenDebugMessage( -1,1.0,FColor::Red, *TheFloatStr );
	//GEngine->AddOnScreenDebugMessage( -1,1.0,FColor::Red, TEXT("HelloHelo"));
	UE_LOG(LogTemp, Warning, TEXT("Plugin installed"));
	FTestPluginStyle::Initialize();
	FTestPluginStyle::ReloadTextures();

	FTestPluginCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);
	PluginCommands2 = MakeShareable(new FUICommandList);
	PluginCommands3 = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FTestPluginCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FTestPluginModule::PluginButtonClicked),
		FCanExecuteAction());
	
	PluginCommands2->MapAction(
		FTestPluginCommands::Get().PluginAction2,
		FExecuteAction::CreateRaw(this, &FTestPluginModule::PluginButtonClicked2),
		FCanExecuteAction());

	PluginCommands3->MapAction(
	FTestPluginCommands::Get().PluginAction3,
	FExecuteAction::CreateRaw(this, &FTestPluginModule::PluginButtonClicked3),
	FCanExecuteAction());

	//----------------------------------------------------------------------------------------------------------
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	//
	// {
	// 	TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
	// 	MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FTestPluginModule::AddMenuExtension));
	//
	// 	LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	// }
	//
	// {
	// 	TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
	// 	ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands2, FToolBarExtensionDelegate::CreateRaw(this, &FTestPluginModule::AddToolbarExtension));
	// 	
	// 	LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	// }
	{
		TSharedPtr<FExtender> ToolbarMenuExtender = MakeShareable(new FExtender);
		ToolbarMenuExtender->AddMenuBarExtension(
		"Help", 
		EExtensionHook::After,
		nullptr,
		FMenuBarExtensionDelegate::CreateRaw(this, &FTestPluginModule::AddMenu)
	  );
			LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(ToolbarMenuExtender);
		}
//------------------------------------------------------------------

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FTestPluginModule::RegisterMenus));

	
}
void FTestPluginModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FTestPluginCommands::Get().PluginAction);
}

void FTestPluginModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FTestPluginCommands::Get().PluginAction);
}

void FTestPluginModule::AddMenu(FMenuBarBuilder& Builder)
{
	Builder.AddPullDownMenu(
		LOCTEXT("MenuLocKey", "MyMenu"),
		LOCTEXT("MenuTooltipKey", "Opens menu for My Plugin"),
		FMenuExtensionDelegate::CreateRaw(this, &FTestPluginModule::FillMenu),
		FName(TEXT("MyMenu")),
		FName(TEXT("MyMenuName")));
}
void FTestPluginModule::FillMenu(FMenuBuilder& Builder) {
	// Fill it same as in the accepted answer
	Builder.AddMenuEntry(FTestPluginCommands::Get().PluginAction3);
	

}

void FTestPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FTestPluginStyle::Shutdown();

	FTestPluginCommands::Unregister();
}

void FTestPluginModule::PluginButtonClicked()
{

	// load blueprint ..
	FString widgetUrl = FString::Printf(TEXT("/TestPlugin/TestWidget"));
	FString fileName = "ToolWidget";
	UClass* uclass = UEditorAssetLibrary::LoadBlueprintClass(widgetUrl);
	UObject* uobj = UEditorAssetLibrary::LoadAsset(*widgetUrl);
	UWidgetBlueprint* Blueprint = Cast<UWidgetBlueprint>(uobj);
	if (Blueprint->GeneratedClass->IsChildOf(UEditorUtilityWidget::StaticClass()))
	{
		UEditorUtilityWidgetBlueprint* EditorWidget = Cast<UEditorUtilityWidgetBlueprint>(Blueprint);
		if (EditorWidget)
		{
			UEditorUtilitySubsystem* EditorUtilitySubsystem = GEditor->GetEditorSubsystem<UEditorUtilitySubsystem>();
			EditorUtilitySubsystem->SpawnAndRegisterTab(EditorWidget);
		}
	}
	
	UE_LOG(LogTemp, Warning, TEXT("Hi"));
	// Put your "OnButtonClicked" stuff here
	// FText DialogText = FText::Format(
	// 						LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
	// 						FText::FromString(TEXT("FTestPluginModule::PluginButtonClicked()")),
	// 						FText::FromString(TEXT("TestPlugin.cpp"))
	// 				   );
	// FMessageDialog::Open(EAppMsgType::Ok, DialogText);


	
}
void FTestPluginModule::PluginButtonClicked2()
{

	UE_LOG(LogTemp, Warning, TEXT("Love you"));

}

void FTestPluginModule::PluginButtonClicked3()
{
	UE_LOG(LogTemp, Warning, TEXT("Action 3"));
}


void FTestPluginModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);
	//
	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FTestPluginCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		
		//UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		//UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("ContentBrowser.AddNewContextMenu");
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			//FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("ContentBrowserNewAdvancedAsset");
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			//FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("LevelEditor");
			{
				//FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitMenuEntry(FTestPluginCommands::Get().PluginAction));
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FTestPluginCommands::Get().PluginAction2));
				Entry.SetCommandList(PluginCommands2);
			}
		}
		
		// //----------------------------------------------------------------------------------------------------------
		// FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
		// //
		// // {
		// // 	TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		// // 	MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FTestPluginModule::AddMenuExtension));
		// //
		// // 	LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
		// // }
		// //
		// // {
		// // 	TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		// // 	ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands2, FToolBarExtensionDelegate::CreateRaw(this, &FTestPluginModule::AddToolbarExtension));
		// // 	
		// // 	LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
		// // }
		// {
		// 	TSharedPtr<FExtender> ToolbarMenuExtender = MakeShareable(new FExtender);
		// 	ToolbarMenuExtender->AddMenuBarExtension(
		// 	"Help", 
		// 	EExtensionHook::After,
		// 	nullptr,
		// 	FMenuBarExtensionDelegate::CreateRaw(this, &FTestPluginModule::AddMenu)
		//   );
		// 	LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(ToolbarMenuExtender);
		// }
		// //------------------------------------------------------------------
		//
		// // {
		// // 	UToolMenu* NewMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.MyMenu");
		// // 	{
		// // 		FToolMenuSection& Section = NewMenu->FindOrAddSection("TestSection");
		// // 		Section.AddMenuEntryWithCommandList(FTestPluginCommands::Get().PluginAction3, PluginCommands3);
		// // 	}
		// // }
		// UToolMenu* NewToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.MyMenu");
		// {
		// 	//FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("ContentBrowserNewAdvancedAsset");
		// 	FToolMenuSection& Section = NewToolbarMenu->FindOrAddSection("Settings");
		// 	//FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("LevelEditor");
		// 	{
		// 		//FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitMenuEntry(FTestPluginCommands::Get().PluginAction));
		// 		FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitMenuEntry(FTestPluginCommands::Get().PluginAction3));
		// 		Entry.SetCommandList(PluginCommands3);
		// 	}
		// }

	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTestPluginModule, TestPlugin)