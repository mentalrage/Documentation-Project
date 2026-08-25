// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HE
// Source by-file doc: by-file/AlertPanes.md
// UID:00000B | by-class/AlertPane.md | Completion:88 | Confidence:92
#include "AlertPanes.h"

// UID:00010W | by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md | Completion:86 | Confidence:92
// Compiler-generated shared scalar deleting destructor for the AlertPane inheritance family.
// Source behavior is represented by virtual destructors on AlertPane and derived classes;
// this wrapper, adjustor thunks, delete-flag branches, and guard path are compiler output.

// UID:00012W | by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md | Completion:88 | Confidence:91
// AlertPane constructor/dismiss method bodies are intentionally not emitted from this cluster.
// The class declaration supplies AlertPane, DismissDialog(int,int), OnPrimaryButton,
// OnSecondaryButton, and m_layoutReference; full bodies wait for source-quality DialogPane helpers.

// UID:0002M5 | by-memory/0x00618b00-0x00618ba0.AlertPaneVtableData.md | Completion:86 | Confidence:92
// Compiler-generated vtable and RTTI-adjacent data for AlertPane.
// Recreated from the AlertPane declaration, virtual destructor, DismissDialog,
// and primary/secondary button callback slots.

// UID:0001WZ | by-type/by-vtable/AlertPaneVtables.md | Completion:88 | Confidence:92
// AlertPane vtable cluster generated from the AlertPane class declaration and inherited DialogPane views.
// Raw vtable dwords and adjustor thunks are not hand-authored source.

// UID:00000Y | by-class/BlueAlertPane.md | Completion:85 | Confidence:87
// BlueAlertPane is assigned to this AlertPanes source family, but current evidence does not yet
// support a source-quality class declaration shell. IDA confirms the constructor/draw/action methods,
// three vtable views, shared AlertPane-family destructor thunks, BDFRAME.EPF drawing, and
// m_layoutReference at +0x26c; it still finds no direct constructor caller/allocation route and
// no final base/member/helper spelling.

// UID:0000FF | by-class/UrlAlertPane.md | Completion:89 | Confidence:91
class UrlAlertPane : public AlertPane
{
public:
    UrlAlertPane(bool exitAfterOpen,
                 Pane *layoutReference,
                 const wchar_t *messageText,
                 const char *urlText,
                 unsigned int urlLength);
    virtual ~UrlAlertPane();

protected:
    virtual void OnPrimaryButton();

private:
    char *m_url;
    bool m_exitAfterOpen;

    // UID:0001KF | by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md | Completion:88 | Confidence:91
UrlAlertPane::UrlAlertPane(bool exitAfterOpen,
                           Pane *layoutReference,
                           const wchar_t *messageText,
                           const char *urlText,
                           unsigned int urlLength)
    : AlertPane(messageText, layoutReference, L"OK", NULL),
      m_url(NULL),
      m_exitAfterOpen(exitAfterOpen)
{
    g_pUrlAlertPane = this;

    m_url = static_cast<char *>(GetMemoryMan()->AllocateBufferMemory(urlLength + 1));
    memcpy(m_url, urlText, urlLength);
    m_url[urlLength] = '\0';
}

UrlAlertPane::~UrlAlertPane()
{
    GetMemoryMan()->FreeBufferMemory(m_url);
    g_pUrlAlertPane = NULL;
}

void UrlAlertPane::OnPrimaryButton()
{
    ShellExecuteA(NULL, NULL, m_url, NULL, NULL, SW_SHOWNORMAL);

    if (m_exitAfterOpen)
        g_pApplication->RequestExit();
}

// UID:0002P0 | by-memory/0x0062e580-0x0062e624.UrlAlertPaneVtableData.md | Completion:86 | Confidence:92
// Compiler-generated vtable and RTTI-adjacent data for UrlAlertPane.
// Recreated from the UrlAlertPane declaration, virtual destructor, and OnPrimaryButton method body.

// UID:0001YZ | by-type/by-vtable/UrlAlertPaneVtables.md | Completion:86 | Confidence:90
// UrlAlertPane vtable cluster generated from the UrlAlertPane class declaration and method bodies.
// Constructor/destructor/thunk behavior belongs to the class and executable method pages, not raw dwords.
};

// UID:0000FU | by-class/VersatileAlertPane.md | Completion:93 | Confidence:96
// UID:0004NB | by-memory/0x004a0690-0x004a06d7.VersatileAlertPaneConstructor.md | Completion:94 | Confidence:96
VersatileAlertPane::VersatileAlertPane(
    const wchar_t *messageText,
    Pane *layoutReference,
    FunctionObjectT<unsigned long> *resultCallback,
    const wchar_t *primaryButtonText,
    const wchar_t *secondaryButtonText)
    : AlertPane(messageText,
                layoutReference,
                primaryButtonText,
                secondaryButtonText),
      m_resultCallback(resultCallback)
{
}

// UID:00012Y | by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneDestructor.md | Completion:94 | Confidence:96
VersatileAlertPane::~VersatileAlertPane()
{
    delete m_resultCallback;
}

// UID:0004NC | by-memory/0x004a0720-0x004a0732.VersatileAlertPaneOnPrimaryButton.md | Completion:95 | Confidence:97
void VersatileAlertPane::OnPrimaryButton()
{
    if (m_resultCallback != NULL)
        m_resultCallback->Invoke(1);
}

// UID:0004ND | by-memory/0x004a0740-0x004a0752.VersatileAlertPaneOnSecondaryButton.md | Completion:95 | Confidence:97
void VersatileAlertPane::OnSecondaryButton()
{
    if (m_resultCallback != NULL)
        m_resultCallback->Invoke(0);
}

// UID:0000SM | by-global/g_pUrlAlertPane.md | Completion:87 | Confidence:92
UrlAlertPane *g_pUrlAlertPane = NULL;

// UID:0001OC | by-memory/0x00613a18-0x00613a1e.DialogOkButtonString.md | Completion:87 | Confidence:92
// Shared pooled UTF-16 dialog button literal: L"OK".
// Source call sites should spell the literal or shared resource text directly;
// this .rdata address is not a feature-owned global, callback table, or hand-authored variable.
