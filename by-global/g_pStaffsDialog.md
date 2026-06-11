*** UID:0000SC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000O3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pStaffsDialog

## Status

- Confidence: strong for singleton address and class owner.
- Address: `0x0069b490`
- Primary memory doc: [UID:0001PT][0x0069b490-0x0069b494.g_pStaffsDialog](by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md)
- Owner class: [UID:0000DY][StaffsDialogPane](by-class/StaffsDialogPane.md)
- Likely owner source: [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md)

## Symbol Role

`g_pStaffsDialog` stores the active main-menu staff/credits dialog instance. The constructor writes it, the singleton clear helper clears it, and the scalar deleting destructor clears it before chaining to `DialogPane` cleanup.

## Evidence Notes

- 2026-06-06 live IDA MCP byte check reports the slot initialized as `ff ff ff ff`, consistent with the other lazily published UI singleton globals in this area.
- Live IDA MCP reports exactly four data xrefs to the slot: writes from `0x004ffaf6` and `0x004ffafd` inside the constructor, a clear at `0x00502410`, and destructor clear at `0x00502cc6`.
- IDA MCP `xrefs_to 0x00502410` reports a constructor-context xref at `0x00601e35`, consistent with small cleanup/unwind support rather than an independent feature entry point.
- 2026-05-26 recheck classifies `0x00502410` as compiler-generated constructor EH cleanup and records it in [UID:0000VN][-ignored](by-memory/-ignored.md), while keeping `g_pStaffsDialog` itself reconstructable project data.

## Open Questions

- Whether the constructor has an indirect menu-command caller not represented in IDA's direct caller list.

## Cross-References

- [UID:0000DY][StaffsDialogPane](by-class/StaffsDialogPane.md)
- [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md)
- [UID:0001PT][0x0069b490-0x0069b494.g_pStaffsDialog](by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md)
- [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md)
- [UID:0001RM][staff-dialog-resources](by-resource/staff-dialog-resources.md)

## Changes

- 2026-06-06: Raised completion to `84` after a live IDA MCP recheck confirmed the initialized bytes, exact four-reference singleton lifecycle, and owner-side constructor/destructor boundaries.
  - Reasoning: the storage has no remaining unresolved writer/reader ambiguity at the global level; final reconstruction C++ stays blank because the page documents data ownership rather than a complete source-level implementation.
- 2026-06-05: Marked reconstructable and attached to [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md) to resolve the global unclassified coverage row.
  - Reasoning: live IDA xrefs cover the complete four-reference singleton lifecycle inside the staff dialog constructor, constructor-cleanup helper, and destructor; the parent file is now projected to `NexusTK/login/`. No score change and no reconstruction C++ were added.
- What existed before: this page had correct owner/lifetime notes but unevaluated completion/confidence metadata and evidence bullets that mixed in non-live provenance context.
- What changed to: the page now uses live IDA MCP as the evidence source for storage shape and all four data xrefs. Completion/confidence are now `84/88`.
- Summary and evidence: IDA MCP on 2026-05-30 verified `0x0069b490` as a 4-byte `.data` singleton pointer with constructor assignment/fallback at `0x004ffaf6`/`0x004ffafd`, constructor cleanup clear at `0x00502410`, and destructor clear at `0x00502cc6`.
