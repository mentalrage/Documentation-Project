*** UID:0000DU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SpellStringInputPane : public LineInputPane
{
public:
    explicit SpellStringInputPane(char spellIndex);
    virtual ~SpellStringInputPane();

protected:
    virtual void OnConfirmInput();

private:
    char m_spellIndex;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

## UID0001LM Signed Prompt-Class Synchronization - 2026-07-19

- The complete declaration now takes plain `char spellIndex` and stores plain `char m_spellIndex` at complete-object `+0x108`. Repeated constructor/consumer `movsx` proves signed semantics; the object remains exactly `0x10c` bytes with natural tail alignment at `+0x109..+0x10b`.
- The class closes before `[[CHILDREN]]`, so exact child definitions emit at namespace scope rather than inside the class. Inheritance and every existing method declaration/access level are unchanged.
- Metadata rises `87/88 -> 89/92` because signed type, exact natural layout, complete declaration, and generated structure are closed. Exact owner/emitter/source route, unrelated method bodies, retained or ownerless no-route raw helpers, destructor/scalar/adjustor evidence, compiler exclusions, and history remain intact.
- Constructors use the shared public inline `UserPane::GetSpellPromptText(char) const`; no private cross-TU table access, `UserSpellRecord`, `GetSpellRecord`, or raw vtable/RTTI/compiler source is introduced.

# SpellStringInputPane
## UID0000LU Header Placement Synchronization - 2026-08-15

The accepted complete SpellStringInputPane declaration was moved verbatim from CPP to H so NewSpellInventoryPane may construct it through `SpellInputPanes.h`. Existing constructor, destructor, and confirmation children remain the only definitions; no wrapper API or duplicate class declaration was added.

## Status

- Confidence: strong for behavior, IDA boundaries, destructor split, scalar-wrapper policy, and the source-ready confirm handler; medium for final class declaration spelling.
- Likely source file: [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- Address range: [UID:0001KV][0x005adf40-0x005ae1a4.SpellStringInputPane](by-memory/0x005adf40-0x005ae1a4.SpellStringInputPane.md), plus shared prompt helper [UID:00018Y][0x004f20a0-0x004f22f4.LineInputPaneSetPromptText](by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md).
- Parent attachment: attached to [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md); both pages now clear the corrected 85/85 gate.
- Reconstruction block: intentionally blank; the direct destructor split, scalar-wrapper policy, and confirm-handler packet/local model are resolved at child pages, but final class declaration still needs a coordinated field/class declaration pass before class-level C++ should be emitted.

## Class Purpose

`SpellStringInputPane` is the string-argument spell prompt. It builds a [UID:000077][LineInputPane](by-class/LineInputPane.md), displays the spell name/prompt, reads the entered text, converts it to the outbound client character form, and sends opcode `0x0f` with the spell index and string payload.

## Method Notes

| Method/helper | Address | Role |
| --- | --- | --- |
| `SetPromptText` | [UID:00018Y][0x004f20a0-0x004f22f4.LineInputPaneSetPromptText](by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md) | Shared spell prompt layout/text helper used by multiple spell input panes. |
| constructor | [UID:0001KU][0x005adf40-0x005adfcd.SpellStringInputPaneConstructor](by-memory/0x005adf40-0x005adfcd.SpellStringInputPaneConstructor.md) | Builds the line-input base, installs vtables, sets spell prompt text from player spell data, and stores the spell slot index. |
| direct destructor | [UID:0003AG][0x005adfd0-0x005ae053.SpellStringInputPaneDirectDestructor](by-memory/0x005adfd0-0x005ae053.SpellStringInputPaneDirectDestructor.md) | Restores the three vtable views, closes or refreshes the spell panel child depending on `byte_66DA97`, and runs shared line-input cleanup. |
| `OnConfirmInput` | [UID:0001KW][0x005ae060-0x005ae1a4.SpellStringInputPaneConfirmInput](by-memory/0x005ae060-0x005ae1a4.SpellStringInputPaneConfirmInput.md) | Source-ready first-draft C++; validates and sanitizes input text, converts it with `WideCharToMultiByte`, sends opcode `0x0f` as `[opcode, m_spellIndex, encoded text bytes]`, and queues exactly `encodedLength + 2` bytes. |
| adjustor thunks | [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md) | Secondary/tertiary vtable thunks to `0x005b7e90`; source reconstruction excludes them through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:0001NH][0x005b7e90-0x005b7f54.SpellStringInputPaneScalarDeletingDestructor](by-memory/0x005b7e90-0x005b7f54.SpellStringInputPaneScalarDeletingDestructor.md) | Raw-byte-confirmed compiler wrapper for `SpellStringInputPane::~SpellStringInputPane()`; routes through primary vtable or `this-0xa0`/`this-0xa4` adjustor thunks, restores panel state through `g_useEpfAssets`, `g_pGeneralPurposePanel`, and child index `3`, runs `LineInputPane` cleanup, handles scalar-delete flags, and should not emit handwritten C++. |

## Evidence Notes

- [UID:0001KU][0x005adf40-0x005adfcd.SpellStringInputPaneConstructor](by-memory/0x005adf40-0x005adfcd.SpellStringInputPaneConstructor.md) records live IDA evidence for exact constructor bounds, base `LineInputPane` construction, three vtable stores, spell-record prompt lookup through [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md), the `this + 0x108` stored spell slot, and three spell-cast callers.
- [UID:0001KV][0x005adf40-0x005ae1a4.SpellStringInputPane](by-memory/0x005adf40-0x005ae1a4.SpellStringInputPane.md) records the contiguous constructor/direct-destructor/confirm map; the direct destructor now has its own exact child page.
- [UID:0001KW][0x005ae060-0x005ae1a4.SpellStringInputPaneConfirmInput](by-memory/0x005ae060-0x005ae1a4.SpellStringInputPaneConfirmInput.md) records B012 live MCP session/database `80de0a67`, exact range `0x005ae060-0x005ae1a4`, vtable ref `0x0062f1cc`, 256-wide input, 256-byte encoded, and 300-byte packet locals, `g_pTextFilter`/sanitizer context, `g_packetSender` handoff, packet layout `[0x0f, m_spellIndex, encodedText...]`, sent length `WideCharToMultiByte(...) + 2`, local-only terminators, and first-draft formal `OnConfirmInput` C++.
- [UID:0003AG][0x005adfd0-0x005ae053.SpellStringInputPaneDirectDestructor](by-memory/0x005adfd0-0x005ae053.SpellStringInputPaneDirectDestructor.md) records live IDA evidence for the direct destructor boundary, vtable restores, `byte_66DA97` branch, general-purpose panel child lookup, panel activation/close calls, and shared line-input cleanup.
- [UID:0001NH][0x005b7e90-0x005b7f54.SpellStringInputPaneScalarDeletingDestructor](by-memory/0x005b7e90-0x005b7f54.SpellStringInputPaneScalarDeletingDestructor.md) records live IDA evidence plus B004 raw PE evidence for the scalar deleting destructor, including exact body bytes, twelve-byte post-padding, vtable restores, `g_useEpfAssets` / `g_pGeneralPurposePanel` state-helper selection, GeneralPurposePanel child index `3`, shared input-pane cleanup, scalar-delete flag handling, raw adjustor thunk bytes, and vtable data refs. The page intentionally keeps formal C++ blank as compiler wrapper output.
- [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md) records the secondary and tertiary destructor adjustor thunks at `0x005b78ba` and `0x005b78c5`; they are compiler-generated wrappers and remain excluded from source reconstruction.
- `SetPromptText` is shared with spell target/slot/selection prompts, so it is source-owned by spell input UI, not a one-method utility source.

## Open Questions

- The confirm-handler packet layout, string byte-count length, and local buffer roles are resolved on [UID:0001KW][0x005ae060-0x005ae1a4.SpellStringInputPaneConfirmInput](by-memory/0x005ae060-0x005ae1a4.SpellStringInputPaneConfirmInput.md); they no longer block that exact child.
- Class-level formal C++ remains pending broader declaration work: exact original field spelling for `m_spellIndex`, the spell-table owner name, inheritance/member declarations, and coordinated constructor/direct-destructor/handler presentation.

## Cross-References

- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0001KV][0x005adf40-0x005ae1a4.SpellStringInputPane](by-memory/0x005adf40-0x005ae1a4.SpellStringInputPane.md)
- [UID:0003AG][0x005adfd0-0x005ae053.SpellStringInputPaneDirectDestructor](by-memory/0x005adfd0-0x005ae053.SpellStringInputPaneDirectDestructor.md)
- [UID:0000DX][SpellWhoInputPane](by-class/SpellWhoInputPane.md)
- [UID:0000DS][SpellSlotInputPane](by-class/SpellSlotInputPane.md)
- [UID:0000DT][SpellSpellInputPane](by-class/SpellSpellInputPane.md)
- [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md)

