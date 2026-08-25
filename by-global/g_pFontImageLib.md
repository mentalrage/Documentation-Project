*** UID:0000QX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class FontImageLib;

FontImageLib *g_pFontImageLib = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Sole externally linked FontImageLib pointer definition at source position 0 with a local class forward declaration, exact zero-filled physical storage UID0001P2, 52 refs, direct Singleton<FontImageLib> PMD +0x04 publication/reverse-clear cause, one class-header extern, FontImageLib.cpp ownership, and no duplicate or handwritten lifecycle source. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# g_pFontImageLib

## Status

- Confidence: strong for address, owner/source route, exact 52-reference lifetime/consumer set, direct Singleton source cause, one-definition linkage, source order, FontImageLib vtable context, and zero-filled static image; original symbol spelling is the remaining lexical cap.
- Kind: process-wide singleton pointer.
- Backing storage: [UID:0001P2][0x0067ab24-0x0067ab28.g_pFontImageLib](by-memory/0x0067ab24-0x0067ab28.g_pFontImageLib.md), IDA `dword_67AB24`.
- Canonical owner: [UID:00005B][FontImageLib](by-class/FontImageLib.md) in [UID:0000JH][FontImageLib](by-file/FontImageLib.md).
- Alias caveat: some text consumers may appear under adjacent or raw pointer names in recovered views even though IDA shows they read `dword_67AB24`.
- C++ reconstruction status: this semantic page emits the sole source definition through [UID:0000JH][FontImageLib](by-file/FontImageLib.md) at position `0`, preceded locally by `class FontImageLib;`. [UID:00005B][FontImageLib](by-class/FontImageLib.md) supplies one compatible header-facing `extern`; physical [UID:0001P2][0x0067ab24-0x0067ab28.g_pFontImageLib](by-memory/0x0067ab24-0x0067ab28.g_pFontImageLib.md) is false/non-emitting and cannot duplicate the definition.

## Meaning

`g_pFontImageLib` is the global pointer to the bitmap font/glyph image library. It is constructed during `Application::Initialize`, then read by GrafPort text helpers and UI controls that need glyph metrics, line height, per-glyph width, or decoded glyph pixels.

Keep this global with `render/FontImageLib.cpp`. Callers that only measure or draw text should not own the singleton storage.

## Write Evidence

