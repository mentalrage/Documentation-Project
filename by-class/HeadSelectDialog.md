*** UID:000062 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../core/DialogPane.h"
#include "../../map/ObjectStatusBlob.h"

class ImageButtonControlPane;
class ObjectImageButtonPane;
class ObjectImageControlPane;

class HeadSelectDialog : public DialogPane
{
public:
    HeadSelectDialog(const unsigned char *packet);
    virtual ~HeadSelectDialog();

    virtual void OnAction(int actionId, int unused);

private:
    void RefreshHeadPreview();
    void UpdatePageButtonStates();
    void NextHeadPage();
    void PreviousHeadPage();
    void PopulateHeadButtons(int page, bool removeExistingButtons);

    unsigned char m_dialogSubtype;
    unsigned int m_headPrice;
    unsigned short m_npcId;
    unsigned short m_objectId;
    ObjectStatusBlob m_previewObject;
    int m_headCount;
    int m_selectedHead;
    int m_currentPage;
    int m_baseHeadDrawOffset;
    ObjectImageControlPane *m_previewPane;
    ObjectImageButtonPane *m_headButtons[10];
    ImageButtonControlPane *m_confirmButton;
    ImageButtonControlPane *m_nextPageButton;
    ImageButtonControlPane *m_prevPageButton;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# HeadSelectDialog

## Status

- Confidence: very strong for class responsibility, direct `DialogPane` inheritance, complete `0x304` layout, vtable/read-only data, core boundaries, constructor-wrapper path, resource/layout ownership, source-ready method behavior, and ordinary-destructor/compiler-support split; exact original names for retained packet fields and private page helpers remain behavior-based inferences.
- Likely source file: [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md)
- Main address range: [UID:0001FI][0x00551030-0x005520e5.HeadSelectDialogCore](by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md)
- Destructor-thunk detail: [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md)
- Current recovered file: `source-3/simroot_v2/class_HeadSelectDialog.cpp`
- Exact vtable data: [UID:0003DA][0x006228b8-0x00622954.HeadSelectDialogVtableData](by-memory/0x006228b8-0x00622954.HeadSelectDialogVtableData.md)
- Class-specific resource string: [UID:0003DG][0x00622d08-0x00622d20.HeadSelectDialogDlgmsghString](by-memory/0x00622d08-0x00622d20.HeadSelectDialogDlgmsghString.md)

## Class Purpose

`HeadSelectDialog` is a packet-driven in-game dialog for selecting a character head/appearance variant. It parses object, NPC, price, and message fields from the packet; builds a dialog from EPF image, image-button, object-image, and static-text controls; shows the current character preview; and manages a ten-button paged head-selection grid.

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| `0x00551030-0x005511fd` | `RefreshHeadPreview` | Rebuilds the object-image preview after the selected head changes. |
| `0x00551200-0x0055124d` | `UpdatePageButtonStates` | Enables or disables page navigation controls. |
| `0x00551250-0x005512c7` | `NextHeadPage` | Private retained helper for next-page navigation; no exported caller/vtable ref found, while `OnAction` duplicates equivalent logic inline. |
| `0x005512d0-0x00551340` | `PreviousHeadPage` | Private retained helper for previous-page navigation; no exported caller/vtable ref found, while `OnAction` duplicates equivalent logic inline. |
| `0x00551350-0x00551510` | `PopulateHeadButtons` | Creates current-page [UID:00009N][ObjectImageButtonPane](by-class/ObjectImageButtonPane.md) controls and applies selected highlighting. |
| `0x00551520-0x00551f26` | constructor | Parses packet data and constructs the initial dialog/control tree. |
| `0x00551f30-0x00551f92` | destructor | Ordinary source destructor: calls inherited `OnDestroy()` and `OnHide()`; compiler lowering restores vtables and performs `DialogPane` base destruction. |
| `0x00551fa0-0x005520e5` | `OnAction` | Handles close, page movement, and head-slot selection actions. |
| `0x005538fe-0x00553914` | [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md) | Secondary/tertiary vtable thunk support. |
| `0x00553920-0x005539c3` | [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md) | Deleting-destructor wrapper. |

## Key Relationships

- Uses [UID:00009O][ObjectImageControlPane](by-class/ObjectImageControlPane.md) for the current character/head preview.
- Uses [UID:00009N][ObjectImageButtonPane](by-class/ObjectImageButtonPane.md) for the paged head-choice buttons.
- Uses [UID:00004G][EPFImageControlPane](by-class/EPFImageControlPane.md), [UID:00006D][ImageButtonControlPane](by-class/ImageButtonControlPane.md), and [UID:0000E3][StaticTextControlPane](by-class/StaticTextControlPane.md) for the dialog background, actions, and packet-provided message text.
- Uses [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) head-count and head-offset data to clamp and preview selectable heads.
- Owns exact source-declared/generated-binary vtable data [UID:0003DA][0x006228b8-0x00622954.HeadSelectDialogVtableData](by-memory/0x006228b8-0x00622954.HeadSelectDialogVtableData.md) and class-specific resource literal [UID:0003DG][0x00622d08-0x00622d20.HeadSelectDialogDlgmsghString](by-memory/0x00622d08-0x00622d20.HeadSelectDialogDlgmsghString.md).
- Consumes static layout/offset tables [UID:00027Z][0x0066df00-0x0066ed20.HeadSelectDialogLayoutTablePrimary](by-memory/0x0066df00-0x0066ed20.HeadSelectDialogLayoutTablePrimary.md) and [UID:000281][0x0066eea0-0x0066fce4.HeadSelectDialogLayoutTableSecondary](by-memory/0x0066eea0-0x0066fce4.HeadSelectDialogLayoutTableSecondary.md). The primary normal-resolution table and secondary high-resolution table now route directly to this class after each table child cleared the strict `85/85` gate.

## Inheritance And Complete Layout

`HeadSelectDialog` directly derives only from `DialogPane`. The executable's `+0xa0` EventHandler and `+0xa4` TimerHandler receiver views are inherited through `Pane`/`DialogPane`; they are not additional direct bases, explicit vptr members, or fields that belong in the human class declaration. The allocation wrapper and deleting-wrapper immediate independently prove `sizeof(HeadSelectDialog) == 0x304`.

| Offset | Size | Human source member/region | Evidence and disposition |
| --- | --- | --- | --- |
| `+0x000` | `0x26c` | `DialogPane` base | Existing exact base layout. |
| `+0x26c` | `1` | `unsigned char m_dialogSubtype` | Packet byte `0`. |
| `+0x26d` | `3` | natural alignment | Implicit alignment before the 32-bit member; intentionally no authored padding field. |
| `+0x270` | `4` | `unsigned int m_headPrice` | Packet dword `1..4`; best source-facing inference, with price/request-id uncertainty retained in prose. |
| `+0x274` | `2` | `unsigned short m_npcId` | First big-endian word after the object-status payload. |
| `+0x276` | `2` | `unsigned short m_objectId` | Second big-endian word after the object-status payload. |
| `+0x278` | `0x44` | `ObjectStatusBlob m_previewObject` | Exact existing by-value status layout. |
| `+0x2bc` | `4` | `int m_headCount` | Head-count/page bound. |
| `+0x2c0` | `4` | `int m_selectedHead` | Selected head index. |
| `+0x2c4` | `4` | `int m_currentPage` | Ten-head page index. |
| `+0x2c8` | `4` | `int m_baseHeadDrawOffset` | Base draw offset derived from the selected table. |
| `+0x2cc` | `4` | `ObjectImageControlPane *m_previewPane` | Current preview control. |
| `+0x2d0` | `0x28` | `ObjectImageButtonPane *m_headButtons[10]` | Ten selectable head controls. |
| `+0x2f8` | `4` | `ImageButtonControlPane *m_confirmButton` | Confirm/OK action control. |
| `+0x2fc` | `4` | `ImageButtonControlPane *m_nextPageButton` | Next-page control. |
| `+0x300` | `4` | `ImageButtonControlPane *m_prevPageButton` | Previous-page control; final member, yielding size `0x304`. |

The formal H block intentionally relies on natural C++ alignment between `m_dialogSubtype` and `m_headPrice`. A named three-byte padding member would reproduce a decompiler layout artifact rather than plausible developer source.

## Destructor Source And Generated ABI Split

- The human declaration is `virtual ~HeadSelectDialog();` and the ordinary body belongs to [UID:0001FI][0x00551030-0x005520e5.HeadSelectDialogCore](by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md).
- The ordinary body contains only the supported inherited calls `OnDestroy();` followed by `OnHide();`. C++ base destruction supplies `DialogPane::~DialogPane()` automatically.
- [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md) contains the generated primary deleting wrapper, `+0xa0`/`+0xa4` inherited-facet adjustors, three vtable restores, deleting flags, storage release, and internal linker alignment. None is a second handwritten destructor or direct class method.
- Primary/secondary/tertiary vtable routes and constructor/ordinary-destructor/deleting-wrapper store triads prove that the declaration and inherited Pane facet layout are sufficient compiler inputs.
- The bit-2 wrapper path carries size `0x304` to a one-byte no-op. It is not vector delete, sized delete, guarded delete, or a public source flag.

## Source-Quality Rejections And Residual Inference

- Reject direct `EventHandler`/`TimerHandler` bases, explicit vptr members, scalar-deleting methods/flags, Boost exception types, and synthetic cleanup names such as `OnDialogDestroying`/`RemoveDialogControls`.
- Retain `m_headPrice` as the strongest current source-facing name; the neutral `m_priceOrRequestId` alternative remains historical evidence because the field is not consumed later in this range.
- Exact PDB spellings and historical compiler switches remain unavailable. They cap confidence but do not block this human class declaration or executable behavior.

## Ownership Notes

The small helper at `0x0049dd00` is currently generated as `HeadSelectDialog::SwitchCategory`, but caller evidence crosses other dialog classes. Treat it as a shared dialog/control-list category switch rather than firm `HeadSelectDialog` ownership.

Adjacent IDA functions at `0x00552110`, `0x00553610`, and nearby starts install other dialog vtables and should not be included in this class by locality.

2026-06-12 live IDA MCP recheck: IDA still shows `0x0049dd00` called from `0x0041cdc0`, twice from `0x0046e2a0`, and from `HeadSelectDialog::PopulateHeadButtons` at `0x00551350`. Current simroot still emits the helper under `HeadSelectDialog`, so preserve the shared-helper caveat without letting it block vtable/resource ownership.

The same pass reconfirmed that the `0x0054ca50` dispatcher wrapper allocates `0x304` bytes and calls the constructor at `0x0054ca93`; constructor disassembly writes the three HeadSelect vtable bases at `0x00551571`, `0x00551577`, and `0x00551581`; and `DLGMSGH.EPF` at `0x00622d08` has exactly three constructor xrefs at `0x005517e9`, `0x00551aba`, and `0x00551cfc`.

B010 2026-07-01 support sync: [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) owns wrapper `0x0054ca50 -> new HeadSelectDialog(payload)` with allocation size `0x304`. This class keeps constructor/core/action ownership and does not move implementation details to the MessageDialogs dispatcher page.

2026-06-12 A003 Batch 337 assigns [UID:00027Z][0x0066df00-0x0066ed20.HeadSelectDialogLayoutTablePrimary](by-memory/0x0066df00-0x0066ed20.HeadSelectDialogLayoutTablePrimary.md) to this class after IDA MCP confirmed this is the normal-resolution head-offset table used only by `RefreshHeadPreview`, `PopulateHeadButtons`, and the constructor. 2026-06-12 A002 Batch 338 assigns the high-resolution companion [UID:000281][0x0066eea0-0x0066fce4.HeadSelectDialogLayoutTableSecondary](by-memory/0x0066eea0-0x0066fce4.HeadSelectDialogLayoutTableSecondary.md) after the same branch/xref/tail-slot review cleared the child gate.

2026-06-18 B001 source-quality execution adds the two omitted private helper starts `0x00551250` and `0x005512d0`, best named `NextHeadPage` and `PreviousHeadPage`. The local exports and vtable/OOAnalyzer sweeps did not find callers or address-taken references for those helpers, but their bodies are complete page-navigation methods inside the HeadSelect core and `OnAction` duplicates their equivalent page-change logic inline.

The same pass resolves the class field model for first-draft source: packet byte `0` is a retained dialog subtype at `+0x26c`; packet dword `1..4` is the high-probability `m_headPrice` at `+0x270`; the object-status parse at `packet+6` fills `ObjectStatusBlob m_previewObject` at `+0x278`; the two following packet words are best named `m_npcId` and `m_objectId` at `+0x274/+0x276`; page state uses `m_headCount`, `m_selectedHead`, `m_currentPage`, and `m_baseHeadDrawOffset` at `+0x2bc/+0x2c0/+0x2c4/+0x2c8`; and child controls are `m_previewPane`, ten `m_headButtons`, `m_confirmButton`, `m_nextPageButton`, and `m_prevPageButton`. The normal/high static offset arrays are best named `s_normalHeadVerticalOffsets[904]` and `s_highResHeadVerticalOffsets[913]`, selected by `g_useEpfAssets`.

## Cross-References

- [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md)
- [UID:0001FI][0x00551030-0x005520e5.HeadSelectDialogCore](by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md)
- [UID:0003DA][0x006228b8-0x00622954.HeadSelectDialogVtableData](by-memory/0x006228b8-0x00622954.HeadSelectDialogVtableData.md)
- [UID:0003DG][0x00622d08-0x00622d20.HeadSelectDialogDlgmsghString](by-memory/0x00622d08-0x00622d20.HeadSelectDialogDlgmsghString.md)
- [UID:00027Z][0x0066df00-0x0066ed20.HeadSelectDialogLayoutTablePrimary](by-memory/0x0066df00-0x0066ed20.HeadSelectDialogLayoutTablePrimary.md)
- [UID:00012T][0x0049dd00-0x0049dd17.DialogCategorySwitch](by-memory/0x0049dd00-0x0049dd17.DialogCategorySwitch.md)
- [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md)
- [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)

## Changes

- 2026-07-26 Agent-B003 UID0001FL implementation callback:
  - Raised `87/88` to `92/93`, populated class-child CPP routing and the complete naturally aligned H declaration, and retained owner/emitter UID0000JT.
  - Added direct-only `DialogPane` inheritance, exact `0x304` field layout, inherited Pane facet interpretation, ordinary destructor source shape, compiler-generated UID0001FL split, and rejected decompiler-shaped alternatives.

- 2026-07-01 Agent-B010 implementation callback: added support note for [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) wrapper `0x0054ca50 -> new HeadSelectDialog(payload)` and allocation size `0x304`, preserving class/core ownership.
- Before: `HeadSelectDialogCore` and `OnAction` ended at `0x005520e4`.
- Changed to: both end at `0x005520e5`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows the old endpoint omitted the final `retn 8` operand byte.
- Completion/confidence score update: existed before as `0/0`; changed to `84/82`. Summary: packet-driven dialog responsibility, method families, control relationships, shared-helper caveat, adjacent non-owned functions, and corrected boundary evidence are documented in detail; confidence remains limited by shared helper ownership. Evidence: `HeadSelectDialogCore`, `HeadSelectDialogDestructorThunks`, `DialogCategorySwitch`, object-image control relationships, and NewHumanImageLib source-file references.
- 2026-06-05: Marked reconstructable and attached to [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md).
  - Before: `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, leaving this packet-driven dialog unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000JT`; left the C++ block blank because the page is below the final reconstruction bar.
  - Summary/evidence: live IDA MCP reconfirms starts at `0x00551030`, `0x00551200`, `0x00551350`, `0x00551520`, `0x00551f30`, `0x00551fa0`, and deleting destructor wrapper `0x00553920`; it also reconfirms shared helper `0x0049dd00` has callers outside this class. The class score `84/82` and parent score `86/80` meet the 80/80 attachment gate.
- 2026-06-12 Agent-A002 Batch 282: Raised `84/82` to `86/87`.
  - Before: the class was below the strict `85/85` gate, so exact children [UID:0003DA][0x006228b8-0x00622954.HeadSelectDialogVtableData](by-memory/0x006228b8-0x00622954.HeadSelectDialogVtableData.md) and [UID:0003DG][0x00622d08-0x00622d20.HeadSelectDialogDlgmsghString](by-memory/0x00622d08-0x00622d20.HeadSelectDialogDlgmsghString.md) stayed parentless.
  - After: the class clears the strict gate and can directly own the exact vtable and class-specific resource string. The file parent remains [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md), which is now `87/86`.
  - Evidence: live IDA MCP session `a001-b276` reconfirmed the main method starts, the `0x0054ca50` allocation wrapper, constructor vtable stores to `0x006228bc`/`0x0062291c`/`0x0062294c`, destructor/deleting-wrapper vtable resets, `DLGMSGH.EPF` constructor-only xrefs, layout-table xrefs to the HeadSelect core, and shared `0x0049dd00` callers outside the class.
- 2026-06-12 A003 Batch 337: Added direct ownership for [UID:00027Z][0x0066df00-0x0066ed20.HeadSelectDialogLayoutTablePrimary](by-memory/0x0066df00-0x0066ed20.HeadSelectDialogLayoutTablePrimary.md). Scores remain `86/87`; this was a scoped table-child routing update after the child itself reached `86/91`.
- 2026-06-12 Agent-A002 Batch 338: Added direct ownership for [UID:000281][0x0066eea0-0x0066fce4.HeadSelectDialogLayoutTableSecondary](by-memory/0x0066eea0-0x0066fce4.HeadSelectDialogLayoutTableSecondary.md). Scores remain `86/87`; this was a scoped table-child routing update after the child itself reached `86/91` and live IDA MCP confirmed it is the high-resolution branch companion to the primary table.
- 2026-06-18 Agent-B001 source-quality report executed by supervisor:
  - Before: `86/87`; method families omitted private starts `0x00551250` and `0x005512d0`, and class-level notes did not carry the packet/member/control/layout inferences needed by the formal C++ draft.
  - After: `87/88`; class notes include the two private page helpers, packet-derived subtype/price/NPC/object/message roles, object-status preview payload ownership, child-control field map, `g_useEpfAssets` table selection, static table source names, and the continued shared-helper caveat for `DialogCategorySwitch`.
