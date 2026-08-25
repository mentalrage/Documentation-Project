*** UID:0000JT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# HeadSelectDialog

## Status

- Confidence: very strong for `HeadSelectDialog` core behavior, complete class/header route, class/vtable/resource ownership, wrapper path, `ui/dialogs/` placement, packet/member/control roles, ordinary-destructor/compiler-support split, and source-ready draft behavior; exact original names for retained packet fields/private page helpers and the shared category-switch helper name remain behavior-based.
- Proposed module: `ui/dialogs/HeadSelectDialog.cpp`
- Proposed header: `ui/dialogs/HeadSelectDialog.h`
- Current recovered source: `source-3/simroot_v2/class_HeadSelectDialog.cpp`
- Main address clusters: `0x00551030-0x005520e5`, destructor/thunk support at [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md), and shared category helper [UID:00012T][0x0049dd00-0x0049dd17.DialogCategorySwitch](by-memory/0x0049dd00-0x0049dd17.DialogCategorySwitch.md)

## File Role

This module owns the in-game head/appearance selection dialog. It parses a server packet containing subtype, price/request, object-status, NPC/object id, flag, and text data; creates a dialog background and control set; displays the current character/object preview; populates a paged 5 by 2 grid of selectable head previews; and updates the preview when the user changes pages or selects a head.

Keep this separate from [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md). Both areas use human/head-count image data, but `HeadSelectDialog` is a packet-driven in-game dialog with price/NPC fields and paged head buttons; the create-user dialogs own login/account character creation UI.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `HeadSelectDialog` | `0x00551030-0x005520e5`, [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md) | Packet-driven head selection dialog, preview refresh, page navigation, button population, action handling, destructor support. |
| [UID:0003DA][0x006228b8-0x00622954.HeadSelectDialogVtableData](by-memory/0x006228b8-0x00622954.HeadSelectDialogVtableData.md) | `0x006228b8-0x00622954` | Source-declared/generated-binary RTTI and vtables for `HeadSelectDialog`, attached to the direct class parent after the class cleared the strict gate. |
| [UID:0003DG][0x00622d08-0x00622d20.HeadSelectDialogDlgmsghString](by-memory/0x00622d08-0x00622d20.HeadSelectDialogDlgmsghString.md) | `0x00622d08-0x00622d20` | Class-specific `DLGMSGH.EPF` resource literal used only by the `HeadSelectDialog` constructor. |
| HeadSelect layout tables | [UID:00027Z][0x0066df00-0x0066ed20.HeadSelectDialogLayoutTablePrimary](by-memory/0x0066df00-0x0066ed20.HeadSelectDialogLayoutTablePrimary.md), [UID:000281][0x0066eea0-0x0066fce4.HeadSelectDialogLayoutTableSecondary](by-memory/0x0066eea0-0x0066fce4.HeadSelectDialogLayoutTableSecondary.md) | Static layout/offset table data consumed by constructor, preview refresh, and button population. The normal-resolution primary table and high-resolution secondary companion both route through the direct class parent. |
| Dialog category switch helper | [UID:00012T][0x0049dd00-0x0049dd17.DialogCategorySwitch](by-memory/0x0049dd00-0x0049dd17.DialogCategorySwitch.md) | Currently emitted under `HeadSelectDialog`, but caller evidence crosses fitting-room and other dialog code; likely a generic dialog/control-list helper. |

## Function Map

| Range | Function | Notes |
| --- | --- | --- |
| `0x00551030-0x005511fd` | `RefreshHeadPreview` | Recomputes preview offsets for high/normal resolution, replaces the current [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md), deletes the old pane, and invalidates the dialog. |
| `0x00551200-0x0055124d` | `UpdatePageButtonStates` | Enables/disables previous/next page buttons from current page and head-count state. |
| `0x00551250-0x005512c7` | `NextHeadPage` | Private retained next-page helper; increments/clamps page, repopulates head buttons, and refreshes page-button state. |
| `0x005512d0-0x00551340` | `PreviousHeadPage` | Private retained previous-page helper; decrements/clamps page, repopulates head buttons, and refreshes page-button state. |
| `0x00551350-0x00551510` | `PopulateHeadButtons` | Optionally switches to category `7`, deletes old head buttons, creates up to ten [UID:00009N][ObjectImageButtonPane](by-class/ObjectImageButtonPane.md) entries, and highlights the selected head. |
| `0x00551520-0x00551f26` | `HeadSelectDialog::HeadSelectDialog` | Parses packet fields, configures high/normal layout tables, creates EPF background, image buttons, object preview, static text, and initial head page. |
| `0x00551f30-0x00551f92` | `~HeadSelectDialog` | Authored body calls inherited `OnDestroy()` then `OnHide()`; compiler lowering restores vtables and chains through `DialogPane` base destruction. |
| `0x00551fa0-0x005520e5` | `OnAction` | Handles close, page previous/next, and head-slot selection actions, then refreshes preview/buttons. |
| `0x005538fe-0x00553914` | [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md) | Compiler-generated `+0xa0`/`+0xa4` inherited Pane-facet deleting-destructor adjustors. |
| `0x00553920-0x005539c3` | [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md) | Compiler-generated deleting wrapper; formal project source declares one virtual destructor rather than a scalar-deleting method. |