Healthy IDA MCP session `9b0396a3` reconfirmed auto-analysis/Hex-Rays/string readiness, exact four zero bytes at `0x0067ab24` with SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`, and all 52 direct references. Its three lifecycle writes/clears are:

| Address | Function | Meaning |
| --- | --- | --- |
| `0x004b5f24` | `FontImageLib::FontImageLib` | Compiler-lowered direct `Singleton<FontImageLib>` base publication through `this+4`, not a handwritten assignment. |
| `0x004b5fc5` | [UID:00015B][0x004b5f60-0x004b5fe6.FontImageLibDestructor](by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md) | Compiler-lowered reverse Singleton-base clear after authored cleanup. |
| `0x004b63c0` | `FontImageLib::ScalarDeletingDestructor` | Inlined compiler Singleton clear in the vtable-only deleting wrapper. |

Application initialization allocates exactly `0x8001c` bytes at `0x00464505` and makes the sole direct constructor call at `0x00464520`. Application cleanup loads/checks this global at `0x00464bcf-0x00464bdd`, pushes scalar delete flag `1`, and dispatches vtable slot 0. Direct RTTI records `FontImageLib`, `LObject`, and `Singleton<FontImageLib>` with Singleton PMD `+4/-1/0`; the empty base overlaps the first slot and explains publication/reverse clear without handwritten global lifecycle statements.

## 2026-06-14 C001 IDA Recheck

The current live IDA MCP session is active on `NexusTK.exe.i64` with auto-analysis and Hex-Rays ready. `lookup_funcs` reconfirmed `0x0067ab24` is not a function; `0x004b5f00`, `0x004b5f60`, and `0x004b6350` are the FontImageLib constructor, ordinary destructor, and scalar deleting destructor bodies; and application initialization/cleanup and GrafPort glyph/text helpers remain modeled around `0x004639d0` and `0x004bb5e0`.

Current `xrefs_to 0x0067ab24` reports 52 refs and no additional pages. The compact xref extraction reconfirmed owner write/clear refs at `0x004b5f24`, `0x004b5fc5`, and `0x004b63c0`; Application cleanup read at `0x00464bcf`; GrafPort text/glyph reads at `0x004ba9cb`, `0x004baaaf`, `0x004babe2`, and `0x004badb1`; and representative UI text/control consumers at `0x00586b79`, `0x00586f2a`, `0x0058a284`, and `0x005948cb`. `analyze_component` reconfirmed the FontImageLib vtable at `0x0061a5f4` is shared by the constructor and destructor paths, while the constructor initializes the glyph library object and destructors release slot/scratch resources before clearing the singleton.

B001's 2026-06-17 source-quality pass corrected the backing storage initial-value note: current IDA reads the bytes around `0x0067ab24` as zero-filled and the live value as `0x0`, not `0xffffffff`. The accepted 2026-06-29 UID0002HP report rechecked this with MCP session `3fa0535f`: `get_global_value(0x0067ab24)` returned `0x0`, `xrefs_to(0x0067ab24)` reported 52 refs, and the constructor/destructor lifecycle write/clear evidence remains unchanged.

## Consumer Evidence

The remaining 49 refs are one Application cleanup read and 48 render/UI/text reads. Exact grouped consumer evidence includes:

- [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md), especially `MeasureTextWidth` and `GetLineHeight`.
- [UID:00016I][0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md), which calls `FontImageLib::MeasureGlyphWidth` and `GetFontMetrics`.
- `ClanItemListPane`, `TextButtonControlPane`, `TextEditPane`, fitting-room download controls, balloon text, and other UI text paths that need font metrics.
- `Application::CleanupResources` at `0x00464bd7`, which checks the pointer and dispatches the virtual deleting destructor.

## Ownership Decision

`g_pFontImageLib` is source-owned by `FontImageLib`, not by `GrafPort`, `DirectX`, `TextButtonControlPane`, or individual UI controls. Font measurement paths should be checked against the concrete storage address; only sites that read `0x0067ab24` are consumers of this singleton.

`ImageLib`, `GrafPort`, Application-owned, class-static, raw `dword_67AB24`, and duplicate physical-storage definitions were tested and rejected. Consumer density does not transfer ownership. The established `NexusTK/render/FontImageLib.cpp` route, one source definition, one class-header extern, direct Singleton RTTI, and exact lifecycle references are mutually consistent.

## Score Rationale

Completion is `92` because storage, exact bytes/hash, all 52 references, source owner/route, Application lifetime, direct Singleton compiler cause, one-definition/header split, source position, consumers, and final formal are closed. Confidence is `94` because address, type, source placement, linkage, order, and lifecycle semantics converge across MCP, RTTI, constructor/destructor order, and project precedent; only unrecoverable original spelling remains capped.

## Cross-References

- [UID:0000JH][FontImageLib](by-file/FontImageLib.md)
- [UID:00005B][FontImageLib](by-class/FontImageLib.md)
- [UID:00015A][0x004b5f00-0x004b6409.FontImageLib](by-memory/0x004b5f00-0x004b6409.FontImageLib.md)
- [UID:0001P2][0x0067ab24-0x0067ab28.g_pFontImageLib](by-memory/0x0067ab24-0x0067ab28.g_pFontImageLib.md)
- [UID:0001XM][FontImageLibVtable](by-type/by-vtable/FontImageLibVtable.md)
- [UID:0001UL][FontImageLibLayout](by-type/by-struct/FontImageLibLayout.md)
- [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md)

## Changes

- 2026-07-20 B003 UID0001P2 source-closure callback:
  - Raised `90/90` to `92/94`, retained UID0000JH as owner/emitter, set source position `0`, and applied the exact local forward declaration plus sole zero definition.
  - Added the exact four-byte hash, full 52-reference/lifetime classification, Application allocation/cleanup routes, direct Singleton PMD `+4/-1/0` EBO cause, one class-header extern contract, rejected competing owners, and `NexusTK/render/FontImageLib.cpp` source placement.
  - Historicalized the prior constructor/destructor statements that treated publication and clear as handwritten source. They are compiler-lowered direct-base effects; this page owns only the definition.

- 2026-06-14 C001 low-confidence global refresh:
  - Changed score from `88/82` to `89/86`.
  - Summary/evidence: current IDA MCP reconfirmed active IDB health, exact 52-ref storage xref set, owner write/clear refs, Application cleanup and GrafPort/text/UI consumer reads, and `FontImageLib` vtable sharing across constructor/destructor paths. Owner/emitter remain [UID:0000JH][FontImageLib](by-file/FontImageLib.md); no C++ or IDA database edits were made because final original symbol spelling remains open.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/82`. Summary/evidence: the page documents backing storage, owner, bitmap-font role, constructor/destructor writes, text/render consumers, ownership decision, and alias caveat; final original symbol spelling remains medium-confidence.
- 2026-06-05: Marked reconstructable under [UID:0000JH][FontImageLib](by-file/FontImageLib.md). Evidence: live IDA MCP reports 52 xrefs to `0x0067ab24`; decompilation confirms `0x004b5f00` writes `dword_67AB24`, while `0x004b5f60` and `0x004b6350` clear it from `FontImageLib` destructor paths.
- 2026-06-17 B001 FontImageLib source-quality correction:
  - Kept score `89/86`; corrected the backing-storage initial-value evidence to zero-filled/current `0x0`.
  - Summary/evidence: B001's fresh IDA pass read `0x0067ab24` as value `0x0` with zero-filled neighborhood bytes while preserving the 52-xref lifecycle model: constructor write, ordinary/scalar destructor clears, application cleanup, and GrafPort/text consumers.
- 2026-06-29 B001 UID0002HP implementation callback:
  - Before: `89/86` with formal C++ blank and final declaration linkage treated as unresolved.
  - Changed to: `90/90` with formal source declaration `FontImageLib *g_pFontImageLib = 0;`.
  - Summary/evidence: accepted report `0002HP-FontImageLibConstructor-empty-emitter-source-quality.md` and MCP session `3fa0535f` confirmed zero-filled/current value `0x0`, constructor write at `0x004b5f24`, ordinary destructor clear at `0x004b5fc5`, scalar deleting destructor clear at `0x004b63c0`, 52 xrefs, and the [UID:0002HP][0x004b5f00-0x004b5f54.FontImageLibConstructor](by-memory/0x004b5f00-0x004b5f54.FontImageLibConstructor.md) constructor source use `g_pFontImageLib = this`.
