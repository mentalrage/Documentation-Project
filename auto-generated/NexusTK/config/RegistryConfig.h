// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000N4
// Source by-file doc: by-file/RegistryConfig.md
// UID:0000BW | by-class/RegistryConfig.md | Completion:92 | Confidence:94
#ifndef NEXUSTK_CONFIG_REGISTRYCONFIG_H
#define NEXUSTK_CONFIG_REGISTRYCONFIG_H

#include "Config.h"

class RegistryConfig : public Config
{
public:
    virtual ~RegistryConfig();

    void LoadOrInitialize();
    void InitializeUserDataDefaults();
    void InitializeDefaults();

    virtual void SaveToRegistry();
    virtual bool LoadFromRegistry();
};

#endif
