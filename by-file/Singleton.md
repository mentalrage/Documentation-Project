*** UID:0004ZK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Singleton

## Status

- Entity kind: reusable project template source root.
- Proposed source pair: `NexusTK/util/Singleton.cpp` and `NexusTK/util/Singleton.h`.
- Reconstruction confidence: strong for a shared complete empty-base template, class-specific specializations, and storage-free primary-template policy; bounded only by original filename/header-guard spelling.
- Formal source owner: [UID:0004ZL][SingletonTemplate](by-type/by-template/SingletonTemplate.md).
- Rebuild handling: the validator-projected CPP is include-only; the guarded H owns the complete reusable template declaration.

## File Role

`Singleton` is the shared project-era empty-base template used as a direct base by unrelated subsystem classes. The header supplies a complete `template <class T> class Singleton` definition with protected constructor and destructor declarations. It intentionally owns no data members, virtual functions, generic static pointer, or universal publication policy.

The companion `Singleton.cpp` exists because direct by-file projection stages a physical translation unit. Its only source is `#include "Singleton.h"`. Concrete publication and clear semantics remain class-specific: the consuming module owns any external singleton pointer and explicit specialization bodies required by its binary.

## Evidence

- `MiscWorkThread` RTTI contains a separate direct `Singleton<MiscWorkThread>` base descriptor after `Thread`/inherited `LObject`, with PMD `{0x68,-1,0}`, zero contained bases, and attributes `0x40`.
- `MiscWorkThread` allocation size is exactly `0x68`; the Singleton facet begins at `+0x68`, proving empty-base optimization rather than a source field.
- Constructor lowering adjusts the empty-base facet back to the complete object before publishing `g_pMiscWorkThread`; reverse destructor order clears the same external cell before `Thread` teardown.
- The physical singleton cell is independent four-byte storage with application and feature consumers. That rules out an inferred universal `Singleton<T>::m_instance` static member.
- Project-wide documentation and RTTI searches find unrelated direct `Singleton<Class>` uses but no existing complete reusable template owner, generated `Singleton.h`, generic storage symbol, or generic runtime body.
- A complete base definition must be visible before a derived class declaration. A forward declaration such as `template <class T> class Singleton;`, a PCH-only assumption, or a feature-local copy cannot legally support the reconstructed class headers.

## Source-Structure Decision

Use one normalized `NexusTK/util/Singleton.h` for the complete storage-free template and an include-only `NexusTK/util/Singleton.cpp` for validator projection. Keep explicit class specializations in the consuming module beside that class's sole external singleton global, before lifecycle children that require them.

For `MiscWorkThread`, [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md) owns the zero-initialized global plus `Singleton<MiscWorkThread>` constructor/destructor specializations. [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) includes this header before inheriting from the complete template.

For `LanguageMan`, [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md) owns the sole zero-initialized pointer and `Singleton<LanguageMan>` constructor/destructor specializations in `LanguageMan.cpp`. RTTI proves a direct empty Singleton base at PMD `mdisp=4`; constructor lowering receives the `this+4` facet and `static_cast<LanguageMan *>(this)` performs the observed null-preserving complete-object adjustment before publication. Reverse base teardown clears the global. The authored LanguageMan constructor/destructor do not duplicate those writes, while EH and scalar wrappers are compiler products.

## Rejected Alternatives

- No generic static `T*`, generic constructor/destructor body, or shared storage cell is inferred.
- No feature-local duplicate template belongs in `MiscWorkThread.cpp` or another class module.
- No incomplete base declaration is legal at the derived class definition.
- No implicit precompiled-header dependency is required by the deterministic reconstruction.
- No virtual destructor, vtable, member field, inline publication policy, or compiler RTTI object is handwritten here.
- `Singleton.cpp` is not claimed as an original body-bearing module; it is the validator-compatible include-only companion for the evidence-backed header.

## Historical And Naming Bounds

The normalized source pair and guard convention are deterministic reconstruction choices. The executable does not retain an original `Singleton.cpp`/`Singleton.h` filename string or header guard token. These bounded textual uncertainties do not weaken the complete-base, EBO, storage, specialization, or ownership conclusions.

## Cross-References

- [UID:0004ZL][SingletonTemplate](by-type/by-template/SingletonTemplate.md)
- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md)
- [UID:0001P8][0x0067ab50-0x0067ab54.g_pMiscWorkThread](by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md)
- [UID:0004HM][0x0061fb70-0x0061fb74.MiscWorkThreadRttiLocatorPointer](by-memory/0x0061fb70-0x0061fb74.MiscWorkThreadRttiLocatorPointer.md)

## Changes

- 2026-08-24 B005 UID0000KK support sync: added the exact LanguageMan class-specific specialization route, direct-base PMD/EBO adjustment, sole g_pLanguageMan storage, null-preserving `static_cast` publication, reverse clear, and compiler-lowering boundary without adding generic Singleton storage or duplicate derived-body assignments.

- 2026-07-31 B004 UID0004HM implementation:
  - Created the reusable `NexusTK/util/Singleton.cpp` plus companion `Singleton.h` source root at `90/92`.
  - Recorded direct-Singleton RTTI, PMD, EBO, external-global, and class-specific specialization evidence without inventing a generic static or body.
  - Established the include-only CPP and complete guarded H route needed by validator output and legal derived-class source.
