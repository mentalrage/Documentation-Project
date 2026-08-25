*** UID:0000M3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ObjectImageControlPane

## 2026-08-18 Permanent Compiler And Vtable Children

- [UID:00055W][0x00520afd-0x00520b13.ObjectImageControlPaneDestructorThunks](by-memory/0x00520afd-0x00520b13.ObjectImageControlPaneDestructorThunks.md) owns the exact base EventHandler/TimerHandler adjustor bytes as non-emitting compiler evidence.
- [UID:00055X][0x00520ca0-0x00520cdb.ObjectImageControlPaneScalarDeletingDestructor](by-memory/0x00520ca0-0x00520cdb.ObjectImageControlPaneScalarDeletingDestructor.md) owns the exact base scalar deleting destructor physical wrapper and 0x14c delete-size evidence.
- [UID:00055Y][0x004242f0-0x004242f5.SharedControlPaneHitTestPartReturn11](by-memory/0x004242f0-0x004242f5.SharedControlPaneHitTestPartReturn11.md) indexes the ten-way compiler-folded return-11 body; human source remains inline in ObjectImageButtonPane.h.
- [UID:00055Z][0x0061f6c0-0x0061f808.ObjectImageControlPaneVtableBand](by-memory/0x0061f6c0-0x0061f808.ObjectImageControlPaneVtableBand.md) records all six table heads and all 82 cells as non-emitting linker data.
- These permanent pages close the physical inventory without adding source functions, manual vtables, RTTI, or compiler glue to ObjectImageControlPane.cpp.

## ObjectStatusBlob dependency synchronization

- This module copies and renders the complete 68-byte UID00009S ObjectStatusBlob. Its proven source-facing fields are kind `+0x00`, appearance/item `+0x04`, variant/palette `+0x06`, display/default `+0x28`, all equipment/riding/color/tail fields, and explicit padding through byte 68.
- Status kinds 0/1/2 are Human/Monster/Item for rendering while remaining compatible with MapPane living/item aliases. The complete class unions deliberately support the existing ObjectImage source without any C++ edit in this callback.
- Historical title/profile/generic-remap summaries are superseded by RidableAnimals, Part.tbl, and NewHuman HAIRCOL evidence. Parser ownership remains UID00009S/UID0000M6; this file's score, contents, route, and emitted formal sources are unchanged.


## Status

- Confidence: strong for `ObjectImageControlPane` behavior, `ObjectStatusBlob` descriptor naming, first-draft base control method bodies, strong that `ObjectImageButtonPane` belongs in this source family, and strong that the button's source-bearing core is split away from compiler-generated destructor glue.
- Proposed module: `ui/controls/ObjectImageControlPane.cpp`
- Current recovered sources: `source-3/simroot_v2/class_ObjectImageControlPane.cpp` and sibling `source-3/simroot_v2/class_ObjectImageButtonPane.cpp`

## File Role

`ObjectImageControlPane` is the reusable centered object-image preview control used by packet/menu/dialog UI. It stores a 68-byte [UID:00009S][ObjectStatusBlob](by-class/ObjectStatusBlob.md) snapshot and paints one of three image families:

- type `0`: human/avatar images through `NewHumanImageLib`.
- type `1`: monster images through `MonsterImageLib`.
- type `2`: item/EPF frames through `ItemObjImageLib` and the EPF resource layer.

`ObjectImageButtonPane` derives from this display behavior and adds button activation, a pane type id, and a highlight/overlay flag. The constructor adjacency, direct base-constructor call, and shared destructor thunk neighborhood make this the preferred original source family for the button variant; [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) should keep only a cross-reference.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `ObjectImageControlPane` | `0x00520540-0x00520816`, thunks `0x00520afd`/`0x00520b08`, destructor `0x00520ca0-0x00520cda` | Centered non-interactive image preview control for human, monster, and item/EPF-backed object images. The source-bearing range contains the constructor `0x00520540-0x005205b5` and `void OnPaint()`; thunks/destructor/vtable bytes are generated support. |
| `ObjectImageButtonPane` | source-bearing core [UID:0001BV][0x00520820-0x00520a97.ObjectImageButtonPaneCore](by-memory/0x00520820-0x00520a97.ObjectImageButtonPaneCore.md) `0x00520820-0x00520a97`, thunks `0x00520ae7-0x00520afd`, scalar wrapper `0x00520c60-0x00520c9b` | Button subclass that reuses object-image rendering, handles Enter/Space activation, and stores an overlay/highlight byte at `+0x14c`; the core now includes the retained highlight getter at `0x00520a90-0x00520a97` and routes directly through [UID:00009N][ObjectImageButtonPane](by-class/ObjectImageButtonPane.md) while this file remains the source-family/generated-file route. Destructor glue is compiler-generated and documented separately; the wrapper's guarded delete path passes object size `0x150` versus `0x14c` for the base preview control. |

