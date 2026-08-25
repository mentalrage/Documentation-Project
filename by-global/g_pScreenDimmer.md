*** UID:0000S5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ScreenDimmer *g_pScreenDimmer = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pScreenDimmer

## Status

- Confidence: very strong for typed identity, zero initialization, direct ScreenDimmer owner, implicit Singleton lifecycle, 40-reference liveness, and one-definition source placement; exact original `g_p` spelling remains inferred.
- Symbol kind: global singleton pointer.
- Address: exact zero-filled storage at `0x0069ae08`; historical decompiler aliases include `dword_69AE08` and `unk_69AE08`.
- Likely owner: [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)
- Exact storage page: [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md), now attached to [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)
- Assignment status: score `92/94`, owner/emitter UID0000NA retained, source position `20`, and sole external-linkage definition emitted in `NexusTK/ui/core/ScreenDimmer.cpp`.

## Role

`g_pScreenDimmer` stores the active modal dim overlay as a typed `ScreenDimmer *`. Direct construction of `Singleton<ScreenDimmer>` publishes it implicitly; ordinary destruction, scalar-wrapper lowering, and constructor-unwind cleanup clear it as consequences of the Singleton base lifecycle. The human UID000392 constructor does not assign or clear this global explicitly.

Live IDA also has a non-emitting constructor EH cleanup/funclet target at [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md) that clears the singleton directly. Treat that target as ScreenDimmer lifecycle cleanup documentation, not as a public global API, class method, source-authored helper body, or generated source marker.

The exact `.data` slot is [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md). That page carries the address-range and source-declared/generated-binary reconstruction evidence; this global page remains the name/lifetime/owner summary.

## Source Definition And One-Definition Policy

- This page emits exactly `ScreenDimmer *g_pScreenDimmer = NULL;` at file position `20`. UID0000C8 declares `extern ScreenDimmer *g_pScreenDimmer;` in the complete class block.
- UID00029D represents the same linker-assigned four-byte `.data` slot and emits only a comment marker. It must not emit another variable definition, anonymous storage array, or address-bound object.
- `ScreenDimmer *` is stronger than `Pane *` or `void *`: constructor/factory allocation produces the complete ScreenDimmer object, destructor consumers invoke the ScreenDimmer deleting path, and all observed accesses use singleton identity rather than a broader interface contract.
- `NULL` preserves the observed zero-filled image value and period-appropriate source style. The historical `0xffffffff` reading is stale and is not a valid initializer.
- Broad dialog/menu/session/map readers demonstrate shared liveness, not ownership. Generic UI-core ScreenDimmer source remains the narrow semantic owner.

Two additional DialogSession-island helpers are part of this same global family even though exact child pages are not split yet:

| Address | Best source-facing role | Evidence |
| --- | --- | --- |
| `0x004a1360-0x004a1371` | `ReleaseScreenDimmer()` / `DestroyScreenDimmer()` | Reads only `g_pScreenDimmer`, ignores the apparent caller `ecx`, and calls the dimmer deleting destructor when the global is present. |
| `0x004a1380-0x004a138b` | `IsScreenDimmerActive()` / `HasScreenDimmer()` | Raw body tests `g_pScreenDimmer != 0` and returns the result. B002 found 24 direct calls, commonly paired with `0x004a1360`; the older `unknown_libname_11` runtime/library label is rejected for source documentation. |

## Evidence

