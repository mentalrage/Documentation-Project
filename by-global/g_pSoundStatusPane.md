*** UID:0000SB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "SoundStatusPane.h"

SoundStatusPane *g_pSoundStatusPane = NULL;

template <>
Singleton<SoundStatusPane>::Singleton()
{
    g_pSoundStatusPane = static_cast<SoundStatusPane *>(this);
}

template <>
Singleton<SoundStatusPane>::~Singleton()
{
    g_pSoundStatusPane = NULL;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SoundStatusPane;

extern SoundStatusPane *g_pSoundStatusPane;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pSoundStatusPane

## Status

- Confidence: source-ready for semantic address binding, loader initialization, lifecycle, class/file owner, explicit Singleton specialization lowering, external linkage, and sole-definition/header route.
- Address: `0x0069b4d4`
- Preferred source name: `g_pSoundStatusPane`.
- Kind: process-wide singleton pointer to [UID:0000DJ][SoundStatusPane](by-class/SoundStatusPane.md)
- Source owner module: [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md)
- Exact memory child: [UID:0002WA][0x0069b4d4-0x0069b4d8.g_pSoundStatusPane](by-memory/0x0069b4d4-0x0069b4d8.g_pSoundStatusPane.md)
- Emission policy: sole semantic definition/header identity at position `0`; exact physical child UID0002WA remains owned evidence but is false/non-emitting.
- Evidence basis: live IDA MCP item/type/comment/xref/decompilation/RTTI checks, constructor callers and allocation sizes, direct PE arithmetic, current documentation, and generated topology.

## Current IDA State And Lifecycle

- The semantic name/global queries resolve exactly one binding, `g_pSoundStatusPane -> 0x0069b4d4`, with no off-target name collision. That semantic address binding is distinct from physical item-name fields.
- Physical inspection returns six separate one-byte undefined heads across `0x0069b4d3-0x0069b4d9`, all with byte `00`, empty physical item names, and empty regular/repeatable address comments. The four target heads are `0x0069b4d4-0x0069b4d8`; only the first target head carries type text `SoundStatusPane *`. The predecessor has no type, and the successor has type `TimerPane *`.
- The exact six-byte window is `00 00 00 00 00 00`, SHA256 `B0F66ADC83641586656866813FD9DD0B8EBB63796075661BA45D1AA8089E1D44`. Range metadata for `[0x0069b4d4,0x0069b4d8)` does not imply a current four-byte IDA aggregate.
- Exactly six direct references target `0x0069b4d4`; predecessor `0x0069b4d3` has zero, and successor `0x0069b4d8` has eight. No data/type/name/comment mutation is authorized: C031 is read-only `NO_CHANGE` protection for the entire six-head neighborhood.

| Address | Access | Source/runtime role |
| --- | --- | --- |
| `0x0057bfc0` | write adjusted `this` | Constructor publishes the live `SoundStatusPane`. |
| `0x0057bfc7` | write zero | Constructor fallback prevents a stale singleton when pointer adjustment yields null. |
| `0x0057c06a` | write zero | Ordinary destructor clears the global before Pane teardown. |
| `0x0057c240` | write zero | Constructor-unwind helper clears partially constructed singleton state. |
| `0x0057c290` | write zero | Scalar deleting destructor clears before optional storage release. |
| `0x005048e6` | read/null-test | MapPane exit-to-menu teardown removes the live pane from the UI graph. |

## Static Initialization And Source Form

- The slot is `0x20cd4` bytes beyond the raw-backed end of `.data`, in its virtual-only tail. The PE contains no target initializer payload, and its relocation directory is absent (`RVA 0`, size `0`); loader-supplied zero is exact.
- The formal CPP first includes `SoundStatusPane.h`, defines `SoundStatusPane *g_pSoundStatusPane = NULL;`, and defines the exact `Singleton<SoundStatusPane>` constructor/destructor specializations. Construction publishes `static_cast<SoundStatusPane *>(this)`; destruction clears the pointer. Explicit `NULL` is the best current human-source token for the client era and project style.
- The formal H forward-declares `SoundStatusPane` and provides `extern SoundStatusPane *g_pSoundStatusPane;`. The external declaration is required because the read at `0x005048e6` belongs to separately documented `MapPane.cpp` code.
- `g_pSoundStatusPane` is the best source name from six role-specific references, the established project `g_p...` convention, current class/file identities, and a zero-collision lookup. The lack of an original PDB does not justify emitting `dword_69B4D4`.

## Singleton, RTTI, And Allocation Evidence

- RTTI names both `SoundStatusPane` and `Singleton<SoundStatusPane>`. The direct Singleton base descriptor records PMD `+0xf8,-1,0`, zero contained bases, and attributes `0x40`.
- `Pane` is `0xf8` bytes. Both `MainMenuPane_InitializeMainUiGraph` routes allocate `0x108` bytes before calling the constructor, matching an empty Singleton base overlapping at `+0xf8` through empty-base optimization plus four derived status-bound dwords through `+0x104`.
- Constructor publication and ordinary/unwind/scalar-destructor clears are the binary lowering of the two explicit Singleton specializations plus ordinary derived construction/destruction. Recovered source expresses the direct base and specializations, not a synthetic registry layer or raw helper bodies.

## Linkage, Ownership, And One Definition

- [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md) owns the definition because its constructor/destructor family writes and clears the global and the visible pane is that file's responsibility.
- `MapPane.cpp` is a consumer only. Its cross-translation-unit teardown read proves external linkage and the H declaration but does not move ownership to MapPane.
- [UID:0002WA][0x0069b4d4-0x0069b4d8.g_pSoundStatusPane](by-memory/0x0069b4d4-0x0069b4d8.g_pSoundStatusPane.md) records the four target one-byte undefined heads inside the protected six-head neighborhood. It remains canonically connected to this semantic page but is false/non-emitting with blank CPP/H; no physical aggregate or physical item-name claim is made.
- This page is the sole semantic source identity and emits at position `0`. A second definition or declaration on UID0002WA would duplicate one storage object and violate one-definition routing.

## Generated Topology

- UID0000SB is the position-zero semantic emitter: CPP includes the complete class header, emits one pointer definition and exactly two Singleton specializations; H emits one forward declaration and one extern.
- Physical UID0002WA has blank formal channels and contributes no marker, definition, or declaration. The complete class and four ordinary methods are emitted once through UID0000DJ/UID0001IG child routing.
- A callback-time generated command/timestamp and physical CPP/H hashes are recorded in the accepted UID0000NX report after all scoped validators complete; no earlier command is treated as current authority.

## Ownership Notes

The global belongs with the HUD sound-status pane, not with [UID:0000NV][SoundManager](by-file/SoundManager.md) or MidiPlayer. It tracks the visible pane instance used by the main UI graph; audio state itself lives in `g_pSoundManager`, `g_pMidiPlayer`, and persisted config fields. File-local `static`, ownership by MapPane/SoundManager/MidiPlayer, modern smart pointers/`nullptr`, raw integer casts, dual definitions, and a synthetic singleton registry are rejected by the cross-file read, raw-pointer ABI, RTTI lowering, source-era style, and one-definition evidence.

## Score And Source-Quality Rationale

- Completion `94`: semantic address binding, loader-zero behavior, all six lifetime accesses, external linkage, owner/position, complete pointer plus Singleton-specialization CPP, H extern, protected physical-child model, and one-definition topology are resolved.
- Confidence `95`: semantic lookup, six-head bytes/types/names/comments, exact `6/0/8` xrefs, RTTI/PMD, two caller allocation sizes, PE arithmetic, and cross-TU use directly support the emitted source and C031 no-change boundary.
- Original lexical alternatives for zero initialization do not change the recovered ABI or source ownership and no longer block source-ready confidence.

## Historical And Data Caveats

- The old `ff ff ff ff` initializer assumption is retained only as superseded history. Current zero bytes, virtual-only `.data` placement, absent relocation payload, and loader behavior disprove it for this executable.
- Some decompiler views omit helper functions that write this global. Use the exact six-reference lifecycle above rather than inferring ownership from one view.

## Cross-References

- [UID:0000DJ][SoundStatusPane](by-class/SoundStatusPane.md)
- [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md)
- [UID:0001IG][0x0057bf70-0x0057c2cf.SoundStatusPane](by-memory/0x0057bf70-0x0057c2cf.SoundStatusPane.md)
- [UID:0000NV][SoundManager](by-file/SoundManager.md)
- [UID:0002WA][0x0069b4d4-0x0069b4d8.g_pSoundStatusPane](by-memory/0x0069b4d4-0x0069b4d8.g_pSoundStatusPane.md)

## Changes

- 2026-08-24 B009 UID0000NX callback: Raised `92/94` to `94/95`. Added the complete include/pointer/two-specialization CPP route, retained the external H declaration, and atomically replaced obsolete aggregate/current-physical-name language with the six one-byte-head neighborhood, four-target-head distinction, separate semantic binding, exact `6/0/8` xrefs, and C031 `NO_CHANGE` protection.
- 2026-08-01 B010 UID0002WA callback: Raised `86/90` to `92/94`, retained owner/emitter UID0000NX, set emitter position `0`, and added the exact formal CPP definition and H declaration. Incorporated loader-zero/PE proof, the complete six-reference lifecycle, direct Singleton RTTI/PMD/EBO and two-allocation evidence, external MapPane linkage, sole-definition/physical-child routing, generated expectations, rejected source alternatives, score rationale, and historical correction of the stale `0xffffffff` initializer.
- 2026-06-05: Marked reconstructable and attached to [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md) to resolve the global unclassified coverage row.
  - Reasoning: live IDA xrefs bind the singleton to the `SoundStatusPane` constructor, cleanup helpers, scalar deleting destructor, and main UI shutdown read. No score change and no reconstruction C++ were added.
- What existed before: this page had the right lifecycle outline but unevaluated completion/confidence metadata and stale raw-label wording.
- What changed to: the page now cites live IDA MCP evidence for storage shape, all six data xrefs, lifecycle writes, and the UI shutdown read. Completion/confidence were set to `82/88`.
- Summary and evidence: IDA MCP on 2026-05-30 verified `0x0069b4d4` as a 4-byte `.data` singleton pointer with six xrefs: shutdown read at `0x005048e6`, constructor assignment/fallback at `0x0057bfc0`/`0x0057bfc7`, cleanup helper clear at `0x0057c06a`, singleton-clear helper at `0x0057c240`, and scalar deleting destructor clear at `0x0057c290`.
- 2026-06-06: Raised completion from `82` to `84` and removed raw storage-label/source-output wording.
  - Reasoning: current live IDA MCP verifies initialized bytes, all six references, constructor publish/fallback clear, non-deleting cleanup clear, singleton-clear helper, scalar deleting destructor clear, and main UI shutdown removal.
  - Historical assumption superseded: this pass recorded `0x0069b4d4` as an exact four-byte `.data` singleton slot initialized to `0xff 0xff 0xff 0xff`. B003's 2026-06-17 source-quality recheck supersedes that byte claim with current zero-filled storage; the lifecycle refs remain valid: shutdown read `0x005048e6`, publish/fallback `0x0057bfc0`/`0x0057bfc7`, cleanup clear `0x0057c06a`, singleton-clear helper `0x0057c240`, and deleting-destructor clear `0x0057c290`.
- 2026-06-11 A005 Batch236 parent-gate repair:
  - Before: `84/88`, one point below the strict completion gate for the exact memory child.
  - After: `86/90`; [UID:0002WA][0x0069b4d4-0x0069b4d8.g_pSoundStatusPane](by-memory/0x0069b4d4-0x0069b4d8.g_pSoundStatusPane.md) can attach to this direct global parent.
  - Evidence: the page now explicitly links the exact child and records the full observed lifecycle: shutdown read, constructor publish/fallback clear, cleanup clear, singleton-clear helper, and scalar deleting destructor clear. The owner module [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md) is repaired to `86/86` in the same batch.
- 2026-06-17 B003 SoundStatusPane source-quality execution:
  - Score unchanged at `86/90`.
  - Evidence: B003 confirmed current live IDA bytes for `0x0069b4d4` are zero-filled, while the lifecycle refs remain constructor publish/fallback, cleanup/destructor/unwind clears, and UI teardown read. Older `ff ff ff ff` initialization wording was stale.
