*** UID:0000OK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# TextButtonControlPane

## Status

- Confidence: very strong for the dedicated text-button class, exact authored/compiler boundaries, `0x110` layout, destructor/vtable ownership, and GrafPort dependency boundary.
- Proposed module pair: `ui/controls/TextButtonControlPane.cpp` and required sibling `ui/controls/TextButtonControlPane.h`.
- Historical validator-generated state at the accepted Gate 1 snapshot: `auto-generated/NexusTK/ui/controls/TextButtonControlPane.cpp` was a 672-byte, ten-line marker-only artifact with SHA256 `E57CC0C12A2E04B6C873AE5731420E82326879AD736CEEB6D3F0082E019BC431`; the sibling `.h` was absent. Historical `source-3/simroot_v2/class_TextButtonControlPane.cpp` is not present and is retained below only as superseded provenance.
- Dated generated-closure receipt: scoped validator command `000000023376` refreshed the owner route at `2026-08-14T04:07:10-04:00` with exit `0`, `ok:1`. That dated physical reread found `TextButtonControlPane.cpp` at 3,997 bytes and 117 lines, SHA256 `783FD57EE868E147C20AC54097B696E4A989B52039A7CBE2198F99AC628A4827`, with the constructor, ordinary destructor, `GetText`, and `OnPaint` definitions plus the UID0002YE covered-by child marker; `TextButtonControlPane.h` was 964 bytes and 30 lines, SHA256 `9ADD6C98CD6597E2B0144A2B9B5EB25C1119E9799D084FFD465D6B3FEDC7CDD4`, with the complete `ButtonControlPane`-derived declaration and `0x110` size invariant. The dated comparison found CPP differing from formal UID0000EJ only by validator provenance and expected expanded UID0002YE child-marker lines, with H equal to its formal body. Validator command `000000023637` at `2026-08-14T18:41:33-04:00`, CPP SHA256 `D308BAA54481932D6EC94BD18A3E5B053E97D17DB6DCE2B474289B887C434A91`, and H SHA256 `2C576892610ED736A335CE527A81A4F9EDAF655D1CBDA0425345E242C925DAD0` are a later dated historical generated snapshot only and have no continuing current-state authority. Present generated-state authority requires a fresh supervisor physical readback.
- Main address ranges: [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md), [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md), and [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md)

## File Role

`TextButtonControlPane` is a text-labeled button control derived from the control pane family. It constructs a text buffer, paints 3D button borders and centered text, and exposes text retrieval behavior. The old generated `SetTextResource` row is not accepted as text-button ownership because the raw body belongs to the radio-group option helper island.

`DrawTextInRect` remains linked because `TextButtonControlPane::OnPaint` calls it, but its source ownership is settled under [UID:0000JR][GrafPort](by-file/GrafPort.md) / shared UI text drawing, with [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md) as the adjacent helper family. Historical generated-output association never made the helper TextButton-owned and no move remains open.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `TextButtonControlPane` | [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md), destructor at [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md) | Text button construction, text buffer ownership, paint, and teardown. |
| `TextButtonControlPane` destructor support | [UID:0002YD][0x0049b05b-0x0049b071.TextButtonControlPaneAdjustorThunks](by-memory/0x0049b05b-0x0049b071.TextButtonControlPaneAdjustorThunks.md), [UID:0002YE][0x0049b7a0-0x0049b854.TextButtonControlPaneScalarDeletingDestructor](by-memory/0x0049b7a0-0x0049b854.TextButtonControlPaneScalarDeletingDestructor.md) | Compiler-generated adjustor thunks and scalar deleting wrapper tied to the `TextButtonControlPane` vtable cells; UID0002YE now emits only a formal covered-by marker through [UID:0000EJ][TextButtonControlPane](by-class/TextButtonControlPane.md), while source should declare the destructor relationship rather than hand-author these ABI stubs. |
| `DrawTextInRect` | [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md) | Shared multi-line wrapped text drawing dependency with alignment support; established GrafPort/shared-text ownership, not a TextButton source child. |

