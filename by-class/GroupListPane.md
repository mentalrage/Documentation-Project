*** UID:00005X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "Group.h"
#include "../ui/panels/UserPane.h"
#include "../render/NewHumanImageLib.h"
#include "../render/PaletteLib.h"
#include "../render/ImageLib.h"
#include "../render/Surface.h"
#include <windows.h>
#include <wchar.h>

class Event;

class GroupListPane : public TextEditPane
{
public:
    GroupListPane();

protected:
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnMouseEvent(Event *event);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# GroupListPane

## Status

- Confidence: very strong for class identity, object size, raw constructor bytes, vtable identity, parent inline-construction parity, `Group.cpp` source placement, target-level constructor C++ readiness, corrected helper/global semantics, and resolved false virtual roles. The formal C++ block now carries the complete bounded source-legal declaration plus `[[CHILDREN]]`; unresolved broader TextEditPane constructor parameter spellings do not block this class surface.
- Likely source file: [UID:0000JS][Group](by-file/Group.md)
- Memory evidence: [UID:0001H8][0x0056baa0-0x0056bafd.GroupListPaneRawConstructor](by-memory/0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md), [UID:0001H9][0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs](by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md), exact vtable data [UID:0002NI][0x00624210-0x006242c4.GroupListPaneVtableData](by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md), and [UID:0001XP][GroupPaneFamilyVtables](by-type/by-vtable/GroupPaneFamilyVtables.md); nearby [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md) constructor is not clean group ownership.
- Generated recovery hint: `source-3/simroot_v2/class_GroupListPane.cpp`; use as a lead only because IDA has no auto-function at the projected constructor start.

## Class Purpose

`GroupListPane` is the list/text child used by the older `GroupPane` and `GroupPane2` shells. The raw constructor at `0x0056baa0` initializes a text-edit style pane and installs `GroupListPane` vtables at offsets `0`, `0xa0`, and `0xa4`. IDA does not auto-model this start as a function, but the bytes form a normal constructor island and the same setup is inlined inside both parent pane constructors.

The source-level reconstruction preserves a thin `TextEditPane`-derived `GroupListPane` child type under [UID:0000JS][Group](by-file/Group.md), while keeping the nearby `SpelledPane` constructor at `0x0056bb20` outside the class. The narrow constructor page [UID:0001H8][0x0056baa0-0x0056bafd.GroupListPaneRawConstructor](by-memory/0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md) carries first-draft constructor C++. The false virtuals page [UID:0001H9][0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs](by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md) emits `GroupListPane::HandleKeyOrTextEvent(Event *event)` and `GroupListPane::OnMouseEvent(Event *event)`. The bounded declaration requires no class-local fields and does not freeze unrelated TextEditPane constructor parameter/enum spellings.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GroupListPane` | `0x0056baa0-0x0056bafd` | Raw constructor island; IDA reports no auto-function at the start. |
| `HandleKeyOrTextEvent`, `OnMouseEvent` | `0x0056bb00`, `0x0056bb10` | IDA-confirmed one-argument bool virtual stubs returning false; `HandleKeyOrTextEvent` is the secondary EventHandler `+0x08` dispatch override, and `OnMouseEvent` is the primary `+0x60` override. |
| nearby constructor-like function | `0x0056bb20-0x0056bbdb` | IDA-confirmed `SpelledPane`/text-edit construction called from other UI code; ownership is not settled. |

## Constructor And Inline Setup

[UID:0001H8][0x0056baa0-0x0056bafd.GroupListPaneRawConstructor](by-memory/0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md) records the standalone raw constructor-shaped body. It loads [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md) / `dword_67AB24`, calls [UID:0003XA][0x004b60b0-0x004b60bd.IsLegacyAssetMode](by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md) (`sub_4B60B0`) as a `g_useEpfAssets` / `byte_66DA97` legacy-mode query, calls [UID:0002ZY][0x0058dce0-0x0058e132.TextEditPaneConstructor](by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md) with fixed group-list dimensions `145 x 84`, installs the three `GroupListPane` vtable views, returns `this`, and ends at `0x0056bafd` followed by `0xcc` alignment.

B007's accepted 2026-06-25/2026-06-26 implementation evidence keeps the raw/no-xref caveat but removes it as a target-level C++ blocker: live MCP session `80de0a67` reconfirmed no IDA function or inbound refs at `0x0056baa0` / `0x0056bafd`, no pointer bytes to the raw start, unique constructor bytes, and the same three vtable-store xref sets in the raw island plus the two inline parent constructors. The constructor page now emits the source-shaped body in its managed C++ block. That target-level code intentionally omits compiler vtable stores, `return this`, the raw `g_pFontImageLib` `ecx` load, and parent-only `Pane::SetMode(1)` / `sub_58EA80` setup. The no-direct-xref raw boundary remains a score cap for the class, not a reason to keep the constructor target blank.

The same memory page also records that `GroupPane` and `GroupPane2` inline the same child setup inside their constructors: both allocate a `0x174`-byte child, run the same `IsLegacyAssetMode()` / `TextEditPane::TextEditPane(...)` setup sequence, install the same three vtables, store the child at parent offset `+0xf8` as `GroupListPane *m_groupListPane`, enable it through [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md), and position/update it through a role-level `TextEditPane` editability/activation helper (`sub_58EA80`). This makes `GroupListPane` a real source-level child type even though the standalone constructor start is a raw/manual boundary.

## Touched State And ABI Evidence

| State / data | Evidence | Class-level meaning |
| --- | --- | --- |
| [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md) / `dword_67AB24` | Read by the raw constructor and by the inline child construction paths in `GroupPane` / `GroupPane2`. | Global `FontImageLib *` load before text-list setup; current helper evidence does not prove `IsLegacyAssetMode()` dereferences it. |
| [UID:0003XA][0x004b60b0-0x004b60bd.IsLegacyAssetMode](by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md) / `sub_4B60B0` | Called by the raw and inline construction paths before the base setup call. | No-argument mode query returning `byte_66DA97 != 1`; the result is passed into `TextEditPane::TextEditPane` as a display/layout mode flag, not a resource/context pointer. |
| [UID:0002ZY][0x0058dce0-0x0058e132.TextEditPaneConstructor](by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md) / `sub_58DCE0` | Called with the same `145 x 84` and flag pattern in all three construction forms. | Text-edit/list base construction for the group-list child; exact parameter names remain support-owned. |
| [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) / `sub_5446B0` | Called by parent inline setup with mode `1`. | Enables the child pane and invalidates as needed. |
| `sub_58EA80` | Called by parent inline setup after enabling/positioning the child. | Role-level `TextEditPane` editable/active mode setter; exact source name remains unresolved. |
| `0x00624214`, `0x0062428c`, `0x006242bc` | Exact vtable stores recorded in [UID:0001H8][0x0056baa0-0x0056bafd.GroupListPaneRawConstructor](by-memory/0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md) and exact data range [UID:0002NI][0x00624210-0x006242c4.GroupListPaneVtableData](by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md). | Primary, secondary, and tertiary `GroupListPane` vtable views. |
| `0x0056bb00`, `0x0056bb10` | [UID:0001H9][0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs](by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md) records two five-byte `return false` virtual stubs referenced only from vtable slots. | Confirms source-declared bool overrides/default handlers: `GroupListPane::HandleKeyOrTextEvent(Event *event)` and `GroupListPane::OnMouseEvent(Event *event)`. |
| `0x0056bb20` | [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md) has non-group callers. | Keep the following text/spelled pane constructor out of `GroupListPane` ownership. |

## Source Quality / Inference Notes

- Best source-facing role: a thin `TextEditPane` specialization for the older `GroupPane` / `GroupPane2` list child. No class-local fields beyond inherited layout are currently proved; parent offset `+0xf8` is the `GroupListPane *m_groupListPane` child field.
- The stale model "`sub_4B60B0` returns a resource/context pointer" is rejected. Accepted support docs resolve it as `IsLegacyAssetMode()` / `IsLegacyUiMode()`-style behavior, reading [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) and returning true for the legacy/non-EPF case.
- The standalone raw constructor is not arbitrary data and not a pure generated artifact: exact prologue/body/epilogue, vtable stores, `TextEditPane` construction, padding, and inline parent-construction parity prove source-level class logic. Do not overstate it as directly called, because saved evidence still has no direct xref to `0x0056baa0`.
- The two [UID:0001H9][0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs](by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md) are resolved one-argument false-return bool virtual overrides. `0x0056bb00` is the secondary EventHandler `+0x08` dispatch override, exact source-facing name `GroupListPane::HandleKeyOrTextEvent(Event *event)`, and `0x0056bb10` is the primary `+0x60` mouse-event override, `GroupListPane::OnMouseEvent(Event *event)`. Historical `OnKeyDown` and earlier generic action/query sketches are superseded.
- Keep owner/emitter [UID:0000JS][Group](by-file/Group.md). Rejected owners include [UID:0000ON][TextEditPane](by-file/TextEditPane.md), [UID:0000JH][FontImageLib](by-file/FontImageLib.md), [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), [UID:0000DK][SpelledPane](by-class/SpelledPane.md), `ScrollNewGroupPane`, and broad UI core.
- Class-page C++ is the complete bounded declaration with `[[CHILDREN]]`. It declares the proven `TextEditPane` base, constructor, and two protected bool overrides without inventing local fields, a destructor override, or unresolved helper APIs. The constructor method body lives on [UID:0001H8][0x0056baa0-0x0056bafd.GroupListPaneRawConstructor](by-memory/0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md), and the false virtual bodies emit from [UID:0001H9][0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs](by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md).

## Evidence Notes

- IDA MCP reports no function at `0x0056baa0`, but raw disassembly from `0x0056baa0-0x0056bafd` shows a constructor prologue/body/epilogue and vtable installs.
- `xrefs_to` the `GroupListPane` vtables `0x00624214`, `0x0062428c`, and `0x006242bc` lands in the raw constructor and in the inline child construction inside `GroupPane` and `GroupPane2`.
- 2026-05-31 IDA MCP confirms the exact vtable-data child [UID:0002NI][0x00624210-0x006242c4.GroupListPaneVtableData](by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md): the range starts at the primary RTTI locator and ends before neighboring `SpelledPane` RTTI at `0x006242c4`.
- IDA MCP confirms real nearby functions at `0x0056bb00`, `0x0056bb10`, and `0x0056bb20`.
- IDA decompilation for `0x0056bb20` installs `SpelledPane` vtables and is called from non-group UI functions, so it should not be treated as a clean group-only constructor without more xref/type evidence.
- 2026-06-11 Batch 232 IDA MCP reconfirmed no IDA function at raw constructor start `0x0056baa0`, five-byte virtual stubs at `0x0056bb00-0x0056bb05` and `0x0056bb10-0x0056bb15`, vtable bases `0x00624214`, `0x0062428c`, and `0x006242bc`, raw stores at `0x0056badc`, `0x0056bae4`, `0x0056baee`, inline stores from `GroupPane`/`GroupPane2`, and the `SpelledPane` RTTI boundary at `0x006242c4`.

## Autogen Handling

Attach this class to [UID:0000JS][Group](by-file/Group.md). The parent is `90/86`, and this class is `88/90`, so the class and source owner satisfy the strict parent-attachment gate. The complete bounded declaration plus `[[CHILDREN]]` supplies the source-legal class surface; constructor and false virtual bodies remain on their exact children.

## Score Rationale

Completion is `88` because the class page records raw constructor behavior, target-level constructor C++ routing, inline parent construction parity, vtable/stub ABI evidence, corrected helper/global semantics, resolved false virtual roles, object size, parent child-field ownership, SpelledPane/LegendPane boundary exclusions, source-owner attachment, exact vtable-data routing through [UID:0001XP][GroupPaneFamilyVtables](by-type/by-vtable/GroupPaneFamilyVtables.md), and a complete bounded declaration. Confidence is `90` because the raw bytes, vtable stores, inline construction, exact vtable-data child, source parent, and virtual-role resolution are IDA/MCP-backed in linked pages; it remains below final-audit confidence because the constructor is still a manual/no-direct-xref boundary and broader inherited helper spellings remain stripped.

## Cross-References

- [UID:0000JS][Group](by-file/Group.md)
- [UID:0001H8][0x0056baa0-0x0056bafd.GroupListPaneRawConstructor](by-memory/0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md)
- [UID:0001H9][0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs](by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md)
- [UID:0002NI][0x00624210-0x006242c4.GroupListPaneVtableData](by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md)
- [UID:0001XP][GroupPaneFamilyVtables](by-type/by-vtable/GroupPaneFamilyVtables.md)
- [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](by-memory/0x0056c4c0-0x0056e939.GroupPanes.md)
- [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md)
- [UID:00005Y][GroupPane](by-class/GroupPane.md)
- [UID:00005Z][GroupPane2](by-class/GroupPane2.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-08-16 B003 UID0003F8 accepted callback: installed the exact UID0000JS-owned eight-include `Group.cpp` translation-unit preamble in this first routed emitter so it appears before all Group class/method children. This is a mechanical emitter-carrier role only: UID0000JS remains the source-root owner, this class retains 88/90 and its existing constructor/virtual-stub scope, and UID0004Z5 remains method-body-only with no embedded includes.
- 2026-07-16 B001 UID00023W accepted callback: replaced the historical no-class placeholder with the complete bounded `TextEditPane`-derived declaration, synchronized exact bool `HandleKeyOrTextEvent`/`OnMouseEvent` contracts, and preserved all constructor, layout, ownership, boundary, and score evidence.
- 2026-06-30 B002 Group empty-emitter implementation:
  - Inserted the formal no class-level C++ body marker plus `[[CHILDREN]]` so exact child by-memory bodies still assemble under the class route.
  - Updated current prose from blank class-level C++ to marker disposition while preserving declaration/header polish caveats and child method emission routes.
- 2026-06-26 B001 implementation callback for [UID:0001H9][0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs](by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md):
  - Changed score from `87/89` to `88/90`; owner/emitter remains [UID:0000JS][Group](by-file/Group.md), and class-level C++ remains blank.
  - Resolved the false virtual role blocker: `0x0056bb00` is `GroupListPane::OnKeyDown(Event *event)`, and `0x0056bb10` is `GroupListPane::OnMouseEvent(Event *event)`.
  - Evidence: B001 MCP session `80de0a67` confirmed unique vtable pointer hits and compared the slots against `ScrollablePane` / `TextEditPane`, while rejecting the earlier generic action/query sketches.
- 2026-06-26 B007 implementation callback:
  - Score unchanged at `87/89`.
  - Updated class-level wording after [UID:0001H8][0x0056baa0-0x0056bafd.GroupListPaneRawConstructor](by-memory/0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md) was raised to `89/91`, `Nested:0`, and given formal constructor C++.
  - Preserved the class-level blank-C++ decision, but narrowed the blocker to false virtual slot names, exact helper spelling, and declaration polish; the target-level constructor body is no longer blocked by the old `TextEditPane` signature or 95/95 gate wording.
- 2026-06-11 Agent-A001 Batch 232: Raised from `80/84` to `85/86`.
  - Before: the page did not clear the strict 85/85 gate and still referenced stale parent scores.
  - After: updated the parent-gate rationale against [UID:0000JS][Group](by-file/Group.md) at `89/85`, recorded the Batch 232 live IDA refresh, and tied the exact vtable child routing to [UID:0001XP][GroupPaneFamilyVtables](by-type/by-vtable/GroupPaneFamilyVtables.md).
  - Evidence: live IDA MCP reconfirmed the manual raw constructor boundary, three vtable-store sets from raw and inline construction, the two five-byte virtual stubs, and the `SpelledPane` boundary.
- 2026-06-20 B001 Rule 26 incorporation:
  - Before: `85/86` and still contained stale `sub_4B60B0` resource/context wording.
  - Changed to: `87/89`; owner/emitter remains [UID:0000JS][Group](by-file/Group.md), and class C++ remains blank.
  - Evidence: B001 reanalysis corrected `sub_4B60B0` to `IsLegacyAssetMode()` / `g_useEpfAssets` semantics, preserved `g_pFontImageLib` as a call-site load, documented `TextEditPane::TextEditPane`, `Pane::SetMode(1)`, and `sub_58EA80` roles, recorded object size `0x174`, parent `+0xf8` child ownership, one-argument false virtual stubs, source-placement and rejected-owner decisions, and exact no-code rationale.
- 2026-06-07: Raised `75/82` to `80/84` and attached `AUTOGEN_PARENT_UID:0000JS`. The page now records the raw constructor behavior, inline setup parity in `GroupPane` and `GroupPane2`, touched state, vtable/stub evidence, `SpelledPane` exclusion, parent-attachment rationale, and final-source blockers. Evidence comes from [UID:0001H8][0x0056baa0-0x0056bafd.GroupListPaneRawConstructor](by-memory/0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md), [UID:0001H9][0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs](by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md), [UID:0002NI][0x00624210-0x006242c4.GroupListPaneVtableData](by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md), and [UID:0000JS][Group](by-file/Group.md).
- Completion/confidence score update: existed before as `0/0`; changed to `70/68`. Summary: raw constructor island, vtable installs, parent inline construction, virtual stubs, and nearby SpelledPane ownership caveat are documented, but the class boundary is only medium-confidence. Evidence: raw constructor page `0x0056baa0-0x0056bb00`, virtual stub page, `GroupPaneFamilyVtables`, parent `GroupPanes` page, and explicit IDA no-function/nearby-function notes.
- 2026-05-31: Added exact vtable-data child and raised metadata from `70/68` to `75/82`.
  - Before: class confidence was capped partly because vtable data was only covered through the broad family page.
  - After: exact vtable-data bounds are linked and IDA-confirmed, while completion remains below final-source level because the raw constructor boundary and final source declaration still need more work.
  - Evidence: IDA MCP `py_eval` and `xrefs_to` checks on `0x00624210-0x006242c4` confirmed the RTTI boundaries and constructor/inline-construction stores.
