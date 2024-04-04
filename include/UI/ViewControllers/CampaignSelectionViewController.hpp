#pragma once

#include "custom-types/shared/macros.hpp"
#include "lapiz/shared/macros.hpp"

#include "Zenject/IInitializable.hpp"
#include "System/IDisposable.hpp"

#include "HMUI/ViewController.hpp"

DECLARE_CLASS_CODEGEN_INTERFACES(CustomCampaigns::UI::ViewControllers, CampaignSelectionViewController, HMUI::ViewController, std::vector<Il2CppClass*>({classof(Zenject::IInitializable*), classof(System::IDisposable*)}), 
    DECLARE_CTOR(ctor);

    DECLARE_OVERRIDE_METHOD_MATCH(void, DidActivate, &HMUI::ViewController::DidActivate, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);

    DECLARE_OVERRIDE_METHOD_MATCH(void, Initialize, &Zenject::IInitializable::Initialize);
    DECLARE_OVERRIDE_METHOD_MATCH(void, Dispose, &System::IDisposable::Dispose);
)