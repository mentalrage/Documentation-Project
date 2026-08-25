*** UID:0001XN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// FpsPane vtables and RTTI are compiler-generated from the UID00005F class declaration; no raw table is handwritten.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FpsPane vtables

## Status

- Entity kind: vtable layout
- Primary vtable: `0x0061a620`
- Secondary pane view: `0x0061a66c`
- Timer/update view: `0x0061a69c`
- Exact vtable data: [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md)
- Confidence: strong for key slots, medium for inherited slot names.
- Direct owner: [UID:00005F][FpsPane](by-class/FpsPane.md)
- Owning source file: [UID:0000JK][FpsPane](by-file/FpsPane.md)
- Layout docs: [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md)

## Key Slots

| Vtable | Slot/offset | Target | Notes |
| --- | --- | --- | --- |
| `0x0061a620` | `+0x00` | `0x004b6c50` | `FpsPane::ScalarDeletingDestructor`. |
| `0x0061a620` | `+0x0c` | `0x004b8e20` | Inherited/overridden pane bounds or paint-support method. |
| `0x0061a620` | `+0x44` | `0x004b67b0` | `FpsPane::OnPaint` / FPS text paint slot. |
| `0x0061a66c` | `+0x00` | `0x004b6c2b` | [UID:00015K][0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks](by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md). |
| `0x0061a69c` | `+0x00` | `0x004b6c36` | [UID:00015K][0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks](by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md). |
| `0x0061a69c` | `+0x04` | `0x004b68b0` | `FpsPane::OnTimer` callback; `UpdateStatistics` is the historical alias. |

The data after `0x0061a6a4` is the adjacent ASCII `FPSDATA-*` string area, so the third vtable view appears to contain only the destructor thunk and update callback before string data begins.

## Parent Gate And Assignment

This vtable layout attaches directly to [UID:00005F][FpsPane](by-class/FpsPane.md). The table describes the class' primary, secondary pane, and timer/update virtual views, including compiler adjustor slots for the secondary views; it is not a file-level free table. [UID:00005F][FpsPane](by-class/FpsPane.md) is now `94/96`, and this page is now `93/96`, so the strict child/direct-parent `85/85` assignment gate clears.

The generated C++ block remains blank. These vtables are source-declared/generated-binary artifacts that should be regenerated from the rebuilt `FpsPane` class declaration, inherited bases, and virtual method set rather than hand-authored as static dword arrays.

B004's 2026-06-20 destructor pass clarifies the destructor slots: the vtable-visible primary entry at `0x0061a620` routes to [UID:00015L][0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor](by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md), while the ordinary source-bearing destructor body is [UID:00015E][0x004b6470-0x004b6499.FpsPaneDestructor](by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md). Both binary destructor paths restore the same three vtable views; the reconstructed C++ should express `virtual ~FpsPane()` and let the compiler emit those stores and wrapper routes.

## Evidence