## Evidence Notes

- Wave3 metadata says `TextButtonControlPane` has a `ButtonControlPane` base and a text pointer at offset `0x10c`.
- 2026-05-25 IDA MCP confirms function starts at `0x00495040`, `0x00495130`, `0x004951b0`, `0x00495220`, and scalar deleting destructor `0x0049b7a0`.
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md) maps the `TextButtonControlPane` adjustor thunks at `[0x0049b05b,0x0049b071)`, the scalar deleting destructor at exact half-open range `[0x0049b7a0,0x0049b854)`, and the primary destructor vtable cell at `0x00617c7c`. That evidence supports this source/class placement even while the destructor wrappers remain compiler-generated aggregate rows.
- Historical simroot output emitted `SetTextResource` at `0x004964e0`; the current simroot file is absent. The accepted bounded IDA evidence reports that address is not a function, has zero direct xrefs, and lies in [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md). The old row is stale/misowned and is rejected, not deferred.
- Historical 2026-05-25 state: `class_TextButtonControlPane.cpp` then emitted the stale `SetTextResource` row while `class_RadioGroupControlPane.cpp` emitted `RadioGroupControlPane::OnPaint` at `0x00496300`. This is provenance only; current reconstruction authority is the validator-routed formal source and current by-* documentation.
- [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md) records 130 direct callers across UI and message rendering code and prefers GrafPort/shared-text ownership, so keep it cross-referenced rather than class-owned here.
- `DrawTextInRect` currently calls `GetFontLineAdvance(...g_pDirectX...)`, but IDA evidence from the DirectX batch indicates this is likely the same `g_pFontImageLib` global-alias issue tracked in [Wave3 noticed problems](../wave3_noticed_problems.md).
- [UID:0002YD][0x0049b05b-0x0049b071.TextButtonControlPaneAdjustorThunks](by-memory/0x0049b05b-0x0049b071.TextButtonControlPaneAdjustorThunks.md) and [UID:0002YE][0x0049b7a0-0x0049b854.TextButtonControlPaneScalarDeletingDestructor](by-memory/0x0049b7a0-0x0049b854.TextButtonControlPaneScalarDeletingDestructor.md) now give this file an exact destructor/vtable support chain: adjustor branches at `0x0049b061` and `0x0049b06c`, primary vtable/data cell `0x00617c7c`, and a confirmed `0x0049b7a0-0x0049b854` scalar deleting wrapper.
- 2026-07-03 B006 source-route sync: UID0002YE is no longer a blank/unresolved emitter. MCP session `3a33af0b` reconfirmed `sub_49B7A0` size `0xb4`, exact `0x0049b7a0-0x0049b854` body, clean `0x0049b854-0x0049b860` `0xcc` padding, direct refs only from adjustor thunks `0x0049b061`/`0x0049b06c` and vtable cell `0x00617c7c`, TextButton vtable restores to `0x00617c7c`/`0x00617ce8`/`0x00617d18`, `+0x10c` cleanup shared with ordinary destructor `0x00495130`, base cleanup `sub_544580`, normal delete-helper path `sub_4F4AC0`, and the compiler guard/object-size path `0x110`. This file should route UID0002YE as a formal marker-covered compiler wrapper through [UID:0000EJ][TextButtonControlPane](by-class/TextButtonControlPane.md), not as standalone scalar deleting destructor C++.
- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) is the broader generic button/choice-control family, but the proposed source tree and this page both keep `TextButtonControlPane.cpp` as a narrower reusable controls module. Use this file as the direct parent for [UID:0000EJ][TextButtonControlPane](by-class/TextButtonControlPane.md); keep broad aggregate and base-button ownership under [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md).

## 2026-06-14 IDA MCP Refresh

