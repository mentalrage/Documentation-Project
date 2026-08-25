*** UID:0000VD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Scoped Marker Generated-Body Quality Issues

## Status

- Queue status: ignored/not scored for source-coverage work.
- Issue type: generated-output/source-emission tracker, not a confirmed recovered-source behavior.
- Rebuild handling: not a reconstructable code item. This page tracks generated-source quality defects; the underlying methods should be documented and rebuilt through their own class/memory/file pages.
- Current documentation state: retained as a cross-cutting quality warning only; do not use this page as evidence for project-code coverage or score increases because it has no single source owner or address range.

## Pattern

Some active `simroot_v2` method sections have a `NTK_Scoped...` marker for a real method address, but the emitted body is missing, decompiler-shaped, still named `sub_xxxxxxxx`, or otherwise not migration-ready despite high generated scores.

Treat these sections as incomplete reconstruction work. A high manual/imported grade does not make the emitted source migration-ready when the method body is absent.

2026-05-31 current-state note: the examples below no longer all demonstrate a literal missing-body defect. Several now emit a body, but the body is still decompiler-shaped or marked `complete=no`. Keep this page as a warning against treating scoped-marker/high-score output as final source; do not use it as proof that every listed method is currently bodyless.

## Current Examples

The examples below are retained as historical generated-output warnings. They are not live source-coverage evidence; use the owning class/memory/file pages and fresh IDA evidence for any real reconstruction work.

| Method | IDA range | Current emitted source evidence |
| --- | --- | --- |
| `MyItemListPane::DrawListEntry` | `0x004aec90-0x004af031` | Current `simroot_v2/ui/dialogs/class_MyItemListPane.cpp` emits a body, but it is decompiler-shaped with generic locals and low fidelity despite score `95.0` and `complete=no`. |
| `FolderTreePane::SetSelection` | `0x004b3210-0x004b32c9` | B011 2026-06-26 implementation updates [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md) with formal source-shaped C++ using `GetScrollPosition`, `GetScrollMax`, `ApplyScrollPosition`, inherited `m_contentRect`, and `InvalidateRect(NULL)`. Current generated `FolderTreePane.cpp` has source-shaped code, but generated score comments/tracker rows may still show stale `78/86` metadata until validator refresh catches up. This row remains only as a generated-output quality warning, not evidence that the by-memory page lacks code. |
| `LineInputPane::HandleKeyInput` | `0x004f25a0-0x004f2754` | Current `class_LineInputPane.cpp` emits a raw `sub_4F25A0` body with generated symbols and decompiler artifacts despite score `97.0` and `complete=no`. |
| `RegistryConfig::SaveToRegistry` | `0x00491b30-0x00492695` | Current `class_RegistryConfig.cpp` emits a raw `sub_491B30` body with generated locals/symbols despite score `95.0` and `complete=no`. |
| `RegistryConfig::LoadFromRegistry` | `0x004926a0-0x00493e29` | Current `class_RegistryConfig.cpp` emits a raw `sub_4926A0` body with generated locals/symbols despite score `95.0` and `complete=no`. |
| `OldSystemMessagePane::OldSystemMessagePane` | `0x00588e30-0x00589173` | Current `class_OldSystemMessagePane.cpp` emits a constructor body, but it still contains vtable/decompiler artifacts and is not final-source quality. |
| `MenuQuestionDialogLarger::MenuQuestionDialogLarger` | `0x0054fb30-0x00550afb` | Current `class_MenuQuestionDialogLarger.cpp` emits a raw `sub_54FB30` constructor body with decompiler artifacts despite score `100.0` and `complete=no`. |
| `EmotionInputPane::OnCharInput` | `0x005b2a70-0x005b2f68` | B009 2026-06-21 recheck found the current generated output in `auto-generated/NexusTK/ui/dialogs/CommandInputPanes.cpp` has empty emitter markers for [UID:00004B][EmotionInputPane](by-class/EmotionInputPane.md)/[UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md)/[UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md), not an active raw `sub_5B2A70` body. B006 2026-06-26 accepted implementation now supplies first-draft formal constructor and `OnCharInput()` C++ on the emitting by-memory page [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md), including exact `a-l`/`m-n`/`o-p` selector arithmetic, current/legacy `?` menu branches, and the call into separate helper [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md). This row remains a generated-output quality tracker until generated `CommandInputPanes.cpp` refreshes; the class page stays declaration-only and the helper remains separate. |

