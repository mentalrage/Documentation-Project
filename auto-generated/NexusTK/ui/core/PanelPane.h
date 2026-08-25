// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000ME
// Source by-file doc: by-file/PanelPane.md
// UID:0000A4 | by-class/PanelPane.md | Completion:93 | Confidence:95
#include "Pane.h"

class PanelPane : public Pane
{
public:
    PanelPane();
    virtual ~PanelPane();
    virtual void OnActivate(const unsigned char *packetData) = 0;
};