- IDA MCP `py_eval` decoded the dword slots at all three vtable bases on 2026-05-24.
- 2026-05-31 IDA MCP dword scan confirms exact vtable-data child [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md). `0x0061a61c` is the primary RTTI locator, and `0x0061a6a4` starts the adjacent `FPSDATA-*` string area.
- `FpsPane::FpsPane`, ordinary/non-deleting source destructor body `0x004b6470`, and scalar deleting destructor wrapper `0x004b6c50` all write the three FpsPane vtable bases.
- 2026-05-25 IDA MCP xrefs confirm writes to the primary vtable at `0x004b643b`, `0x004b6470`, and `0x004b6c56`; secondary view at `0x004b6441`, `0x004b6476`, and `0x004b6c5c`; and timer/update view at `0x004b644b`, `0x004b6480`, and `0x004b6c66`.
- The two thunks at `0x004b6c2b` and `0x004b6c36` subtract owner offsets and forward to `0x004b6c50`.
- The `0x0061a69c` update callback is invoked with the `+0xa4` subobject pointer. Normalize `0x004b68b0` field offsets by adding `0xa4`; see [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md).
- 2026-05-26 IDA MCP reconfirmed the thunk pair as vtable-only compiler glue. They are documented in [UID:00015K][0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks](by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md) and listed in [UID:0000VN][-ignored](by-memory/-ignored.md).
- 2026-06-11 A002 live IDA MCP `lookup_funcs` confirms modeled functions for the non-deleting destructor (`0x004b6470`, size `0x29`), paint slot (`0x004b67b0`, size `0xfb`), timer/update slot (`0x004b68b0`, size `0x100`), adjustor thunks (`0x004b6c2b` and `0x004b6c36`, each size `0x0b`), and scalar deleting destructor (`0x004b6c50`, size `0x5f`).
- 2026-06-11 A002 live IDA MCP `xrefs_to` confirms each vtable base has the expected three lifecycle stores: raw constructor stores at `0x004b643b`, `0x004b6441`, and `0x004b644b`; non-deleting destructor stores at `0x004b6470`, `0x004b6476`, and `0x004b6480`; and scalar deleting destructor stores at `0x004b6c56`, `0x004b6c5c`, and `0x004b6c66`.
- 2026-06-11 A002 live IDA MCP dword scan confirms the primary view from RTTI locator `0x0061a61c` through paint slot `0x0061a664`, the secondary view from `0x0061a668` through `0x0061a694`, the tertiary view from `0x0061a698` through `0x0061a6a0`, and `0x0061a6a4 == 0x44535046`, the little-endian `FPSD` start of the adjacent `FPSDATA-*` string.
- 2026-06-11 A002 live IDA MCP decompilation confirms `0x004b67b0` formats and draws `"%5.1f FPS"`, `0x004b68b0` samples/resets the subobject-relative frame counter and schedules the next 1000 ms timer, and `0x004b6c50` restores all three vtable views before clearing `g_pFpsPane` and optionally deleting storage.

## Score Rationale

- Completion is `93` because the page closes all 34 vtable dwords, all 12 semantic RTTI records, lifecycle writers, adjustor ownership, authored virtual slots, the adjacent string boundary, and the compiler-generated source treatment. It remains below final-audit completion because inherited/shared slots are still named by role rather than proven original declarations.
- Confidence is `96` because live IDA MCP evidence and the accepted UID0000JK report jointly confirm exact slot values, function identities, lifecycle xrefs, subobject adjustments, RTTI boundaries, and authored paint/timer behavior. The remaining uncertainty is limited to historical source spelling for inherited slot declarations, not binary identity or ownership.

## Cross-References

- [UID:00005F][FpsPane](by-class/FpsPane.md)
- [UID:0000JK][FpsPane](by-file/FpsPane.md)
- [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md)
- [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md)
- [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md)
- [UID:00015K][0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks](by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md)

## 2026-08-24 Complete Vtable And RTTI Inventory

All 34 dwords in `[0x0061a61c,0x0061a6a4)` are accounted for:

| ID | Address | Exact role/value |
| --- | --- | --- |
| V01 | `0x0061a61c` | primary RTTI locator `0x00647a50` |
| V02 | `0x0061a620` | primary scalar deleting destructor `0x004b6c50` |
| V03 | `0x0061a624` | inherited/default `0x004f4b10` |
| V04 | `0x0061a628` | inherited `nullsub_18` `0x0041b6c0` |
| V05 | `0x0061a62c` | inherited bounds/paint support `0x004b8e20` |
| V06 | `0x0061a630` | inherited `nullsub_19` `0x0041d680` |
| V07-V18 | `0x0061a634-0x0061a660` | inherited Pane slots `0x00544730`, `0x00544750`, `0x005447a0`, `0x00544800`, `0x00544a20`, `0x00544b80`, `0x00544bd0`, `0x00544c70`, `0x00544cb0`, `0x00544ce0`, `0x00544d30`, `0x00544d70` in order |
| V19 | `0x0061a664` | authored primary virtual `FpsPane::OnPaint` at `0x004b67b0` |
| V20 | `0x0061a668` | secondary RTTI locator `0x00647b00` |
| V21 | `0x0061a66c` | secondary deleting-destructor adjustor `0x004b6c2b` |
| V22-V27 | `0x0061a670-0x0061a684` | inherited EventHandler slots `0x00544db0`, `0x00544dc0`, `0x00544dd0`, `0x00544de0`, `0x00544df0`, `0x00544e00` |
| V28 | `0x0061a688` | inherited pane/dialog behavior `0x004a89f0` |
| V29-V31 | `0x0061a68c-0x0061a694` | inherited EventHandler slots `0x00544e10`, `0x00544e30`, `0x00544e70` |
| V32 | `0x0061a698` | tertiary RTTI locator `0x00647b14` |
| V33 | `0x0061a69c` | TimerHandler deleting-destructor adjustor `0x004b6c36` |
| V34 | `0x0061a6a0` | authored `FpsPane::OnTimer` at `0x004b68b0` |

