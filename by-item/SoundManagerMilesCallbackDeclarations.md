*** UID:0004WV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000DG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:15 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "SoundManager.h"

static U32 AILCALLBACK AILFileOpenCallback(const char *filename, U32 *fileHandle);
static void AILCALLBACK AILFileCloseCallback(U32 fileHandle);
static S32 AILCALLBACK AILFileSeekCallback(U32 fileHandle, S32 offset, U32 origin);
static U32 AILCALLBACK AILFileReadCallback(U32 fileHandle, void *buffer, U32 bytes);
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Declaration-only SoundManager.cpp preamble including the centralized SoundManager class header and declaring exactly four file-static Miles open, close, seek, and read callbacks with their 32-bit SDK ABI before every free-callback use; the stream-completion callback is a private static SoundManager member declared only by UID0000DG. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# SoundManager Miles Callback Declarations

## Source Role

This item emits the translation-unit preamble required by the SoundManager Miles file-callback integration. `SoundManager.h` carries the sole complete class declaration through [UID:0000DG][SoundManager](by-class/SoundManager.md), including the private static `AILStreamEndCallback(HSTREAM)` declaration. The four open/close/seek/read callbacks here have internal linkage and remain implementation details canonically owned by [UID:0000NV][SoundManager](by-file/SoundManager.md). The CPP insertion route is UID0000DG so position `15` sorts before that class emitter's constructor/method children; the route controls generated placement and does not make these four file-static callbacks class members.

The position `15` is deliberate: under UID0000DG it precedes the constructor at position `20` and declares all four free File callbacks before `SoundManager::ReinitializeAudioDriver` passes them to `AIL_set_file_callbacks`. The stream callback needs no free prototype here because its private static declaration appears inside UID0000DG's class declaration. A direct UID0000NV emitter at position `15` was tested during the callback and rejected because the generator emits the complete position-10 class subtree before later direct file children, placing these free prototypes after their first uses.

## Exact ABI And Definition Ownership

| Callback | Miles ABI | Sole definition range / source position |
| --- | --- | --- |
| `AILFileOpenCallback` | `U32 AILCALLBACK(const char *, U32 *)` | `[0x0057b630,0x0057b72b)`, position `520` |
| `AILFileCloseCallback` | `void AILCALLBACK(U32)` | `[0x0057b730,0x0057b74a)`, position `530` |
| `AILFileSeekCallback` | `S32 AILCALLBACK(U32,S32,U32)` | `[0x0057b750,0x0057b793)`, position `540` |
| `AILFileReadCallback` | `U32 AILCALLBACK(U32,void *,U32)` | `[0x0057b7a0,0x0057b7e8)`, position `550` |

The four body pages own one file-static CPP definition each and keep their H channels blank. This declaration item owns no body and its H channel is exactly blank: exporting these translation-unit-private File callbacks from `SoundManager.h` would invent a public interface, while repeating prototypes on body pages would create duplicate source declarations. UID0004X0 is deliberately outside this table: it owns the qualified `SoundManager::AILStreamEndCallback` definition, while UID0000DG owns its sole private static declaration.

## Type Providers

- The unchanged `#include "SoundManager.h"` now supplies every token used by the four declarations. UID0004UF's position-zero H preamble defines `U32` as `unsigned long`, `S32` as `signed long`, and guarded `AILCALLBACK` as `__stdcall`, then declares the matching five callback procedure types and complete 37-function Miles boundary.
- These are 32-bit x86 ABI declarations: decorated imports prove stack arity/calling convention, callback body/callsite use proves signed versus unsigned values, and current handle/file-token use proves four-byte widths. The page does not depend on implicit SDK/PCH declarations.
- No local Miles SDK/header/shim exists. The type providers are bounded local compatibility declarations in the owning `SoundManager.h`, not imported proprietary source; `<mss.h>`, a new callback header, and duplicated typedefs on this item are rejected.
- The formal CPP block above remains byte-for-byte unchanged. This callback adds type-source rationale only; the include and exactly four file-static prototypes retain their established order and ownership.

