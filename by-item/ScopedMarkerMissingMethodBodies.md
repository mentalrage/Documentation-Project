*** UID:0000VD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Scoped Marker Generated-Body Quality Issues

## Status

- Confidence: strong for the generated-source quality pattern and example IDA function boundaries; medium for whether any listed row still has a fully missing emitted body in the current generated tree.
- Issue type: Wave3 data/source-emission issue, not a confirmed recovered-source behavior.
- Rebuild handling: not a reconstructable code item. This page tracks generated-source quality defects; the underlying methods should be documented and rebuilt through their own class/memory/file pages.
- Current documentation state: sufficient as a cross-cutting quality tracker; it should not be promoted into a reconstructable code page because it has no single source owner or address range.
- Tracking issue: [Wave3 data issues](../wave3_data_issues.md)
- Detection support: [Wave3 tool guide](../wave3_tool_guide.md)

## Pattern

Some active `simroot_v2` method sections have a `NTK_Scoped...` marker for a real method address, but the emitted body is missing, decompiler-shaped, still named `sub_xxxxxxxx`, or otherwise not migration-ready despite high generated scores.

Treat these sections as incomplete reconstruction work. A high manual/imported grade does not make the emitted source migration-ready when the method body is absent.

2026-05-31 current-state note: the examples below no longer all demonstrate a literal missing-body defect. Several now emit a body, but the body is still decompiler-shaped or marked `complete=no`. Keep this page as a warning against treating scoped-marker/high-score output as final source; do not use it as proof that every listed method is currently bodyless.

## Current Examples

This pass did not run `wave3.py` directly. The examples below were rechecked from current `simroot_v2` source and IDA MCP function-boundary evidence.

| Method | IDA range | Current emitted source evidence |
| --- | --- | --- |
| `MyItemListPane::DrawListEntry` | `0x004aec90-0x004af031` | Current `simroot_v2/ui/dialogs/class_MyItemListPane.cpp` emits a body, but it is decompiler-shaped with generic locals and low fidelity despite score `95.0` and `complete=no`. |
| `FolderTreePane::SetSelection` | `0x004b3210-0x004b32c9` | Current `class_FolderTreePane.cpp` emits a raw `sub_4B3210` body after the scoped marker; it is not original-source quality despite score `97.0` and `complete=no`. |
| `LineInputPane::HandleKeyInput` | `0x004f25a0-0x004f2754` | Current `class_LineInputPane.cpp` emits a raw `sub_4F25A0` body with generated symbols and decompiler artifacts despite score `97.0` and `complete=no`. |
| `RegistryConfig::SaveToRegistry` | `0x00491b30-0x00492695` | Current `class_RegistryConfig.cpp` emits a raw `sub_491B30` body with generated locals/symbols despite score `95.0` and `complete=no`. |
| `RegistryConfig::LoadFromRegistry` | `0x004926a0-0x00493e29` | Current `class_RegistryConfig.cpp` emits a raw `sub_4926A0` body with generated locals/symbols despite score `95.0` and `complete=no`. |
| `OldSystemMessagePane::OldSystemMessagePane` | `0x00588e30-0x00589173` | Current `class_OldSystemMessagePane.cpp` emits a constructor body, but it still contains vtable/decompiler artifacts and is not final-source quality. |
| `MenuQuestionDialogLarger::MenuQuestionDialogLarger` | `0x0054fb30-0x00550afb` | Current `class_MenuQuestionDialogLarger.cpp` emits a raw `sub_54FB30` constructor body with decompiler artifacts despite score `100.0` and `complete=no`. |
| `EmotionInputPane::OnCharInput` | `0x005b2a70-0x005b2f68` | Current `class_EmotionInputPane.cpp` emits a raw `sub_5B2A70` body with generated locals/symbols despite score `70.0` and `complete=no`. |

## IDA MCP Evidence

Rechecked on 2026-05-31:

- IDA confirms each listed address is a real function with the documented exclusive end or exact endpoint family: `0x004aec90-0x004af031`, `0x004b3210-0x004b32c9`, `0x004f25a0-0x004f2754`, `0x00491b30-0x00492695`, `0x004926a0-0x00493e29`, `0x00588e30-0x00589173`, `0x0054fb30-0x00550afb`, and `0x005b2a70-0x005b2f68`.
- IDA decompilation also shows these functions are substantial project-code bodies, not padding or runtime stubs. The current issue is generated-source quality/ownership, not whether the code exists.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 70 | The page now has a stable purpose, current examples, concrete IDA range evidence, handling rules, and cross-references to the owning docs for each affected method family. |
| Confidence | 82 | Confidence is above the attachment threshold for the tracker itself because the listed addresses and quality pattern were IDA/source checked, but it remains capped because the current generated tree can change and each affected method still needs its own source-quality review. |
| Reconstructable | false | This is not a source unit. It records a generated-output quality condition across unrelated methods, so reconstructed C++ must live on the individual method/file/memory pages. |

## Handling Rule

Do not migrate an affected method from generated C++ just because the containing class has a good grade. For each row, use IDA/source evidence to either:

- reconstruct the missing body;
- intentionally classify the range as omitted with a source-authoritative reason; or
- correct the method/function boundary if the row is a projection artifact.

## Cross-References

- [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md)
- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- [UID:000077][LineInputPane](by-class/LineInputPane.md)
- [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md)
- [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md)
- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:00007Y][MenuQuestionDialogLarger](by-class/MenuQuestionDialogLarger.md)
- [UID:00004B][EmotionInputPane](by-class/EmotionInputPane.md)
- [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- [UID:000111][0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup](by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md)
- [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)
- [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)
- [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md)

## Changes

- What existed before: the page claimed the listed examples were missing emitted method bodies and had no score or reconstructable classification.
- What it was changed to: the page now tracks scoped-marker generated-body quality issues; the examples are updated to reflect current generated bodies where present, and the page is marked non-reconstructable because it is a data-quality tracker rather than a code item.
- Summary and evidence: IDA MCP verification on 2026-05-31 confirmed the method ranges are real project code, while current `simroot_v2` snippets show several listed examples now emit decompiler-shaped bodies rather than literal `WAVE3 OMITTED METHOD BODY` placeholders.
- 2026-06-02: Raised from `50/75` to `70/82` after confirming the page is now a useful tracker with current examples, IDA range evidence, handling rules, and owner cross-references. Kept `RECONSTRUCTABLE:FALSE` and parent blank because this page intentionally tracks a cross-file generated-output condition rather than a source-owned code range.
