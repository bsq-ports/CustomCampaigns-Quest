#include "UI/ViewControllers/CampaignSelectionViewController.hpp"

#include "UnityEngine/CanvasGroup.hpp"
#include "BSML/shared/BSML.hpp"

#include "logging.hpp"
#include "assets.hpp"

DEFINE_TYPE(CustomCampaigns::UI::ViewControllers, CampaignSelectionViewController);

namespace CustomCampaigns::UI::ViewControllers {
    void CampaignSelectionViewController::ctor() {
        INVOKE_CTOR();
    }

    void CampaignSelectionViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
        if (firstActivation) {
            gameObject->AddComponent<UnityEngine::CanvasGroup*>();
            BSML::parse_and_construct(Assets::Resources::CampaignSelectionView_bsml, transform, this);
        }
    }

    void CampaignSelectionViewController::Initialize() {
        INFO("Initialized!");
    }

    void CampaignSelectionViewController::Dispose() {
        INFO("Disposed!");
    }
}