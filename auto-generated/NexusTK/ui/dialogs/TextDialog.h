// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OL
// Source by-file doc: by-file/TextDialog.md
// UID:0000EL | by-class/TextDialog.md | Completion:90 | Confidence:93
#include "PursuitMessageDialogPane.h"

class TextDialog : public PursuitMessageDialogPane
{
public:
    TextDialog(const unsigned char *payload,
               bool showObjectImage,
               bool useLargeLayout);
    virtual void OnControlCommand(int controlIndex, int notifyCode);
};