- `lookup_funcs` reconfirms the source-bearing method anchors at `0x00495040` size `0xef`, `0x00495130` size `0x73`, `0x004951b0` size `0x68`, and `0x00495220` size `0x230`; the stale generated `0x004964e0` row is still not an IDA function.
- `xrefs_to` confirms the class-local fan-in: `0x00495040` has ten constructor/setup callsites, `0x00495130` has two code callsites, `0x004951b0` and `0x00495220` are vtable/data referenced, and `0x00617c7c` has the constructor/destructor reset refs at `0x004950bc`, `0x0049515b`, and `0x0049b7d2`.
- Destructor support remains exact: `0x0049b05b` and `0x0049b066` are `0x0b` adjustor thunks with vtable refs at `0x00617ce8` and `0x00617d18`; scalar deleting destructor `0x0049b7a0` size `0xb4` is referenced by those thunks and the primary vtable cell at `0x00617c7c`.
- `xrefs_to 0x004bad70` reports 130 refs, including the `TextButtonControlPane::OnPaint` call at `0x004953e7`, so `DrawTextInRect` remains documented here only as a dependency/historical generated association, not a direct text-button source child.
- `callees` confirms the constructor/setup bodies use shared control/text buffer helpers, the paint method calls GrafPort draw-state helpers and `DrawTextInRect`, and the scalar deleting destructor calls cleanup/delete support. This raises confidence for this file's class boundary while keeping shared text-render ownership outside the file.

## 2026-08-13 B006 Whole-File Closure

The accepted UID0000OK report, exact Gate 1 SHA256 `252A1CEB3A98F1ED96A6A65DF6B76D74330C4A085840A5CB388804D6F16B93BD`, closes the complete file rather than one representative method. The dated read-only evidence snapshot used session identifier `supervisor-canonical-uid0002PR-retry2-20260813` and saved-IDB SHA256 `5CCAF2321601201E12AFE937EEC6511B9E92B7B54CEAD23F5464E1D3D2440C43`; those values are provenance only and do not claim current Gate 2B authority.

Exact authored inventory:

| Entity | Half-open range | Size | Function-byte SHA256 | Source disposition |
| --- | --- | ---: | --- | --- |
| constructor | `[0x00495040,0x0049512f)` | `0xef` | `B77069621D6F69D5189CC6B3066A7CEFE4EEF7160CE82247097A2954394D1DFC` | Authored definition in UID0000EJ formal CPP. |
| ordinary destructor | `[0x00495130,0x004951a3)` | `0x73` | `E00E4974D52F7C71BDF339BC3D182644DD50CA5B9B05ABE936132589326D8ED8` | Authored definition; compiler vptr/base teardown is not handwritten. |
| `GetText` | `[0x004951b0,0x00495218)` | `0x68` | `085A029DBA6AB39CD94F026D15CA1FA34AA2D2221C3D7D15A3C4FBF7AB874C72` | Authored virtual definition preserving the observed count/byte mismatch. |
| `OnPaint` | `[0x00495220,0x00495450)` | `0x230` | `F0A470DA1DAC209B84349BBF4E9DE6E27BFE4B2C163F4D15EAA83F3424AB9DF4` | Authored virtual definition preserving the full draw order. |

The authored band is exactly `[0x00495040,0x00495450)` and has no terminal TextButton pad after `OnPaint`; the TextButtonEx constructor begins at `0x00495450`. Exact all-`0xcc` boundaries are predecessor fence `[0x0049503d,0x00495040)` SHA256 `E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE`, constructor fence `[0x0049512f,0x00495130)` SHA256 `1DD8312636F6A0BF3D21FA2855E63072507453E93A5CED4301B364E91C9D87D6`, destructor fence `[0x004951a3,0x004951b0)` SHA256 `0D0BB866505BC0E2D4276FCDEE1AFDC8887662D04CCE9E4BBB4C10FBA6D0F1CE`, and GetText fence `[0x00495218,0x00495220)` SHA256 `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3`; every bounded both-direction fence xref result is zero.

The class is a `ButtonControlPane`-derived `0x110`-byte object: the established base occupies `[+0x000,+0x10c)`, and one owned wide-text pointer occupies `+0x10c`. Constructor allocation/copy, destructor free/clear, GetText read/copy, and OnPaint read converge on that field. The member remains protected because current FittingRoom-derived formal source reads it. Every observed complete-object allocation is `0x110`.