## Changes

- 2026-06-30 B002 SpellInputPanes implementation callback:
  - Added the accepted declaration-only `SpellStringInputPane : public LineInputPane` formal C++ block with `m_spellIndex` and `[[CHILDREN]]`.
  - Exact constructor, confirm handler, and direct destructor source bodies remain on the by-memory child pages; the scalar deleting destructor page remains compiler-wrapper coverage.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Evidence: the page documents line-input behavior, shared prompt helper, constructor/confirm/destructor/thunk memory docs, opcode/string packet behavior, and ignored adjustor-thunk handling; confidence is capped by exact source split and shared helper ownership.
- 2026-06-05: Marked reconstructable and left unassigned.
- Evidence: live IDA MCP `lookup_funcs` confirms the shared prompt helper, constructor, confirm handler, scalar deleting destructor, and adjustor thunks at `0x004f20a0`, `0x005adf40`, `0x005ae060`, `0x005b7e90`, `0x005b78ba`, and `0x005b78c5`. The likely parent file meets 80/80, but this class confidence is `78`, so the parent UID stays blank.
- 2026-06-06: Raised confidence from `78` to `82`, attached the class to [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md), removed generated-source provenance wording, and replaced the thin evidence note with child-page-backed evidence for constructor, aggregate, scalar destructor, and adjustor thunks.
  - Before: the page still treated the exact source split as a confidence blocker and did not attach to the file parent.
  - After: the source split is still a caveat, but the class/file relationship now clears the documented 80/80 attachment gate; final C++ remains blank because the direct destructor split, confirm-handler evidence, and source-quality field/local names are still incomplete.