## IDA MCP Evidence

Rechecked on 2026-05-31:

- IDA confirms each listed address is a real function with the documented exclusive end or exact endpoint family: `0x004aec90-0x004af031`, `0x004b3210-0x004b32c9`, `0x004f25a0-0x004f2754`, `0x00491b30-0x00492695`, `0x004926a0-0x00493e29`, `0x00588e30-0x00589173`, `0x0054fb30-0x00550afb`, and `0x005b2a70-0x005b2f68`.
- IDA decompilation also shows these functions are substantial project-code bodies, not padding or runtime stubs. The current issue is generated-source quality/ownership, not whether the code exists.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | -1 | Ignored for source-coverage scoring because the page is a generated-output quality tracker, not a source unit, memory range, class, file, type, global, resource, or reconstructable item. |
| Confidence | -1 | Ignored for source-coverage scoring; confidence belongs on the owning class/memory/file pages after fresh IDA-backed review. |
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

- 2026-06-26 B011 FolderTreePane `SetSelection` correction:
  - Updated the `FolderTreePane::SetSelection` row to record that [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md) now carries formal C++ with accepted `ScrollablePane` helper names and `InvalidateRect(NULL)`, while any stale `78/86` generated comments/tracker rows are validator refresh state.
  - Evidence: B011 report `000156-FolderTreePaneSetSelection-source-quality.md` confirmed active MCP session `80de0a67`, exact function/helper sizes, three normal callers, direct helper call sites, and current generated/source-page mismatch.
- What existed before: the page claimed the listed examples were missing emitted method bodies and had no score or reconstructable classification.
- What it was changed to: the page now tracks scoped-marker generated-body quality issues; the examples are updated to reflect current generated bodies where present, and the page is marked non-reconstructable because it is a data-quality tracker rather than a code item.
- Summary and evidence: IDA MCP verification on 2026-05-31 confirmed the method ranges are real project code, while current `simroot_v2` snippets show several listed examples now emit decompiler-shaped bodies rather than literal `WAVE3 OMITTED METHOD BODY` placeholders.
- 2026-06-02: Raised from `50/75` to `70/82` after confirming the page is now a useful tracker with current examples, IDA range evidence, handling rules, and owner cross-references. Kept `RECONSTRUCTABLE:FALSE` and parent blank because this page intentionally tracks a cross-file generated-output condition rather than a source-owned code range.
- 2026-06-04: Changed completion/confidence from `70/82` to `-1/-1`.
  - Before: The page appeared in the low-completion queue even though its own status and reconstructable flag identified it as a generated-output quality tracker with no single source owner or address range.
  - After: Marked ignored/not scored for source-coverage work so the queue focuses on live IDA-backed project-code documentation instead of generated-output caveats.
  - Evidence: The page is `RECONSTRUCTABLE:FALSE`, documents no canonical source unit, and directs real reconstruction work to the owning class/memory/file pages.
- 2026-06-21 Rule 26 B009 EmotionInputPane correction:
  - Updated the EmotionInputPane row from the stale raw `sub_5B2A70` symptom to the current empty-emitter-marker symptom in `auto-generated/NexusTK/ui/dialogs/CommandInputPanes.cpp`.
  - Evidence: B009 rechecked the generated output and the owning docs [UID:00004B][EmotionInputPane](by-class/EmotionInputPane.md), [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md), and [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md).
- 2026-06-26 B006 EmotionInputPane implementation support sync:
  - Updated the EmotionInputPane row to record that accepted formal constructor and `OnCharInput()` C++ now lives on [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md).
  - Evidence: B006 MCP session `80de0a67` confirmed constructor size `176`, handler size `1272`, vtable slot `0x0062fa00`, exact selector arithmetic, current/legacy menu branches, and the separate `SendEmotionPacket` helper route. This tracker still records generated-output staleness only and does not own or emit reconstruction C++.
