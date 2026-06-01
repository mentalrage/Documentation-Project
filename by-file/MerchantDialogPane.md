*** UID:0000L9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MerchantDialogPane

## Status

- Confidence: strong for shared dialog-base ownership; medium for whether it was a standalone `.cpp` or private code in a broader menu-dialog source.
- Candidate file: `NexusTK/ui/dialogs/MerchantDialogPane.cpp`
- Alternative compact placement: private base code inside `ui/dialogs/TextMenuDialogs.cpp` or a broader menu-dialog source.
- Current generated source: `source-3/simroot_v2/class_MerchantDialogPane.cpp` is used only as historical generated-output context; current confidence comes from IDA evidence and local docs.
- Primary class doc: [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md)
- Main address doc: [UID:0001BL][0x00517d30-0x00517ebf.MerchantDialogPaneBase](by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md)
- Exact shared virtual doc: [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md)
- Vtable/layout anchor: [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)

## File Role

`MerchantDialogPane` is the shared `DialogPane`-derived base used by merchant/NPC packet menu dialogs. It stores the merchant/menu type byte at offset `+0x26c`, installs three `MerchantDialogPane` vtable views, and provides a shared virtual helper for special row/action strings.

The shared helper at `0x00517d80` is referenced from vtables for `MerchantDialogPane`, `TextMenuDialog`, `TextInputMenuDialog`, `ServerItemMenuDialog`, `ClientItemMenuDialog`, `ServerSpellMenuDialog`, `ClientSpellMenuDialog`, and `ArgumentedMenuMenuDialog`. That makes this base a cross-family dialog component, not a text-menu-only helper.

The adjacent [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) range is a caller-side menu-dialog factory island, not part of the base class body. Keep it near the merchant/menu dialog family, but do not merge it into `MerchantDialogPane` unless the final source file deliberately groups factory and base helpers together.

IDA confirms `MerchantDialogPane` vtable bases at `0x0061ec10`, `0x0061ec70`, and `0x0061eca0`. Current generated metadata omits these vtables, so use the family page above for reconstruction layout decisions.

## Proposed Contents

| Entity | Address evidence | Current file | Role |
| --- | --- | --- | --- |
| `MerchantDialogPane` constructor | `0x00517d30-0x00517d71` | `class_MerchantDialogPane.cpp` | Initializes the empty-title modal `DialogPane` base, stores the merchant type byte, and installs primary/secondary/tertiary vtables. |
| shared merchant action-string virtual | [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md) | omitted from active class output | Vtable helper that accepts slash-prefixed action strings and normalizes `0...` encoded payloads into a 10-byte outbound packet buffer. |

## Boundary Notes

- IDA does not currently model `0x00517d30` as a function, but raw disassembly shows a complete constructor-shaped body ending at `0x00517d71`.
- IDA does model `0x00517d80-0x00517ebf` as a function, with only data xrefs from merchant/text/item/spell/argumented-menu vtables.
- `0x00517d23-0x00517d30` is alignment padding after the preceding factory helper cluster.
- `0x00517ec0` starts `TextMenuDialog` logic; do not extend the base class range into the text-menu constructor/method island.
- 2026-06-01 IDA MCP recheck: `0x00517d30` remains unmodeled but byte-confirmed as constructor-shaped code; `0x00517d80` remains modeled as `sub_517D80` size `0x13f`; `0x00517ec0` remains the next modeled `TextMenuDialog` function; constructor bytes write the three `MerchantDialogPane` vtable bases at `0x0061ec10`, `0x0061ec70`, and `0x0061eca0`.
- Current generated output still omits the shared virtual body, so reconstruction must account for it explicitly before treating the generated class file as complete.

## Placement Notes

The cleanest migration target is:

```text
NexusTK/ui/dialogs/MerchantDialogPane.cpp
```

If final source reconstruction prefers fewer small files, this base can fold into `TextMenuDialogs.cpp` or a broader `MenuDialogs.cpp`, but it should remain adjacent to [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md), [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md), and [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md).

## Cross-References

- [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md)
- [UID:0001BL][0x00517d30-0x00517ebf.MerchantDialogPaneBase](by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md)
- [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md)
- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:78`.
  - Summary/evidence: shared merchant/menu dialog base role, constructor and action-string virtual, vtable family, boundary notes, placement choices, and cross-family refs are documented; confidence is capped by raw constructor modeling and uncertainty over standalone versus broader menu-dialog source placement.
- 2026-06-01 IDA MCP path/confidence update:
  - What existed before: `COMPLETION:82`, `CONFIDENCE:78`, and blank projected reconstruction path.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:82`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`.
  - Summary/evidence: current IDA MCP recheck reconfirms constructor-shaped bytes, vtable stores, shared virtual xrefs across merchant/text/item/spell/argumented menu dialogs, and the `0x00517ec0` text-menu boundary. Confidence now clears the parent-attachment threshold, while final C++ remains gated by raw constructor modeling and exact file split.