Constructor inbound callsites are exactly `0x00424030`, `0x004a02de`, `0x004a034d`, `0x004b06f0`, `0x004b075f`, `0x00500afb`, `0x00500b6b`, `0x00545336`, `0x0054733b`, and `0x0054890e`. The ordinary destructor has exact code refs `0x0042407a` and `0x004242b0`. `GetText` is live through data cells `0x0060e038` and `0x00617ce0`; `OnPaint` is live through `0x00617cc0`. Their lack of ordinary direct callers is expected virtual dispatch, not dead code.

Compiler support is exact and source-covered: UID0002YD contains two 11-byte deleting adjustors `[0x0049b05b,0x0049b066)` and `[0x0049b066,0x0049b071)`, hashes `5094DF2027E238735082AE0ACCBD42F6FD4850A0C8164B63C5ADE1340FE26C84` and `AB47BB04B0727C4B1F9F8A32FDDD3738633EED0C750392A18BA0A3E6C4946A72`, which subtract `0xa0`/`0xa4` and tail-jump to UID0002YE. UID0002YE is `[0x0049b7a0,0x0049b854)`, `0xb4` bytes, SHA256 `4CE2CAD4CC097F60E6E19F36F835DE2D0A6AF2103FE58555F3381775313549B0`, followed by the all-CC fence `[0x0049b854,0x0049b860)` SHA256 `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902`. The class declaration and ordinary destructor are the human source cause; adjustors, hidden deleting flags, wrapper body, vptr restoration, and alignment emit no handwritten C++.

The exact generic vtable island is `[0x00617c78,0x00617d20)`, 168 bytes, overall SHA256 `8F923BE84B8B527ADB646BA48FABEF55B79B06ABBB4DB7787D9289AF046C429E`. It consists of three COL cells and 26/11/2-slot views. Primary, secondary, and tertiary callable heads are `0x00617c7c`, `0x00617ce8`, and `0x00617d18`; constructor, ordinary destructor, and scalar-wrapper stores independently bind all three. RTTI anchors are BCD `0x00640a10`, CHD `0x00640a2c`, BCA `0x00640a3c`, COLs `0x006459d0/0x006459e4/0x006459f8`, and type descriptor `0x00673b54`. UID000252 owns this exact non-emitting compiler-data inventory.

There is no file-owned global, static, constant table, string, resource, import definition, or separate data translation unit. Palette values, pressed state `11`, half-height `6`, and one-pixel offsets are immediates. MemoryMan, rectangle, Pane/GrafPort drawing, CRT wide-string, and delete support are dependencies. `TTONEX.EPF`, `TTONEX.EPD`, and `TT001.EPF` are excluded zero-xref neighboring resource items. FittingRoomTextButtonControlPane remains feature-owned derived source.

Historical assumptions are retained but closed: Wave2/Wave3 and simroot output are leads rather than authority; inclusive-looking endpoints are superseded by the half-open ranges above; the base/field/source split is resolved by the `0x10c` base, `+0x10c` pointer lifecycle, `0x110` allocations, vptr triads, and derived member access; `SetTextResource` is rejected as RadioGroup code; and `DrawTextInRect` remains a GrafPort dependency. The direct file/class route is reconstructable and the formal UID0000EJ CPP/H channels are the only source-emission authority.

## Cross-References

- [UID:0000EJ][TextButtonControlPane](by-class/TextButtonControlPane.md)
- [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md)
- [UID:0000UJ][DrawTextInRect_004BAD70](by-item/DrawTextInRect_004BAD70.md)
- [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md)
- [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)
- [UID:0000JH][FontImageLib](by-file/FontImageLib.md)

## Changes

