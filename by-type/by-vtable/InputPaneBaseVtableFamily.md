*** UID:0001XS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# InputPane Base Vtable Family

## Status

- Confidence: strong for vtable bases, constructor/destructor stores, and slot boundaries; still below final-audit confidence because exact source-level virtual names and every inherited slot declaration are not fully reconstructed.
- Likely owner source: [UID:0000K7][InputPanes](by-file/InputPanes.md)
- Memory range: [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- Destructor adjustors: [UID:00018Z][0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks.md)

## Vtable Bases

| Class | Primary | Secondary `+0xa0` | Tertiary `+0xa4` | Constructor / owner stores |
| --- | --- | --- | --- | --- |
| [UID:000077][LineInputPane](by-class/LineInputPane.md) | `0x0061ca58` | `0x0061caa8` | `0x0061cad8` | Constructor `0x004f1c00`; setup/helper `0x004f2010`; destructors `0x004f2dd0` and `0x004f2ea0`. |
| [UID:00009L][NumberInputPane](by-class/NumberInputPane.md) | `0x0061cae4` | `0x0061cb34` | `0x0061cb64` | Constructor `0x004f27a0`. |
| [UID:00001P][CharInputPane](by-class/CharInputPane.md) | `0x0061cb70` | `0x0061cbc0` | `0x0061cbf0` | Constructor `0x004f28a0`. |
| [UID:000035][ConfirmInputPane](by-class/ConfirmInputPane.md) | `0x0061cbfc` | `0x0061cc4c` | `0x0061cc7c` | Raw/inline stores near `0x004f29d9`; scalar deleting destructor `0x004f2fb0`; late constructor `0x005b75d0`. |
| [UID:00001O][CharArgsInputPane](by-class/CharArgsInputPane.md) | `0x0061cc88` | `0x0061ccd8` | `0x0061cd08` | Constructor `0x004f2a60`. |
| [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md) | `0x0061cd14` | `0x0061cd64` | `0x0061cd94` | Constructor `0x004f2b80`. |
| [UID:00008T][MultiLineInputPane](by-class/MultiLineInputPane.md) | `0x0061cda0` | `0x0061cdf0` | `0x0061ce20` | Constructor `0x004f2c90`. |

## Key Slots

| Class | Primary slot notes | Secondary slot notes | Tertiary slot notes |
| --- | --- | --- | --- |
| `LineInputPane` | `+0x00 -> 0x004f2ea0` scalar deleting destructor; `+0x0c -> 0x004f2320`; `+0x30 -> 0x004f2430`; `+0x38 -> 0x004f24c0`; `+0x44 -> 0x004f2790`; `+0x48 -> 0x0041b6a0` guard/default. | `+0x00 -> 0x004f2e59` adjustor; `+0x04 -> 0x004f24f0`; `+0x08 -> 0x004f25a0` key-input handler; `+0x0c -> 0x004f2580`; `+0x10 -> 0x004f2760`. | `+0x00 -> 0x004f2e64` adjustor; `+0x04 -> 0x00544e90` default/update slot. |
| `NumberInputPane` | Inherits the `LineInputPane` primary behavior and scalar destructor. | Overrides secondary `+0x08 -> 0x004f2820` numeric key filter. | Same tertiary shape as `LineInputPane`. |
| `CharInputPane` | `+0x00 -> 0x004f2f70` scalar deleting destructor; inherited primary behavior otherwise. | `+0x00 -> 0x004f2e6f` adjustor; overrides `+0x08 -> 0x004f2920` printable-character acceptor. | `+0x00 -> 0x004f2e7a` adjustor; `+0x04 -> 0x00544e90`. |
| `ConfirmInputPane` | `+0x00 -> 0x004f2fb0` scalar deleting destructor; `+0x48 -> 0x004f2a10` yes/no confirmation action. | `+0x00 -> 0x004f2e85` adjustor; inherits `CharInputPane` key acceptor at `+0x08 -> 0x004f2920`. | `+0x00 -> 0x004f2e90` adjustor; `+0x04 -> 0x00544e90`. |
| `CharArgsInputPane` | Inherits the `LineInputPane` primary behavior and scalar destructor. | Overrides secondary `+0x08 -> 0x004f2ae0` alphabetic/comma/space argument filter. | Same tertiary shape as `LineInputPane`. |
| `NumberArgsInputPane` | Inherits the `LineInputPane` primary behavior and scalar destructor. | Overrides secondary `+0x08 -> 0x004f2c00` digit/comma/space argument filter. | Same tertiary shape as `LineInputPane`. |
| `MultiLineInputPane` | Inherits the `LineInputPane` primary behavior and scalar destructor. | Overrides secondary `+0x08 -> 0x004f2cd0` multi-line submit/close key handler. | Same tertiary shape as `LineInputPane`. |

## Boundary Notes

- These are MSVC-style vtables with a complete-object-locator dword immediately before each vtable start. Do not treat the dword after each primary or secondary slot span as a virtual slot; it is the next table's locator.
- Primary tables have valid slots through `+0x48`, secondary tables through `+0x28`, and tertiary tables through `+0x04`.
- Secondary and tertiary destructor slots point at compiler-generated this-adjustor thunks in `0x004f2e59-0x004f2e9a`; these wrappers subtract `0xa0` or `0xa4` from `ecx` and tail-jump to the real scalar deleting destructor.
- The dword at `0x0061ce28` after the `MultiLineInputPane` tertiary table is the locator for the neighboring `List` vtable, not another input-pane slot.
- `ConfirmInputPane` has two construction patterns: raw/inline vtable stores in the base cluster near `0x004f29d9`, and the IDA-defined constructor at `0x005b75d0` that calls `CharInputPane` and installs the same three vtables.

## Evidence

- IDA MCP `list_globals` reports all bases above with MSVC decorated vtable names plus matching RTTI locator names. The 2026-05-31 check specifically confirmed `CharArgsInputPane`, `NumberArgsInputPane`, `MultiLineInputPane`, and `ConfirmInputPane`; earlier IDA-backed rows already covered `LineInputPane`, `NumberInputPane`, and `CharInputPane`.
- IDA MCP `xrefs_to` on 2026-05-31 confirms constructor/destructor stores for every listed vtable. `LineInputPane` vtables are stored by `0x004f1c00`, restored by `0x004f2010`, and restored during destructors `0x004f2dd0` / `0x004f2ea0`; the derived input panes store their three-table families from `0x004f27a0`, `0x004f28a0`, raw stores near `0x004f29d9`, `0x004f2a60`, `0x004f2b80`, `0x004f2c90`, `0x004f2fb0`, and `0x005b75d0`.
- IDA MCP `py_eval` dword reads on 2026-05-31 confirm the slot values listed above, including the shared scalar destructor/adjustor targets, derived key-filter overrides, and `0x0061ce28 -> ??_R4List@@6B@` boundary after the `MultiLineInputPane` tertiary table.
- IDA MCP function lookup through the read slot values confirms the relevant executable targets lie inside the documented `0x004f1c00-0x004f3017` input-pane cluster, with the adjustor thunks in [UID:00018Z][0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks.md).
- Current `simroot_v2` metadata reports `vtable_count: 0` for `LineInputPane`, `NumberInputPane`, `CharInputPane`, `ConfirmInputPane`, `CharArgsInputPane`, `NumberArgsInputPane`, and `MultiLineInputPane`; this page is the IDA-backed replacement anchor until generated vtable inventory is repaired.

## Cross-References

- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- [UID:00018Z][0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks.md)
- [UID:000077][LineInputPane](by-class/LineInputPane.md)
- [UID:00009L][NumberInputPane](by-class/NumberInputPane.md)
- [UID:00001P][CharInputPane](by-class/CharInputPane.md)
- [UID:000035][ConfirmInputPane](by-class/ConfirmInputPane.md)
- [UID:00001O][CharArgsInputPane](by-class/CharArgsInputPane.md)
- [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md)
- [UID:00008T][MultiLineInputPane](by-class/MultiLineInputPane.md)
- [wave3 data issues](../../wave3_data_issues.md)

## Changes

### 2026-05-31 - Scored IDA-verified vtable family

- Before: validator metadata still marked this page `COMPLETION:0`, `CONFIDENCE:0`, and left `RECONSTRUCTABLE` blank despite an already documented vtable inventory.
- Changed to: `COMPLETION:84`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`. No parent attachment or C++ reconstruction code was added because the exact source-level declaration shape and every virtual slot name are not final-audit complete.
- Evidence: IDA MCP `list_globals`, `xrefs_to`, and `py_eval` checks on 2026-05-31 confirmed the decorated vtable names, constructor/destructor stores, slot target dwords, function boundaries for selected slot targets, and the `0x0061ce28` transition into the neighboring `List` RTTI locator.
