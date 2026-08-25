*** UID:0000JS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/social/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Group

## Status

- Confidence: strong for `NewGroupPane`, `GroupPane`, `GroupPane2`, `GroupListPane` class identity and bounded declaration, exact group vtable children, group packet/list behavior, group marker helpers, target-level `GroupListPane` constructor C++ routing, resolved `GroupListPane` false virtual roles, and the 2026-06-30 empty-emitter family repair that gives formal first-draft C++ to the remaining executable/helper rows; medium-high for exact broader source splits.
- Proposed module folder: `social/`
- Proposed source file: `social/Group.cpp`
- Possible split files: `social/GroupPane.cpp`, `social/GroupChatInput.cpp`, [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md), and [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- Evidence basis: existing by-memory/by-class documentation and IDA MCP function-boundary, vtable, destructor, and decompilation checks.
- Parent gate: this file now clears the corrected 85/85 gate for [UID:00005Z][GroupPane2](by-class/GroupPane2.md) and other exact group-pane class children that independently clear the child side.

## Hypothesis

The original group/party UI likely had a feature-owned source file for the visible group panes, packet parsing, group member drawing, and map-marker synchronization. `NewGroupPane` is the strongest anchor: it constructs the custom scroll child, requests group lists with opcode `0x2d`, parses the server member list, draws names/levels/HP/MP rows, toggles expanded mode, and updates map markers through `MapPane`.

`GroupPane` and `GroupPane2` look like older or alternate group list shells. They allocate a `0x174`-byte `GroupListPane` text-list child, refresh a fixed list viewport, and paint the `GROUP.EPF` background/tab graphic.

`SayToGroupMessageInputPane` is feature-related because it targets group chat, but current source-route evidence keeps it with the broader `SayInputPanes.cpp` target-message input family rather than the main group pane file. `GroupInputPane` is already documented with command input panes because its confirmed function sends generic group-command opcode `0x2e` from a line prompt and is separate from the target-message class.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `GroupPane` | `0x0056c4c0-0x0056c750`, destructor `0x00573490-0x0057353d`; exact OnPaint child [UID:00050R][0x0056c6c0-0x0056c731.GroupPaneOnPaint](by-memory/0x0056c6c0-0x0056c731.GroupPaneOnPaint.md) | `class_GroupPane.cpp` evidence routed into `NexusTK/social/Group.cpp` | Older group panel shell with a `GroupListPane`/text child, fixed list viewport refresh, and exact `TABS.PAL` plus `GROUP.EPF` frame-0 paint override. |
| `GroupPane2` | `0x0056c770-0x0056ca00`, destructor `0x005733e0-0x0057348d`; exact OnPaint child [UID:00050S][0x0056c970-0x0056c9e1.GroupPane2OnPaint](by-memory/0x0056c970-0x0056c9e1.GroupPane2OnPaint.md) | `class_GroupPane2.cpp` evidence routed into `NexusTK/social/Group.cpp` | Alternate group panel shell with the same list viewport behavior and the corresponding exact `TABS.PAL` plus `GROUP.EPF` frame-0 paint override; historical `DrawTabBackground` wording is superseded by the vtable-backed OnPaint identity. |
| `LegendPane` boundary false virtual stubs | `0x0056c4a0-0x0056c4b5` | boundary context only | Two tiny `LegendPane` `return false` vtable targets immediately before the `GroupPane` constructor range; keep them in [UID:00023W][0x0056c4a0-0x0056c4b5.LegendPaneInputFalseOverrides](by-memory/0x0056c4a0-0x0056c4b5.LegendPaneInputFalseOverrides.md) and do not treat them as `Group.cpp` source content. |
| `NewGroupPane` | `0x0056ca20-0x0056e939`, destructor/thunks at `0x0057329f`, `0x005732aa`, `0x00573570-0x00573634` | `class_NewGroupPane.cpp` | Main group management pane: request list, layout, render rows, handle input, parse group list packets, update scroll range, and toggle expanded mode. |
| `ScrollNewGroupPane` | core split index [UID:0001GP][0x00560900-0x0056141f.ScrollNewGroupPaneCore](by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md), exact core children [UID:00044X][0x00560900-0x005609a1.ScrollNewGroupPaneConstructor](by-memory/0x00560900-0x005609a1.ScrollNewGroupPaneConstructor.md) through [UID:000456][0x00560d40-0x00561420.ScrollNewGroupPaneOnPaint](by-memory/0x00560d40-0x00561420.ScrollNewGroupPaneOnPaint.md) plus raw helper children [UID:0004I3][0x00560ac0-0x00560ada.ScrollNewGroupPaneHideRaw](by-memory/0x00560ac0-0x00560ada.ScrollNewGroupPaneHideRaw.md) and [UID:0004I5][0x00560ae0-0x00560afa.ScrollNewGroupPaneCanAdjustRaw](by-memory/0x00560ae0-0x00560afa.ScrollNewGroupPaneCanAdjustRaw.md), hit-test [UID:0001GQ][0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart](by-memory/0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart.md), part rect [UID:0001GR][0x00561740-0x005619c7.ScrollNewGroupPanePartRect](by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md), interaction split [UID:0001GS][0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers](by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md) | `class_ScrollNewGroupPane.cpp` source route through [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md) into `NexusTK/social/Group.cpp` | Custom EPF-backed scrollbar used by `NewGroupPane`; core and interaction aggregate ranges are non-emitting split indexes, source-ready children carry formal first-draft C++, and raw no-entry setter rows carry formal no-standalone markers. Group source imports `../ui/core/ScrollBar.h` for the one shared `kScrollPanePartExtentBySkin` declaration and does not define a local copy. |
| `GroupListPane` | raw [UID:0001H8][0x0056baa0-0x0056bafd.GroupListPaneRawConstructor](by-memory/0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md), real [UID:0001H9][0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs](by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md), nearby [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md) | `class_GroupListPane.cpp` recovered artifact; source stays in this feature file | Thin `TextEditPane`-derived group-list child; B007's 2026-06-25/26 live MCP pass reconfirmed the raw no-function constructor island, no start/end xrefs or pointer bytes, unique signature, exact `TextEditPane` base-initializer constants, and inline `GroupPane`/`GroupPane2` parity. [UID:0001H8][0x0056baa0-0x0056bafd.GroupListPaneRawConstructor](by-memory/0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md) carries first-draft `GroupListPane::GroupListPane()` C++; [UID:0001H9][0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs](by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md) emits bool `GroupListPane::HandleKeyOrTextEvent(Event *event)` and bool `GroupListPane::OnMouseEvent(Event *event)`. The class page carries the complete bounded declaration. |
| `SayToGroupMessageInputPane` | `0x005b1ec0-0x005b2152` | `class_SayToGroupMessageInputPane.cpp` | Feature cross-reference only under current evidence; direct owner/source route remains [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md). It stores `m_groupName[128]`, prompts `Group => `, and sends opcode `0x19` group-name/message bytes through `g_packetSender`. |
| `GroupInputPane` | `0x005b5440-0x005b5547`, projected constructor `0x005b5400` | `class_GroupInputPane.cpp` | Generic group command prompt; see [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md). This command-input class sends opcode `0x2e` and is separate from `SayToGroupMessageInputPane`. |
| `RefreshGroupMemberMarkers` | `0x005adc20-0x005adc63` | `NexusTK/social/Group.cpp` | Replays cached UserPane group-member ids through [UID:0003TB][0x0050e4c0-0x0050e68d.MapPaneRefreshGroupMemberHitBar](by-memory/0x0050e4c0-0x0050e68d.MapPaneRefreshGroupMemberHitBar.md) `MapPane::RefreshGroupMemberHitBar`. |
| `ClearGroupMemberMarkers` | `0x005adc70-0x005adcb3` | `NexusTK/social/Group.cpp` | Replays cached UserPane group-member ids through [UID:0003TD][0x0050e810-0x0050e848.MapPaneRemoveGroupMemberHitBar](by-memory/0x0050e810-0x0050e848.MapPaneRemoveGroupMemberHitBar.md) `MapPane::RemoveGroupMemberHitBar`. |

## GROUP.EPF Paint-Emitter Closure - 2026-08-14

[UID:0003F0][0x00624a84-0x00624a98.GroupPaneGroupEpfResourceString](by-memory/0x00624a84-0x00624a98.GroupPaneGroupEpfResourceString.md) is the one 20-byte pooled UTF-16LE `GROUP.EPF\0` cell used by three Group-family paint methods. The source module repeats `L"GROUP.EPF"` at each lookup rather than declaring a synthetic source object:

| Source order | Exact child/source | Binary proof | Group.cpp disposition |
| ---: | --- | --- | --- |
| 1 | [UID:00050R][0x0056c6c0-0x0056c731.GroupPaneOnPaint](by-memory/0x0056c6c0-0x0056c731.GroupPaneOnPaint.md) through [UID:00005Y][GroupPane](by-class/GroupPane.md), class position `40` | `[0x0056c6c0,0x0056c731)`, 113 bytes, SHA256 `60A9066D737851AF85F810A77E699BC4C6A522A3005762FD2EEFE75C1826F8E3`, literal xref `0x0056c6fd`, vtable slot `0x00624480` | Complete `void GroupPane::OnPaint()` resolves `TABS.PAL`, loads `GROUP.EPF` frame 0, and blits into `m_visibleBounds`. |
| 2 | [UID:00050S][0x0056c970-0x0056c9e1.GroupPane2OnPaint](by-memory/0x0056c970-0x0056c9e1.GroupPane2OnPaint.md) through [UID:00005Z][GroupPane2](by-class/GroupPane2.md), class position `40` | `[0x0056c970,0x0056c9e1)`, 113 bytes, SHA256 `FD4698757D9BFFA6D1FFD9254A7BD71D28566ACAE9B6DE5E87F4BF01FB95BDAE`, literal xref `0x0056c9ad`, vtable slot `0x0062450c` | Complete `void GroupPane2::OnPaint()` is the structural twin; old `DrawTabBackground` prose is historicalized. |
| 3 | [UID:0004Z5][0x0056ce50-0x0056da03.NewGroupPaneOnPaint](by-memory/0x0056ce50-0x0056da03.NewGroupPaneOnPaint.md) through [UID:000090][NewGroupPane](by-class/NewGroupPane.md) | Literal xref `0x0056cf39`, vtable slot `0x00624598`, existing accepted formal/generated source | Existing complete `void NewGroupPane::OnPaint()` selects `GROUP.EPF` on the normal branch. |

The pooled data page contributes only a formal covered-by marker. It emits no `wchar_t` object, member, global, array, macro, address, or method body. Both focused method children intentionally have blank H channels because a standalone method fragment cannot validly emit `virtual void OnPaint();` outside complete class declarations. The GroupPane class marker gains one CPP child token; GroupPane2 retains its existing single token. Generated acceptance requires all three complete method bodies, exactly three actual `L"GROUP.EPF"` expressions inside those bodies, no empty child emitter, no UID0003F0 data definition, and no new free-standing H declaration.

[UID:00042L][0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw](by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md) is a retained `ScrollNewGroupPane::SetHighlightedPart` source method in this `Group.cpp` route, not a separate source file. Its exact out-of-line body remains emitted by the child through [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md). Catalog entry0369 now models the exact target and `GetPartRect` functions with the accepted class/enum ABI and comments while preserving the target's zero static entry route. `ScrollNewGroupPane::HandleMouseEvent` contains constant-thumb `[0x00560bfd,0x00560c3a)` and constant-none `[0x00560b5f,0x00560b87)` lowerings of the same highlight transition; this is compiler retention/inlining evidence, not a reason to move or suppress the child.

## GROUPCOL Resource And Percent-Format Emitter Closure - 2026-08-15

[UID:0003F2][0x00624b30-0x00624b74.NewGroupPaneCollectionResourceStrings](by-memory/0x00624b30-0x00624b74.NewGroupPaneCollectionResourceStrings.md) is exact `[0x00624b30,0x00624b74)`, 68 bytes, SHA256 `1A235EB91D69386B623C22DA79C998C57E1BE65D661B4F0116412783FF64EAE4`. It remains one class-owned physical child because every source-bearing literal has the same sole consumer and no-object disposition.

| Physical/source entity | Exact binary evidence | `Group.cpp` disposition |
| --- | --- | --- |
| `L"GROUPCOL.EPF"` | `[0x00624b30,0x00624b4a)`, 26 bytes, SHA256 `07075DA84F0379446E4E9F7099EA31150EE70CB9CDE9D57A7B30B84EBFC5DB10`; sole xref `0x0056d012`, push SHA256 `72327BA38DFC654E8B33769E0FF8B5ED903A3743E842A446B7B7D50EAE5A3035` | Existing [UID:0004Z5][0x0056ce50-0x0056da03.NewGroupPaneOnPaint](by-memory/0x0056ce50-0x0056da03.NewGroupPaneOnPaint.md) row-frame lookup expression. |
| `L"GROUPCOL.PAL"` | `[0x00624b4c,0x00624b66)`, 26 bytes, SHA256 `CD25106123888EC2D00DC6F8AC8721CC2A360EA44D52FD4E4F681B1877BE4BCD`; sole xref `0x0056d04c`, push SHA256 `F8B34BB1A3468F62BA40EADF46FBD55EB2DD722763A0DB5B42C4661C1735D096` | Existing UID0004Z5 row-frame palette expression. |
| Two `L"%d%%"` expressions | Complete source envelope `[0x00624b68,0x00624b72)`, 10 bytes, SHA256 `C5D4AD672797CF035D26435DBE8CE61F75C2D279B025C91B92F867724E8B87EF`; HP/MP xrefs `0x0056d5c6` and `0x0056d884`, each push SHA256 `DBC18A9C9017F8C30C0A0493FC5F0EE05646666C32EEDBCAED9B3045B3304A7A` | Existing UID0004Z5 HP and MP percentage formatting expressions. The IDA `%d` head plus unnamed `%%\0` suffix is one source literal. |
| Three two-byte zero alignments | `[0x00624b4a,0x00624b4c)`, `[0x00624b66,0x00624b68)`, `[0x00624b72,0x00624b74)`; each SHA256 `96A296D224F285C67BEE93C30F8A309157F0DAA35DC5B87E410B78630A09CFC7`, zero xrefs | Non-source padding; no emitted definition. |

All four xrefs are inside UID0004Z5 `[0x0056ce50,0x0056da03)`, current type `void __thiscall(NewGroupPane *this)`. Canonical owner/emitter is [UID:000090][NewGroupPane](by-class/NewGroupPane.md), and UID0003F2 enters its CPP child stream at position `75`, after OnPaint position `70` and before the next method position `80`. The complete route is UID0003F2 -> UID000090 -> UID0000JS -> `NexusTK/social/Group.cpp`.

The target emits only its exact three-line covered-by marker. `NewGroupPane::OnPaint` retains one EPF literal, one PAL literal, and two percent-format expressions; no standalone `wchar_t` object, member, global, table, macro, pointer, duplicate paint body, synthetic file, or per-literal child is emitted. UID0003F2 H is blank because there is no declaration; `Group.h` changes only through existing class declarations and receives zero target declarations.

Generated acceptance is exact: `Group.cpp` must contain one `L"GROUPCOL.EPF"`, one `L"GROUPCOL.PAL"`, two `L"%d%%"` expressions, one non-empty UID0003F2 covered-by marker, and zero UID0003F2 empty-emitter markers. `Group.h` must contain zero UID0003F2 markers and zero target declarations. This closure preserves Group at `91/88` and does not change unrelated file inventory.

## NewGroupPane Percentage Scale Closure - 2026-08-15

[UID:0003F6][0x00624bd0-0x00624be0.GroupPaneScaleConstant](by-memory/0x00624bd0-0x00624be0.GroupPaneScaleConstant.md) is exact `[0x00624bd0,0x00624be0)`, 16 bytes, SHA256 `3F2F2A9DC01360F3C383FA53B3F2C5B2860A2A6D38F0197C2327BE38DAF280F0`. Its first eight bytes `00 00 00 00 00 00 59 40` are the unique loaded-image little-endian `double 100.0`; its final eight zero bytes are no-xref alignment before the SelfLookPane-owned item at `0x00624be0`.

The literal has exactly two data xrefs, both in [UID:0004Z5][0x0056ce50-0x0056da03.NewGroupPaneOnPaint](by-memory/0x0056ce50-0x0056da03.NewGroupPaneOnPaint.md): `0x0056d5b8` computes the HP percentage and `0x0056d876` computes the MP percentage. The accepted method source already expresses both operations as current/maximum division multiplied by inline `100.0`, followed by unsigned conversion and percentage formatting.

Compiler/linker pooling explains why the two source expressions share one binary cell. The Group translation unit therefore owns UID0003F6's physical range and covered-by route, but it must not define a `qword_624BD0` object, `NewGroupPane_PercentScale` object, `static const double`, global, table entry, macro, or header declaration. The final alignment bytes also produce no source. UID0003F6 emits only `// Covered by NewGroupPane::OnPaint() HP and MP percentage expressions.` while the complete behavior remains in UID0004Z5.

Generated closure requires `NexusTK/social/Group.cpp` to retain both inline `100.0` expressions and contain one non-empty UID0003F6 covered-by marker with no empty-emitter marker or duplicate data object. `Group.h` receives no UID0003F6 declaration or marker. This preserves Group at `91/88`, its source order, and all unrelated inventory.

## ScrollNewGroupPane Range-Setter Route

[UID:000450][0x00560a10-0x00560a6b.ScrollNewGroupPaneSetMaxRange](by-memory/0x00560a10-0x00560a6b.ScrollNewGroupPaneSetMaxRange.md) is an exact `ScrollNewGroupPane::SetMaxRange(short)` child emitted through [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md) into this `NexusTK/social/Group.cpp` route. `NewGroupPane::UpdateScrollRange` calls it at `0x0056cda2` on the child stored at `NewGroupPane +0x100`, using cached member count `+0xfd` minus six normal or twelve expanded rows selected by `+0x10c`.

The 91-byte UID000450 body is byte-identical to [UID:0004X7][0x00561ec0-0x00561f1b.ScrollCollectionPaneSetMaxRange](by-memory/0x00561ec0-0x00561f1b.ScrollCollectionPaneSetMaxRange.md) and [UID:0004XR][0x00564820-0x0056487b.ScrollVolumePaneSetRange](by-memory/0x00564820-0x0056487b.ScrollVolumePaneSetRange.md), SHA256 `C504A31BD1577B41537AE91425C5D2575483ED073207193C545B615792BE1F23`. The common source contract is a signed `0..30000` clamp, outer unchanged-range no-op, direct current-position/value clamp, and ordered one/two invalidations through inherited `m_visibleBounds`. Exact method C++ remains in the child pages; this by-file page only owns their source route and does not duplicate the bodies.

[UID:000451][0x00560a70-0x00560a97.ScrollNewGroupPaneSetScrollPosition](by-memory/0x00560a70-0x00560a97.ScrollNewGroupPaneSetScrollPosition.md) is the companion exact `ScrollNewGroupPane::SetScrollPosition(short position)` child at position `44`, also emitted through [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md) into `NexusTK/social/Group.cpp`. Its three NewGroupPane callers are `0x0056ce39` for post-range current-position reconciliation, `0x0056dbbd` for mouse-wheel application after signed caller-side clamping, and `0x0056df1c` for owner-callback synchronization. The target itself performs no clamp: equality is a no-op, and the changed path makes one signed `+0xfe` store followed by one inherited `m_visibleBounds` invalidation.

The 39-byte UID000451 body is byte-identical to [UID:0004X8][0x00561f20-0x00561f47.ScrollCollectionPaneSetScrollPosition](by-memory/0x00561f20-0x00561f47.ScrollCollectionPaneSetScrollPosition.md) and [UID:0004XS][0x00564880-0x005648a7.ScrollVolumePaneSetValue](by-memory/0x00564880-0x005648a7.ScrollVolumePaneSetValue.md), SHA256 `C823BE0B3A17B1411AAC7D79C9052DA8122A7E32F5B2A7C23FCBFB6C1AEEE940`. The typed homologs resolve the human source as `void`, signed short, equality-gated store, and one invalidation through `m_visibleBounds`. Historical child C++ using decompiler-return semantics, an unconditional store, or `m_bounds` is superseded. Exact source remains only in each class-owned child; this file page records route and cross-family proof without duplicating method bodies.

## ScrollBar Header Dependency

- [UID:0003CQ][0x00624138-0x00624168.ScrollPaneScrollbarConstantData](by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md) defines one shared `const int kScrollPanePartExtentBySkin[3] = {38,38,38}` object at `0x00624144` through [UID:0000NF][ScrollBar](by-file/ScrollBar.md). The Group translation unit consumes it through `ScrollNewGroupPane`; it does not own the storage.
- `ScrollNewGroupPane::OnPaint`, `HitTestPart`, and `GetPartRect` provide Group-family reads at `0x00560e47`, `0x00561146`, `0x005615ac`, and `0x0056189b`. All use `m_scrollSkinIndex` at `+0xf8`; the separate `m_scrollStyleByte` at `+0xfa` is not the table index.
- [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md) adds `#include "../ui/core/ScrollBar.h"` before child insertion so the generated `NexusTK/social/Group.cpp` sees the external declaration. No Group-local `extern`, duplicate definition, or new constants file is warranted.
- Historical `kScrollNewGroupPartExtentByStyle[m_scrollStyle]` was a source-facing alias for this same address and field before cross-family reconciliation. It is superseded documentation history, not evidence for a Group-owned table.
- This dependency adds no Group behavior or ownership and leaves the file's `90/86` score and existing content union unchanged.

## Boundary And Data Notes

- IDA MCP confirms the main group pane function starts at `0x0056c4c0`, `0x0056c5c0`, `0x0056c630`, `0x0056c6c0`, `0x0056c770`, `0x0056c870`, `0x0056c8e0`, `0x0056c970`, `0x0056ca20`, `0x0056cb80`, `0x0056cbf0`, `0x0056cc80`, `0x0056cd30`, `0x0056ce50`, `0x0056da10`, `0x0056db00`, `0x0056df00`, `0x0056df40`, `0x0056dfb0`, `0x0056dfd0`, `0x0056e130`, `0x0056e6d0`, and `0x0056e8c0`.
- Historical IDA evidence reported no auto-function at `0x0056baa0`, `0x005619d0`, `0x00561d50`, `0x0056e570`, or `0x005b5400`. Catalog entry0369 now defines only `0x005619d0` as `ScrollNewGroupPane__SetHighlightedPart`; the other listed source-boundary observations remain unchanged. The `0x0056baa0-0x0056bafd` bytes are a constructor-shaped manual boundary and are documented separately.
- `GroupListPane` vtables are `0x00624214`, `0x0062428c`, and `0x006242bc`; exact data lives at [UID:0002NI][0x00624210-0x006242c4.GroupListPaneVtableData](by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md). `GroupPane`, `GroupPane2`, and `NewGroupPane` use the same `+0x00`, `+0xa0`, `+0xa4` vtable pattern documented in [UID:0001XP][GroupPaneFamilyVtables](by-type/by-vtable/GroupPaneFamilyVtables.md), with exact data children [UID:0002NJ][0x00624438-0x006244c4.GroupPaneVtableData](by-memory/0x00624438-0x006244c4.GroupPaneVtableData.md), [UID:0002NK][0x006244c4-0x00624550.GroupPane2VtableData](by-memory/0x006244c4-0x00624550.GroupPane2VtableData.md), and [UID:0002NL][0x00624550-0x006245dc.NewGroupPaneVtableData](by-memory/0x00624550-0x006245dc.NewGroupPaneVtableData.md).
- 2026-06-20 B001 GroupListPane reanalysis resolves the stale constructor-helper model: [UID:0003XA][0x004b60b0-0x004b60bd.IsLegacyAssetMode](by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md) is a `g_useEpfAssets`/`byte_66DA97` legacy-mode query, while [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md) is a call-site singleton load before [UID:0002ZY][0x0058dce0-0x0058e132.TextEditPaneConstructor](by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md). B007's 2026-06-26 implementation pass then raised the raw constructor page to `89/91` and added formal constructor C++; the UID00023W callback later resolves the false virtual roles as `HandleKeyOrTextEvent` and `OnMouseEvent` and supplies the bounded class declaration. Historical `OnKeyDown` and blank-class wording are superseded.
- The mixed destructor area is split between [UID:00023Z][0x00573310-0x0057353d.CollectionAndGroupPaneDestructors](by-memory/0x00573310-0x0057353d.CollectionAndGroupPaneDestructors.md) for `GroupPane2`/`GroupPane` and [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md) for `NewGroupPane`.
- IDA confirms nearby real functions `0x00561420`, catalog0369-renamed `ScrollNewGroupPane__GetPartRect` at `0x00561740`, catalog0369-created `ScrollNewGroupPane__SetHighlightedPart` at `0x005619d0`, and modeled functions `0x00561b00`/`0x00561bc0`; caller/callback evidence ties them to `ScrollNewGroupPane`. Historical generated `TextEditPane` ownership for this family is stale pollution: RTTI, receiver offsets, helper calls, `NewGroupPane` construction/callbacks, and exact child ownership place the methods in `ScrollNewGroupPane` under this Group source route. The separate `0x00561a40` and `0x00561d50` helpers remain raw/manual method starts.
- 2026-07-06 B007 UID000452 implementation corrects the old `ScrollNewGroupPane` core split: `0x00560aba-0x00560b00` now contains padding at `0x00560aba-0x00560ac0`, raw [UID:0004I3][0x00560ac0-0x00560ada.ScrollNewGroupPaneHideRaw](by-memory/0x00560ac0-0x00560ada.ScrollNewGroupPaneHideRaw.md), padding at `0x00560ada-0x00560ae0`, raw [UID:0004I5][0x00560ae0-0x00560afa.ScrollNewGroupPaneCanAdjustRaw](by-memory/0x00560ae0-0x00560afa.ScrollNewGroupPaneCanAdjustRaw.md), and padding at `0x00560afa-0x00560b00`.
- 2026-06-26 B005 core split implementation adds exact `ScrollNewGroupPane` core children before existing [UID:0001GQ][0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart](by-memory/0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart.md): constructor [UID:00044X][0x00560900-0x005609a1.ScrollNewGroupPaneConstructor](by-memory/0x00560900-0x005609a1.ScrollNewGroupPaneConstructor.md), raw setters [UID:00044Y][0x005609b0-0x005609d7.ScrollNewGroupPaneSkinIndexSetterRaw](by-memory/0x005609b0-0x005609d7.ScrollNewGroupPaneSkinIndexSetterRaw.md) and [UID:00044Z][0x005609e0-0x00560a04.ScrollNewGroupPaneStyleByteSetterRaw](by-memory/0x005609e0-0x00560a04.ScrollNewGroupPaneStyleByteSetterRaw.md), range/position/show helpers [UID:000450][0x00560a10-0x00560a6b.ScrollNewGroupPaneSetMaxRange](by-memory/0x00560a10-0x00560a6b.ScrollNewGroupPaneSetMaxRange.md), [UID:000451][0x00560a70-0x00560a97.ScrollNewGroupPaneSetScrollPosition](by-memory/0x00560a70-0x00560a97.ScrollNewGroupPaneSetScrollPosition.md), and [UID:000452][0x00560aa0-0x00560aba.ScrollNewGroupPaneShow](by-memory/0x00560aa0-0x00560aba.ScrollNewGroupPaneShow.md), mouse handler [UID:000453][0x00560b00-0x00560ce1.ScrollNewGroupPaneHandleMouseEvent](by-memory/0x00560b00-0x00560ce1.ScrollNewGroupPaneHandleMouseEvent.md), false virtual [UID:000454][0x00560cf0-0x00560cf5.ScrollNewGroupPaneCanScroll](by-memory/0x00560cf0-0x00560cf5.ScrollNewGroupPaneCanScroll.md), timer callback [UID:000455][0x00560d00-0x00560d33.ScrollNewGroupPaneOnScrollTimer](by-memory/0x00560d00-0x00560d33.ScrollNewGroupPaneOnScrollTimer.md), and paint virtual [UID:000456][0x00560d40-0x00561420.ScrollNewGroupPaneOnPaint](by-memory/0x00560d40-0x00561420.ScrollNewGroupPaneOnPaint.md). Those children keep the direct class owner [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md) and emit through this file route at positions `40` through `49` when they have formal C++.
- 2026-06-30 B002 revised empty-emitter family implementation resolves the current 18 generated empty-marker rows for `auto-generated/NexusTK/social/Group.cpp`: [UID:000453][0x00560b00-0x00560ce1.ScrollNewGroupPaneHandleMouseEvent](by-memory/0x00560b00-0x00560ce1.ScrollNewGroupPaneHandleMouseEvent.md), [UID:000456][0x00560d40-0x00561420.ScrollNewGroupPaneOnPaint](by-memory/0x00560d40-0x00561420.ScrollNewGroupPaneOnPaint.md), and [UID:0001KR][0x005adc20-0x005adcb3.GroupMemberMarkers](by-memory/0x005adc20-0x005adcb3.GroupMemberMarkers.md) now carry formal first-draft C++; [UID:00005X][GroupListPane](by-class/GroupListPane.md), [UID:00005Y][GroupPane](by-class/GroupPane.md), [UID:00005Z][GroupPane2](by-class/GroupPane2.md), [UID:000090][NewGroupPane](by-class/NewGroupPane.md), [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md), [UID:00044Y][0x005609b0-0x005609d7.ScrollNewGroupPaneSkinIndexSetterRaw](by-memory/0x005609b0-0x005609d7.ScrollNewGroupPaneSkinIndexSetterRaw.md), [UID:00044Z][0x005609e0-0x00560a04.ScrollNewGroupPaneStyleByteSetterRaw](by-memory/0x005609e0-0x00560a04.ScrollNewGroupPaneStyleByteSetterRaw.md), [UID:0002OS][0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData](by-memory/0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData.md), [UID:0001YR][ScrollNewGroupPaneVtables](by-type/by-vtable/ScrollNewGroupPaneVtables.md), [UID:00044V][0x00610fbc-0x00610fd0.SharedTabsPaletteResourceString](by-memory/0x00610fbc-0x00610fd0.SharedTabsPaletteResourceString.md), [UID:0001XP][GroupPaneFamilyVtables](by-type/by-vtable/GroupPaneFamilyVtables.md), [UID:0002NI][0x00624210-0x006242c4.GroupListPaneVtableData](by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md), [UID:0002NJ][0x00624438-0x006244c4.GroupPaneVtableData](by-memory/0x00624438-0x006244c4.GroupPaneVtableData.md), [UID:0002NK][0x006244c4-0x00624550.GroupPane2VtableData](by-memory/0x006244c4-0x00624550.GroupPane2VtableData.md), and [UID:0002NL][0x00624550-0x006245dc.NewGroupPaneVtableData](by-memory/0x00624550-0x006245dc.NewGroupPaneVtableData.md) carry formal no-body/no-standalone markers for class aggregate, raw no-entry setter, compiler-emitted vtable/data, or shared string-data dispositions.
- IDA decompilation at `0x0056bb20` constructs a `SpelledPane`/text-edit style object and is called from other UI code, so it should not be used as clean `GroupListPane` ownership without more evidence.
- `NewGroupPane::UpdateGroupEntry` is currently projected at `0x0056e570`, but IDA says `0x0056e570` is not a function; the confirmed parser at `0x0056e130` ends at `0x0056e565`, and the next confirmed function is `0x0056e6d0`.
- 2026-06-15 live IDA route correction identifies `0x0056c4a0-0x0056c4b5` as `LegendPane` vtable targets. They are useful predecessor-boundary context for `GroupPane`, but they should not be emitted from `Group.cpp`.
- B001 2026-06-18 source-quality reanalysis found a fourth raw `NewGroupPane` helper at `0x0056e820-0x0056e8b4`: it hit-tests only the toggle-button part `6` rectangle `(168,37,185,54)`, has no known callers or pointer refs, and should be tracked with the other no-route raw helpers.
- 2026-06-07 Batch 067 reviewed [UID:0002NK][0x006244c4-0x00624550.GroupPane2VtableData](by-memory/0x006244c4-0x00624550.GroupPane2VtableData.md) as a direct `GroupPane2` child route into this file: the vtable bases are installed by `GroupPane2` constructor/destructor/scalar deleting destructor paths, and the file already owns the class's executable method/destructor ranges.

## UID0003UW Group-Member Marker Source Synchronization - 2026-07-15

- [UID:0001KR][0x005adc20-0x005adcb3.GroupMemberMarkers](by-memory/0x005adc20-0x005adcb3.GroupMemberMarkers.md) remains the sole exact Group-owned emitter for the two global marker helpers and the thirteen bytes of internal alignment padding at `[0x005adc63,0x005adc70)`. This by-file page receives prose/source-order evidence only and has no reconstruction metadata or duplicate helper body.
- `RefreshGroupMemberMarkers` iterates signed `UserPane::m_groupMemberCount` at `+0x3cb0`, reads `memberId` from naturally aligned `0x12c` records beginning at `+0x218`, and calls [UID:0003TB][0x0050e4c0-0x0050e68d.MapPaneRefreshGroupMemberHitBar](by-memory/0x0050e4c0-0x0050e68d.MapPaneRefreshGroupMemberHitBar.md) `MapPane::RefreshGroupMemberHitBar` for every positive-count entry.
- `ClearGroupMemberMarkers` performs the identical dynamic-count/stride walk and calls [UID:0003TD][0x0050e810-0x0050e848.MapPaneRemoveGroupMemberHitBar](by-memory/0x0050e810-0x0050e848.MapPaneRemoveGroupMemberHitBar.md) `MapPane::RemoveGroupMemberHitBar` for every member id. Each helper re-reads the signed count after the downstream call and intentionally adds no null guard or capacity clamp.
- NewOptionPane's GroupBar option is the sole caller pair at `0x00540c04` and `0x00540c0b`, selecting refresh when enabled and removal when disabled. OptionPane owns only that UI toggle; Group owns replay policy, UserPane owns cached records, and MapPane owns HitBar object effects.
- The downstream source names are resolved. Historical `ProcessMapEvent` and `ActivateLinkedObjectById` labels are superseded generic interpretations retained only in dated history. Exact helper starts/sizes, caller sites, table offsets, signed-loop behavior, padding, and Group ownership remain unchanged.
- Group.cpp/header visibility must preserve the `UserPane` parameter and make the helper names available to the callback-last complete UserPane class friendship/declaration union. That shared declaration synchronization is deliberately not duplicated on this by-file root.
- Broad Group metadata remains `90/86`, `CANONICAL_OWNER:FILE`, and projected path `NexusTK/social/`; unrelated pane generations, vtables, packets, layouts, and source-split evidence are preserved.
- Compiler exclusions: no handwritten scalar-delete ABI, packet parsing, MapPane object lookup, HitBar construction, or duplicated UserPane record definition belongs in these helpers. Their exact source is only the two ordinary loops emitted by UID0001KR.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `90` | The page covers group-pane generations, exact class/vtable/destructor children, custom scroll child, raw constructors/stubs, packet/list behavior, group marker helpers, source placement, split caveats, target-level `GroupListPane` constructor C++ readiness, resolved `GroupListPane` false virtual roles, and the current Group.cpp empty-emitter family repair. Completion remains below final because whole-class declarations and final group/chat input source split still need source-quality cleanup. |
| Confidence `86` | Exact by-memory children and IDA-backed vtable/destructor evidence support direct file ownership for `GroupPane2`, `GroupListPane`, and related group-pane classes. The bounded GroupList declaration and corrected event contracts close that local blocker; some helper/source-split evidence remains provisional around other group classes and input-pane routing. |

## Migration Notes

Do not run source ownership migrations until the projected starts above are either corrected or explicitly marked projected/non-IDA. A future dry-run should keep `GroupInputPane` with command inputs unless stronger evidence ties it to the main group pane file. Do not attach `SayToGroupMessageInputPane` to `Group.cpp` under current evidence; it remains a group-feature cross-reference routed through `SayInputPanes.cpp` unless future original source metadata proves otherwise.

```powershell
python source-3\wave3.py create file Group.cpp --kind source --simpath social/Group.cpp --dry-run
python source-3\wave3.py attach class GroupPane --to-file Group.cpp
python source-3\wave3.py attach class GroupPane2 --to-file Group.cpp
python source-3\wave3.py attach class NewGroupPane --to-file Group.cpp
python source-3\wave3.py attach class ScrollNewGroupPane --to-file Group.cpp
```

`SayToGroupMessageInputPane` has been reviewed with the broader `Say*InputPane` family by B006; current documentation should keep it under `SayInputPanes.cpp` and reference this file only for feature context.

## Cross-References

- [UID:00005Y][GroupPane](by-class/GroupPane.md)
- [UID:00005Z][GroupPane2](by-class/GroupPane2.md)
- [UID:000090][NewGroupPane](by-class/NewGroupPane.md)
- [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md)
- [UID:00005X][GroupListPane](by-class/GroupListPane.md)
- [UID:0001H8][0x0056baa0-0x0056bafd.GroupListPaneRawConstructor](by-memory/0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md)
- [UID:0001H9][0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs](by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md)
- [UID:00023W][0x0056c4a0-0x0056c4b5.LegendPaneInputFalseOverrides](by-memory/0x0056c4a0-0x0056c4b5.LegendPaneInputFalseOverrides.md) - boundary context only; live IDA now routes these preceding stubs to `LegendPane`, not `Group.cpp`.
- [UID:0001XP][GroupPaneFamilyVtables](by-type/by-vtable/GroupPaneFamilyVtables.md)
- [UID:0002NI][0x00624210-0x006242c4.GroupListPaneVtableData](by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md)
- [UID:0002NJ][0x00624438-0x006244c4.GroupPaneVtableData](by-memory/0x00624438-0x006244c4.GroupPaneVtableData.md)
- [UID:0002NK][0x006244c4-0x00624550.GroupPane2VtableData](by-memory/0x006244c4-0x00624550.GroupPane2VtableData.md)
- [UID:0002NL][0x00624550-0x006245dc.NewGroupPaneVtableData](by-memory/0x00624550-0x006245dc.NewGroupPaneVtableData.md)
- [UID:0001HM][0x00573273-0x005732b5.GroupPaneAdjustorThunks](by-memory/0x00573273-0x005732b5.GroupPaneAdjustorThunks.md)
- [UID:00023Z][0x00573310-0x0057353d.CollectionAndGroupPaneDestructors](by-memory/0x00573310-0x0057353d.CollectionAndGroupPaneDestructors.md)
- [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md)
- [UID:0000C4][SayToGroupMessageInputPane](by-class/SayToGroupMessageInputPane.md)
- [UID:00005W][GroupInputPane](by-class/GroupInputPane.md)
- [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](by-memory/0x0056c4c0-0x0056e939.GroupPanes.md)
- [UID:0001GP][0x00560900-0x0056141f.ScrollNewGroupPaneCore](by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md)
- [UID:00044X][0x00560900-0x005609a1.ScrollNewGroupPaneConstructor](by-memory/0x00560900-0x005609a1.ScrollNewGroupPaneConstructor.md)
- [UID:00044Y][0x005609b0-0x005609d7.ScrollNewGroupPaneSkinIndexSetterRaw](by-memory/0x005609b0-0x005609d7.ScrollNewGroupPaneSkinIndexSetterRaw.md)
- [UID:00044Z][0x005609e0-0x00560a04.ScrollNewGroupPaneStyleByteSetterRaw](by-memory/0x005609e0-0x00560a04.ScrollNewGroupPaneStyleByteSetterRaw.md)
- [UID:000450][0x00560a10-0x00560a6b.ScrollNewGroupPaneSetMaxRange](by-memory/0x00560a10-0x00560a6b.ScrollNewGroupPaneSetMaxRange.md)
- [UID:000451][0x00560a70-0x00560a97.ScrollNewGroupPaneSetScrollPosition](by-memory/0x00560a70-0x00560a97.ScrollNewGroupPaneSetScrollPosition.md)
- [UID:000452][0x00560aa0-0x00560aba.ScrollNewGroupPaneShow](by-memory/0x00560aa0-0x00560aba.ScrollNewGroupPaneShow.md)
- [UID:0004I3][0x00560ac0-0x00560ada.ScrollNewGroupPaneHideRaw](by-memory/0x00560ac0-0x00560ada.ScrollNewGroupPaneHideRaw.md)
- [UID:0004I5][0x00560ae0-0x00560afa.ScrollNewGroupPaneCanAdjustRaw](by-memory/0x00560ae0-0x00560afa.ScrollNewGroupPaneCanAdjustRaw.md)
- [UID:000453][0x00560b00-0x00560ce1.ScrollNewGroupPaneHandleMouseEvent](by-memory/0x00560b00-0x00560ce1.ScrollNewGroupPaneHandleMouseEvent.md)
- [UID:000454][0x00560cf0-0x00560cf5.ScrollNewGroupPaneCanScroll](by-memory/0x00560cf0-0x00560cf5.ScrollNewGroupPaneCanScroll.md)
- [UID:000455][0x00560d00-0x00560d33.ScrollNewGroupPaneOnScrollTimer](by-memory/0x00560d00-0x00560d33.ScrollNewGroupPaneOnScrollTimer.md)
- [UID:000456][0x00560d40-0x00561420.ScrollNewGroupPaneOnPaint](by-memory/0x00560d40-0x00561420.ScrollNewGroupPaneOnPaint.md)
- [UID:0001GQ][0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart](by-memory/0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart.md)
- [UID:0001GR][0x00561740-0x005619c7.ScrollNewGroupPanePartRect](by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md)
- [UID:0001GS][0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers](by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md)
- [UID:0001LZ][0x005b1ec0-0x005b2152.SayToGroupMessageInputPane](by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md)
- [UID:0001KR][0x005adc20-0x005adcb3.GroupMemberMarkers](by-memory/0x005adc20-0x005adcb3.GroupMemberMarkers.md)
- [UID:0003F2][0x00624b30-0x00624b74.NewGroupPaneCollectionResourceStrings](by-memory/0x00624b30-0x00624b74.NewGroupPaneCollectionResourceStrings.md)
- [UID:0004Z5][0x0056ce50-0x0056da03.NewGroupPaneOnPaint](by-memory/0x0056ce50-0x0056da03.NewGroupPaneOnPaint.md)
- [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)

## Changes

- 2026-08-15 B003 UID0003F6 accepted callback: added exact `NewGroupPane::OnPaint` percentage-scale range/xref/source closure and the no-static-object/no-header policy while preserving Group metadata and source order.
- 2026-08-15 B008 UID0003F2 accepted callback: added the exact `GROUPCOL.EPF`/`GROUPCOL.PAL`/`%d%%` emitter closure, all seven physical-item and four-xref facts, the UID0003F2 -> UID000090 position-75 route, no-object/blank-H policy, and exact generated acceptance counts while preserving `91/88` and unrelated Group inventory.
- 2026-08-14 B004 UID0003F0 accepted callback: recorded the pooled `GROUP.EPF` cell and exact three-use source disposition, attached UID00050R and UID00050S to the GroupPane/GroupPane2 routes, and required complete generated Group.cpp bodies with blank focused H contributions.
- 2026-07-31 B002 UID000090 dependency callback: documented the corrected `Group.h` -> `../ui/core/PanelPane.h` dependency chain and preserved Group.cpp ownership; the actual emitted-H edit remains atomically owned by [UID:000090][NewGroupPane](by-class/NewGroupPane.md), not this by-file prose page.

- 2026-07-30 B002 accepted UID0003CQ support synchronization: recorded the `../ui/core/ScrollBar.h` dependency, exact shared table/value/address, four Group-family consumers, normalized `m_scrollSkinIndex` contract, one-definition ownership, and superseded class-local aliases without changing Group contents, ownership, or `90/86` score.

- 2026-07-30 B004 UID00042L post-IDA file-route reconciliation: recorded catalog entry0369's applied `ScrollNewGroupPane__SetHighlightedPart` and `ScrollNewGroupPane__GetPartRect` identities under the existing `NexusTK/social/Group.cpp` route, historicalized the target's old raw/no-function prestate, and preserved all unrelated Group source inventory and metadata.
- 2026-07-29 B004 UID00042L support callback: retained file metadata `90/86` and the `NexusTK/social/Group.cpp` root; added UID00042L as a retained `ScrollNewGroupPane::SetHighlightedPart` child whose out-of-line body remains emitted through UID0000CL, recorded the active constant-thumb/constant-none inline-lowering explanation for its absent static route, and rejected historical generated `TextEditPane` ownership as stale pollution without adding a separate file or duplicate body.
- 2026-07-29 B007 UID000451 accepted support callback: retained file metadata `90/86` and the `NexusTK/social/Group.cpp` route; added the exact position-setter child route, all three NewGroupPane caller roles, signed/no-local-clamp division, byte-identical UID0004X8/UID0004XS proof, and current `m_visibleBounds` correction without duplicating method C++.
- 2026-07-29 B002 UID000450 accepted support callback: score and file ownership remain `90/86`; added the exact UID000450 -> UID0000CL -> `NexusTK/social/Group.cpp` route, NewGroupPane caller calculation, byte-identical UID0004X7/UID0004XR clone proof, and non-duplication policy for exact child C++.
- 2026-07-16 B001 UID00023W accepted callback: preserved the complete current Group union while synchronizing the exact Legend predecessor boundary and replacing historical GroupList `OnKeyDown`/blank-class conclusions with bool `HandleKeyOrTextEvent`, bool `OnMouseEvent`, and the complete bounded declaration.
- 2026-07-15 B002 UID0003UW callback: synchronized Group marker helper names/ranges, resolved MapPane call targets, signed table-walk and option-caller evidence, ownership boundaries, shared declaration dependency, compiler exclusions, and historical generic names without changing Group metadata or adding by-file reconstruction metadata.

- 2026-07-06 B007 UID000452 implementation:
  - Score unchanged at `90/86`.
  - Updated the `ScrollNewGroupPane` proposed-content row, boundary notes, and cross-references for raw [UID:0004I3][0x00560ac0-0x00560ada.ScrollNewGroupPaneHideRaw](by-memory/0x00560ac0-0x00560ada.ScrollNewGroupPaneHideRaw.md) and raw [UID:0004I5][0x00560ae0-0x00560afa.ScrollNewGroupPaneCanAdjustRaw](by-memory/0x00560ae0-0x00560afa.ScrollNewGroupPaneCanAdjustRaw.md).
  - Preserved the source route through [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md) into `NexusTK/social/Group.cpp`; new raw children are documented as source-ready but left without emitter positions to avoid renumbering the existing core method sequence.
- 2026-06-30 B002 revised Group empty-emitter implementation:
  - Score changed from `89/85` to `90/86`.
  - Recorded that [UID:000453][0x00560b00-0x00560ce1.ScrollNewGroupPaneHandleMouseEvent](by-memory/0x00560b00-0x00560ce1.ScrollNewGroupPaneHandleMouseEvent.md), [UID:000456][0x00560d40-0x00561420.ScrollNewGroupPaneOnPaint](by-memory/0x00560d40-0x00561420.ScrollNewGroupPaneOnPaint.md), and [UID:0001KR][0x005adc20-0x005adcb3.GroupMemberMarkers](by-memory/0x005adc20-0x005adcb3.GroupMemberMarkers.md) now receive formal first-draft C++.
  - Recorded that the remaining 15 current empty-marker rows receive formal no-body/no-standalone markers for declaration, raw no-entry setter, compiler-emitted vtable/data, or shared string-data dispositions.
  - Preserved the `NexusTK/social/Group.cpp` route, SayToGroup/GroupInputPane source-split exclusions, and class-declaration caveats.
- 2026-06-26 B005 core split implementation:
  - Score unchanged at `89/85`.
  - Updated the `ScrollNewGroupPane` proposed-content row, boundary notes, and cross-references after [UID:0001GP][0x00560900-0x0056141f.ScrollNewGroupPaneCore](by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md) became a non-emitting split index with the initial ten exact child pages at emitter positions `40` through `49`.
  - Preserved the source route through [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md) into `NexusTK/social/Group.cpp`; exact child C++ now belongs to the child pages rather than the broad core aggregate.
  - Evidence: accepted B005 report with MCP session `80de0a67` for core function boundaries, raw setter non-function/no-route status, vtable slots, renamed `CanScroll`/`OnScrollTimer` roles, and paint helper no-code proof.
- 2026-06-26 B001 implementation callback for [UID:0001H9][0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs](by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md):
  - Score unchanged at `89/85`.
  - Narrowed stale `GroupListPane` caveats: the false virtual roles are now resolved as `GroupListPane::OnKeyDown(Event *event)` and `GroupListPane::OnMouseEvent(Event *event)`, with formal method bodies emitted by the child by-memory page.
  - Evidence: B001 MCP session `80de0a67` confirmed the two unique vtable pointer hits and slot parity with `ScrollablePane` / `TextEditPane`.
- 2026-06-26 B007 implementation callback:
  - Score unchanged at `89/85`.
  - Updated the `GroupListPane` row, boundary notes, and score rationale after [UID:0001H8][0x0056baa0-0x0056bafd.GroupListPaneRawConstructor](by-memory/0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md) was raised to `89/91`, set to `Nested:0`, and given formal first-draft constructor C++.
  - Preserved route under `NexusTK/social/Group.cpp` and preserved the class-level caveat for false virtual names, exact helper spelling, `sub_58EA80`, and full declaration polish.
- 2026-06-26 B006 source-quality implementation for [UID:0001LZ][0x005b1ec0-0x005b2152.SayToGroupMessageInputPane](by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md):
  - Score unchanged at `89/85`.
  - Updated hypothesis, proposed-content, and migration wording so `SayToGroupMessageInputPane` is feature-related but routed to `SayInputPanes.cpp`, not a pending `Group.cpp` ownership candidate.
  - Preserved `GroupInputPane` as a separate command-input/CommandInputPanes-owned class with opcode `0x2e`.
  - Evidence: B006 MCP session `80de0a67` confirms [UID:0001LZ][0x005b1ec0-0x005b2152.SayToGroupMessageInputPane](by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md) uses `Group => ` prompt, `m_groupName[128]`, submit vtable slot `0x0062f85c`, inline opcode `0x19` group/message packet serialization, and no route through adjacent helper clones; this supports feature cross-reference status without changing `Group.cpp` ownership.
- 2026-06-07 Batch 067 parent-gate refresh:
  - Before: `COMPLETION:88`, `CONFIDENCE:80`; the file was below the corrected direct-parent gate for [UID:00005Z][GroupPane2](by-class/GroupPane2.md).
  - After: `COMPLETION:89`, `CONFIDENCE:85`.
  - Evidence: recorded the exact `GroupPane2` vtable-data child route, existing destructor island split, class method ownership, and IDA-backed group-pane family boundaries. Remaining confidence cap is the still-open `GroupListPane`, scrollbar helper, and group chat/input source split.
- 2026-06-20 B001 GroupListPane source-quality incorporation:
  - Score unchanged at `89/85`; updated `GroupListPane` row and notes after [UID:00005X][GroupListPane](by-class/GroupListPane.md) reached `87/89`.
  - Evidence: corrected `sub_4B60B0` to `IsLegacyAssetMode()` / `g_useEpfAssets` semantics, preserved `g_pFontImageLib` as a call-site singleton load, documented `TextEditPane::TextEditPane` setup, parent `+0xf8` child ownership, false-gate virtual stubs, and the remaining no-C++ blockers.
- 2026-06-01: Set projected reconstruction path to `NexusTK/social/`.
  - Evidence: this page already proposes `social/Group.cpp`; current IDA evidence on [UID:0001GP][0x00560900-0x0056141f.ScrollNewGroupPaneCore](by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md) confirms a Group-owned child can attach here.
  - Scope: path assignment only; reconstructed C++ remains gated by exact child-page confidence and final helper naming quality.
- 2026-05-28: Added `0x0056c4a0-0x0056c4b5` as group-pane false virtual stubs.
  - Before: the range between `LegendPane` and `GroupPanes` was an UNKNOWN gap.
  - After: padding is separated from two real `return false` stubs that belong with the group pane family.
  - Evidence: IDA MCP reports functions at `0x0056c4a0-0x0056c4a5` and `0x0056c4b0-0x0056c4b5`, both `xor al, al; retn 4`, with `0xcc` alignment around them.
- 2026-05-28: Added exact group-pane destructor island pages.
  - Before: group-pane destructor references were listed as start addresses only.
  - After: exact destructor endpoints and owning mixed destructor pages are recorded for `GroupPane2`, `GroupPane`, and `NewGroupPane`.
  - Evidence: IDA MCP reports `sub_5733e0`, `sub_573490`, and `sub_573570` as the scalar deleting destructors for those vtable families.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:80`.
  - Summary/evidence: group pane generations, custom scroll child, raw constructors/stubs, vtable/destructor islands, group packet/list behavior, marker helpers, migration notes, and split caveats are documented; confidence is capped by exact `GroupListPane` emission and scrollbar/helper source ownership.
- 2026-05-31: Added exact group-pane vtable-data child references.
  - Before: vtable ownership was summarized through the family page only.
  - After: the source-file page points to exact by-memory children for `GroupListPane`, `GroupPane`, `GroupPane2`, and `NewGroupPane`.
  - Evidence: IDA MCP `py_eval` and `xrefs_to` checks confirmed class-specific RTTI boundaries and store xrefs.

## 2026-07-31 B002 NewGroupPane Source Inventory

- NexusTK/social/Group.cpp is the accepted translation-unit route for NewGroupPane. No separate speculative NewGroupPane.cpp is introduced.
- The feature now includes one complete UID000090 declaration, twenty-one exact method/helper source pages, ScrollNewGroupPane range/position dependencies, group-member marker integration, and compiler ABI support represented without handwritten vtable arrays.
- File-local static helpers own row/toggle geometry and hit testing; member methods own construction, destruction, render/layout, input, packet parsing, status update, scrolling, drawing, and expanded-mode transitions.
- GroupPane and GroupPane2 remain separate class families in the same physical/source neighborhood. UID0001HC remains a non-emitting physical index and does not duplicate exact child definitions.
- Completion/confidence becomes 91/88: source placement and complete NewGroupPane topology are fixed, while the exact historical translation-unit split across the broader Group feature remains inferred.

### NewGroupPane Header Dependency Closure

- `Group.h` consumes [UID:000090][NewGroupPane](by-class/NewGroupPane.md), whose formal declaration includes `../ui/core/PanelPane.h` from the physical `NexusTK/social/` output location. The relative include belongs to the emitting NewGroupPane H block; this non-emitting by-file page documents the route but does not emit or replace header text.
- The complete dependency chain is `Group.h` -> `../ui/core/PanelPane.h` -> `Pane.h` -> complete GrafPort/EventHandler/TimerHandler and value-type headers. This rejects the prior same-directory `PanelPane.h` assumption without moving Group implementation ownership or duplicating class declarations at file level.
- `Group.cpp` remains the source owner for NewGroupPane methods and exact by-memory children. Dependency closure changes only legal header consumption and does not change method ranges, behavior, class ownership, or emitter positions.

### Exact NewGroupPane Source Split

| Exact child | Role | Route |
| --- | --- | --- |
| [UID:0004YZ][0x0056ca20-0x0056caeb.NewGroupPaneConstructor](by-memory/0x0056ca20-0x0056caeb.NewGroupPaneConstructor.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004Z0][0x0056caf0-0x0056cb73.NewGroupPaneDestructor](by-memory/0x0056caf0-0x0056cb73.NewGroupPaneDestructor.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004Z1][0x0056cb80-0x0056cbe6.NewGroupPaneOnActivate](by-memory/0x0056cb80-0x0056cbe6.NewGroupPaneOnActivate.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004Z2][0x0056cbf0-0x0056cc78.NewGroupPaneUpdateRenderRegion](by-memory/0x0056cbf0-0x0056cc78.NewGroupPaneUpdateRenderRegion.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004Z3][0x0056cc80-0x0056cd25.NewGroupPaneSetBounds](by-memory/0x0056cc80-0x0056cd25.NewGroupPaneSetBounds.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004Z4][0x0056cd30-0x0056ce4b.NewGroupPaneUpdateScrollRange](by-memory/0x0056cd30-0x0056ce4b.NewGroupPaneUpdateScrollRange.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004Z5][0x0056ce50-0x0056da03.NewGroupPaneOnPaint](by-memory/0x0056ce50-0x0056da03.NewGroupPaneOnPaint.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0003F2][0x00624b30-0x00624b74.NewGroupPaneCollectionResourceStrings](by-memory/0x00624b30-0x00624b74.NewGroupPaneCollectionResourceStrings.md) | pooled GROUPCOL.EPF/GROUPCOL.PAL/%d%% covered-by source-use child at position 75 | UID000090 -> UID0000JS |
| [UID:0003F8][0x00624bf0-0x00624c00.GroupPaneRectConstant](by-memory/0x00624bf0-0x00624c00.GroupPaneRectConstant.md) | pooled automatic `RectBounds rowBounds = { 6, 14, 161, 54 };` covered-by child at position 76 | UID000090 -> UID0000JS |
| [UID:0004Z6][0x0056da10-0x0056daf7.NewGroupPaneHandleKeyOrTextEvent](by-memory/0x0056da10-0x0056daf7.NewGroupPaneHandleKeyOrTextEvent.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004Z7][0x0056db00-0x0056dd46.NewGroupPaneHandlePointerOrMouseEvent](by-memory/0x0056db00-0x0056dd46.NewGroupPaneHandlePointerOrMouseEvent.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004Z8][0x0056dd50-0x0056def6.NewGroupPaneHandlePacketEvent](by-memory/0x0056dd50-0x0056def6.NewGroupPaneHandlePacketEvent.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004Z9][0x0056df00-0x0056df38.NewGroupPaneSetScrollPosition](by-memory/0x0056df00-0x0056df38.NewGroupPaneSetScrollPosition.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004ZA][0x0056df40-0x0056dfa6.NewGroupPaneAddToLayer](by-memory/0x0056df40-0x0056dfa6.NewGroupPaneAddToLayer.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004ZB][0x0056dfb0-0x0056dfc6.NewGroupPaneRemoveFromLayer](by-memory/0x0056dfb0-0x0056dfc6.NewGroupPaneRemoveFromLayer.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004ZC][0x0056dfd0-0x0056e027.GetGroupToggleButtonRect](by-memory/0x0056dfd0-0x0056e027.GetGroupToggleButtonRect.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004ZD][0x0056e030-0x0056e086.GetGroupMemberRowRect](by-memory/0x0056e030-0x0056e086.GetGroupMemberRowRect.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004ZE][0x0056e090-0x0056e126.HitTestGroupMemberRow](by-memory/0x0056e090-0x0056e126.HitTestGroupMemberRow.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004ZF][0x0056e130-0x0056e565.NewGroupPaneParseGroupListPacket](by-memory/0x0056e130-0x0056e565.NewGroupPaneParseGroupListPacket.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004ZG][0x0056e570-0x0056e6c1.NewGroupPaneUpdateGroupMemberStatus](by-memory/0x0056e570-0x0056e6c1.NewGroupPaneUpdateGroupMemberStatus.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004ZH][0x0056e6d0-0x0056e813.NewGroupPaneDrawNumberString](by-memory/0x0056e6d0-0x0056e813.NewGroupPaneDrawNumberString.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004ZI][0x0056e820-0x0056e8b4.HitTestGroupToggleButton](by-memory/0x0056e820-0x0056e8b4.HitTestGroupToggleButton.md) | exact source child | UID000090 -> UID0000JS |
| [UID:0004ZJ][0x0056e8c0-0x0056e939.NewGroupPaneToggleExpandedMode](by-memory/0x0056e8c0-0x0056e939.NewGroupPaneToggleExpandedMode.md) | exact source child | UID000090 -> UID0000JS |

The twenty-one pages use half-open body ranges only. Exact excluded  xcc fences are: 56caeb-caf0 (5), 56cb73-cb80 (13), 56cbe6-cbf0 (10), 56cc78-cc80 (8), 56cd25-cd30 (11), 56ce4b-ce50 (5), 56da03-da10 (13), 56daf7-db00 (9), 56dd46-dd50 (10), 56def6-df00 (10), 56df38-df40 (8), 56dfa6-dfb0 (10), 56dfc6-dfd0 (10), 56e027-e030 (9), 56e086-e090 (10), 56e126-e130 (10), 56e565-e570 (11), 56e6c1-e6d0 (15), 56e813-e820 (13), and 56e8b4-e8c0 (12). The aggregate successor fence remains [0x56e939,0x56e940).

## UID0003F8 NewGroupPane Paint And Translation-Unit Closure - 2026-08-16

`NexusTK/social/Group.cpp` remains the sole source root. UID0003F8 is not a named file-static constant: its unique `[6,14,161,54]` 16-byte image has one `NewGroupPane::OnPaint` xref, is stored immediately to a typed stack `RectBounds`, and is mutated as the member-row cursor. It therefore routes as a UID000090 position-76 covered-by child while UID0000JS remains the transitive file owner. Adjacent SelfLookPane vectors, shared COMMA data, and the broad UID0002V2/UID0001HC indexes remain distinct and non-emitting.

The owning `NewGroupPane::OnPaint` source now follows the binary's complete lifecycle and call shape: six explicit `EPFTileContext::Initialize()` calls; accepted `.bounds`; frame-zero `COMMA.EPF`; one context reused for background, rows, and toggle; an initialized-only scratch context; global `GroupMemberRecord`; exact partial `HumanImageRenderParams` writes without `Reset()` or whole-object clearing; full `NewHumanImageLib::CalculateBounds` and `Draw` arguments; direct member-image geometry; HP/MP frame cropping; and constructor-free `RectBounds` aggregate/direct-edge source. The old `.m_bounds`, nested `UserPane::GroupMemberRecord`, shortened NewHuman calls, copied body color, invented reset, constructor, `Width()`, and `Height()` forms are superseded history.

The exact translation-unit preamble is:

```cpp
#include "Group.h"
#include "../ui/panels/UserPane.h"
#include "../render/NewHumanImageLib.h"
#include "../render/PaletteLib.h"
#include "../render/ImageLib.h"
#include "../render/Surface.h"
#include <windows.h>
#include <wchar.h>
```

By-file pages cannot carry formal reconstruction channels under current validator structure. UID00005X `GroupListPane`, the first existing emitter routed to UID0000JS, is therefore the physical carrier for this UID0000JS-owned preamble so the block is emitted once before all class/method children. This carrier role does not transfer semantic ownership, alter GroupListPane behavior, or place includes inside UID0004Z5. Group.h remains assembled from class/type H emitters; UserPane friendship, NewHuman nested rows/class/extern, and Palette class/extern remain in their respective formal H owners.

### Source-Placement And Negative Evidence

- `rowBounds` is the strongest source-facing local name; lexical uncertainty is scored and does not justify retaining `xmmword_624BF0` in source.
- No global/static/member/array identity, guard, address escape, or repeated direct read exists for the packed rectangle.
- UID0001HC remains a non-emitting physical split index; UID0002V2 remains an ownerless mixed `.rdata` index. Neither may duplicate the body, declaration, or pooled local.
- Pooled `COMMA.EPF` remains ownerless because SelfLookPane, Group, and UserStatusPane2 consume it independently; only the Group call site belongs in this source file.
- Compiler vtables, RTTI, scalar-deleting wrappers, adjustor thunks, padding, and pooled data are documented but not handwritten.
- The inferred exact original translation-unit split remains a confidence cap at 91/88, not a blocker to the complete current Group.cpp route.