## Evidence Notes

- IDA MCP confirms `ObjectImageControlPane::ObjectImageControlPane` at `0x00520540`, `OnPaint` at `0x005205c0-0x00520816`, adjustor thunks at `0x00520afd-0x00520b12`, and scalar deleting destructor at `0x00520ca0-0x00520cda`. B008's raw PE/Capstone recheck corrects the constructor half-open end to `0x005205b5`, with padding starting immediately after the `ret 8`.
- IDA MCP reports many constructor xrefs for `0x00520540`, including text-menu constructors, argumented-menu construction at `0x0051e9a0`, message/menu-question dialogs, head-selection UI, client/server item menu dialogs, and the `ObjectImageButtonPane` constructor at `0x00520820`.
- Generated source call sites include `ArgumentedMenuMenuDialog`, `ClientItemMenuDialog`, `ClientSpellMenuDialog`, [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md), `MenuQuestionDialog`, `MessageDialog`, `ServerItemMenuDialog`, `ServerSpellMenuDialog`, [UID:0000OL][TextDialog](by-file/TextDialog.md), and `TextInputMenuDialog`.
- IDA MCP decompiles both object-image deleting destructors as calls to shared pane-base teardown helper `0x00544580` followed by conditional delete helper `0x004f4ac0`; current generated `TextButtonExControlPane`/`Pane` labels are owner-name pollution, not inheritance proof.
- B002 2026-06-19 local PE audit refines the generated destructor handling: [UID:0003MA][0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor](by-memory/0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md) is a 59-byte MSVC scalar deleting destructor with `flags & 1` ordinary delete through `0x004f4ac0(this)` and `flags & 4` guarded sized/vector-delete through `0x0041b6a0(this, 0x150)`. The plain `ObjectImageControlPane` wrapper uses the same shape with size `0x14c`, confirming the button subclass extension and keeping the class in this object-image source family.
- B008 2026-06-19 source-quality pass resolves the base control's descriptor and source signatures. The constructor is `ObjectImageControlPane(const ObjectStatusBlob *objectStatus, const RectBounds *bounds)`; visible call sites push bounds first and the descriptor second, matching descriptor-first/bounds-second thiscall source order. The copied member at base offset `+0x108..+0x14b` is `ObjectStatusBlob m_objectStatus`; object offset `+0x130` is descriptor byte `+0x28` (`m_displayStatusByte` / `defaultByte`) rather than independent pane state.
- First-draft C++ is now ready and populated in [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md). The emitted source should include the constructor and `OnPaint` bodies only for that range; it should not include vtable stores, adjustor thunks, scalar deleting destructor wrappers, or rdata bytes as handwritten source.
- Exact generated destructor support pages for the button are no-code: [UID:0003M9][0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks](by-memory/0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks.md) contains `sub ecx,0xa0` / `sub ecx,0xa4` adjustors from vtable cells `0x0061f7cc` and `0x0061f7fc`, and [UID:0003MA][0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor](by-memory/0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md) contains the primary vtable slot target at `0x0061f764`.
- `ObjectImageButtonPane::SetButtonHighlight` at `0x00520a80` is called by [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md) paths at `0x0055149a`, `0x0055209a`, and `0x005520c3`.
- 2026-06-12 barrier repair split the source-bearing object-image button core away from [0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks](by-memory/0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks.md) and [0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor](by-memory/0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md). B002 2026-07-02 current MCP session `1f24c222` extends the exact source-bearing core to [UID:0001BV][0x00520820-0x00520a97.ObjectImageButtonPaneCore](by-memory/0x00520820-0x00520a97.ObjectImageButtonPaneCore.md) after proving the formerly ignored `0x00520a90-0x00520a97` bytes are a real getter for `+0x14c`. The class-owned target now routes through [UID:00009N][ObjectImageButtonPane](by-class/ObjectImageButtonPane.md) to this source file.

## Placement Notes

Prefer `ui/controls/ObjectImageControlPane.cpp` over a feature-dialog file because the control has broad dialog reuse and no single owning feature. Move `ObjectImageButtonPane` into this object-image control module or a directly adjacent `ObjectImageButtonPane.cpp`; do not keep it in the generic specialized-button bucket unless later source-file evidence outweighs the inheritance/locality evidence. In particular, the scalar deleting destructor wrapper and adjustor thunks are compiler output and should not be used to create a new source file split by themselves.