## Ownership Decision

Place the main class under `ui/dialogs/HeadSelectDialog.cpp`. It is a user-facing packet dialog rather than a generic image control, and it composes existing controls such as [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md), [UID:00006D][ImageButtonControlPane](by-class/ImageButtonControlPane.md), [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md), and [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md).

Do not pull adjacent `0x00552110+` functions into this file by address locality. IDA decompilation shows `0x00552110` installs [UID:0000OL][TextDialog](by-file/TextDialog.md) vtables and `0x00553610` installs an anonymous [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md) vtable; those are adjacent dialog implementations, not `HeadSelectDialog` methods.

## Source And Header Contract

- Source root: `NexusTK/ui/dialogs/HeadSelectDialog.cpp`; companion declaration: `NexusTK/ui/dialogs/HeadSelectDialog.h`.
- [UID:000062][HeadSelectDialog](by-class/HeadSelectDialog.md) emits `[[CHILDREN]]` into the source and the complete class declaration into the companion header. [UID:0001FI][0x00551030-0x005520e5.HeadSelectDialogCore](by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md) supplies the authored constructor, destructor, preview, page, button, and action method definitions.
- `HeadSelectDialog` directly derives only from `DialogPane`. Primary, `+0xa0` EventHandler-view, and `+0xa4` TimerHandler-view vtables arise from facets inherited through Pane/DialogPane, not from extra direct bases or explicit vptr fields.
- The complete object is `0x304` bytes: a `0x26c` DialogPane base followed by subtype at `+0x26c`, naturally aligned 32-bit price/request field at `+0x270`, NPC/object words, `0x44`-byte ObjectStatusBlob, page/selection state, preview pointer, ten head-button pointers, and three image-button pointers through `+0x300`. Natural alignment supplies `+0x26d..+0x26f`; no named source padding field is authored.
- The ordinary destructor source is `OnDestroy(); OnHide();`. C++ supplies `DialogPane` base destruction, while UID0001FL records generated vtable restoration, deleting flags, storage release, inherited-facet adjustors, and internal alignment.
- UID0003DA is the source-declared/generated-binary RTTI/vtable island regenerated from this class declaration and its virtual destructor; it is not a handwritten table in this module.

## Source-Placement Negative Evidence

- `MessageDialogs.cpp` owns the packet allocation/dispatch caller, not the HeadSelect implementation. `DialogPane.cpp` owns only inherited virtual/base behavior.
- Neighboring TextDialog/NexonclubProxy code, shared `DialogPane::RemoveControl`, compiler/runtime support, and historical Boost labels do not acquire this file's class source.
- No evidence supports a separate destructor source file, direct EventHandler/TimerHandler bases, explicit vptr storage, or handwritten deleting-wrapper flags.
- Exact PDB identifiers and historical compiler switches are unavailable; this limits final-perfect certainty but does not change the selected source/header root or runtime behavior.

## Evidence Notes

