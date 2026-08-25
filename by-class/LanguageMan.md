*** UID:000071 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "LanguageMan.h"
#include "../archive/DATFile.h"
#include "../util/Error.h"
#include "../util/MemoryMan.h"

#include <windows.h>

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_LOCALIZATION_LANGUAGEMAN_H
#define NEXUSTK_LOCALIZATION_LANGUAGEMAN_H

#include "../util/LObject.h"
#include "../util/Singleton.h"
#include "../util/StringBase.h"

class LanguageMan;
extern LanguageMan *g_pLanguageMan;

class LanguageMan : public LObject, public Singleton<LanguageMan>
{
public:
    LanguageMan();
    virtual ~LanguageMan();

    const wchar_t *GetLocalizedString(int stringId) const;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >
    CopyLocalizedString(int stringId) const;

private:
    wchar_t **m_strings;
    int m_stringCount;
    unsigned int m_reservedState[8];
};

typedef char LanguageManSizeMustBe44[
    sizeof(LanguageMan) == 0x2c ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# LanguageMan

## Status

- Confidence: strong for layout and lifecycle.
- Likely source file: [UID:0000KK][LanguageMan](by-file/LanguageMan.md)
- Main address range: [UID:00018R][0x004f0010-0x004f0477.LanguageManLocalization](by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md)
- Current generated file: `auto-generated/NexusTK/localization/LanguageMan.cpp`
- Formal source status: the CPP channel supplies the position-`0` include preamble and explicit recursive child insertion point; the H channel supplies a complete source-quality draft with direct `LObject` and `Singleton<LanguageMan>` bases, the two proved fields, the exact lookup/copy surface, and one explicitly bounded eight-dword reserved tail needed to preserve the proved `0x2c` ABI.

## Class Purpose

`LanguageMan` owns the client localized string table loaded from `str.res`. It directly inherits `LObject` and `Singleton<LanguageMan>`, is constructed during application initialization, obtains process-wide singleton publication/clear through that Singleton base, and supplies wide strings by integer id to UI, dialog, scanner, startup, and gameplay prompt code.

## Layout Notes

| Offset | Meaning | Evidence |
| --- | --- | --- |
| `+0x0` | `LObject` base / vtable | Constructor calls `0x004f4a80` and installs vtable `0x0061c9e0`; exact vtable data is [UID:00040W][0x0061c9dc-0x0061c9ec.LanguageManVtableData](by-memory/0x0061c9dc-0x0061c9ec.LanguageManVtableData.md). |
| `+0x4` | `m_strings` / `wchar_t**` string table | Constructor writes allocated table; exact lookup children [UID:00040P][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md) and [UID:00040Q][0x004f0380-0x004f03bb.LanguageManCopyLocalizedString](by-memory/0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md) index it. |
| `+0x8` | `m_stringCount` | Constructor increments per parsed line; exact lookup children bounds-check against it. |
| `+0x0c..+0x28` | `m_reservedState[8]` | Allocation and scalar-delete paths prove a `0x2c` complete object, leaving exactly eight dwords after the two named fields. No consumer proves individual semantic names, so the header preserves the ABI as one source-facing reserved state block rather than inventing eight meanings or leaking decompiler labels. |

RTTI hierarchy records three entries: `LanguageMan`, `LObject`, and direct `Singleton<LanguageMan>`. The Singleton PMD is `mdisp=4`, `pdisp=-1`, `vdisp=0`, attributes `0x40`; empty-base optimization overlaps the Singleton subobject at `+0x04` with `m_strings`. Constructor `this+4/-4` publication and destructor/unwind/scalar clears are compiler/base lowering, not explicit source fields or statements.

B002's 2026-06-20 scalar-deleting-destructor pass adds a provisional complete-object size: the compiler flag-4 delete path in [UID:00018V][0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor](by-memory/0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor.md) pushes `0x2c` / 44 bytes (Verified with int_convert.py). Treat this as strong evidence for `sizeof(LanguageMan) == 0x2c` in this build. It does not by itself name or prove fields at `+0x0c..+0x28`; [UID:00018T][0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer](by-memory/0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer.md) still remains only a file-level helper/orphan until caller/layout/vtable/EH evidence proves the object owner.

## Complete Header Inference Decision

- The accepted declaration preserves two evidence levels without changing the binary contract. `m_strings` at `+0x04` and `m_stringCount` at `+0x08` are directly behavior-backed names. `m_reservedState[8]` is a bounded source-reconstruction inference for the otherwise unnamed `+0x0c..+0x28` tail; its count is exact because `sizeof(LanguageMan) == 0x2c`, the two direct bases use empty-base optimization at the proved offsets, and no additional vptr or virtual base is present.
- The reserved block is intentionally not eight invented feature fields, raw `field_0C` labels, byte padding, or a miniature local class. Those alternatives either claim semantics the executable does not reveal, preserve IDA-shaped names in final source, or create an ODR/layout conflict. A single neutral state array matches ordinary mid-2000s C++ practice for unrecovered private storage while preserving exact execution layout.
- The adjacent `0x004f0310` zero initializer is not used to assign this tail. It has no direct caller, xref, vtable, EH, or source route tying it to `LanguageMan`; physical adjacency alone is negative evidence. Its writes through `+0x24` neither prove the eighth dword at `+0x28` nor justify moving the helper into this class.
- Direct `LObject` plus `Singleton<LanguageMan>` inheritance is not speculative: RTTI hierarchy/PMD evidence, constructor publication, unwind cleanup, and reverse destruction establish the base topology. The two lookup methods are the complete reusable public surface needed by consumers. This full header replaces the rejected local forward-only or miniature-class workaround while leaving exact method bodies on their existing by-memory children.

## Method Notes

| Method/helper | Address | Role |
| --- | --- | --- |
| constructor | [UID:00041V][0x004f0010-0x004f028c.LanguageManConstructor](by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md) | Source-authored `LanguageMan::LanguageMan` body loads `str.res`, converts lines, and stores the table; direct Singleton base construction supplies compiler-lowered `g_pLanguageMan` publication/fallback cleanup, so formal source has no explicit assignment. |
| non-deleting destructor body | `0x004f0290-0x004f0310` | Source-authored `LanguageMan::~LanguageMan` body frees every string and the table; reverse Singleton/LObject base teardown supplies the observed global clear and base call implicitly. IDA currently mislabels it as `boost::exception`. See [UID:00018S][0x004f0290-0x004f0310.LanguageManCleanupDestructor](by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md). |
| adjacent zero-initializer | `0x004f0310-0x004f0342` | Zeroes fields `+0x0c..+0x24`; no xrefs found, so ownership is unresolved. |
| `GetLocalizedString` | [UID:00040P][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md) | Exact direct lookup child; returns `m_strings[stringId]` or `L"Invalid String ID"` after signed lower-bound and count upper-bound checks; 351 direct callers and first-draft C++ ready. |
| `CopyLocalizedString` | [UID:00040Q][0x004f0380-0x004f03bb.LanguageManCopyLocalizedString](by-memory/0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md) | Returns one-pointer `StringBase<wchar_t, mychar_traits<wchar_t> >` by value. The explicit ABI output pointer at callers `0x00530c27` and `0x005c08a2` is the MSVC hidden result object; `0x00582560` constructs it from selected/fallback raw UTF-16 and does not assign an initialized output facade. |
| constructor-unwind clear | [UID:00040R][0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper](by-memory/0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper.md) | Exact 11-byte compiler cleanup; no `this`, args, callees, or ordinary calls and one EH near jump from `0x00600a64`. Direct Singleton base construction regenerates it; no source helper or marker emits. |
| scalar deleting destructor | `0x004f03d0-0x004f0477` | Compiler-generated MSVC scalar deleting destructor wrapper for `~LanguageMan`; vtable-only reachable, no direct callers, and fully non-emitting with blank formal. See [UID:00018V][0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor](by-memory/0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor.md). |

## Naming Notes

- [UID:000072][LanguageManager](by-class/LanguageManager.md) is a generated alias/view for the old `0x004f0350` output, not a separate original class.
- Final source should use `LanguageMan` as the canonical class name for the lookup helpers. The singleton/global name, `LanguageMan` / `Singleton<LanguageMan>` RTTI, `LanguageMan.cpp` source-family route, and exact child pages all point to this class; no separate `LanguageManager` allocation/RTTI/name identity is known.
- 2026-05-26 recheck: active `class_LanguageMan.cpp` contained only the constructor and deleting destructor, while active `class_LanguageManager.cpp` contained the lookup method as a separate generated class. The 2026-06-21 split supersedes that generated division: [UID:00040P][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md) is now the direct class child, and [UID:00018U][0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers](by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md) is only a non-emitting split index.
- 2026-06-22 B013 source-quality report review reconfirmed that raw/generated names such as `cls_0x4f0350`, `meth_0x4f0350`, `FUN_004f0380`, and `FUN_004f03c0` normalize into LanguageMan-family evidence. Its file-local singleton-clear helper interpretation is superseded by direct Singleton RTTI/PMD proof; `FUN_004f03c0` is compiler EH cleanup, while the `LanguageManager` aggregate-emitter route remains historical.
- 2026-05-26 IDA `py_eval` recheck found `LanguageMan` and `Singleton<LanguageMan>` RTTI/name records, 351 xrefs to the lookup helper at `0x004f0350`, and 192 xrefs to `g_pLanguageMan`; no `LanguageManager` RTTI/name evidence was found.

## Data Caveats

- Current output should emit the constructor from [UID:00041V][0x004f0010-0x004f028c.LanguageManConstructor](by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md), the ordinary destructor from [UID:00018S][0x004f0290-0x004f0310.LanguageManCleanupDestructor](by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md), and direct lookup/copy children [UID:00040P][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md) and [UID:00040Q][0x004f0380-0x004f03bb.LanguageManCopyLocalizedString](by-memory/0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md). UID00040R, UID00018V, UID00040W, and aggregate UID00018R are compiler/data/index no-code pages and generate no source markers.
- [UID:00040V][0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants](by-memory/0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants.md) and [UID:00040X][0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals](by-memory/0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals.md) are file-level `LanguageMan.cpp` data, not class fields. [UID:00040W][0x0061c9dc-0x0061c9ec.LanguageManVtableData](by-memory/0x0061c9dc-0x0061c9ec.LanguageManVtableData.md) retains this class as semantic owner but is false/non-emitting compiler binary data regenerated from class declarations.
- The class formal now carries the complete `0x2c` declaration. The two behavior-backed member names remain exact, while `m_reservedState[8]` records the only bounded source-facing representation of the eight unnamed tail dwords. This is an explicit inference, not a claim that the original private semantics were recovered.
- [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md) emits the sole `LanguageMan.cpp` definition and class-specific Singleton constructor/destructor specializations at position `10`. This class emits includes at position `0` and the matching `extern LanguageMan *g_pLanguageMan;` declaration inside the canonical header guard. No second storage definition is introduced.
- C134 compile closure places the matching `g_pLanguageMan` forward/extern pair once inside this canonical `NEXUSTK_LOCALIZATION_LANGUAGEMAN_H` guard; the by-global H channel is blank and continues to own only the CPP definition. The class H channel omits its empty child token because exact method bodies are CPP children, eliminating command20473's invalid generated attachment attribute while preserving the complete `0x2c` declaration.
- IDA still reports no direct callers for `0x004f0310`; keep it unresolved rather than folding it into localization by physical adjacency alone.
- Current exported `simroot_v2/class_LanguageMan.meta_wave3` still reports a stored method-name control-character reason for `0x004f0010`, even though the active emitted method name is normal.

## Cross-References

- [UID:0000KK][LanguageMan](by-file/LanguageMan.md)
- [UID:000072][LanguageManager](by-class/LanguageManager.md)
- [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md)
- [UID:00018R][0x004f0010-0x004f0477.LanguageManLocalization](by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md)
- [UID:00041V][0x004f0010-0x004f028c.LanguageManConstructor](by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md)
- [UID:00018S][0x004f0290-0x004f0310.LanguageManCleanupDestructor](by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md)
- [UID:00018U][0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers](by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md)
- [UID:00040P][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md)
- [UID:00040Q][0x004f0380-0x004f03bb.LanguageManCopyLocalizedString](by-memory/0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md)
- [UID:00040R][0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper](by-memory/0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper.md)
- [UID:00040W][0x0061c9dc-0x0061c9ec.LanguageManVtableData](by-memory/0x0061c9dc-0x0061c9ec.LanguageManVtableData.md)
- [UID:00040X][0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals](by-memory/0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals.md)
- [UID:0001OS][0x0067a750-0x0067a754.g_pLanguageMan](by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md)
- [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md)
- [UID:0000HG][Application](by-file/Application.md)

## Changes

- 2026-08-24 B005 UID0000KK callback: raised scores to `94/95`, set include emitter position `0`, populated the exact LanguageMan.cpp include preamble and explicit `[[CHILDREN]]` insertion point for positions `10` through `70`, replaced the explicit-output CopyLocalizedString declaration with the source-facing by-value StringBase API, and retained the exact direct bases, `0x2c` layout, `m_strings`, `m_stringCount`, neutral eight-dword tail, extern global, virtual destructor, and compiler/no-code child dispositions.

- 2026-07-31 B001 UID0001HA dependency callback: populated the complete guarded `LanguageMan.h` declaration with direct `LObject` and `Singleton<LanguageMan>` bases, proved `m_strings`/`m_stringCount` fields, lookup/copy declarations, and exact `0x2c` size assertion. The otherwise unnamed eight-dword tail is represented as bounded `m_reservedState[8]` inference; the adjacent unreferenced zero initializer remains rejected as ownership proof. Synchronized the separate `g_pLanguageMan` external-declaration route without adding storage or changing the existing `89/92` metadata.
- 2026-07-20 B005 UID0001OS source-quality callback:
  - Scores, owner/emitter/file route, reconstructable state, and blank class formal remain `89/92` and unchanged.
  - Added direct `LObject` plus `Singleton<LanguageMan>` source inheritance, exact RTTI hierarchy/PMD/EBO, compiler publication/clear lowering, sole semantic-global definition and separate future header declaration placement, and the exact no-placeholder reason the complete `0x2c` class declaration stays blank.
  - Reclassified UID00040R as compiler constructor-unwind no-code, UID00018V as false/non-emitting scalar wrapper, and UID00040W as false/non-emitting compiler RTTI/vtable data while preserving every child behavior, slot, field, and historical source interpretation.
- 2026-06-25 B012 constructor child implementation:
  - Scores unchanged.
  - Summary/evidence: added exact constructor child [UID:00041V][0x004f0010-0x004f028c.LanguageManConstructor](by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md) as the class-owned source-bearing `LanguageMan::LanguageMan` body. The child emits through this class using the confirmed `m_strings` at `+0x04` and `m_stringCount` at `+0x08`; the `+0x0c..+0x24` caveat remains limited to [UID:00018T][0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer](by-memory/0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer.md).

- Completion/confidence score update: existed before as `0/0`; changed to `86/88`. Summary: the localization singleton is well documented across purpose, layout, lifecycle, lookup helpers, naming evidence, and caveats, with only the adjacent zero-initializer and final generated split preventing a higher score. Evidence: documented `str.res` ownership, `g_pLanguageMan`, lookup/helper ranges, destructor body, RTTI/name evidence, and LanguageManager alias analysis.
- 2026-06-05: Marked reconstructable and attached to [UID:0000KK][LanguageMan](by-file/LanguageMan.md).
  - Before: `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, leaving the localization singleton class unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000KK`; left the C++ block blank because the page is below the final reconstruction bar.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x004f0010`, `0x004f0290`, `0x004f0350`, `0x004f0380`, `0x004f03c0`, and `0x004f03d0`, with `LanguageMan`/`Singleton<LanguageMan>` RTTI/name records and no `LanguageManager` name records. The class score `86/88` and parent score `88/84` meet the 80/80 attachment gate.
- 2026-06-13: Confirmed [UID:00018S][0x004f0290-0x004f0310.LanguageManCleanupDestructor](by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md) as a direct class child.
  - Before: the cleanup destructor page was attached to the file parent [UID:0000KK][LanguageMan](by-file/LanguageMan.md) even though the body uses the `LanguageMan` object layout.
  - After: the memory page is routed to this class parent; this class remains `86/88`, with C++ blank below the final reconstruction-code gate.
  - Summary/evidence: live IDA MCP reconfirmed the stale Boost name, exact 128-byte body, LanguageMan vtable write, `this + 0x4` string-table and `this + 0x8` count cleanup loop, `g_pLanguageMan` clear, zero direct callers, and shared state with the scalar deleting destructor. The child `86/90`, class `86/88`, and file parent `88/85` satisfy the strict parent gate.
- 2026-06-20: Incorporated B002 `00018V` scalar-deleting-destructor source-quality report.
  - Changed to: completion/confidence `87/89`.
  - Summary/evidence: B002 raw PE/Capstone evidence proves [UID:00018V][0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor](by-memory/0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor.md) is a vtable-only MSVC scalar deleting wrapper for `LanguageMan::~LanguageMan`, not a handwritten method. The class page now records the `0x2c` / 44-byte object-size immediate (Verified with int_convert.py), keeps only `+0x04` and `+0x08` as proven localization fields, marks [UID:00018S][0x004f0290-0x004f0310.LanguageManCleanupDestructor](by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md) as the source-authored destructor body, and keeps [UID:00018T][0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer](by-memory/0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer.md) out of class ownership despite the size-envelope inference.
- 2026-06-21 Rule 26 B007 lookup/copy/clear split:
  - Changed to: completion/confidence `89/92`.
  - Summary/evidence: [UID:00018U][0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers](by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md) is now a non-emitting split index. Exact children [UID:00040P][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md), [UID:00040Q][0x004f0380-0x004f03bb.LanguageManCopyLocalizedString](by-memory/0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md), and [UID:00040R][0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper](by-memory/0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper.md) preserve B007's PE/exported-data evidence: 351 direct lookup callers, two copy-helper callers at `0x00530c27` and `0x005c08a2`, constructor-cleanup near jump to the clear helper at `0x00600a64`, `m_strings` at `+0x04`, `m_stringCount` at `+0x08`, fallback literal `0x0061ca20`, `0x00582560` StringBase assignment caveat, and canonical `LanguageMan` naming. `LanguageManager` is now documented as an alias/view rather than an unresolved equal candidate.
- 2026-06-22 Rule 26 B013 verification:
  - Scores unchanged.
  - Summary/evidence: added B013's independent exported-data/raw-name review as confirmation of the existing class split. The class still owns `GetLocalizedString` and the copy-output helper behavior; the file page, not this class, owns the no-`this` singleton clear helper.
- 2026-06-22 B013 read-only-data source-routing incorporation:
  - Scores unchanged.
  - Summary/evidence: added exact vtable child [UID:00040W][0x0061c9dc-0x0061c9ec.LanguageManVtableData](by-memory/0x0061c9dc-0x0061c9ec.LanguageManVtableData.md) as class-owned generated-binary data. The adjacent parser-limit constants [UID:00040V][0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants](by-memory/0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants.md) and string literal island [UID:00040X][0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals](by-memory/0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals.md) are documented as LanguageMan.cpp file-level data, not object fields.
