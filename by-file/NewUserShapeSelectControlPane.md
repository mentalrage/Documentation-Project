*** UID:0000LY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# NewUserShapeSelectControlPane

## Status

- Confidence: very strong for the standalone source split, complete CPP/H inventory, control behavior, exact `0x11c` layout, class/vtable/compiler ownership, render-type ABI, resources/globals, exact child source, and login/create-user placement. Original private identifier spellings remain inferred.
- Proposed module pair: `login/NewUserShapeSelectControlPane.cpp` and `login/NewUserShapeSelectControlPane.h`.
- Umbrella doc: [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- Evidence basis: exact function/raw-body inventory, constructor and packet-consumer callers, decorated RTTI and three vtable views, class allocation/layout, compiler destructor support, resource/global xrefs, HumanImageRenderParams ABI closure, current by-* pages, and the accepted UID0000LY whole-file report. Historical recovered-source and Wave2/Wave3 artifacts are not evidence.

## File Role

`NewUserShapeSelectControlPane.cpp` should own the newer body-shape preview/selection control used by create-user dialogs. It is adjacent to login/create-user code, not a generic game UI control.

## Boundary Notes

This file is the final standalone source-module route for the `NewUserShapeSelectControlPane` class and exact child [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md). Concrete RTTI, an independent method/vtable island, a separate `NewCreateUserDialogPane` consumer, a public header contract, and the established source-tree split outweigh the single known constructor consumer. Folding into [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md) is rejected because it would conflate separate class identity, header ownership, compiler support, and source ranges.

It is also adjacent to [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md), the alternate 640x480 create-character dialog. Keep it out of [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md), which is account-registration UI rather than shape-selection UI.

The exact core child ends at `0x004fdd33`, followed by thirteen `0xcc` bytes `[0x004fdd33,0x004fdd40)` before adjacent [UID:0002QA][0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore](by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md). Compiler-only support is now split exactly into [UID:00050L][0x0050253a-0x00502550.NewUserShapeSelectControlPaneDestructorAdjustorThunks](by-memory/0x0050253a-0x00502550.NewUserShapeSelectControlPaneDestructorAdjustorThunks.md) and [UID:00050K][0x00502a70-0x00502aab.NewUserShapeSelectControlPaneScalarDeletingDestructor](by-memory/0x00502a70-0x00502aab.NewUserShapeSelectControlPaneScalarDeletingDestructor.md); five bytes `[0x00502aab,0x00502ab0)` remain padding before unrelated ScrolledPictureControlPane support.

## Proposed Contents

| Range | Current method family | Notes |
| --- | --- | --- |
| [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md) | class declaration / method owner | Direct class parent for the exact core method cluster; owns the vtable-backed constructor, virtual handlers, retained raw shape-step helpers, descriptor builder, page helpers, and scalar deleting destructor support. |
| [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md) | constructor, `BuildPreviewParams`, direction, page helpers, timer, mouse, paint, and point-to-shape helpers | Exact child page covering the newer shape selector's constructor, descriptor builder, `AdvanceDirection`, retained no-xref shape-step helpers, `SelectNextPage`, `SelectPreviousPage`, timer/mouse handlers, paint path, `SelectShapeAtPoint(localY, localX)`, and formal first-draft C++. Dialog-owned tail chunks remain documented but excluded from standalone selector method emission. |
| [UID:00050L][0x0050253a-0x00502550.NewUserShapeSelectControlPaneDestructorAdjustorThunks](by-memory/0x0050253a-0x00502550.NewUserShapeSelectControlPaneDestructorAdjustorThunks.md) | two compiler destructor adjustors | Exact `0x0b` EventHandler-view `this-0xa0` and `0x0b` TimerHandler-view `this-0xa4` entries; class-owned, non-reconstructable, non-emitting. |
| [UID:00050K][0x00502a70-0x00502aab.NewUserShapeSelectControlPaneScalarDeletingDestructor](by-memory/0x00502a70-0x00502aab.NewUserShapeSelectControlPaneScalarDeletingDestructor.md) | compiler scalar deleting destructor | Exact 59-byte primary/adjusted target; generated from the ordinary virtual destructor, non-reconstructable and non-emitting. |
| [UID:00025Q][0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData](by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md) nested `[0x0061d604,0x0061d6a8)` | three-view vtable/RTTI block | Primary, EventHandler, and TimerHandler views plus COL records; compiler-generated from the class declaration and never emitted as source arrays. |
| [UID:00050M][HumanImageRenderParams](by-type/by-struct/HumanImageRenderParams.md) | packed render descriptor | Exact `0x40` H-only type emitted through NewHumanImageLib; closes stack allocation and field access for preview/bounds/draw consumers. |
| `0x0061e3c0` / `0x0061e420` | `USERPART.EPF` / `USERPART.PAL` | Exact UTF-16 frame and palette literals consumed by selector paint; not pointer globals. |
| [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md) | service dependencies | Layout lookup and new-human count/bounds/draw services; referenced but not owned by this file. |

## 2026-08-11 B005 Whole-File Closure

### Complete authored and compiler inventory

| Range/item | Source role | CPP/H disposition |
| --- | --- | --- |
| `[0x004fd520,0x004fd60b)` | constructor; `ControlPane(8, bounds)`, state initialization, timer registration | out-of-line CPP |
| `[0x004fd610,0x004fd656)` | exact partial `HumanImageRenderParams` builder | out-of-line CPP |
| `[0x004fd660,0x004fd67b)` | byte direction advance modulo four | out-of-line CPP |
| `0x004fd680` / `0x004fd6a0` tails | dialog-owned male/female calls into inline selector mode API | inline H cause only; no duplicate CPP |
| `[0x004fd6c0,0x004fd72c)` / `[0x004fd730,0x004fd786)` | retained signed-short forward/backward shape steppers, including original invalid-state fallthrough | out-of-line CPP |
| `[0x004fd790,0x004fd84d)` / `[0x004fd850,0x004fd8e9)` | next/previous 15-entry page methods and short-last-page quirks | out-of-line CPP |
| `[0x004fd8f0,0x004fd8f3)` / `[0x004fd900,0x004fd903)` | retained compatibility `IsSelected` false getter and no-op `SetSelected` | out-of-line CPP |
| `[0x004fd910,0x004fd961)` | timer 0 animation and 200 ms reschedule | out-of-line CPP |
| `[0x004fd970,0x004fda2d)` | mouse hit/drag path preserving y/x helper order | out-of-line CPP |
| `[0x004fda30,0x004fdc8f)` | 5x3 paint grid, frame resources, preview bounds/draw | out-of-line CPP |
| `[0x004fdc90,0x004fdd33)` | `(localY, localX)` point-to-slot conversion | out-of-line CPP |
| class API/state | virtual destructor/handlers, descriptor/direction/page/selection methods, inline mode setters and slot/page accessors, exact `0x11c` fields | formal H |
| `[0x0050253a,0x00502550)` / `[0x00502a70,0x00502aab)` | receiver adjustors and scalar deleting wrapper | compiler-only child pages; blank CPP/H |
| `[0x0061d604,0x0061d6a8)` | COL, primary/secondary/tertiary vtables and RTTI | compiler-generated; no source array |

The exact core contains 13 out-of-line selector definitions. Four source-authored inline/public API methods and two inline accessors live in the class H. Thirteen core padding gaps and the post-wrapper gap are compiler alignment, not missing functions. ChangePassword at `0x004fdd40` and ScrolledPicture compiler support at `0x00502ab0` are explicit neighboring exclusions.

### Behavior and interactions

- Constructor caller `0x0052c7aa` allocates `0x11c`, computes `rand()%15`, supplies bounds `(539,164)-(955,574)`, chooses male/female mode, passes a control flag, constructs the selector, and registers child id `8`.
- `BuildPreviewParams` writes only the observed fields of [UID:00050M][HumanImageRenderParams](by-type/by-struct/HumanImageRenderParams.md). It does not call an invented reset and does not serialize packets.
- [UID:0002QS][0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore](by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md) reads `SelectedShapeSlot() + 15 * ShapePage()`, calls the builder, and owns opcode `0x04` serialization.
- Direction callers are `0x0052cedf` and `0x0052d24a`; page callers are `0x0052ce6e` and `0x0052cdce`; the private selection helper is called at `0x004fd9d3`.
- Paint consumes `g_pEPFLib`, `USERPART.EPF`, `USERPART.PAL`, `g_pNewHumanImageLib`, `EPFTileContext`, distinct cell/source/destination rectangles, five columns, three rows, 80x132 cells, and origin `(17,6)`.
- The two raw steppers and tiny compatibility getter have no direct xrefs or encoded VA/RVA pointers. Their complete bodies and sibling API sequence support retained source inclusion but do not justify invented live callers.

### Ownership, source placement, and generated acceptance

- Final owner route is file UID0000LY -> class UID00009G -> core UID0002Q9. The mixed UID00019U and UID00025Q pages remain non-emitting evidence indexes.
- The source pair is `NexusTK/login/NewUserShapeSelectControlPane.cpp` and `.h`; `ui/controls` placement and folds into NewCreate/CreateUserDialogs are rejected.
- Expected generated CPP contains the exact two includes, namespace constants/helper, and 13 out-of-line definitions. Expected H contains complete includes, declarations, inline mode/accessor API, exact fields/padding, and `[[CHILDREN]]` expansion.
- Generated acceptance requires no empty class emitter, no raw wrapper/thunk/vtable body, no `Reset()`, no `constexpr`, no `sub_`/`dword_`/raw-address names, no duplicated dialog tails, and no missing selector H.

### Historical assumptions corrected and retained

- The former standalone-versus-folded uncertainty is superseded by RTTI, independent code/data islands, separate consumer, and a required public H contract.
- Historical `StepShapeForwardRetained` / `StepShapeBackwardRetained` are retained traceability names only; current source-facing methods drop the synthetic suffix.
- Historical deterministic fallback returns are rejected because the invalid-state machine paths leave the short return uninitialized; formal source preserves that fallthrough.
- Historical `HumanImageRenderParams::Reset()`, broad `RectBounds` paint-context substitution, derived-member initialization of inherited `m_controlFlags`, and `0x00502aaa` exclusive-end wording are contradicted by current evidence.
- Historical raw global/resource labels remain traceability aliases only. Current source uses semantic service globals and exact wide resource literals.

## Evidence Notes

- B001 MCP session `80de0a67` confirms `0x004fd520` as a `0xeb`-byte constructor, `0x004fd610` as `BuildPreviewParams`, `0x004fd970` as a `0xbd`-byte mouse handler, `0x004fda30` as a `0x25f`-byte paint helper, and `0x004fdc90` as the `0xa3`-byte `SelectShapeAtPoint` helper ending before padding at `0x004fdd33`.
- IDA MCP xref checks show the constructor is directly called from [UID:0002QS][0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore](by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md) at `0x0052c7aa`; `BuildPreviewParams`, `AdvanceDirection`, `SelectNextPage`, and `SelectPreviousPage` are reached from nearby create-user dialog code at `0x0052d85f`, `0x0052cedf`, `0x0052d24a`, `0x0052ce6e`, and `0x0052cdce`.
- [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md) is attached to this file page as its class parent after the file/class/core set reached the strict `85/85` reconstruction gate.
- [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md) records constructor writes for vtables at `0x0061d608`, `0x0061d670`, and `0x0061d6a0`, selected shape/page/direction/animation fields, caller-provided `rand()%15` selected slot, child id `8`, and a 200 ms timer registration.
- The same exact core page records the `+0x110` direction field advancing modulo four, dialog-owned tail chunks at `0x004fd680` and `0x004fd6a0` writing mode values through `+0x10c`, retained no-xref shape-step helpers at `0x004fd6c0` and `0x004fd730`, next/previous page directionality from MCP id `44`, and `0x004fdc90-0x004fdd33` converting `(localY, localX)` into the selected shape/page state before redraw.
- Paint/render code draws the selector grid with `g_pNewHumanImageLib` shape-count/render data, frame resources `USERPART.EPF` / `USERPART.PAL`, and `g_pEPFLib` lookup support; this keeps the file tied to create-user appearance selection rather than generic controls.
- Because no direct caller from [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md) is currently observed, keep reuse by `NewUserDialogPane2` as a proximity/source-layout hypothesis rather than confirmed caller evidence.

## Score Rationale

The projected path remains `NexusTK/login/`. Completion is `93` because the whole-file page now accounts for the complete CPP/H source pair, all 13 out-of-line bodies, inline API/accessors, exact class/type layouts, every compiler/no-code range, resources/globals, callers, padding, neighbors, source order, owner route, historical contradictions, and generated acceptance contract. Confidence is `94` because behavior, ranges, ABI, ownership, and source split are independently corroborated; only unavailable original private identifier spelling and pending supervisor generated readback prevent final-audit scoring.

## Cross-References

- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md)
- [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md)
- [UID:00019U][0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs](by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md)
- [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md)
- [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md)
- [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md)
- [UID:0000LX][NewUserMiscDialogPane](by-file/NewUserMiscDialogPane.md)
- [UID:00050L][0x0050253a-0x00502550.NewUserShapeSelectControlPaneDestructorAdjustorThunks](by-memory/0x0050253a-0x00502550.NewUserShapeSelectControlPaneDestructorAdjustorThunks.md)
- [UID:00050K][0x00502a70-0x00502aab.NewUserShapeSelectControlPaneScalarDeletingDestructor](by-memory/0x00502a70-0x00502aab.NewUserShapeSelectControlPaneScalarDeletingDestructor.md)
- [UID:00050M][HumanImageRenderParams](by-type/by-struct/HumanImageRenderParams.md)
- [UID:00025Q][0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData](by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md)