- 2026-06-11 Batch 197 strict-gate repair:
  - Before: `84/82`, attached under the old gate with an unsplit direct destructor and stale confirm-handler evidence caveat.
  - After: `86/86`; parent [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md) now also clears 85 confidence.
  - Evidence: created the exact direct-destructor child, refreshed confirm-handler callee evidence, and updated the contiguous aggregate as a non-emitting index. Final C++ remains blank because packet-buffer locals, field names, and class declaration details are not 95/95.
- 2026-06-18 B004 scalar-wrapper source-quality sync:
  - Score unchanged at `86/86`.
  - Summary/evidence: [UID:0001NH][0x005b7e90-0x005b7f54.SpellStringInputPaneScalarDeletingDestructor](by-memory/0x005b7e90-0x005b7f54.SpellStringInputPaneScalarDeletingDestructor.md) is now raw-byte-confirmed at `86/90` with exact PE offsets, hashes, vtable/thunk route, resolved `g_useEpfAssets` / `g_pGeneralPurposePanel` aliases, and a final no-handwritten-C++ scalar deleting destructor policy. The class page no longer treats the direct destructor split as pending; the B004-era confirm-handler packet/local blocker is superseded by the 2026-06-26 B012 entry below, leaving only final field/class declaration spelling as class-level C++ follow-up.
- 2026-06-26 B012 confirm-handler source-quality sync:
  - Before: `86/86`, with the confirm handler still treated as blocked by packet-buffer locals, string length, and final field naming.
  - After: `87/88`; [UID:0001KW][0x005ae060-0x005ae1a4.SpellStringInputPaneConfirmInput](by-memory/0x005ae060-0x005ae1a4.SpellStringInputPaneConfirmInput.md) now carries first-draft C++ and resolves the exact packet layout, `WideCharToMultiByte` length, local-only terminators, `m_spellIndex`, sanitizer, and sender handoff. Class-level C++ remains blank only because declaration-level field/inheritance presentation still needs a coordinated pass.