- Live IDA MCP check on 2026-05-30 confirms `0x0069ae08` is `dword_69AE08`, a 4-byte `.data` item with 40 data xrefs.
- Live IDA MCP on 2026-06-10 reconfirms 40 direct data xrefs to `0x0069ae08`; the writer set remains the ScreenDimmer lifecycle sites while dialog/menu/session/map consumers only read or test the singleton.
- Live IDA MCP on 2026-06-16 reconfirms the same 40 direct data xrefs to `0x0069ae08`; C001 saved function labels for `ScreenDimmer_Constructor`, `ScreenDimmer_Destructor`, historical/documentation `ClearScreenDimmerSingleton`, `ScreenDimmer_ScalarDeletingDestructor`, and `CreateScreenDimmerFactory`. B004's current MCP session `43ccf853` reports the UID0001GB function itself as `sub_55A030` and the slot as `unk_69AE08`, so `ClearScreenDimmerSingleton` should not be presented as the current IDA name.
- 2026-07-14 live MCP reanalysis preserves exactly 40 refs and zero image bytes, while RTTI proves direct `Singleton<ScreenDimmer>` at complete-object `+0xf8`. The constructor publish/null-adjust sites are therefore compiler lowering of base construction, not handwritten global assignments.
- Live IDA MCP `lookup_funcs` on 2026-06-10 reports the owning lifecycle functions as `sub_559B90` size `0x156`, 342 decimal bytes (Verified with int_convert.py), ordinary destructor `sub_559CF0` size `0xd4`, 212 decimal bytes (Verified with int_convert.py), tiny clear helper `sub_55A030` size `0xb`, 11 decimal bytes (Verified with int_convert.py), scalar deleting destructor `sub_55A070` size `0x103`, 259 decimal bytes (Verified with int_convert.py), and factory `sub_4A12B0` size `0xb0`, 176 decimal bytes (Verified with int_convert.py).
- Lifecycle writes are concentrated in the ScreenDimmer block: `0x00559be4` stores the constructed pointer, `0x00559beb` clears the null/fallback path, `0x00559d9b` clears during cleanup, `0x0055a030` is the non-emitting constructor EH cleanup/funclet clear target, and `0x0055a122` clears during the deleting-destructor path.
- 2026-06-10 decompilation/disassembly confirms the constructor stores `this` to `dword_69AE08` after deriving the object base from the dim-level byte at `this+0xf8`, 248 decimal bytes (Verified with int_convert.py), installs vtables at object base, `+0xa0` / 160 decimal bytes (Verified with int_convert.py), and `+0xa4` / 164 decimal bytes (Verified with int_convert.py), then registers the `+0xa0` interface in the modal list.
- 2026-06-10 decompilation confirms `CreateScreenDimmer_4A12B0` allocates `0xfc` bytes, 252 decimal bytes (Verified with int_convert.py), and constructs a level-5 `ScreenDimmer` through `0x00559b90`; this proves factory use, not independent ownership of the singleton.
- 2026-07-07 B004 MCP session `43ccf853` `xrefs_to 0x0055a030` reports one cleanup/funclet jump xref at `0x006074a1`; focused disassembly at `0x00607498-0x006074a1` computes `this+0xf8` in `ecx` then jumps to `sub_55A030`, and the target ignores `ecx`. This resolves UID0001GB as local ScreenDimmer constructor unwind cleanup rather than a public global API or source-authored helper.
- Representative consumers include modal/menu/dialog flows at `0x004a0f05`, `0x004a1360`, `0x004a1380`, `0x004a1599`, `0x004f69a0`, `0x004f8a9f`, `0x004f8ebc`, `0x004fa5fd`, `0x004fab7c`, `0x004fcb57`, `0x004fec28`, `0x004fee8d`, and the `0x00502xxx`/`0x0052xxxx` dialog families.
- B002 2026-06-19 DialogSession reanalysis found 24 direct calls to `0x004a1360` and 24 direct calls to `0x004a1380`. These are broad consumers of the active dimmer singleton, not evidence that DialogSession owns the global.
- Later consumers at `0x0057406d`, `0x005742ca`, `0x00587eb2`, and `0x00588043` confirm the singleton remains a generic overlay dependency beyond the constructor/destructor block.
- Keep this as an alias/ownership page rather than duplicating backing-storage documentation; the exact storage is documented at [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md), while [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md) documents the tiny clear helper.
- 2026-06-06 A009/A010 refresh: [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md) now records exact bytes, no callees, no ordinary callers, one cleanup/funclet xref, and the lifecycle-defining `g_pScreenDimmer` refs; [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md) is attached to [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md).

## Ownership Guidance

Define this once in `NexusTK/ui/core/ScreenDimmer.cpp` and declare it from the complete ScreenDimmer class/header surface. Do not give the storage to `MapRefreshDimmer`, DialogSession, a caller-local dialog, or ScreenFadeOut; those are consumers or peers, while this singleton represents the generic modal ScreenDimmer overlay.

## Open Questions

- Type resolution: use `ScreenDimmer *`; broader `Pane *`/interface and `void *` alternatives lose proven constructor/destructor identity and are rejected.
- Helper `0x0055a030` is resolved for current documentation as non-emitting constructor EH cleanup/funclet support around the dimmer singleton. A future normal caller, recovered source map, or stronger source-name artifact would be needed to reopen it as a named teardown function.
- The explicit IDA data label remains unapplied because the current MCP `rename` tool rejected both name-based `dword_69AE08` and address-based `0x0069ae08` data rename attempts; existing decompilation now shows `unk_69AE08`. Keep the documented source name `g_pScreenDimmer` but do not force an unsupported DB data mutation.
- Exact original lexical spelling and header declaration location remain sub-95 confidence caps; they do not block the typed definition or justify duplicate storage.

## Cross-References