## Changes

- 2026-08-11 B005 UID0000LY whole-file implementation callback:
  - Raised `85/87 -> 93/94` after resolving the standalone CPP/H split, exact `0x11c` class declaration, packed `0x40` HumanImageRenderParams dependency, complete authored/compiler inventory, source order, resources/globals, callers, padding, and generated acceptance contract.
  - Added exact compiler-only children UID00050L and UID00050K, corrected the wrapper end to `0x00502aab`, and preserved UID00019U/UID00025Q as mixed non-emitting indexes.
  - Historical folded-file, `Retained` suffix, deterministic fallback, `Reset()`, RectBounds-context, inherited-member-initializer, raw-label, and stale exclusive-end assumptions remain recorded above with contradiction evidence.
- 2026-06-25 B001 accepted source-quality synchronization:
  - Score unchanged at `85/87`.
  - Summary/evidence: replaced stale blank-C++/folded-source caveat with the accepted route: [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md) owns the class, [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md) carries formal first-draft C++, and this source module remains the login/create-user file expectation while final standalone-vs-folded layout stays below final audit.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `76`, confidence `72`.
- Summary/evidence: the page documents control role, boundary decisions, method-family ranges, constructor caller evidence, and create-user cross-references; confidence remains limited by standalone-file uncertainty and unconfirmed reuse beyond `NewCreateUserDialogPane`.
- 2026-06-03 path and confidence update:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, the page was scored `76/72`, and the proposed contents used unlinked method-family rows.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"`, score `80/82`, and proposed contents now point to exact child page [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md).
  - Summary/evidence: the create-user umbrella, proposed source tree, class page, and exact memory page all support login/create-user placement; final standalone-vs-folded source split remains open.
- 2026-06-07 A010 evidence-sync update:
  - What existed before: the page was scored `80/82` and documented method-family/caller evidence, but did not yet summarize the class-parent attachment, exact state fields, timer interval, tail-chunk mode writes, or the current MCP limitation.
  - Changed to: completion `82`, confidence `84`, stronger evidence notes for [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md) and [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md), and explicit boundary text for the `0x004fdd33` core end before [UID:0002QA][0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore](by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md).
  - Summary/evidence: synchronized the by-file page with existing class/core documentation only; current-session IDA MCP was unavailable, so no new live IDA facts were introduced.
- 2026-06-13 C001 Goal 2 low-completion/low-both pass:
  - Changed from: `COMPLETION:82`, `CONFIDENCE:84`.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:87`.
  - Evidence: live IDA 9.1 MCP reconfirmed exact core boundaries, helper/vtable/destructor xrefs, decompiled selector behavior, raw page-step caveats, paint dependencies, and the `0x004fdd33-0x004fdd40` padding boundary. This source page now clears the strict parent gate for [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md), while preserving the standalone-vs-folded file caveat.
