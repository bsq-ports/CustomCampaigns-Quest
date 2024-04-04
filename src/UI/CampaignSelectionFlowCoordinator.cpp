#include "UI/CampaignSelectionFlowCoordinator.hpp"
#include "BSML/shared/BSML.hpp"
#include "UI/ViewControllers/CampaignSelectionViewController.hpp"

DEFINE_TYPE(CustomCampaigns::UI, CampaignSelectionFlowCoordinator);

namespace CustomCampaigns::UI {
    void CampaignSelectionFlowCoordinator::ctor() {
        INVOKE_CTOR();
        HMUI::FlowCoordinator::_ctor();
    }

    void CampaignSelectionFlowCoordinator::Inject(GlobalNamespace::MainFlowCoordinator* baseFlow, ViewControllers::CampaignSelectionViewController* campaignSelection) {
        _baseFlow = baseFlow;
        _campaignSelection = campaignSelection;
    }

    void CampaignSelectionFlowCoordinator::Initialize() {
        _menuButton = BSML::Register::RegisterMenuButton("Custom Campaigns", "Now on Quest!", std::bind(&CampaignSelectionFlowCoordinator::Present, this));
    }

    void CampaignSelectionFlowCoordinator::Dispose() {
        BSML::Register::RegisterMenuButton(_menuButton);
        _baseFlow->_providedMainViewController = nullptr;
    }

    void CampaignSelectionFlowCoordinator::Present() {
        auto fc = _baseFlow->YoungestChildFlowCoordinatorOrSelf();
        fc->PresentFlowCoordinator(this, nullptr, HMUI::ViewController::AnimationDirection::Horizontal, false, false);
    }

    void CampaignSelectionFlowCoordinator::BackButtonWasPressed(HMUI::ViewController* topViewController) {
        _parentFlowCoordinator->DismissFlowCoordinator(this, HMUI::ViewController::AnimationDirection::Vertical, nullptr, false);
    }

    void CampaignSelectionFlowCoordinator::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
        if (firstActivation) {
            SetTitle("Custom Campaigns", HMUI::ViewController::AnimationType::In);
            ProvideInitialViewControllers(_campaignSelection, nullptr, nullptr, nullptr, nullptr);
            showBackButton = true;
        }
    }
}