The 12 semantic RTTI records are also closed:

| ID | Exact range | Record |
| --- | --- | --- |
| R01 | `0x00647a50-0x00647a64` | primary complete-object locator `??_R4FpsPane@@6B@` |
| R02 | `0x00647a64-0x00647a74` | FpsPane class hierarchy descriptor |
| R03 | `0x00647a74-0x00647a94` | seven-entry base-class array |
| R04 | `0x00647a94-0x00647ab0` | FpsPane base descriptor |
| R05 | `0x00647ab0-0x00647acc` | `Singleton<FpsPane>` direct-base descriptor, PMD `+0xf8` |
| R06 | `0x00647acc-0x00647adc` | Singleton hierarchy descriptor |
| R07 | `0x00647adc-0x00647ae4` | Singleton base array |
| R08 | `0x00647ae4-0x00647b00` | Singleton self descriptor |
| R09 | `0x00647b00-0x00647b14` | secondary complete-object locator |
| R10 | `0x00647b14-0x00647b28` | tertiary complete-object locator; FrameHandler RTTI starts at `0x00647b28` |
| R11 | `0x0067628c-0x006762a4` | FpsPane type descriptor/text |
| R12 | `0x006762a4-0x006762cc` | Singleton type descriptor/text; successor begins `0x006762cc` |

- Constructor, ordinary destructor, and scalar wrapper each store all three vtable bases, proving lifecycle ownership and exact subobject offsets. Adjustor thunks are compiler-generated from this declaration.
- No new RTTI page is required. Formal CPP is the compiler-covered comment above; H remains blank because UID00005F owns the complete declaration.
- Metadata remains owner/emitter `00005F`, reconstructable `TRUE`; score is `93/96`.

## Changes

- 2026-06-20 B004 destructor source-quality sync:
  - Score unchanged.
  - Clarified that [UID:00015E][0x004b6470-0x004b6499.FpsPaneDestructor](by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md) is the ordinary source-bearing `FpsPane::~FpsPane()` body and [UID:00015L][0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor](by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md) is the vtable-visible scalar deleting destructor wrapper. The vtable page remains blank-code because the vtable bytes should be regenerated from `virtual ~FpsPane()` and the inherited view declarations.

- 2026-06-17 B003 source-quality sync:
  - Score remains `85/90`.
  - Updated the parent-gate score for [UID:00005F][FpsPane](by-class/FpsPane.md) to `87/88`; vtable C++ remains blank because the bytes are compiler-generated from declarations.

- 2026-06-11 A002 assigned type coverage pass:
  - Before: the page was `84/88`, reconstructable but unassigned.
  - After: raised to `85/90` and attached to [UID:00005F][FpsPane](by-class/FpsPane.md).
  - Summary/evidence: live IDA MCP rechecked the full three-view slot run, lifecycle xrefs, paint/update/scalar-delete decompilation, and adjacent `FPSDATA` boundary. The direct class parent was raised to `85/86` with the same vtable evidence, so the strict child/direct-parent `85/85` gate clears. C++ remains blank because the vtable bytes should be compiler-generated from the class declaration.
- 2026-05-31: Changed completion/confidence from `0/0` to `84/88` and marked the page reconstructable. Evidence: IDA MCP rechecked `list_globals`, `lookup_funcs`, vtable xrefs, and an exact dword scan; exact child [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md) now records the RTTI/vtable boundaries and slot values.
