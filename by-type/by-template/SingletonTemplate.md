*** UID:0004ZL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0004ZK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0004ZK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "Singleton.h"
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UTIL_SINGLETON_H
#define NEXUSTK_UTIL_SINGLETON_H

template <class T>
class Singleton
{
protected:
    Singleton();
    ~Singleton();
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Singleton Template

## Status

- Entity kind: reusable source-authored C++ template declaration.
- Direct owner/emitter: [UID:0004ZK][Singleton](by-file/Singleton.md).
- Source projection: `NexusTK/util/Singleton.cpp` and `NexusTK/util/Singleton.h`.
- Rebuild handling: header-owned complete empty-base declaration; include-only CPP companion.
- Confidence: very strong for complete-base necessity, empty-base layout, absence of generic storage, and class-specific specialization policy; strong for normalized filename/guard spelling.

## Formal Source

The formal H block is the complete template. Protected constructor and destructor declarations permit explicit out-of-line class specializations while preventing direct general use. There are no data members, virtual functions, generic static pointer, inline publication body, or source-visible RTTI object.

The formal CPP block is exactly `#include "Singleton.h"`. This is a validator-compatible physical translation unit, not evidence for a generic runtime implementation. Concrete specialization bodies remain in the consuming module.

## Layout And Empty-Base Evidence

- `MiscWorkThread` RTTI names a separate direct `Singleton<MiscWorkThread>` base after direct `Thread` and inherited `LObject`.
- The direct Singleton BCD has zero contained bases, attributes `0x40`, and PMD `{mdisp=0x68,pdisp=-1,vdisp=0}`.
- `MiscWorkThread` allocation is exactly `0x68`; the Singleton facet starts at `+0x68`. Therefore the template contributes no ordinary storage and is represented through empty-base optimization.
- No Singleton vtable or virtual destructor route exists. The concrete class's own virtual destructor regenerates only class compiler wrappers.

## Lifetime And Storage Model

The primary template declares lifetime hooks but does not impose one universal storage model. A consuming module may define explicit class specializations when its binary proves class-specific behavior.

For `MiscWorkThread`, [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md) owns the sole external `MiscWorkThread*` definition and both `Singleton<MiscWorkThread>` specializations. The constructor specialization converts the `+0x68` base facet back to the complete object and publishes it; the destructor specialization clears the same cell. The derived constructor/destructor bodies do not duplicate those writes.

For `LanguageMan`, [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md) owns the sole external `LanguageMan *` definition and both `Singleton<LanguageMan>` specializations. RTTI/PMD places the direct empty Singleton facet at `+0x4`; the constructor specialization's `static_cast<LanguageMan *>(this)` expresses the observed null-preserving `this+4/-4` complete-object adjustment before publication, and the destructor specialization clears the same cell. Constructor-unwind UID00040R and scalar-wrapper UID00018V are compiler consequences, not extra source specializations or helper bodies.

## Source-Shape Reasoning

One guarded shared template header matches widespread cross-subsystem direct-Singleton RTTI use and ordinary late-1990s/mid-2000s C++ practice. It gives every derived declaration a legal complete base while keeping per-class storage and specialization definitions local to their owning source module.

The normalized guard `NEXUSTK_UTIL_SINGLETON_H` follows the accepted projected-path/stem convention. The executable does not retain the original filename or macro token, so the exact historical spelling remains bounded inference rather than recovered symbol evidence.

## Negative Evidence And Rejected Alternatives

- No generic `static T*`, generic constructor/destructor implementation, or one universal singleton cell is supported.
- No feature-local duplicate `Singleton` template belongs in `MiscWorkThread.cpp`.
- No incomplete template forward declaration can legally serve as a direct base.
- No implicit PCH-only definition is needed for deterministic generated output.
- No data member, virtual, vtable, virtual destructor, or generic RTTI storage should be added.
- The include-only CPP must not acquire a generic body solely to justify its existence.

## Cross-References

- [UID:0004ZK][Singleton](by-file/Singleton.md)
- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md)
- [UID:0001P8][0x0067ab50-0x0067ab54.g_pMiscWorkThread](by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md)
- [UID:0004HM][0x0061fb70-0x0061fb74.MiscWorkThreadRttiLocatorPointer](by-memory/0x0061fb70-0x0061fb74.MiscWorkThreadRttiLocatorPointer.md)

## Changes

- 2026-08-24 B005 UID0000KK support sync: added LanguageMan as a second exact class-specific specialization example, including direct-base PMD/EBO, complete-object adjustment, external-cell publication/clear, null preservation, and derived/EH/scalar no-duplicate-source boundaries.

- 2026-07-31 B004 UID0004HM implementation:
  - Created the reusable template page at `92/94` under file owner/emitter [UID:0004ZK][Singleton](by-file/Singleton.md).
  - Added exact include-only CPP and guarded complete H source.
  - Documented empty-base PMD/allocation proof, class-specific specialization and external-storage policy, source-era placement, and all rejected generic-static/duplicate/PCH/incomplete-base alternatives.