## Evidence And Source-Placement Decision

- `SoundManager::ReinitializeAudioDriver` pushes the read, seek, close, and open callback addresses in exact Miles registration order before `_AIL_set_file_callbacks@16`.
- `SoundManager::PlayTrackByIndex` registers the separate private static `SoundManager::AILStreamEndCallback` with the active Miles stream; its no-`this` `void __stdcall(HSTREAM)` ABI is unchanged by class scope.
- Current generator readback proved that canonical ownership and output insertion ancestry must differ here: `CANONICAL_OWNER:0000NV` retains file ownership, while `EMITTER_UIDS:0000DG` inserts the preamble before class-owned method definitions and still surfaces to the same SoundManager.cpp root.
- Callback xrefs are limited to SoundManager registration/use sites; FileIO supplies the polymorphic `File`, `DATFile`, and `StdioFile` dependencies but does not own or register this ABI glue.
- The open callback implements NexusTK DAT-first policy. The separately class-declared stream callback reads NexusTK Config/Application/SoundManager state. Both source shapes remain project-owned SoundManager.cpp integration, not third-party Miles source and not a separate callback translation unit.
- Contemporary Miles header spellings support `U32`, `S32`, `HSTREAM`, and `AILCALLBACK`. Human-facing names are evidence-backed inference; raw IDA labels are not emitted.

## Rejected Alternatives And History

- Making the four File callbacks `SoundManager` members is rejected because they consume only generic `File` handles and do not access private SoundManager state. The earlier blanket rejection of class scope for every callback is superseded: UID0004X0 must be a private static member because its SDK callback body directly reads private `m_zonePlaylistActive` while preserving a no-`this` ABI.
- Header export is rejected because no external translation unit calls the callbacks.
- FileIO ownership is rejected because generic file operations are dependencies, while all address-taking and runtime policy belong to SoundManager.
- Earlier documentation left callback declarations implicit and body formals blank because exact SDK ABI/source placement had not been resolved. The UID0001IC source-quality pass resolved both and introduced this narrow declaration-only emitter. Its first implementation included a fifth free stream prototype; generated source review proved that shape compile-illegal because the free body accessed a private class field, so the stream declaration moved into UID0000DG while this page retained exactly the four legal file-static declarations.
- The accepted report initially proposed a direct UID0000NV emitter at position `15`. Callback implementation readback showed that this placed the declarations after the class subtree and therefore after use. The final UID0000DG insertion route is the minimum validator-structure correction that preserves canonical file ownership, exact position `15`, internal linkage, and source-before-use order.

## Score Rationale

Completion `93` covers the exact four-declaration text, internal linkage, ABI, source order, body ownership, registration/use sites, dependency direction, class/static separation, and no-duplicate policy. Confidence `94` reflects exact binary, generated-source legality, and SDK agreement; only original local spelling/order within the translation unit remains inferred.

## Cross-References

- [UID:0000DG][SoundManager](by-class/SoundManager.md)
- [UID:0000NV][SoundManager](by-file/SoundManager.md)
- [UID:0001IC][0x0057b490-0x0057b5f0.SoundManagerReinitializeAudioDriver](by-memory/0x0057b490-0x0057b5f0.SoundManagerReinitializeAudioDriver.md)

## Changes

- 2026-08-24 B009 UID0000NX callback: Preserved the formal CPP block byte-for-byte and added the exact `U32`/`S32`/`AILCALLBACK` provider route through the local SoundManager.h compatibility preamble, with x86 ABI evidence and unavailable SDK/PCH/duplicate-typedef alternatives rejected.
- 2026-07-24 B002 UID0001IC implementation callback: created this declaration-only source emitter after Gate 1 acceptance, preserving one class declaration, one prototype preamble, and one CPP definition per exact callback body.
- 2026-07-24 B002 focused source-legality callback: removed only the stream-completion prototype after generated review proved that callback must be the private static `SoundManager::AILStreamEndCallback`; the include and four file-static File callback prototypes remain unchanged.
