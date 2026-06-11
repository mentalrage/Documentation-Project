*** UID:00005R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GeneralPurposePanel2

## Status

- Confidence: strong for behavior, singleton ownership, vtable identity, and single-child `NewSystemMessagePane` construction.
- Likely source file: [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md)
- Main address doc: [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md)

## Functionality

`GeneralPurposePanel2` is a smaller alternate general-purpose panel shell. It constructs one `NewSystemMessagePane` child, exposes index-based child lookup, tracks a single active state value, and clears `g_pGeneralPurposePanel2` during teardown.

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| constructor | `0x004b8830-0x004b88e0` | Constructs the alternate panel and one child pane. |
| destructor | `0x004b88f0-0x004b8943` | Releases the child pane and clears singleton. |
| `GetChildPaneByIndex` | `0x004b8950-0x004b8968` | Returns the single child for index `0`, otherwise null. |
| active switch helper | [UID:00015Y][0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md) | IDA-confirmed one-child activation/layout helper. |
| scalar deleting destructor | `0x004b8aa0-0x004b8b31` | Deleting destructor wrapper. |

## IDA Evidence

Live IDA MCP recheck on 2026-06-04 used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.

- `0x004b8830` calls the panel base constructor `0x004f4a80`, writes `dword_69B358` at `0x004b8872` / `0x004b8879`, stores `GeneralPurposePanel2::vftable` at `0x004b888c`, initializes the active index field at `this+8` to `-1`, allocates `0x304` bytes, and calls `0x00588560` for the single child.
- `0x00588560` has a single direct caller at `0x004b88ae` from this constructor. Live decompilation shows it installs `NewSystemMessagePane` vtables and maintains `g_pNewSystemMessagePane`, confirming the child identity rather than only a generic pane allocation.
- `0x0061a894` / `0x0061a898` are the adjacent RTTI/vtable records for `GeneralPurposePanel2`; vtable stores occur from constructor/destructor/scalar-destructor paths at `0x004b888c`, `0x004b8915`, and `0x004b8ac5`.
- `g_pGeneralPurposePanel2` at `0x0069b358` has writes from constructor/destructor/clear/destructor-wrapper paths at `0x004b8872`, `0x004b8879`, `0x004b8925`, `0x004b8a80`, and `0x004b8adc`, plus read-side users in the `0x005a76c0` user-pane message handler family.
- `GetChildPaneByIndex` accepts only index `0`; live xrefs include `0x0050feff`, several calls inside `0x005a76c0`, and `0x005aace2`.
- The switch helper at `0x004b89a0` has one direct caller at `0x005a771b` and uses the same `this+8` active-index field and `this+4` child slot initialized by the constructor.
- Batch 118 live IDA `py_eval` corrected the switch helper boundary to `0x004b89a0-0x004b8a7f`; the final byte at `0x004b8a7e` is part of the `retn 8` immediate, followed by `0xcc` alignment. This supports retaining the helper as a direct `GeneralPurposePanel2` method rather than a sibling free helper.

## Assignment Decision

`AUTOGEN_PARENT_UID` remains [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md). The class is now `85/90`, and the direct file parent is now `85/86`, so both sides clear the corrected `85/85` gate. This is a direct file assignment because the file page owns both general-purpose panel shells, the singleton lifecycle evidence, and the shared panel-switch/frame-refresh boundary notes.

## Cross References

- [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md)
- [UID:00005Q][GeneralPurposePanel](by-class/GeneralPurposePanel.md)
- [UID:0000R1][g_pGeneralPurposePanel2](by-global/g_pGeneralPurposePanel2.md)
- [UID:00015Y][0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md)

## Changes

- 2026-06-08 A006 Batch 118 parent-gate repair:
  - Changed score from `84/90` to `85/90`.
  - Summary/evidence: corrected and attached [UID:00015Y][0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md), including the final `retn` byte in the exact range. The helper's one-child bounds check, `this+8` active index, `this+4` child slot, sole `UserPane` caller, and frame-refresh dependency all match this class, while the file parent now clears the corrected gate.
- 2026-06-04: Raised completion/confidence from `72/78` to `84/90`. Summary/evidence: live IDA MCP confirmed the exact `GeneralPurposePanel2` constructor/destructor/accessor/switch/scalar-destructor family, vtable stores, singleton writes/reads, constructor caller from `InitializeMainUiGraph`, direct switch caller from the user-pane message handler, and the single child constructor at `0x00588560` as `NewSystemMessagePane`. Completion remains below final-source quality because final public method names and all higher-level user-message call semantics still need deeper reconstruction.
- Completion/confidence score update: existed before as `0/0`; changed to `72/78`. Summary: alternate one-child panel role, singleton, core methods, and missing active-switch helper are documented; exact feature meaning of the single child pane remains medium-confidence. Evidence: shared `GeneralPurposePanel` memory page, `GeneralPurposePanel2SwitchActiveChild`, and `g_pGeneralPurposePanel2`.
- 2026-06-05: Marked reconstructable and attached to [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md) because the class is `84/90` and the parent is `84/80`, satisfying the 80/80 parent gate. Live IDA MCP `lookup_funcs` confirms exact starts at `0x004b8830`, `0x004b88f0`, `0x004b8950`, `0x004b89a0`, and `0x004b8aa0`; current `callers` confirms the constructor reference from `InitializeMainUiGraph` at `0x004f8020`.