- Historical Wave3 metadata imported this class from `HeadSelectDialog.cpp`, reported grade `96.9`, and listed eight active methods plus two disabled thunks. It is retained only as historical context; current live IDA and current by-* documentation, not Wave3, support the accepted source route.
- IDA MCP confirms real function starts for all active methods and disabled thunks.
- IDA caller evidence shows the constructor at `0x00551520` is reached from a small allocation wrapper at `0x0054ca50`, which allocates `0x304` bytes before calling the constructor.
- B010 2026-07-01 support sync: [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) owns wrapper `0x0054ca50 -> new HeadSelectDialog(payload)` with allocation size `0x304`; this file keeps HeadSelect implementation, preview/page/action behavior, and layout-table ownership.
- 2026-06-12 live IDA MCP session `a001-b276` reconfirmed the wrapper disassembly (`push 304h`, then call `0x00551520` at `0x0054ca93`), constructor vtable stores to the three HeadSelect bases, and constructor-only xrefs to `DLGMSGH.EPF`.
- `PopulateHeadButtons` and `OnAction` call `ObjectImageButtonPane` highlight/constructor paths, matching the paged grid interpretation; IDA confirms `SetButtonHighlight` callers at `0x0055149a`, `0x0055209a`, and `0x005520c3`.
- The constructor calls packet readers, `DialogPane` setup, EPF image control construction, image button construction, object-image preview construction, static text construction, and `NewHumanImageLib` head-count behavior.
- 2026-06-12 A003 Batch 337 confirms [UID:00027Z][0x0066df00-0x0066ed20.HeadSelectDialogLayoutTablePrimary](by-memory/0x0066df00-0x0066ed20.HeadSelectDialogLayoutTablePrimary.md) is the normal-resolution head-offset table for this file's class: `RefreshHeadPreview`, `PopulateHeadButtons`, and the constructor are its only direct users, and [UID:000062][HeadSelectDialog](by-class/HeadSelectDialog.md) clears the strict parent gate.
- 2026-06-12 Agent-A002 Batch 338 confirms [UID:000281][0x0066eea0-0x0066fce4.HeadSelectDialogLayoutTableSecondary](by-memory/0x0066eea0-0x0066fce4.HeadSelectDialogLayoutTableSecondary.md) is the high-resolution companion table for this file's class: the same three HeadSelect methods consume it when `byte_66DA97 == 1`, and the constructor patches thirteen high-resolution tail offsets.
- 2026-06-18 Agent-B001 source-quality execution confirms local exported function starts at `0x00551250` and `0x005512d0` for private next/previous page helpers. Local exported vtable and OOAnalyzer sweeps found no caller/address-taken reference for either start, so this file treats them as retained private helpers while the virtual action handler keeps equivalent logic inline.
- The same pass records the file-level source model used by the formal draft: `g_useEpfAssets == 1` selects `s_highResHeadVerticalOffsets[913]`, high/current EPF preview/button rectangles, and thirteen high-res tail patches; other values select `s_normalHeadVerticalOffsets[904]`, normal/legacy rectangles, and three normal tail patches. The constructor uses the full dword table entry to compute the base draw offset, while refresh/populate use the low byte of each dword for the object-status head draw-offset byte.

## Current Caveats

- `0x0049dd00-0x0049dd17` is still emitted as `HeadSelectDialog::SwitchCategory`, but direct callers include fitting-room and other dialog code. Treat it as a shared dialog/control-list helper until final owner is resolved.
- 2026-05-24 recheck: current `class_HeadSelectDialog.cpp` starts with ASCII comment bytes and no longer shows visible mojibake before method install comments. Its autograder header still reports an `encoding BOM or mojibake artifact` penalty, so treat that as stale/noisy generated diagnostics rather than source text to preserve.
- 2026-05-25 recheck: disabled `class_HeadSelectDialog.cpp.disabled` still reports missing code for `0x00553909`, but IDA models it as an 11-byte `this -= 0xa4` adjustor thunk jumping to `0x00553920`; see the exact thunk page.
- The packet/dispatcher path around `0x0054ca50` is now documented as part of [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md).
- Exact original member names for packet subtype, price/request, NPC/object ids, and private page helpers remain inferred from behavior. Current source-facing names are documented in [UID:0001FI][0x00551030-0x005520e5.HeadSelectDialogCore](by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md) and are acceptable for first-draft C++ because no stronger binary evidence names them differently.

The prior disabled-output "missing code" description for `0x00553909` is superseded. Live IDA proves it is a complete compiler adjustor thunk, and the accepted virtual class/destructor source lets MSVC regenerate it without a handwritten body.

## Score Rationale

The file is `90/92` after the complete class/header/destructor pass. Module placement, message-dispatch boundary, full `0x304` class shape, direct/inherited-facet hierarchy, ordinary destructor source, compiler-generated ABI route, vtable/resource/table ownership, and exact neighboring exclusions are established. Remaining uncertainty is limited to unavailable original identifier spellings and build switches, plus the already isolated shared category-removal helper owner.

## Cross-References

- [UID:000062][HeadSelectDialog](by-class/HeadSelectDialog.md)
- [UID:0001FI][0x00551030-0x005520e5.HeadSelectDialogCore](by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md)
- [UID:0003DA][0x006228b8-0x00622954.HeadSelectDialogVtableData](by-memory/0x006228b8-0x00622954.HeadSelectDialogVtableData.md)
- [UID:0003DG][0x00622d08-0x00622d20.HeadSelectDialogDlgmsghString](by-memory/0x00622d08-0x00622d20.HeadSelectDialogDlgmsghString.md)
- [UID:00012T][0x0049dd00-0x0049dd17.DialogCategorySwitch](by-memory/0x0049dd00-0x0049dd17.DialogCategorySwitch.md)
- [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md)
- [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md)
- [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md)
- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)
- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0000OL][TextDialog](by-file/TextDialog.md)
- [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md)
- [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md)

