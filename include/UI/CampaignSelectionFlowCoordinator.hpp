#pragma once

#include "custom-types/shared/macros.hpp"
#include "bsml/shared/BSML/MenuButtons/MenuButton.hpp"

#include "lapiz/shared/macros.hpp"

#include "Zenject/IInitializable.hpp"
#include "system/IDisposable.hpp"

#include "HMUI/FlowCoordinator.hpp"
#include "GlobalNamespace/MainFlowCoordinator.hpp"
#include "UI/CampaignSelectionFlowCoordinator.hpp"

DECLARE_CLASS_CODEGEN_INTERFACES(CustomCampaigns::UI, CampaignSelectionFlowCoordinator, HMUI::FlowCoordinator, std::vector<Il2CppClass*>({classof(Zenject::IInitializable*), classof(System::IDisposable*)}), 
    DECLARE_CTOR(ctor);

    DECLARE_INSTANCE_FIELD_PRIVATE(BSML::MenuButton*, _menuButton);
    DECLARE_INSTANCE_FIELD_PRIVATE(GlobalNamespace::MainFlowCoordinator*, _baseFlow);

    DECLARE_INJECT_METHOD(void, Inject, GlobalNamespace::MainFlowCoordinator* baseFlow);

    DECLARE_OVERRIDE_METHOD_MATCH(void, Initialize, &Zenject::IInitializable::Initialize);
    DECLARE_OVERRIDE_METHOD_MATCH(void, Dispose, &System::IDisposable::Dispose);

    void Present();

    DECLARE_OVERRIDE_METHOD_MATCH(void, BackButtonWasPressed, &HMUI::FlowCoordinator::BackButtonWasPressed, HMUI::ViewController* topViewController);
    DECLARE_OVERRIDE_METHOD_MATCH(void, DidActivate, &HMUI::FlowCoordinator::DidActivate, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
)
