#pragma once

#define CUSTOMCAMPAIGNS_EXPORT __attribute__((visibility("default")))
#ifdef __cplusplus
#define CUSTOMCAMPAIGNS_EXPORT_FUNC extern "C" CUSTOMCAMPAIGNS_EXPORT
#else
#define CUSTOMCAMPAIGNS_EXPORT_FUNC CUSTOMCAMPAIGNS_EXPORT
#endif 