- [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)
- [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md)
- [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md)
- [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md)
- [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md)
- [UID:0000PJ][CreateScreenDimmer_4A12B0](by-global/CreateScreenDimmer_4A12B0.md)

## Changes

- 2026-07-14 B004 UID000392 source-quality callback:
  - Raised `87/89` to `92/94`, retained owner/emitter UID0000NA, set source position `20`, and installed the sole `ScreenDimmer *g_pScreenDimmer = NULL;` definition.
  - Added the typed external-linkage contract, exact zero storage/40 refs, direct Singleton EBO publication and ordinary/scalar/unwind cleanup lifecycle, class extern declaration, one-definition policy, source placement, and rejected raw/void/duplicate-storage alternatives.
  - Historical direct handwritten constructor-assignment and unresolved pointer-type wording are superseded; binary write sites remain preserved as compiler provenance.

- 2026-07-07 B004 UID0001GB support sync:
  - Changed the `0x0055a030` helper wording to non-emitting constructor EH cleanup/funclet support.
  - Evidence: accepted B004 report and MCP session `43ccf853` prove the sole cleanup xref at `0x006074a1`, ignored `ecx`, no callees, no ordinary callers, no raw pointer/vtable route, current `sub_55A030`/`unk_69AE08` names, and current zero-valued `0x0069ae08` slot.

- 2026-06-16 C001 Goal 2 global/IDA refresh:
  - Changed to: `COMPLETION:87` and `CONFIDENCE:89`.
  - Summary/evidence: live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed zero-filled neighboring storage bytes, 40 xrefs to `0x0069ae08`, constructor publish/null-clear, ordinary destructor clear, tiny clear helper, scalar-deleting destructor clear, factory allocation/call path, and broad consumer-only reads. C001 saved the five low-risk ScreenDimmer lifecycle/factory function labels. Confidence remains below final-audit because the exact public declaration type, tiny helper source spelling, broad consumer aliases, and explicit IDA data label remain unresolved.

- 2026-06-20 B002 DialogSession helper ownership sync:
  - Score unchanged.
  - Summary/evidence: recorded `0x004a1360` as a `ReleaseScreenDimmer`/`DestroyScreenDimmer` helper and `0x004a1380` as `IsScreenDimmerActive`/`HasScreenDimmer`, both operating only on this global. This corrects the previous DialogSession/runtime ambiguity without creating duplicate global ownership.

- 2026-06-10 A001 live lifecycle/xref refresh:
  - Before: score `80/86` but the page was already attached to [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md), leaving the child side below the strict `85/85` gate.
  - Changed to: score `85/88`; retained `AUTOGEN_PARENT_UID:0000NA`.
  - Summary/evidence: live IDA MCP reconfirmed 40 direct xrefs to `0x0069ae08`, exact lifecycle writer sites in the constructor, ordinary destructor, tiny cleanup helper, and scalar deleting destructor, the single cleanup/funclet jump xref to `0x0055a030`, the factory allocation/constructor path, and the modal-list registration/interface offsets. The direct file parent already clears `87/86`, so the assignment now satisfies the strict child/direct-parent gate. Completion stays below final-audit because exact original declaration spelling and several broad consumer pages still retain raw `dword_69AE08` labels.
- 2026-06-05: Marked reconstructable and attached to [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md) to resolve the global unclassified coverage row.
  - Reasoning: live IDA xrefs bind the singleton to the ScreenDimmer constructor, cleanup helper, direct clear helper, and deleting-destructor path; the broad consumer fan-out is overlay usage rather than ownership. No score change and no reconstruction C++ were added.
- 2026-06-06 A010 storage/owner sync:
  - Before: score `74/84`; the page summarized the singleton but did not link the exact `.data` slot as the attached storage page.
  - Changed to: score `80/86`, added [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md) as exact storage, and recorded the A009/A010 attachment evidence.
  - Summary/evidence: the exact memory slot, clear helper, and overlay aggregate pages now agree on ScreenDimmer ownership, lifecycle writes/clears, and generic UI overlay placement. Confidence remains below final-audit because several consumer pages still use raw `dword_69AE08` labels and exact original header declaration spelling remains open.
- 2026-05-30: What existed before: the page relied partly on weak source-output evidence and had no completion/confidence score. What changed: set completion/confidence to `74/84` and replaced that evidence with live IDA MCP storage and xref evidence. Summary/evidence: IDA reports `0x0069ae08` as a 4-byte `.data` item with 40 xrefs; the constructor/destructor/helper clear sites are identifiable, but the consumer set is broad and several references still need source-level owner names, so completion and confidence remain below the tighter singleton pages.