- 2026-08-13 B006 UID0000OK whole-file implementation callback:
  - Before: `COMPLETION:86`, `CONFIDENCE:87`; the page retained current-simroot wording, inclusive-looking ranges, an unresolved DrawText ownership caveat, marker-only generated CPP, absent generated H, and no exhaustive itemized closure.
  - Changed to: `COMPLETION:94`, `CONFIDENCE:95`; exact authored/fence/compiler/vtable/RTTI inventories, caller/xref evidence, layout, generated audit, source route, negative inventory, score caps, and historical corrections are now explicit. File identity, canonical `FILE` owner, and `NexusTK/ui/controls/` path remain unchanged.
  - Evidence: accepted B006 report SHA256 `252A1CEB3A98F1ED96A6A65DF6B76D74330C4A085840A5CB388804D6F16B93BD`; ordinary callback only. Manual coverage, generated refresh, IDA mutation, audit/lifecycle, and report execution remain outside this edit.

- 2026-07-03 B006 implementation callback:
  - Metadata unchanged. Updated UID0002YE destructor-support/source-route wording so the scalar deleting destructor child emits only a formal covered-by marker through [UID:0000EJ][TextButtonControlPane](by-class/TextButtonControlPane.md).
  - Evidence: accepted report/target details include current MCP session `3a33af0b`, exact wrapper size/body/padding, vtable/thunk-only refs, three TextButton vtable restores, ordinary destructor cleanup comparison, delete-helper/guard-size compiler paths, and rejected raw-wrapper/non-emitting/aggregate/adjustor/no-owner alternatives.
- 2026-06-07 A010 Batch096 parent-gate update:
  - What existed before: `COMPLETION:84`, `CONFIDENCE:82`, below the corrected 85/85 parent gate for [UID:0000EJ][TextButtonControlPane](by-class/TextButtonControlPane.md).
  - Changed to: `COMPLETION:85`, `CONFIDENCE:85`.
  - Summary/evidence: exact destructor support pages now document the TextButton adjustor thunk pair and scalar deleting destructor/vtable cell, while the file page narrows ownership to constructor/destructor/get-text/paint and treats `DrawTextInRect` as a shared GrafPort/text-render helper rather than text-button-owned code. Confidence stays at the gate because final field names and the broader button/source split still need a final source-layout pass.
- 2026-06-14 C001 Goal2 score refresh:
  - Before: score `85/85`.
  - Changed to: score `86/87`.
  - Summary/evidence: live IDA MCP reconfirmed method sizes, stale `0x004964e0` non-function/no-xref status, constructor/setup fan-in, vtable/destructor refs, exact adjustor/scalar destructor support, and 130-call shared `DrawTextInRect` fanout. No owner/emitter routing changed; final field names and shared text-render helper ownership remain the blockers to a higher score.

- 2026-06-07 A003 ownership-boundary refinement:
  - What existed before: confidence was `78`, and the file-role text still said this page owned the broad `DrawTextInRect` helper while also carrying the stale generated `SetTextResource` caveat.
  - Changed to: confidence `82`, with `DrawTextInRect` documented as a historical/generated association and likely GrafPort/shared-text helper; `TextButtonControlPane` class placement is supported by constructor/paint/accessor boundaries plus destructor/vtable evidence from the destructor aggregate.
  - Summary/evidence: existing memory pages record the class functions at `0x00495040`, `0x00495130`, `0x004951b0`, and `0x00495220`, TextButton adjustor/scalar destructor/vtable ownership at `0x0049b05b`, `0x0049b7a0`, and `0x00617c7c`, the stale `0x004964e0` radio-group island, and the shared 130-caller `DrawTextInRect` helper. Completion stays `84` because final helper ownership and source split remain open.

- 2026-06-05 projected-path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file row remained a generated-root coverage error.
  - Changed to: `NexusTK/ui/controls/`.
  - Summary/evidence: live IDA MCP lookup confirms the documented text-button method anchor at `0x00495040`; proposed-source-tree treats `TextButtonControlPane.cpp` as a reusable UI-control module while keeping broad text drawing helper ownership open.

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `78`.
  - Evidence: document captures text-button role, proposed contents, Wave3/IDA evidence, stale `SetTextResource` ownership caveat, shared `DrawTextInRect` helper issue, font/global alias caveat, and cross-references; confidence is capped by shared text-render helper ownership.