## Changes

- 2026-07-26 Agent-B003 UID0001FL implementation callback:
  - Raised `88/88` to `90/92` and documented the complete `HeadSelectDialog.cpp` plus companion `.h` source root.
  - Added class-emitter routing, exact ordinary-destructor/compiler-support split, direct DialogPane/inherited Pane-facet hierarchy, natural `0x304` layout contract, source-placement negative evidence, and corrected historical disabled/Wave3 context.

- 2026-07-01 Agent-B010 implementation callback: added support note for [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) wrapper `0x0054ca50 -> new HeadSelectDialog(payload)` and allocation size `0x304`, while preserving HeadSelect implementation ownership.
- 2026-06-02: Set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/dialogs/` so reviewed `HeadSelectDialog` data/memory pages can attach without projected-path errors.
  - Evidence: the page already proposes `ui/dialogs/HeadSelectDialog.cpp`, and its ownership decision keeps the class under packet-driven UI dialogs rather than create-user or generic image-control modules.
- Before: `HeadSelectDialog` core and `OnAction` ended at `0x005520e4`, and the `0x0054ca50` wrapper path was unnamed.
- Changed to: the core/action range ends at `0x005520e5`, and the `0x0054ca50` wrapper is part of the message-dialog dispatcher/wrapper island.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows the old endpoint omitted the final `retn 8` operand byte, and the wrapper at `0x0054ca50-0x0054caa9` allocates `0x304` bytes before calling the `HeadSelectDialog` constructor.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:80`.
  - Summary/evidence: core dialog behavior, function map, packet-driven preview/page/action handling, destructor support, wrapper path, and resource/control dependencies are documented; confidence is capped by the shared category-switch helper owner and generated-data caveats.
- 2026-06-12 Agent-A002 Batch 282:
  - What existed before: `86/80`; the page had the main class map and wrapper path but did not reflect exact HeadSelect vtable/string child routing, and confidence stayed below the strict parent-chain gate because shared helper ownership was over-weighted.
  - Changed to: `87/86`; added exact vtable/string children, refreshed live wrapper/vtable/resource evidence, and clarified that the shared category helper remains a caveat without blocking source-file ownership for the HeadSelect class.
  - Assignment effect: [UID:000062][HeadSelectDialog](by-class/HeadSelectDialog.md) can remain attached to this file under the strict `85/85` gate, enabling [UID:0003DA][0x006228b8-0x00622954.HeadSelectDialogVtableData](by-memory/0x006228b8-0x00622954.HeadSelectDialogVtableData.md) and [UID:0003DG][0x00622d08-0x00622d20.HeadSelectDialogDlgmsghString](by-memory/0x00622d08-0x00622d20.HeadSelectDialogDlgmsghString.md) to route through the class.
- 2026-06-12 A003 Batch 337:
  - Added the routed primary layout-table child [UID:00027Z][0x0066df00-0x0066ed20.HeadSelectDialogLayoutTablePrimary](by-memory/0x0066df00-0x0066ed20.HeadSelectDialogLayoutTablePrimary.md). Scores remain `87/86`; this file was already above the strict gate.
  - Evidence: IDA MCP decompilation shows the table is consumed only by the HeadSelect preview refresh, head-button population, and constructor normal-resolution branch.
- 2026-06-12 Agent-A002 Batch 338:
  - Added the routed secondary/high-resolution layout-table child [UID:000281][0x0066eea0-0x0066fce4.HeadSelectDialogLayoutTableSecondary](by-memory/0x0066eea0-0x0066fce4.HeadSelectDialogLayoutTableSecondary.md). Scores remain `87/86`; this file was already above the strict gate.
  - Evidence: IDA MCP decompilation shows the table is consumed only by the HeadSelect preview refresh, head-button population, and constructor high-resolution branch.
- 2026-06-18 Agent-B001 source-quality report executed by supervisor:
  - Before: `87/86`; function map omitted `0x00551250` and `0x005512d0`, packet/member/control/layout source names were not carried at file level, and confidence was still capped by unresolved draft-C++ blockers.
  - After: `88/88`; file docs include the private page helpers, packet-derived field model, source-facing head-offset table names, `g_useEpfAssets` branch model, and first-draft C++ readiness while preserving the shared `DialogCategorySwitch` caveat.
