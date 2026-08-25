*** UID:00000T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class BackStoryDialogPane;
extern BackStoryDialogPane *g_pBackStoryDialogPane;

class BackStoryDialogPane : public DialogPane,
                            public Singleton<BackStoryDialogPane>
{
public:
    BackStoryDialogPane();

protected:
    virtual void OnControlCommand(int controlIndex, int notifyCode);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BackStoryDialogPane

## Status

- Confidence: very strong for UI construction, resource selection, direct `DialogPane`/`Singleton<BackStoryDialogPane>` inheritance, exact `0x26c` size and EBO layout, singleton lifecycle, three-view vtable/RTTI family, login/main-menu ownership, negative active-route evidence, and retained/compatibility classification.
- Likely source file: [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md)
- Core address range: [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md)
- Autogen status: attached to [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md) at position `10`, with the complete class declaration and `[[CHILDREN]]`; exact constructor/handler bodies are owned by [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md) at position `20`.

## Class Purpose

`BackStoryDialogPane` is retained/compatibility main-menu BackStory text-dialog code. It displays a story art background and a scrolled text control populated from the unique `BACKTALE` resource, then closes when its only button action is activated. Current active story/history menu navigation constructs [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md), not this older text dialog.

## Class Shape

- Direct bases: `DialogPane` and `Singleton<BackStoryDialogPane>`.
- Exact complete-object size: `0x26c`; no recovered authored fields beyond base subobjects.
- Singleton EBO: direct nonvirtual empty base PMD `{0x26c,-1,0}`, attributes `0x40`, placed at complete-object end.
- Singleton definition: live instance tracked by [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md); the class formal carries its forward declaration/`extern` contract, while the semantic global page owns the sole definition.
- Vtable views: primary at `+0x00`, secondary at `+0xa0`, tertiary at `+0xa4`; exact backing is [UID:0004WA][0x0061da54-0x0061daf0.BackStoryDialogPaneVtableData](by-memory/0x0061da54-0x0061daf0.BackStoryDialogPaneVtableData.md), and semantic inventory is [UID:0004WB][BackStoryDialogPaneVtables](by-type/by-vtable/BackStoryDialogPaneVtables.md).
- Destruction: ordinary implicit virtual destruction is sufficient. No unique authored derived-destructor statement survives after direct Singleton/base/compiler effects are subtracted.
- Resource role: uses EPF/EPD story art plus `BACKTALE` text content, with asset-mode-dependent palette/resource selection.
- Source placement: [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md) under `NexusTK/login/`; direct active constructor reachability is resolved negative for current story/history menu routing and now treated as retained/compatibility code evidence rather than an unresolved blocker.
- Not the active frame story/history viewer: [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md) owns the currently direct `MainMenuPane` story/history construction path, while this class is retained as the older `BACKTALE` text dialog and still participates in singleton cleanup.
- Parent evidence: [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md) is the accepted `92/93` source union at `NexusTK/login/` and stages `auto-generated/NexusTK/login/BackStoryDialogPane.cpp`.

## Source Placement And Reachability

The class belongs to the login/main-menu dialog family. The file-level page has the projected source folder `NexusTK/login/`, and [by-project-structure/proposed-source-tree.md](../by-project-structure/proposed-source-tree.md) lists `BackStoryDialogPane` with the main-menu story resources and singleton cleanup path.

Direct code xrefs to the constructor were absent in refreshed IDA and B014 local PE scans, so this page must not claim a proven current menu-open call. That negative evidence now resolves the active-route question: active `MainMenuPane` story/history branches and retained story/history wrappers construct `HistoryViewingPane`, while `BackStoryDialogPane` remains source-authored retained/compatibility BackStory text-dialog code. The class is still real project code: its constructor writes the singleton, its destructor support clears it, its button handler is vtable-referenced, and `CloseMainMenuDialogSingletons` reads the singleton during main-menu dialog cleanup.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x00500090-0x005003e3` | Constructs `DialogPane`, stores singleton, installs vtables, selects EPF/EPD layout, adds image/button/text controls, creates/shows/slides the dialog. |
| `OnControlCommand(int controlIndex, int notifyCode)` | `0x005003f0-0x0050040d` | Established `DialogPane` primary-vtable `+0x48` override; ignores the second argument and closes only for logical control id `1`. |
| [UID:0003HH][0x00502390-0x0050239b.BackStoryDialogPaneSingletonBaseDestructor](by-memory/0x00502390-0x0050239b.BackStoryDialogPaneSingletonBaseDestructor.md) | `0x00502390-0x0050239b` | Compiler/template constructor-EH base teardown; clears the singleton and emits no handwritten method. |
| [UID:0004W8][0x0050245e-0x00502474.BackStoryDialogPaneDestructorAdjustorThunks](by-memory/0x0050245e-0x00502474.BackStoryDialogPaneDestructorAdjustorThunks.md) | `0x0050245e-0x00502474` | Compiler `this - 0xa0` / `this - 0xa4` vtable routes to the common scalar wrapper. |
| [UID:0004W9][0x00502600-0x00502645.BackStoryDialogPaneScalarDeletingDestructor](by-memory/0x00502600-0x00502645.BackStoryDialogPaneScalarDeletingDestructor.md) | `0x00502600-0x00502645` | Direct-Singleton clear, `DialogPane` teardown, delete flags, optional free; no authored derived-destructor remainder. |

## Data Notes

- [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md) tracks the live singleton dialog at `0x0069b498`.
- `g_useEpfAssets` selects `STORY.EPF`/`PAL01.PAL` versus `STORY.EPD`/`NPAL8.PAL`.
- [UID:0000RF][g_pMainMenuPane](by-global/g_pMainMenuPane.md) is the parent/show context for the final show/register helper.
- [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md) identifies historical `dword_69B36C` as `g_mainUiLayerSlots.overlayPaneLayerContext`, the dialog create/layout slot; it remains distinct from `g_pMainMenuPane`.

## Layout Branches

| Branch | Background | Palette | Background rect | Button rect | Text rect | Dialog position |
| --- | --- | --- | --- | --- | --- | --- |
| EPF asset mode | `STORY.EPF` | `PAL01.PAL` | `0,0,384,341` | visual image index `14`, `169,305,232,329` | `BACKTALE`, `25,56,361,278`, step `50` | `246,150,630,491` |
| legacy asset mode | `STORY.EPD` | `NPAL8.PAL` | `0,0,267,337` | visual image index `14`, `98,287,170,303` | `BACKTALE`, `36,71,228,265`, step `50` | `363,150,630,487` |

The logical close action id is `1`. The constructor's image-button value `14` is a visual image/resource index, not the callback/action id.

## Touched State

| State/resource | Role | Evidence source |
| --- | --- | --- |
| `0x0069b498` / [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md) | Constructor writes the live singleton; clear helper and destructor clear it; main-menu cleanup reads it. | [UID:00029F][0x0069b498-0x0069b49c.g_pBackStoryDialogPane](by-memory/0x0069b498-0x0069b49c.g_pBackStoryDialogPane.md) and [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md). |
| `this+0x00`, `this+0xa0`, `this+0xa4` | Constructor installs the `BackStoryDialogPane` vtable family. | Core page records constructor vtable writes and vtable data refs around `0x0061da58`/`0x0061daa0`. |
| [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` | Selects EPF versus legacy resource/layout branch. | Core page branch reconstruction and resource xrefs. |
| `g_mainUiLayerSlots.overlayPaneLayerContext` / historical `dword_69B36C`, [UID:0000RF][g_pMainMenuPane](by-global/g_pMainMenuPane.md) / historical IDA `dword_67ABA4` | Separate dialog create/layout context and concrete parent/show context. | Constructor tail in the core page and UID0000OX. |
| `STORY.EPF`, `STORY.EPD`, `PAL01.PAL`, `NPAL8.PAL`, `BACKTALE` | Story background, palette, and scrolled text resources. | [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md). |

## Boundary And Support Ranges

| Range | Kind | Notes |
| --- | --- | --- |
| `0x00500090-0x005003e3` | constructor | Main construction and layout branch logic. |
| `0x005003e3-0x005003f0` | alignment | Thirteen `0xcc` bytes between constructor and button handler; recorded in [by-memory/-ignored.md](../by-memory/-ignored.md). |
| `0x005003f0-0x0050040d` | button handler | Closes the dialog only for the expected button id path. |
| `0x0050040d-0x00500410` | alignment | Three `0xcc` bytes before `NewHistoryDialogPaneCore`; recorded in [by-memory/-ignored.md](../by-memory/-ignored.md). |
| `0x00502390-0x0050239b` | Singleton base destructor | UID0003HH compiler/template clear used by constructor unwind; no authored helper. |
| `0x0050245e-0x00502474` | adjustor thunks | Compiler this-adjustor thunks into deleting destructor support. |
| `0x00502600-0x00502645` | scalar deleting destructor | Clears singleton, tears down the `DialogPane` base, optionally deletes memory. |
| `0x0061da54-0x0061daf0` | vtable/RTTI backing | Exact 156-byte three-view compiler data child UID0004WA; 23/11/2 slots, eight-entry hierarchy, direct Singleton EBO. |

## Evidence Notes

- IDA decompilation of `0x00500090` matches the generated constructor layout and resource selection.
- IDA decompilation labels the destructor body through `boost::exception`, but the generated source and vtable context indicate this is type pollution over `DialogPane` teardown.
- IDA MCP `xrefs_to 0x0069b498` on 2026-05-25 confirms the singleton lifecycle: constructor writes it, the clear helper and destructor clear it, and `CloseMainMenuDialogSingletons` reads/closes it.
- Refreshed IDA evidence on 2026-06-01 in [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md) records exact function sizes, no direct constructor caller, vtable xrefs, singleton xrefs, branch-specific resource xrefs, callee sets, and raw `0xcc` boundary bytes.
- 2026-06-14 C001 IDA MCP recheck confirms constructor `0x00500090` size `0x353`, button handler `0x005003f0` size `0x1d`, singleton clear helper `0x00502390` size `0x0b`, adjustor thunks at `0x0050245e` and `0x00502469`, and scalar deleting destructor `0x00502600` size `0x45`.
- The same live pass found no direct constructor code xrefs, but confirmed the button-handler vtable slot at `0x0061daa0`, scalar-destructor/thunk refs through `0x0061da58`, five singleton xrefs to `0x0069b498` across constructor publish/clear, clear helper, destructor clear, and main-menu cleanup, plus byte evidence for the constructor/handler boundary padding.
- [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md) now carries enough file-root evidence for attachment: exact core child, singleton cleanup path, login folder placement, resource operands, and retained older-dialog caveat.
- [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md) is `88/87`, attached to the same file parent, and documents constructor/clear/destructor/main-menu-cleanup xrefs for the singleton storage.
- [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md) documents the `STORY.EPF`, `STORY.EPD`, `PAL01.PAL`, `NPAL8.PAL`, and `BACKTALE` resource operands used by this class.
- Direct constructor xrefs were not found in IDA during this pass; the class may be opened through an indirect path or be a retained older story dialog path.
- B014 2026-06-19 source-quality reanalysis resolves that caveat in favor of retained/compatibility BackStory text-dialog code: local PE scans found no rel32 call/jump, absolute VA pointer, or RVA pointer to constructor `0x00500090`, and the BackStory vtable head is only stored by this constructor. Active story/history menu branches and retained wrappers construct `HistoryViewingPane`, while this class remains source-authored because of the singleton, vtables, destructor support, cleanup consumer, unique `BACKTALE` resource, and complete constructor/handler shape.
- Helper `0x0049fc00` is an inherited `DialogPane` control-id update helper. Draft C++ may use `SetHoverControl(1)` until a final project-approved source name is settled.

## Vtable, RTTI, And Destruction Evidence

- Exact physical cluster [UID:0004WA][0x0061da54-0x0061daf0.BackStoryDialogPaneVtableData](by-memory/0x0061da54-0x0061daf0.BackStoryDialogPaneVtableData.md) is 156 bytes, SHA256 `612C02F9BECCB97561B968979DAA3F8D743982053D8FBE8A7EBEA5CB37422771`.
- Primary/secondary/tertiary locator bases are `0x0061da54`, `0x0061dab4`, and `0x0061dae4`; vtable bases are `0x0061da58`, `0x0061dab8`, and `0x0061dae8`; slot counts are 23/11/2.
- Primary slot zero points to scalar wrapper UID0004W9; primary `+0x48` points to `OnControlCommand` at `0x005003f0`; secondary/tertiary slot zero point to UID0004W8's `-0xa0`/`-0xa4` adjustors.
- RTTI contains eight bases: BackStoryDialogPane, DialogPane, Pane, GrafPort, LObject, EventHandler, TimerHandler, and `Singleton<BackStoryDialogPane>`.
- Direct Singleton PMD `{0x26c,-1,0}` plus object size `0x26c` proves EBO and rejects an authored singleton field.
- UID0003HH, UID0004W8, UID0004W9, the three vtables, RTTI records, vptr writes, delete flags, and base teardown are compiler/template artifacts caused by this declaration. They must not be copied into handwritten class/source code.

## Negative Evidence And Rejected Alternatives

- No authored data member, explicit destructor statement, standalone vtable array, handwritten singleton publication/clear, or fourth vtable view is required by the binary.
- Historical `HandleButtonClick` naming is superseded by the exact current `DialogPane::OnControlCommand(int,int)` slot contract and `retn 8` body shape.
- Historical source with `g_pBackStoryDialogPane = this` in the constructor or clear in a destructor duplicates direct Singleton lowering and is rejected.
- MainMenuPane is a show/cleanup consumer, HistoryViewingPane is the current active replacement, and UID00025Q is physical table containment; none is the direct class/source owner.

## Autogen Status

- Reconstructable: true, because this is a NexusTK-authored login/main-menu story dialog class that must be represented in the rebuilt source tree.
- Parent: [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md).
- C++: complete fieldless `DialogPane` plus direct `Singleton<BackStoryDialogPane>` declaration, global `extern`, constructor, protected `OnControlCommand`, and `[[CHILDREN]]` are emitted here. Exact method bodies emit from UID0001A2. UID0003HH/UID0004W8/UID0004W9/UID0004WA/UID0004WB remain compiler-only blank-C++ evidence.

## Score Rationale

- Completion `92` records the complete declaration, exact size/fieldless layout, direct bases/EBO, three-view vtable/RTTI inventory, compiler support splits, exact core behavior/resources, singleton linkage/lifecycle, retained classification, source ownership, and historical corrections.
- Confidence `94` is supported by current method bytes/xrefs, RTTI PMD, exact table cells/hash, compiler-wrapper ranges, global PE mapping/lifecycle, and family API contracts. Original lexical names and historical launcher remain bounded caps.
- The class emits declaration-level C++ only. Exact method bodies stay in exact by-memory children so the class page does not blur method-range ownership.

## Open Questions With Attempted Resolution

- Historical launcher: exhaustive caller/xref/VA/RVA/raw-pointer and current-menu analysis found none. Resolved as retained compatibility source whose active route was replaced by HistoryViewingPane; this is a confidence cap, not an implementation blocker.
- Helper/API names: current family contracts support `SetHoverControl`, `SetPendingControl`, `OnCreate`, `OnShow`, `SlideOpenVertical`, `SlideCloseVertical`, and `CloseDialog`; raw labels are rejected from final C++.
- Layer context: [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md) resolves `dword_69B36C` as `g_mainUiLayerSlots.overlayPaneLayerContext`; it is distinct from `g_pMainMenuPane`.
- Destructor: direct Singleton RTTI/EBO and exact wrapper effect subtraction resolve ordinary implicit virtual destruction with no authored body.

## Cross-References

- [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md)
- [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md)
- [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md)
- [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:00007O][MainMenuPane](by-class/MainMenuPane.md)
- [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- [UID:00029F][0x0069b498-0x0069b49c.g_pBackStoryDialogPane](by-memory/0x0069b498-0x0069b49c.g_pBackStoryDialogPane.md)
- [UID:0001A1][0x004ffd80-0x0050008b.HistoryViewingPaneCore](by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md)
- [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md)
- [UID:0003HH][0x00502390-0x0050239b.BackStoryDialogPaneSingletonBaseDestructor](by-memory/0x00502390-0x0050239b.BackStoryDialogPaneSingletonBaseDestructor.md)
- [UID:0004W8][0x0050245e-0x00502474.BackStoryDialogPaneDestructorAdjustorThunks](by-memory/0x0050245e-0x00502474.BackStoryDialogPaneDestructorAdjustorThunks.md)
- [UID:0004W9][0x00502600-0x00502645.BackStoryDialogPaneScalarDeletingDestructor](by-memory/0x00502600-0x00502645.BackStoryDialogPaneScalarDeletingDestructor.md)
- [UID:0004WA][0x0061da54-0x0061daf0.BackStoryDialogPaneVtableData](by-memory/0x0061da54-0x0061daf0.BackStoryDialogPaneVtableData.md)
- [UID:0004WB][BackStoryDialogPaneVtables](by-type/by-vtable/BackStoryDialogPaneVtables.md)

## Changes

- 2026-07-22 B002 UID00029F accepted callback:
  - Raised `88/89 -> 92/94`, set emitter position `10`, added direct `Singleton<BackStoryDialogPane>` and the global extern/`[[CHILDREN]]` contract, and renamed the virtual to `OnControlCommand(int,int)`.
  - Added exact `0x26c` size/fieldless/EBO evidence, three vtable views, 23/11/2 slot inventory, RTTI hierarchy, real compiler child UIDs 0003HH/0004W8/0004W9/0004WA/0004WB, implicit-destructor proof, and resolved helper/layer naming.
  - Historical explicit singleton publication/clear, generic callback naming, active-route uncertainty, and compiler-artifact source interpretations remain documented as superseded rather than silently removed.

- 2026-06-07 A008 alias cleanup: normalized the `byte_66DA97` layout/resource branch to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), preserving `byte_66DA97` as the IDA lookup alias.
- What existed before: the page documented UI construction, singleton data, and reachability uncertainty but had unevaluated scores.
- What it was changed to: scores were set to `66/78`, and class-shape notes were added for dialog base, singleton, resource role, and source placement.
- Summary and evidence: constructor/resource behavior is clear from IDA decompilation and singleton xrefs; confidence stays medium-high because no direct constructor xref was found in the prior pass.
- 2026-06-02: Raised the class page from `66/78` to `72/84`.
  - Before: the class page summarized the constructor and singleton but did not carry over the refreshed file/core evidence, layout tables, touched-state evidence, or boundary/support ranges.
  - After: the page records login/main-menu placement, retained reachability caveats, exact EPF/legacy layout branches, singleton/vtable/resource state, padding boundaries, destructor support ranges, and autogen rationale.
  - Evidence: existing IDA-backed [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md), [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md), [UID:00029F][0x0069b498-0x0069b49c.g_pBackStoryDialogPane](by-memory/0x0069b498-0x0069b49c.g_pBackStoryDialogPane.md), and [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md).
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE` and updated the autogen-status note accordingly. Current IDA MCP `lookup_funcs` reconfirmed the constructor/button-handler/deleting-destructor starts at `0x00500090`, `0x005003f0`, and `0x00502600`; constructor callers remained absent in that IDA pass, so legacy parent metadata and reconstruction C++ stayed blank pending stronger reachability and class-layout evidence.
- 2026-06-06 parent attachment update:
  - Before: the class was reconstructable but still unattached at `72/84`, and the manual class coverage row was stale at `66% : medium-high`.
  - Changed to: `82/84`, parent [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md) at position `10`, with explicit autogen status and score rationale added.
  - Evidence: [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md) is `82/84` and stages `BackStoryDialogPane.cpp` under `NexusTK/login/`; [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md) records exact constructor/button-handler boundaries, vtable/singleton/resource xrefs, layout branches, and padding; [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md) documents singleton lifecycle xrefs; [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md) documents the story art/text operands. C++ remains blank because direct constructor reachability and final field/helper names are not final-source quality.
- 2026-06-14 C001 Goal 2 IDA refresh:
  - Before: `82/84`, with stale recovered-file/position/final-code-gate wording.
  - After: `86/86`, with live IDA 9.1 evidence for constructor/handler/clear-helper/thunk/destructor sizes, singleton and vtable xrefs, no direct constructor xrefs, and byte-boundary confirmation. Owner/emitter routing remains [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md); final C++ stays blank until live construction and source-quality field/helper names are resolved.
- 2026-06-22 Rule 26 incorporation of B014 report `0001A2-BackStoryDialogPaneCore-source-quality`:
  - Before: `86/86`, class C++ blank, with direct construction still framed as unresolved.
- Historical after-state: `88/89`, declaration-level `DialogPane`-derived class C++, retained/compatibility classification, then-current `g_pMainUiGraph` and `dword_69B36C` wording, logical close action id `1`, and visual image index `14`. Current show parent is `g_pMainMenuPane`; the layer/context remains separate.
  - Evidence: B014 local PE route scan found no rel32/VA/RVA constructor route and no external vtable-head store; active `MainMenuPane` story/history paths construct `HistoryViewingPane`; singleton, vtable, destructor-support, cleanup-consumer, `STORY.*`, palette, and `BACKTALE` evidence keep this class source-authored under `BackStoryDialogPane.cpp`.
