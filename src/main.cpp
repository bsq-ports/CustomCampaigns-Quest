#include "../shared/_config.h"
#include "UI/MenuButton.hpp"
#include "main.hpp"
#include "logging.hpp"

#include "custom-types/shared/register.hpp"

#include "lapiz/shared/zenject/Zenjector.hpp"
#include "lapiz/shared/zenject/Location.hpp"
#include "zenject/ScopeConcreteIdArgConditionCopyNonLazyBinder.hpp"

#include "bsml/shared/BSML.hpp"

static modloader::ModInfo modInfo = {MOD_ID, VERSION, 0}; // Stores the ID and version of our mod, and is sent to the modloader upon startup

// Called at the early stages of game loading
CUSTOMCAMPAIGNS_EXPORT_FUNC void setup(CModInfo* info) {
    info->id = MOD_ID;
    info->version = VERSION;
;
    INFO("Completed setup!");
}

// Called later on in the game loading - a good time to install function hooks
CUSTOMCAMPAIGNS_EXPORT_FUNC void late_load() {
    il2cpp_functions::Init();

    custom_types::Register::AutoRegister();
    BSML::Init();

    auto z = Lapiz::Zenject::Zenjector::Get();

    z->Install(Lapiz::Zenject::Location::App, [](::Zenject::DiContainer* container){
        
    });

    z->Install(Lapiz::Zenject::Location::Menu, [](::Zenject::DiContainer* container) {
        container->BindInterfacesAndSelfTo<CustomCampaigns::UI::MenuButton*>()->AsSingle()->NonLazy();
    });

    z->Install(Lapiz::Zenject::Location::GameCore, [](::Zenject::DiContainer* container) {

    });
}
s