The plain control and button subclass should use the same `ObjectStatusBlob` descriptor naming. `ObjectImageDescriptor` remains only a historical/readability alias unless a later header pass deliberately introduces a typedef; current parser, HeadSelect, MapPane, and object-image caller evidence all point at the shared `ObjectStatusBlob` layout.

## Cross-References

- [UID:00009O][ObjectImageControlPane](by-class/ObjectImageControlPane.md)
- [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md)
- [UID:00009N][ObjectImageButtonPane](by-class/ObjectImageButtonPane.md)
- [UID:0001BV][0x00520820-0x00520a97.ObjectImageButtonPaneCore](by-memory/0x00520820-0x00520a97.ObjectImageButtonPaneCore.md)
- [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md)
- [UID:0000OL][TextDialog](by-file/TextDialog.md)
- [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `84`.
- Summary/evidence: the page documents the reusable preview/button control family, proposed contents, broad constructor caller evidence, destructor-owner pollution, placement notes, and cross-references; confidence is strong because behavior and sibling ownership are well supported.
- 2026-06-01: Set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/controls/` so reviewed object-image child pages can attach without autogen path errors.
- 2026-06-12 Supervisor Goal 2 barrier repair: raised confidence from `84` to `86` after splitting `ObjectImageButtonPane` into a contiguous source-bearing core plus exact generated destructor-glue pages. The file now clears the strict `85/85` gate for [UID:00009N][ObjectImageButtonPane](by-class/ObjectImageButtonPane.md) and the source-bearing core now documented as [UID:0001BV][0x00520820-0x00520a97.ObjectImageButtonPaneCore](by-memory/0x00520820-0x00520a97.ObjectImageButtonPaneCore.md).
- 2026-07-02 B002 UID0001BV implementation callback: score unchanged. Updated the object-image button core route to [UID:0001BV][0x00520820-0x00520a97.ObjectImageButtonPaneCore](by-memory/0x00520820-0x00520a97.ObjectImageButtonPaneCore.md), recorded the retained `0x00520a90-0x00520a97` highlight getter, and clarified that [UID:0001BV][0x00520820-0x00520a97.ObjectImageButtonPaneCore](by-memory/0x00520820-0x00520a97.ObjectImageButtonPaneCore.md) now uses [UID:00009N][ObjectImageButtonPane](by-class/ObjectImageButtonPane.md) as direct owner/emitter while this file remains the generated source root.
- 2026-06-20 B002 Rule 26 cross-reference: score unchanged. Added exact `ObjectImageButtonPane` destructor-wrapper evidence from [UID:0003M9][0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks](by-memory/0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks.md)/[UID:0003MA][0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor](by-memory/0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md), including vtable slots `0x0061f764`/`0x0061f7cc`/`0x0061f7fc`, subtract amounts `0xa0`/`0xa4`, delete-helper roles, `0x150` versus `0x14c` size comparison, and no-code/source-placement policy.
- 2026-06-21 B008 Rule 26 source-quality incorporation: raised from `86/86` to `88/88`. The file page now records the base control constructor endpoint correction, `ObjectStatusBlob` descriptor/member naming, descriptor byte `+0x28` handling, first-draft constructor/paint C++ readiness in [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md), and the rule that emitted source should include source-authored constructor/paint bodies while excluding compiler-generated vtable/thunk/scalar-delete/rdata bytes.

## 2026-08-18 Whole-File Source Closure

- Canonical source is the pair `NexusTK/ui/controls/ObjectImageControlPane.cpp` and `ObjectImageControlPane.h`. The header owns the `ObjectImageControlPane` declaration first and the `ObjectImageButtonPane` declaration second. The source owns exactly seven out-of-line authored functions in address order: base constructor and `OnPaint`, then button constructor, `HandleKeyOrTextEvent`, `OnPaint`, `SetButtonHighlight`, and retained zero-xref `IsButtonHighlighted`.
- `ObjectImageControlPane` derives from `ControlPane`, stores the complete `ObjectStatusBlob m_objectStatus` at `+0x108`, and is `0x14c` bytes. `ObjectImageButtonPane` derives from it, adds only `bool m_buttonHighlight` at `+0x14c`, and rounds to `0x150`. The non-const inline `HitTestPart(int,int)` override returns `11` and matches the inherited non-const virtual slot.
- The authored base range is `[0x00520540,0x00520816)`: constructor `[0x00520540,0x005205b5)` and paint `[0x005205c0,0x00520816)`. The authored button range is `[0x00520820,0x00520a97)`: constructor `[0x00520820,0x0052086f)`, event handler `[0x00520870,0x0052090d)`, paint `[0x00520910,0x00520a79)`, setter `[0x00520a80,0x00520a90)`, and getter `[0x00520a90,0x00520a97)`.
- The exact base constructor fan-in is `{51832d,5188bc,518c20,519c94,51a134,51aaae,51bcaa,51c1d6,51ceae,51d3eb,51df07,51e3a4,51ef56,520830,54d3ad,54d9c9,54e130,54e752,54f02c,54f783,55023f,5509a8,5510c9,55117b,5519c0,551ed3,552867,553020}`. The button constructor has caller `0x00551479`; setter callers are `0x0055149a`, `0x0055209a`, and `0x005520c3`; the getter has no inbound xref but remains exact retained source.
- Base paint clears the visible bounds through `g_pfnFillRect`, centers Human and Monster bounds, returns immediately after those two draw paths, and on the Item path draws the item glyph and alone releases `EPFTileContext` buffers. Button activation accepts key-down Space/Return, drives selection states `11` then `10` around two presentation calls and `Sleep(0x85)`, and dispatches command `11` to its parent `DialogPane`. Button paint uses exact UTF-16 resources `CAPSULE.EPD` and `NPAL3.PAL`, the six-argument `RenderTileFrame` contract, and then centers and draws the human image.
- Four destructor adjustors and two scalar deleting wrappers are compiler output, not authored functions. Button adjustors `[0x00520ae7,0x00520afd)` subtract `0xa0`/`0xa4` and tail-jump to `[0x00520c60,0x00520c9b)`; base adjustors `[0x00520afd,0x00520b13)` tail-jump to `[0x00520ca0,0x00520cdb)`. The scalar wrappers use inherited teardown, `flags & 1`/`flags & 4`, and complete-object sizes `0x150` and `0x14c`. Normal class declarations and implicit virtual destruction regenerate them.
- Six vtables occupy the exact 328-byte band `[0x0061f6c0,0x0061f808)`: base primary/EventHandler/TimerHandler at `0x0061f6c0/0x0061f728/0x0061f758`, followed by button primary/EventHandler/TimerHandler at `0x0061f764/0x0061f7cc/0x0061f7fc`. The band has 82 pointer cells and SHA256 `A2EED27B58FA7C7185D0AC6A8F6311C54650308FFBF8CFCB9AF83A5718C805A2`; it is indexed in its own non-emitting page and is never emitted manually.
- Exact non-source gaps are `[0x00520500,0x00520540)`, `[0x005205b5,0x005205c0)`, `[0x00520816,0x00520820)`, `[0x0052086f,0x00520870)`, `[0x0052090d,0x00520910)`, `[0x00520a79,0x00520a80)`, `[0x00520a97,0x00520aa0)`, `[0x00520b6b,0x00520b70)`, `[0x00520bab,0x00520bb0)`, `[0x00520c17,0x00520c20)`, `[0x00520c5b,0x00520c60)`, `[0x00520c9b,0x00520ca0)`, and `[0x00520cdb,0x00520ce0)`.
- Nineteen modeled functions in the surrounding interval are explicitly excluded as menu/list/compiler ownership rather than absorbed here: `0x00520aa0`, `0x00520aa5`, `0x00520ab0`, `0x00520abb`, `0x00520ac6`, `0x00520ad1`, `0x00520adc`, `0x00520b13`, `0x00520b1e`, `0x00520b29`, `0x00520b34`, `0x00520b3f`, `0x00520b4a`, `0x00520b55`, `0x00520b60`, `0x00520b70`, `0x00520bb0`, `0x00520c20`, and `0x00520ce0`. The `0x00520aa0` boost-exception-labeled jump is unrelated glue, not ObjectImage source.
- Required compile-visible dependencies are the corrected `ObjectStatusBlob.cpp/.h`, `MonsterImageLib.cpp/.h`, external `g_pMonsterImageLib`, public `DialogPane::SetSelectionVisualState`, and current ControlPane/Event/ScreenPane/EPFTileContext/GrafPort/ImageLib/ItemObjImageLib/NewHumanImageLib/Surface APIs. ObjectImage source is project-owned reconstructed UI code, so no third-party import directive applies.
- Historical generated output from commands `000000025752` and `000000025804` lacked the required H and retained empty markers/invalid APIs. It is dated defect evidence only. Superseded names and APIs include `m_bounds`, `SurfaceRenderCallbackTable::PreparePaneRegion`, `InitTileContext`, `KeyEvent`, `ControlManager`, `g_pDisplayContext`, `NEWBUTT.EPF`, `NEWBUTT.PAL`, abbreviated render overloads, and manual compiler glue.
- Completion/confidence `93/93` reflects complete file inventory, exact ownership and split, formal H/CPP routing, source-compatible dependency closure, and physical generated verification. Remaining caps are original lexical spellings and absence of a rebuilt-binary comparison.
