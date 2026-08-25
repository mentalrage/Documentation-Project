*** UID:0000RC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000071 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
LanguageMan *g_pLanguageMan = 0;

template <>
Singleton<LanguageMan>::Singleton()
{
    g_pLanguageMan = static_cast<LanguageMan *>(this);
}

template <>
Singleton<LanguageMan>::~Singleton()
{
    g_pLanguageMan = 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Sole LanguageMan singleton pointer definition plus exact class-specific Singleton constructor/destructor specializations in NexusTK/localization/LanguageMan.cpp at position 10, backed by physical UID0001OS; the matching extern is emitted once by the guarded LanguageMan header. Exact evidence proves zero storage, 192 refs, five compiler-lowered lifetime writes/clears, 187 reads, direct Singleton PMD/EBO adjustment, external linkage, and one-definition policy. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# g_pLanguageMan

## Status

- Address: `0x0067a750`
- Exact memory range: [UID:0001OS][0x0067a750-0x0067a754.g_pLanguageMan](by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md)
- Kind: singleton pointer / global data.
- Confidence: very strong.
- Canonical owner: [UID:0000KK][LanguageMan](by-file/LanguageMan.md). Recursive CPP emitter: [UID:000071][LanguageMan](by-class/LanguageMan.md), position `10`, surfacing to the same file root.
- Source disposition: sole externally linked `g_pLanguageMan` module definition in `NexusTK/localization/LanguageMan.cpp`.

## Role

`g_pLanguageMan` points to the process-wide localized string table loaded from `str.res`. Dialog, prompt, scanner, startup, and gameplay UI code pass this pointer into localized string lookup helpers with numeric string ids.

## Source Definition And Header Separation

- This page is the single source-bearing semantic representation of the global. Exact backing storage [UID:0001OS][0x0067a750-0x0067a754.g_pLanguageMan](by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md) is false/non-emitting so generated output cannot create a duplicate definition.
- The managed block is routed into `LanguageMan.cpp` after UID000071's position-0 include fragment; it contains the sole zero-initialized module definition followed by the exact class-specific Singleton constructor/destructor specializations. The guarded header owns the prior declaration, so no local forward declaration is needed here.
- The matching external pointer declaration is emitted once inside the canonical guarded [UID:000071][LanguageMan](by-class/LanguageMan.md) H channel. This by-global page owns the sole CPP storage definition but intentionally leaves its H channel blank, preventing an unguarded preamble before `LanguageMan.h` while preserving the same semantic global and external linkage.
- A pointer definition requires only an incomplete class type, so the unresolved human identities for `LanguageMan +0x0c-+0x28` do not block this source definition. The class formal remains independently blank rather than inventing reserved layout fields.
- External linkage is required: 187 reads occur across Application, RegistryConfig, UserPane, dialogs, prompts, scanner, VirusChecker, command-input, and gameplay source families. File-static linkage is rejected.

## Lifetime

- Published by compiler lowering for the direct `Singleton<LanguageMan>` base during exact constructor child [UID:00041V][0x004f0010-0x004f028c.LanguageManConstructor](by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md) / `LanguageMan::LanguageMan`.
- Cleared by reverse direct-base teardown represented in the ordinary destructor at `0x004f0290` and compiler scalar wrapper at `0x004f03d0`.
- Cleared by compiler constructor-unwind helper [UID:00040R][0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper](by-memory/0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper.md), reached only through constructor EH metadata/near jump `0x00600a64`.
- Read by broad callers before invoking exact lookup/copy children [UID:00040P][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md) or [UID:00040Q][0x004f0380-0x004f03bb.LanguageManCopyLocalizedString](by-memory/0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md).
- Application cleanup reads `g_pLanguageMan` at `0x00464c2e` and checks it before shutdown dispatch. When non-null, cleanup supplies scalar-delete flag `1` and invokes the object's virtual scalar-deleting-destructor route at `0x00464c3c`; this is the exact terminal consumer of the semantic global and compiler UID00018V wrapper.
- B002 2026-06-20 clarification: the constructor sequence around `0x004f0055-0x004f0066` uses `lea eax, [this+4]`, null-tests, then `add eax, -4` before storing to `0x0067a750`. The effective stored value is the complete `LanguageMan*` when non-null, not a persistent `this + 4` view pointer.
- The five exact writes/clears are constructor publication `0x004f0066`, constructor fallback clear `0x004f006d`, ordinary teardown clear `0x004f02ef`, constructor-unwind clear `0x004f03c0`, and scalar-wrapper clear `0x004f0431`. The other 187 of 192 references are reads.

## Evidence

- IDA MCP xrefs to `0x0067a750` show writes in `0x004f0010`, `0x004f0290`, `0x004f03c0`, and `0x004f03d0`.
- IDA MCP xrefs show many data references immediately paired with calls to `0x004f0350` or `0x004f0380`.
- Application shutdown supplies the complementary lifetime consumer: the global load at `0x00464c2e` is checked for null, delete flag `1` is prepared, and the virtual scalar-deleting-destructor call occurs at `0x00464c3c`. This route confirms live external shutdown use without requiring handwritten scalar-wrapper C++.
- 2026-05-24 IDA recheck found 192 xrefs to `0x0067a750`, reinforcing that `LanguageManager` should be treated as an alias/view over this singleton unless separate allocation evidence is found.
- 2026-05-26 IDA recheck again returned a large xref set, truncated by MCP after representative callers, with constructor/destructor/clear writes still present.
- 2026-05-27 IDA MCP item-action rechecks show prompt constructors reading `dword_67A750` before localized string lookup: `ThrowInputPane` uses string id `0x23`, `UseInputPane` uses `0x09`, `EatInputPane` uses `0x0c`, `WieldInputPane` uses `0x0d`, and `WearInputPane` uses `0x21`. Aliases such as `g_pStringTable` should normalize back to this singleton unless the address differs.
- 2026-06-21 B005/B012 SelfSave passes add prompt consumers: [UID:0003O5][0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw](by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md) reads this singleton at `0x005b67c7`, passes id `0x26` to `LanguageMan::GetLocalizedString`, and uses current [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md) text `Save profile? (Y/N) ` as the `CharInputPane` prompt. [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md) duplicates the same lookup during retained `CreateSelfSaveInputPane()` construction after allocation.
- 2026-06-05 live IDA MCP again reports 192 xrefs to `0x0067a750`; decompilation confirms constructor `0x004f0010`, clear helper `0x004f03c0`, and deleting destructor `0x004f03d0` write/clear `dword_67A750`.
- 2026-06-16 C001 live IDA MCP refresh reports active database `c001_midiplayer_rdata_20260615`, `NexusTK.exe.i64`, Hex-Rays ready, and strings cache ready. `xrefs_to 0x0067a750` again returned the localization singleton fanout with the documented lifecycle writes at `0x004f0066`/`0x004f006d`, `0x004f02ef`, `0x004f03c0`, and `0x004f0431`; `get_bytes 0x0067a740` confirmed the surrounding singleton cluster is zero-initialized.
- C001 reported applying saved IDA names for `g_pLanguageMan` and the four LanguageMan lifecycle helpers in its 2026-06-16 session. B015's 2026-06-25 live MCP session `80de0a67` still reports `0x004f0290` as `??1exception@boost@@MAE@XZ_3`, so the Boost-name repair should be treated as session/IDA-state-specific rather than guaranteed in the active IDB. The source-facing documentation remains `LanguageMan_CleanupDestructor` / `LanguageMan::~LanguageMan` because the body writes the LanguageMan vtable, uses `m_strings`/`m_stringCount`, and clears `g_pLanguageMan`.
- 2026-06-20 B002 source-quality pass reconciles the constructor store idiom: the temporary `this + 4` value is adjusted back to the complete object pointer before assignment, and the lookup/destructor helpers then read `+0x04` / `+0x08` from that complete object. Keep `LanguageManager` as an alias/view only unless separate allocation or RTTI evidence appears.
- 2026-06-21 B007 split resolves the `LanguageMan` versus generated `LanguageManager` alias for the lookup/copy/clear helpers: `LanguageMan` is canonical, while `LanguageManager` is only a generated alias/view. Exact child [UID:00040R][0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper](by-memory/0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper.md) owns the constructor-cleanup clear helper, and exact children [UID:00040P][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md)/[UID:00040Q][0x004f0380-0x004f03bb.LanguageManCopyLocalizedString](by-memory/0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md) own lookup/copy consumers.
- 2026-06-25 B012 constructor split creates exact child [UID:00041V][0x004f0010-0x004f028c.LanguageManConstructor](by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md), which is now the source-bearing publisher of this singleton. [UID:00018R][0x004f0010-0x004f0477.LanguageManLocalization](by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md) remains only the non-emitting island map.
- The former claim that final C++ had to remain blank pending a broader `LanguageMan.cpp` pass is superseded. Exact type, external linkage, semantic owner, source order, and incomplete-type legality are now closed. The unrelated `0x004f0310` object/field uncertainty still caps the complete class declaration but does not block this module definition.

## 2026-07-20 Direct Singleton And One-Definition Evidence

- Current RTTI names `LanguageMan` and `Singleton<LanguageMan>` and exposes direct `LanguageMan`, `LObject`, and Singleton hierarchy entries. No separate `LanguageManager` RTTI, allocation, vtable, or singleton exists.
- The Singleton base descriptor has PMD `mdisp=4`, `pdisp=-1`, `vdisp=0`, attributes `0x40`. Empty-base optimization overlaps the base at `+0x04` with `m_strings`; the constructor's `this+4/-4` adjustment is compiler base publication, not a handwritten assignment.
- Ordinary clear, the exact 11-byte constructor-unwind clear, and scalar-wrapper clear are reverse/base/compiler manifestations. Human constructor/destructor source omits direct singleton assignment/clear; compiler output regenerates the observed writes.
- Application cleanup completes the source-to-compiler route: it reads/checks this global and dispatches the virtual scalar-deleting destructor with flag `1` at `0x00464c3c`. The observed shutdown call targets compiler wrapper behavior already documented by UID00018V and does not alter this page's sole pointer-definition formal.
- Exact storage is zero-initialized and bounded by separate singleton slots: predecessor `0x0067a74c` has 72 refs, target `0x0067a750` has 192, and successor `0x0067a754` has 210. No split, merge, extension, or padding ownership change applies.
- Canonical source name is `g_pLanguageMan`; `dword_67A750`, `DAT_0067a750`, `g_pStringTable`, and `LanguageManager` remain raw/generated aliases or rejected alternatives.
- Score `92/94` reflects closed storage/type/linkage/lifetime/owner/emitter/formal blockers. Original whitespace, exact header path, and `0` versus `NULL` are not binary-recoverable and cap confidence below final certainty.

## Cross-References

- [UID:0000KK][LanguageMan](by-file/LanguageMan.md)
- [UID:000071][LanguageMan](by-class/LanguageMan.md)
- [UID:000072][LanguageManager](by-class/LanguageManager.md)
- [UID:00018R][0x004f0010-0x004f0477.LanguageManLocalization](by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md)
- [UID:00041V][0x004f0010-0x004f028c.LanguageManConstructor](by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md)
- [UID:0001OS][0x0067a750-0x0067a754.g_pLanguageMan](by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md)
- [UID:00040P][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md)
- [UID:00040Q][0x004f0380-0x004f03bb.LanguageManCopyLocalizedString](by-memory/0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md)
- [UID:00040R][0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper](by-memory/0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper.md)
- [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md)
- [UID:0000EY][ThrowInputPane](by-class/ThrowInputPane.md)
- [UID:0000FG][UseInputPane](by-class/UseInputPane.md)
- [UID:000047][EatInputPane](by-class/EatInputPane.md)
- [UID:0000G4][WieldInputPane](by-class/WieldInputPane.md)
- [UID:0000G0][WearInputPane](by-class/WearInputPane.md)

## Changes

- 2026-08-24 B005 UID0000KK callback: raised scores to `94/96`, moved the fragment to position `10` under UID000071's explicit recursive insertion point, retained UID0000KK canonical ownership and the sole `LanguageMan *g_pLanguageMan = 0` definition, and added exact `Singleton<LanguageMan>` constructor/destructor specializations. The specializations source the observed publication/clear while compiler EH/scalar helpers remain implicit; the guarded extern remains class-owned and UID0001OS emits no duplicate storage.

- 2026-07-20 B005 C10 Gate 2 repair:
  - Scores, owner/emitter, reconstructability, position, and managed source block remain unchanged.
  - Added exact Application shutdown evidence: global read at `0x00464c2e`, non-null check, scalar-delete flag `1`, and virtual scalar-deleting-destructor dispatch at `0x00464c3c`; preserved the direct-Singleton/compiler-wrapper/no-handwritten-wrapper source disposition.
- 2026-07-20 B005 UID0001OS source-quality callback:
  - Changed to `92/94`, retained owner/emitter `0000KK`, retained reconstructable true, and set source position `0`.
  - Historical, superseded source shape: this callback had used a CPP-local forward declaration plus sole definition. The 2026-08-24 UID0000KK completion replaces that fragment with the definition and class-specific Singleton specializations after the class include preamble; the guarded extern remains class-H-owned.
  - Incorporated the complete 192-reference inventory, five lifetime writes/clears, 187 reads, direct `Singleton<LanguageMan>` RTTI/PMD/EBO proof, complete-object pointer type, external linkage, one-definition policy, clean singleton boundaries, compiler-lowered lifecycle, canonical-name rejection set, and independent unresolved class-tail cap.
- 2026-06-25 B012 constructor child implementation:
  - Scores unchanged.
  - Summary/evidence: linked [UID:00041V][0x004f0010-0x004f028c.LanguageManConstructor](by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md) as the exact source-bearing publisher of `g_pLanguageMan`; the broader [UID:00018R][0x004f0010-0x004f0477.LanguageManLocalization](by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md) page is now a non-emitting split index.

### 2026-05-30 completion/confidence evidence pass

- What existed before: the page had `0` completion/confidence values and broad owner notes.
- What changed: completion/confidence were raised to `84/88`, and the evidence now distinguishes exact IDA-backed singleton storage from alias/source naming.
- Summary and evidence: existing IDA-backed docs establish `0x0067a750-0x0067a754`, lifecycle writes/clears, and broad lookup callers. Completion remains capped because the final original spelling and split between `LanguageMan` and `LanguageManager` naming are still unresolved.
- 2026-06-05: Marked reconstructable under [UID:0000KK][LanguageMan](by-file/LanguageMan.md). Evidence: live IDA MCP reports 192 xrefs to `0x0067a750`; decompilation confirms `0x004f0010`, `0x004f03c0`, and `0x004f03d0` write/clear `dword_67A750`.
- 2026-06-16 C001 global/source-quality refresh:
  - What existed before: score `84/88`, exact singleton storage and lifecycle evidence existed, but IDA still used generated data/function names and the page did not record the current source-quality blocker review.
  - Changed to: score `85/90`; IDA names were saved for the global and four lifecycle helpers.
  - Summary/evidence: live IDA reconfirmed the 192-xref localization singleton fanout, zeroed singleton-cluster bytes, constructor publish/fallback clear, cleanup destructor clear, singleton clear helper, and scalar-deleting destructor clear. Owner/emitter stay [UID:0000KK][LanguageMan](by-file/LanguageMan.md); final C++ is still blocked by class-spelling and adjacent zero-initializer field/type questions rather than by storage evidence.
- 2026-06-20 B002 scalar-wrapper support incorporation:
  - What changed: no score change; added constructor pointer-idiom clarification.
  - Summary/evidence: B002 rechecked the LanguageMan scalar deleting destructor and support lifecycle, confirming that `g_pLanguageMan` stores the complete `LanguageMan*` and that the generated `LanguageManager` view remains an alias over the same singleton.
- 2026-06-21 Rule 26 B005 incorporation:
  - What changed: no score change; added the SelfSave constructor as a representative localized prompt consumer of `g_pLanguageMan`.
  - Summary/evidence: B005 tied `0x005b67c7` to the constructor singleton read, string id `0x26`, and current `STR.RES` text `Save profile? (Y/N) `; B012 tied the retained factory [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md) to the same lookup path during `CreateSelfSaveInputPane()` construction.
- 2026-06-21 Rule 26 B007 lookup/copy/clear split:
  - Changed to: completion/confidence `87/92`.
  - Summary/evidence: exact child pages now replace the old aggregate-only helper references. [UID:00040P][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md) carries the 351-caller direct lookup, [UID:00040Q][0x004f0380-0x004f03bb.LanguageManCopyLocalizedString](by-memory/0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md) carries the two-caller copy-output helper, and [UID:00040R][0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper](by-memory/0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper.md) carries the constructor-cleanup singleton clear body with near jump `0x00600a64`. This resolves `LanguageMan` as canonical over the generated `LanguageManager` alias for this singleton's consumers.
- 2026-06-25 B015 source-quality support correction:
  - What changed: no score, owner, emitter, or C++ change; the C001 IDA-name repair statement is now historical/session-scoped instead of absolute.
  - Summary/evidence: B015 live MCP session `80de0a67` still reports the cleanup destructor at `0x004f0290` as `??1exception@boost@@MAE@XZ_3`. Source-facing docs still use `LanguageMan_CleanupDestructor` / `LanguageMan::~LanguageMan` because the body writes the LanguageMan vtable, uses `m_strings`/`m_stringCount`, and clears `g_pLanguageMan`.
